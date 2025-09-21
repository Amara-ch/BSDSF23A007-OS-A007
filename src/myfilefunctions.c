#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    *lines = *words = *chars = 0;
    int c, in_word = 0;
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (c == ' ' || c == '\n' || c == '\t')
            in_word = 0;
        else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }
    rewind(file);
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    char line[256];
    int count = 0;
    *matches = malloc(100 * sizeof(char*));
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_str)) {
            (*matches)[count] = strdup(line);
            count++;
        }
    }
    rewind(fp);
    return count;
}
