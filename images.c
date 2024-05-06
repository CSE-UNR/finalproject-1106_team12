/*
Michelle Shen, Riley Peterson
Final Project
May 3, 2024
 
Program Description:
 Users will be prompted with a menu of options.
 1, Load a new image --- The program will attempt to read the contents of an image from a file name they provide.
 2, Display the current image --- The program will display the image from the file.
 3, Edit the current image --- The users will be able to choose from another menu of options.
    1, crop --- The crop option allows the users to crop the image from a certain x y center point and make it smaller.
    2, dim --- The dim option creates an edited image where each pixel is one step "dimmer".
    3, brighten --- The brighten option creates an edited image where each pixel is one step "brighter".
    4, rotate --- The rotate option allows the users to rotate 90 degrees clockwise
    5, save file --- The save file option allows the users to save the edited image. (Modified from the Executable for the users to save the file after completing all edits, user may also save the file after each edits)
    6, Back to the main menu --- It will take the users back to the main menu.
 4, Exit --- Exiting the main program.
*/

#include <stdio.h>

// Maximum character in a Row
#define MAX_ROWS 1500
// Maximum character in a Collum
#define MAX_COLS 1500
#define MAX_LENGTH 1500

char image[MAX_ROWS][MAX_COLS];
int rows = 0, cols = 0;

void load_image(); // Michelle Shen
void display_image(); // Michelle Shen
void edit_image(); // Michelle Shen
void dim_image(); // Riley Peterson
void brighten_image(); // Riley Peterson
void crop_image(); // Riley Peterson
void rotate_image(); // Michelle Shen
void save_file(); // Michelle Shen

// Main Function
int main() {
    int option;

    // Display the main menu options.
    do {
        printf("|----------------------------| \n");
        printf("|            MENU            | \n");
        printf("|----------------------------| \n");
        printf("| 1 |    Load a new image    | \n");
        printf("|---|------------------------| \n");
        printf("| 2 |  Display current image | \n");
        printf("|---|------------------------| \n");
        printf("| 3 |   Edit current image   | \n");
        printf("|---|------------------------| \n");
        printf("| 4 |          Exit          | \n");
        printf("|----------------------------| \n");
        printf("Enter your choice: ");

        // Read user's input.
        scanf("%d", &option);

        switch (option) {
            case 1:
                load_image();
                break;
            case 2:
                display_image();
                break;
            case 3:
                edit_image();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again\n");
                break;
        }
    } while (option != 4);

    return 0;
}

// Load image function.
void load_image() {
    FILE *file;
    char filename[100];

    // Prompt the users to enter the filename.
    printf("Enter the filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    rows = 0;
    cols = 0;
    while ((ch = fgetc(file)) != EOF && rows < MAX_ROWS) {
        if (ch == '\n') {
            // End of a row, move to the next row
            rows++;
            cols = 0; // Reset column count for the new row
        } else if (cols < MAX_COLS) {
            // Store the character in the image array
            image[rows][cols++] = ch;
        }
    }

    fclose(file);
    printf("Image loaded successfully.\n\n");
}

// Display Image function.
void display_image() {
    if (rows == 0 || cols == 0) {
        printf("No image loaded.\n");
        return;
    }

    printf("Displaying current image:\n\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char output_char;

            switch (image[i][j]) {
                case '0':
                    output_char = ' '; // Input Zero '0' Output Space ' '
                    break;
                case '1':
                    output_char = '.'; // Input One '1' Output Period '.'
                    break;
                case '2':
                    output_char = 'o'; // Input Two '2' Output Lowercase 'o'
                    break;
                case '3':
                    output_char = 'O'; // Input Two '3' Output Uppercase 'O'
                    break;
                case '4':
                    output_char = '0'; // Input Four '4' Output Zero '0'
                    break;
                default:
                    output_char = '?'; // Any Unknown character will Output '?'
                    break;
            }

            putchar(output_char);
        }
        printf("\n");
    }
}

