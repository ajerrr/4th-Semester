#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void findVarianceAndSD(struct Node* head, float* variance, float* stdDev) {
    int sum = 0, count = 0;
    float mean = 0.0;
    *variance = 0.0;

    struct Node* current = head;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }

    if (count > 0)
        mean = (float)sum / count;

    current = head;
    while (current != NULL) {
        *variance += pow((current->data - mean), 2);
        current = current->next;
    }

    if (count > 0)
        *variance /= count;

    *stdDev = sqrt(*variance);
}

int main() {
    struct Node* head = createNode(5);
    head->next = createNode(7);
    head->next->next = createNode(12);
    head->next->next->next = createNode(15);

    float variance, stdDev;
    findVarianceAndSD(head, &variance, &stdDev);

    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdDev);

    return 0;
}
