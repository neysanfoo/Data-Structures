// Using stack to reverse a string

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void Reverse(char C[], int n);
void ReverseAlt(char *C, int n);

int main(void)
{
    char C[51];
    printf("Enter a string: \n");
    gets(C);
    ReverseAlt(C,strlen(C));
    printf("Output = %s\n",C);
}

void Reverse(char *C, int n) // Time complexity O(n), Space Complexity O(n)
{
    stack<char> S;
    for (int i = 0; i<n; i++)
    {
        S.push(C[i]);
    }
    for (int i = 0; i<n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

void ReverseAlt(char *C, int n) // Time complexity O(n), Space Complexity O(1)
{
    int i = 0;
    int j = n-1;
    while( i < j)
    {
        int temp = C[i];
        C[i] = C[j];
        C[j] = temp;
        i++;
        j--;
    }
}