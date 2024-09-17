/*Joao Pedro Costa Guerios GRR20234965*/
void removeFirst(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* last = *head;

    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    while (last->next != *head) {
        last = last->next;
    }

    *head = temp->next;
    last->next = *head;
    free(temp);
}
