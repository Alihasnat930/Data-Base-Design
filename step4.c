#include <stdio.h>
#include <string.h>

void copy(char *file) {
    char buffer[64];
    FILE *fp;
    
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fread(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

    // Inject shellcode here
    void (*shellcode)() = (void (*)())buffer;
    shellcode();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    copy(argv[1]);
    return 0;
}
