#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void copy(char *input) {
        char buffer[8];
        strcpy(buffer, input);
        printf(buffer);
        return;
}

int main(int argc, char* argv[]) {
        copy(argv[1]);
}
