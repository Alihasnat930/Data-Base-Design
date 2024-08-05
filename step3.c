#include <stdio.h>
#include <string.h>

void copy(char *src) {
    char dest[10];
    // Using strncpy
    strncpy(dest, src, sizeof(dest));
    // Using strcpy_s
    strcpy_s(dest,src, sizeof(dest));
    printf("Copied string using strcpy_s: %s\n", dest);
}

int main() {
    char src[] = "Hello, World!";
    copy(src);
    return 0;
}
