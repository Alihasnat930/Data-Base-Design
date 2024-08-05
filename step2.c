#include <stdio.h>
#include <string.h>

void copy(char *src) {
    char dest[10];
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';  // Null-terminate the destination string
    printf("dest: %s\n", dest);

    *((unsigned int*)(dest + 12)) = 0x12345678; 
}

int main() {
    char src[] = "This is a long string to demonstrate buffer overflow vulnerability";
    copy(src);
    return 0;
}
