#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function prototypes
void load_image();

int main() {
    int options;

    do {
        printf("**MENU**\n");
        printf("1. Load a new image\n");
        printf("2. Display current image\n");
        printf("3. Edit the current image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &options);

        switch (options) {
            case 1:
                load_image();
                break;
            case 2:
                printf("Displaying current image...\n");
                break;
            case 3:
                printf("Editing current image...\n");
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while (options != 4);

    return 0;
}

void load_image() {
    FILE *file;
    char filename[100];
    char image[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    printf("Enter the filename: ");
    scanf("%99s", filename);
    
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

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


    fclose(file);

 
    printf("Loaded image:\n");
    printf("\n");
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
        printf("\n");
    }
}
