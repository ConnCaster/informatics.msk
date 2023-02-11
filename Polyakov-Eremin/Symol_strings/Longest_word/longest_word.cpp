#include <stdio.h>
#include <cstring>

int main() {
    char str[256] = {'\0'};
    fgets(str, 256, stdin);
    int size = strlen(str);
    str[size-1] = '\0';
    int max_len = 0;
    char longest_word[256] = {'\0'};
    char * token = strtok(str, " ");
    strcpy(longest_word, token);
    max_len = strlen(token);
    while (token != nullptr) {
        token = strtok(nullptr, " ");
        if(token != nullptr && strlen(token) > max_len) {
            strcpy(longest_word, token);
            max_len = strlen(token);
        }
    }
    printf("%s\n%d", longest_word, max_len);
    return 0;
}