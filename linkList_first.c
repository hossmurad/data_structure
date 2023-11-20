#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node *link;
};

void insertAtfirst(struct node **head, int data)
{
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation fail");
        return;
    }
    temp-> data = data;
    temp-> link = *head;
    *head  = temp;

}

void deleteAtfirst(struct node **head)
{
    if (*head == NULL) {
        return;
    } else if ((*head)->link == NULL) {

        free(*head);
        *head = NULL;
    } else {
        struct node *temp = *head;
        *head = (*head)->link;
        free(temp);

    }

}

void print (struct node *head)
{
     struct node *ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

}
int main()
{
    struct node *head = NULL;

    insertAtfirst(&head,10);
    insertAtfirst(&head,20);
    insertAtfirst(&head,30);
    insertAtfirst(&head,40);
    insertAtfirst(&head,50);

    print(head);

    deleteAtfirst(&head);
    deleteAtfirst(&head);
    deleteAtfirst (&head);
    printf("after delete\n");
    print(head);

    return 0;
}
















