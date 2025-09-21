#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    char a[100], b[100];
    mystrcpy(a, "Hello");
    printf("Copied: %s (len=%d)\n", a, mystrlen(a));

    mystrncpy(b, "World", 3);
    printf("Copied n=3: %s\n", b);

    mystrcat(a, " World");
    printf("Concatenated: %s\n", a);

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "This is one line\nThis is second line with apple\nThird line apple again\n");
    fclose(f);

    f = fopen("test.txt", "r");
    int l, w, c;
    wordCount(f, &l, &w, &c);
    printf("File: lines=%d words=%d chars=%d\n", l, w, c);

    char **matches;
    int m = mygrep(f, "apple", &matches);
    printf("Found %d matches:\n", m);
    for (int i = 0; i < m; i++) {
        printf("%s", matches[i]);
        free(matches[i]);
    }
    free(matches);
    fclose(f);
    return 0;
}
