#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    FILE *file;
    int choice;

    printf("Welcome to the Text Editor\n");

    while (1)
    {
        printf("\n1. Create new file\n");
        printf("2. Open existing file and read the file content\n");
        printf("3. Modify and Save file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter the filename: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';
            file = fopen(filename, "w");
            
            if (file == NULL)
            {
                perror("Error creating file");
            }
            
            else
            {
                printf("File created successfully.\n");
                fclose(file);
            }
            break;
        
        case 2:
            printf("Enter the filename to open: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';
            file = fopen(filename, "r");
        
            if (file == NULL)
            {
                perror("Error opening file");
            }
        
            else
            {
                printf("File opened successfully.\n");
                printf("File content:\n");
        
                while (fgets(content, sizeof(content), file) != NULL)
                {
                    printf("%s", content);
                }
                fclose(file);
            }
            break;
        
        case 3:
            printf("Enter the filename to save: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';
            file = fopen(filename, "w");
        
            if (file == NULL)
            {
                perror("Error saving file");
            }
        
            else
            {
                printf("Enter the content to save (press Ctrl+D to finish):\n");
        
                while (fgets(content, sizeof(content), stdin) != NULL)
                {
                    fputs(content, file);
                }
                fclose(file);
                printf("File saved successfully.\n");
            }
            break;
        
        case 4:
            printf("Exiting...\n");
            exit(0);
        
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
