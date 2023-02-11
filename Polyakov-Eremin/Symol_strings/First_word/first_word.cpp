#include <stdio.h>
#include <cstring>

int main() {
    char str[1000] = {'\0'};
    fgets(str, 1000, stdin);
    char *first_word = strtok(str, " ");
    printf("%s", first_word);
    return 0;
}