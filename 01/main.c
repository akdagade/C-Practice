#include <stdio.h>
#include <ctype.h>
int main() {
    printf("Hello, World!\n");

    int a = 33;
    int b = 286;

    printf("%d %s\n",a, isalpha(a)? "true" : "false");
    printf("%c %s\n\n",a, isalpha(a)? "true" : "false");

    printf("%d %s\n",b, isalpha(b)? "true" : "false");
    printf("%c %s\n",b, isalpha(b)? "true" : "false");
    return 0;
}