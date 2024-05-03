//Author: Riley Peterson and Michelle Shen
//Date: 05/03/2024
//Purpose: Final Project

#include <stdio.h>




int main() {	
	int choice;
	
	do{
		printf("**MENU**\n");
		printf("1. Load a new image \n");
		printf("2. Display current image\n");
		printf("3. Edit the current image\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
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
	}while(choice != 4);
	
	return 0;
}
