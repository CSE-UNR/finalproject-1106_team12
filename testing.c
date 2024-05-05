#include <stdio.h>

#define MAX_ROWS 1000 // Maximum character in a Row
#define MAX_COLS 1000 // Maximum character in a Collum

void load_image();
void display_image();
void edit_image();
void dim_image();
void brighten_image();
void crop_image();
void rotate_image();

char image[MAX_ROWS][MAX_COLS]; // Array to store the image
int rows = 0, cols = 0;


// Main Function
int main() {
    int option;

    // Display menu options.
    do {
        printf("**MENU**\n");
        printf("1. Load a new image\n");
        printf("2. Display current image\n");
        printf("3. Edit the current image\n");
        printf("4. Exit\n");
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

void load_image() {
    FILE *file;
    char filename[100];

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
    printf("Image loaded successfully.\n");
}

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
                    output_char = ' '; // Space
                    break;
                case '1':
                    output_char = '.'; // Period
                    break;
                case '2':
                    output_char = 'o'; // Lowercase 'o'
                    break;
                case '3':
                    output_char = 'O'; // Uppercase 'O'
                    break;
                case '4':
                    output_char = '0'; // Zero
                    break;
                default:
                    output_char = '?'; // Unknown character (for safety)
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
        printf("1. Dim image\n");
        printf("2. Brighten image\n");
        printf("3. Crop image\n");
        printf("4. Rotate image\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");
        
        // Read user's input.
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // dim_image();
                break;
            case 2:
                // brighten_image();
                break;
            case 3:
                // crop_image();
                break;
            case 4:
                // rotate_image();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while (choice != 5);
 
}

/*
void dim_image(){
    return 0;
}
void brighten_image(){
    return 0;
}
void crop_image(){
    return 0;
}
void rotate_image(){
    return 0;
}*/
