#include <stdio.h>
#include <cstring>

int main() {
    char str[256] = {'\0'};
    fgets(str, 256, stdin);
    int size = strlen(str);
    str[size-1] = '\0';
    char * token = strtok(str, " ");
    int counter = 0;
    while (token != nullptr) {
        counter++;
        token = strtok(nullptr, " ");
    }
    printf("%d", counter);
    return 0;
}