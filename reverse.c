#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    int temp = num;

    
    while (temp != 0) {
        remainder = temp % 10;
        reversed = reversed * 10 + remainder;
        temp /= 10;
    }

    
    int result = reversed + 10;

    printf("Original Number : %d\n", num);
    printf("Reversed Number : %d\n", reversed);
    printf("Result (Reversed + 10) : %d\n", result);

    return 0;
}