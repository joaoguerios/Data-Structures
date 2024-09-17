/*Joao Pedro Costa Guerios GRR20234965*/
void removeLast(DNode** head) {
    if (*head == NULL) return;

    DNode* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}
