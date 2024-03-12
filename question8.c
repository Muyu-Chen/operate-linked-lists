#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//create a circle linked list
Node* createCircularLinkedList(int n) 
{
    Node* head = NULL;
    Node* prev = NULL;
    for (int i = 0; i < n; ++i)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) return 1;
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
        }
        else 
        {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = head; //turn the line into a circle
    return head;
}

// delete a node and move to the next one
Node* removeNode(Node* prev, Node* current) 
{
    Node* nextNode = current->next;
    prev->next = nextNode;
    free(current);
    return nextNode;
}

//solve this problem
int josephus(int n, int m) 
{
    Node* head = createCircularLinkedList(n);
    Node* prev = NULL;
    Node* current = head;


    while (head->next != head)
    {
        //move m-1 times
        for (int i = 0; i < m - 1; ++i) {
            prev = current;
            current = current->next;
        }
        //delete the m-1
        head = removeNode(prev, current);
        current = head->next; //move to the next one
    }
    int winner = head->data; //the last one is the winner
    free(head);
    return winner;
}

int main() {
    int n, m;
    printf("Enter the total number of people (N): ");
    scanf("%d", &n);
    printf("Enter the count to eliminate (M-1): ");
    scanf("%d", &m);

    int winner = josephus(n, m);
    printf("The winner's number is (counted from 0): %d\n", winner);

    return 0;
}
