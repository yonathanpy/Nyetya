#include <stdio.h>

void print_help() {
    printf("NotPetya Analysis Framework CLI\n");
    printf("--inspect\n--trace\n--audit\n--report\n");
}

int main(int argc, char **argv) {
    print_help();
    return 0;
}
