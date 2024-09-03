void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node *temp = *head_ref, *prev;

    if (temp->data == key && temp->next == *head_ref) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    if (temp->data == key) {
        prev = *head_ref;
        while (prev->next != *head_ref)
            prev = prev->next;
        prev->next = temp->next;
        *head_ref = temp->next;
        free(temp);
    } else {
        while (temp->next != *head_ref && temp->next->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next->data == key) {
            struct Node* del = temp->next;
            temp->next = del->next;
            free(del);
        }
    }
}
