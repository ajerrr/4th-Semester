void insertNode(struct Node** head_ref, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head_ref;
    }
}
