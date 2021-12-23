// Using stack to reverse 
// 1) Reverse a string
// 2) Reverse a linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char C[51];
    printf("Enter a string:");
    fgets(C, 51, stdin);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
}

void Reverse(char C[], int n)
{
    
}