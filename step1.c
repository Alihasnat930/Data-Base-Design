#include <stdio.h>
#include <string.h>

void copy(char *src, char *dest) {
    strcpy(dest, src);
}

int main() {
    char file[28];
    FILE *fp;
    
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fgets(file, sizeof(file), fp);
    fclose(fp);
    
    char dest[28]; // Assuming the file size won't exceed 28 characters
    copy(file, dest);
    
    printf("Contents of file copied into dest: %s\n", dest);
    
    return 0;
}
