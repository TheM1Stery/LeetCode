#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x);

int main(int argc, char *argv[])
{
    printf("%d", isPalindrome(1234567899));
    return 0;
}

bool isPalindrome(int x) {
    int c = x;
    long temp = 0;
    while(c > 0){
        int digit = c % 10;
        temp = temp * 10 + digit;
        c = c / 10;
    }
    return x == temp;
}