// Edit image function
void edit_image(){
    int choice;
  
    do {
        printf("\n|----------------------------| \n");
        printf("|        EDITING MENU        | \n");
        printf("|----------------------------| \n");
        printf("| 1 |        Dim image       | \n");
        printf("|---|------------------------| \n");
        printf("| 2 |     Brighten image     | \n");
        printf("|---|------------------------| \n");
        printf("| 3 |       Crop image       | \n");
        printf("|---|------------------------| \n");
        printf("| 4 |      Rotate image      | \n");
        printf("|---|------------------------| \n");
        printf("| 5 |    Save edited image   | \n");
        printf("|---|------------------------| \n");
        printf("| 6 |    Back to main menu   | \n");
        printf("|----------------------------| \n");
        printf("Enter your choice: ");
        
        // Read user's input.
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                dim_image();
                break;
            case 2:
                brighten_image();
                break;
            case 3:
                crop_image();
                break;
            case 4:
                rotate_image();
                break;
            case 5:
                save_file();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while (choice != 6);
 
}

// Riley Made this function
// Dim Image Function.
void dim_image(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(image[i][j] > '0'){
                image[i][j]--;
            }
        }
    }
    printf("Image has been dimmed.\n");
    display_image();
    
}
// Riley Made this function
// Brighten Image function
void brighten_image(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(image[i][j] < '4'){
                image[i][j]++;
            }
        }
    }
    printf("Image is brighter.\n");
    // Display the cropped image
    display_image();
}

// Riley Made this function
// Crop Image function.
void crop_image() {
    int x, y;
    int width, height;
    int original_rows = rows;
    int original_cols = cols;
    
    // Display the original dimention.
    printf("Image dimensions: %dx%d\n", original_cols, original_rows);
    
    // Prompt the users to
    printf("Enter the x and y for crop: ");
    scanf("%d %d", &x, &y);
    printf("Enter the width and height for crop: ");
    scanf("%d %d", &width, &height);
    if (x < 0 || y < 0 || width <= 0 || height <= 0 || x + width > cols || y + height > rows) {
        printf("Invalid Dimensions for cropping.\n");
        return;
    }
    // Store original dimensions before cropping
    
    char cropped_image[MAX_ROWS][MAX_COLS];
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            cropped_image[i - y][j - x] = image[i][j];
        }
    }
    // Update rows and cols for the cropped image
    rows = height;
    cols = width;
    // Copy cropped image back to the original image array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = cropped_image[i][j];
        }
    }
    // Fill the rest of the image with spaces
    for (int i = rows; i < MAX_ROWS; i++) {
        for (int j = cols; j < MAX_COLS; j++) {
            image[i][j] = ' ';
        }
    }
    printf("Image has been cropped to %dx%d.\n", cols, rows);
    
    // Display the cropped image
    display_image();
}
 
// Rotate Image function
void rotate_image() {
    if (rows == 0 || cols == 0) {
        printf("No image loaded.\n");
        return;
    }

    // Temporary array to store the rotated image
    char rotated_image[MAX_COLS][MAX_ROWS]; // Swapping rows and columns

    // Perform rotation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated_image[j][rows - 1 - i] = image[i][j];
        }
    }

    // Update rows and cols for the rotated image
    int temp = rows;
    rows = cols;
    cols = temp;

    // Copy rotated image back to the original image array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = rotated_image[i][j];
        }
    }

    printf("Image rotated 90 degrees clockwise.\n");
    // Displaying the edited image
    display_image();
}

// Save File function.
void save_file() {
    FILE *saved_file;
    char filename[1000];
    
    printf("Enter a filename: ");
    scanf("%s", filename);

    saved_file = fopen(filename, "w");
    if (saved_file == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }
    
    // Write the image data to the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fputc(image[i][j], saved_file);
        }
        fputc('\n', saved_file); // Add a newline character at the end of each row
    }

    // Close the output file
    fclose(saved_file);

    printf("File saved successfully as %s\n", filename);
}
