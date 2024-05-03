#include <stdio.h>
#define MAX_ROWS 100   // Maximum number of rows in the image (adjust as needed)
#define MAX_COLS 100   // Maximum number of columns in the image (adjust as needed)
int main() {
    FILE *file;
    char filename[100];  // Assuming a maximum filename length of 99 characters
    char image[MAX_ROWS][MAX_COLS];  // Array to hold the image data
    int rows = 0, cols = 0;  // To track the number of rows and columns in the image
    // Prompt the user to enter the filename
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

