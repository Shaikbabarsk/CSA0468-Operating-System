#include <stdio.h>

int main() {
    const char *filename = "example.txt";
    FILE *file = fopen(filename, "w"); 

    if (file != NULL) {
        fclose(file);

        if (chmod(filename, 0600) == 0) {
            printf("File permissions updated successfully.\n");
        } else {
            perror("Error updating file permissions");
        }
    } else {
        perror("Error opening file");
    }

    return 0;
}
