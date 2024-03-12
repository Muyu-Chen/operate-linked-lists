#include "stdio.h"
#include "stdlib.h"

// Define the structure for the store list
struct storeManagement 
{
	float price;
	int num;
	struct storelist* next;
};

typedef struct storeManagement storelist; //Typedef for convenience

//Function to insert or update the store list
void Store(storelist* head, float n, int m) {
	storelist* pre, * p;
	pre = p = head->next;

	//If the list is empty or the new price is less than the first price
	if (pre == NULL || pre->price > n) {
		storelist* s = (storelist*)malloc(sizeof(storelist));
		if (s == NULL)return 1;
		s->price = n;
		s->num = m;
		s->next = pre;
		head->next = s;
		return;
	}

	// Traverse the list to find the appropriate position to insert or update
	while (p != NULL && p->price < n) {
		pre = p;
		p = p->next;
	}

	// If p is NULL or p's price is greater than n, insert a new storelist
	if (p == NULL || p->price > n) {
		storelist* s = (storelist*)malloc(sizeof(storelist));
		s->price = n;
		s->num = m;
		s->next = p;
		pre->next = s;
	}
	// If p's price is equal to n, update the quantity
	else {
		p->num += m;
	}
}

// Function to print the store list
void PrintStoreList(storelist* head) {
	storelist* current = head->next;
	while (current != NULL) {
		printf("Price: %.2f, Quantity: %d\n", current->price, current->num);
		current = current->next;
	}
}

// Function to get input from user and update inventory
void updateAndPrintInventory(storelist* head) {
	int m;
	float n;
	char choice;

	do {
		printf("Enter the price of TV: ");
		scanf("%f", &n);
		printf("Enter the quantity: ");
		scanf("%d", &m);

		Store(head, n, m);

		// Print the updated inventory
		printf("\nUpdated Inventory:\n");
		PrintStoreList(head);

		printf("\n\n");
		
		//printf("Do you want to enter more data? (y/n): ");
		//scanf(" %c", &choice);
	} while (1);//while (choice == 'y' || choice == 'Y');
}

int main() {
	// Create a dummy head storelist for the store list
	storelist* head = (storelist*)malloc(sizeof(storelist));
	head->next = NULL;

	// Update inventory and print after each update
	updateAndPrintInventory(head);

	// Free allocated memory
	storelist* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}

	return 0;
}

