#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Из слова яблоко путем "вырезок" и "склеек" его букв получить слова блок и око.
 */


int fun(char *mas, size_t size);
int fun(char *mas, size_t size){
    for (int i=size-1; i>0; i--){
        if (mas[i]=='B')
            return i;
    }
    return -1;
}

int main() {
    char mas[100000]={'\0'};
    fgets(mas, 100000,stdin);
    size_t size=strlen(mas);
    int counter = 0;
    for(int i=0; i<size; i++) {
        int lastB_idx = fun(mas, size);
        if(i>lastB_idx){
            break;
        }
        if(mas[i]=='R'){
            counter++;
            mas[i]='_';
            mas[lastB_idx]='_';
        }
    }
    for (int i = 0; i < size; ++i) {
        if (mas[i] != '_')
            printf("%c", mas[i]);
    }
    printf("\n");
    printf("%d", counter * 2);

    return 0;
}