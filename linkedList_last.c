#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node *link;
};

void insertAtEnd(struct node **head, int data)
{
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation fail");
        return;
    }
    temp-> data = data;
    temp-> link = NULL;

    if(*head == NULL){
        *head = temp;
    }else
    {
        ptr = *head;
        while (ptr-> link != NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

void deleteAtEnd(struct node **head)
{
    if (*head == NULL) {
        return;
    } else if ((*head)->link == NULL) {

        free(*head);
        *head = NULL;
    } else {
        struct node *temp = *head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
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

    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);

    print(head);

    deleteAtEnd(&head);
    deleteAtEnd(&head);
    deleteAtEnd (&head);
    printf("after delete\n");
    print(head);

    return 0;
}















