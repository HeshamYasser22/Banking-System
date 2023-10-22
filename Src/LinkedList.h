#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef enum {
	Active = 1,
	Restricted = 2,
	Closed = 3,
}Status;
typedef struct List LinkedList;
struct List{
	u8 Name[20];
	u8 Address[30];
	u8 Age [4];
	u8 NationalId [15];
	u8 GuardianId [15]; 
	u8 BankId [11];
	u8 BankPassword [5];
	Status State;
	u32 Money;
	LinkedList *Next;
};

LinkedList* LinkedList_CreateNewNode(void);
LinkedList* LinkedList_Search (u8 *A_Value);
#define NOTHING		0
#endif