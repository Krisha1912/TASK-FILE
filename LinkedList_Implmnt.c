#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nSingly Linked List Menu:\n");
        printf("1. Insert\n2. Delete\n3.Traverse\n4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Insert at end
            printf("Enter value to insert: ");
            scanf("%d", &value);

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            printf("Node inserted: %d\n", value);
        }

        else if (choice == 2) {
            // Delete by value
            printf("Enter value to delete: ");
            scanf("%d", &value);

            struct Node *temp = head, *prev = NULL;

            if (head == NULL) {
                printf("List is empty.\n");
            } 
            else if (head->data == value) {
                head = head->next;
                free(temp);
                printf("Node deleted: %d\n", value);
            } 
            else {
                int found = 0;
                while (temp != NULL && temp->data != value) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Node not found: %d\n", value);
                } else {
                    prev->next = temp->next;
                    free(temp);
                    printf("Node deleted: %d\n", value);
                }
            }
        }

        else if (choice == 3) {
            // Traverse the list
            struct Node* temp = head;

            if (temp == NULL) {
                printf("List is empty.\n");
            } else {
                printf("Linked List: ");
                while (temp != NULL) {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
            }
        }

        else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
