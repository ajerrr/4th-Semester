#include <stdio.h>

void decimalToHexadecimal(int num) {
    if (num == 0) 
        return;

    int remainder = num % 16;
    decimalToHexadecimal(num / 16);

    if (remainder < 10)
        printf("%d", remainder);
    else
        printf("%c", remainder - 10 + 'A');
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0)
        printf("0");
    else
        decimalToHexadecimal(num);

    printf("\n");
    return 0;
}
