#include <stdio.h>
#include <cstring>

int main() {
    char str[1000] = {'\0'};
    fgets(str, 1000, stdin);
    int size = strlen(str);
    str[size-1] = '\0';
    char *last_space = strrchr(str, ' ');
    if (last_space == nullptr) printf("%s", str);
    else printf("%s", last_space+1);

    return 0;
}