#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100


int main() {
    
    int options;

    do{
        printf("**MENU**\n");
        printf("1. Load a new image \n");
        printf("2. Display current image\n");
        printf("3. Edit the current image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &options);
        
        switch(options){
            case 1:
                load_image();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice, try again\n");
        }
    }while(options != 4);

    return 0;
}

void load_image(){
 
    FILE *file;
    char filename[100];
    char image[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;
   
    
        printf("Enter the filename: ");
        scanf("%99s", filename);  // Read filename from user, max 99 characters
        
        // Open the input file for reading
        file = fopen(filename, "r");
        
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
        
        // Read characters from the file and populate the image array
        char ch;
        while ((ch = fgetc(file)) != EOF && rows < MAX_ROWS) {
            if (ch == '\n') {
                // End of a row, move to the next row
                rows++;
                cols = 0;  // Reset column count for the new row
            } else if (cols < MAX_COLS) {
                // Store the character in the image array
                image[rows][cols++] = ch;
            }
        }
        
        // Close the file
        fclose(file);
        
        // Output the formatted image to the console
        for (int i = 0; i <= rows; i++) {
            for (int j = 0; j < cols; j++) {
                char output_char;
                
                // Translate each pixel character to the corresponding output character
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
                
                // Output the translated character to the console
                putchar(output_char);
            }
            printf("\n");  // Move to the next line after each row
        }

    return 0;
}
