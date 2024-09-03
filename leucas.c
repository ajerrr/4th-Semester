#include <stdio.h>

int lucas(int n) {
    if (n == 0)
        return 2;
    if (n == 1)
        return 1;
    return lucas(n - 1) + lucas(n - 2);
}

void generateLucasSeries(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lucas(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms in the Lucas series: ");
    scanf("%d", &n);

    generateLucasSeries(n);
    return 0;
}
