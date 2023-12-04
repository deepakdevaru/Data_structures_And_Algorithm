#include <stdio.h>

typedef union second {
    char c;
    int b;
} second;

typedef struct name {
    char c;
    int a;
    double b;
    union second second;
    double e;
} name;

int main() {
    printf("Size of struct name: %zu bytes\n", sizeof(name));
    return 0;
}