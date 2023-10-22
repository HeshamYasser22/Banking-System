#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "LinkedList.h"
#include <string.h>


extern LinkedList Head ;
u16 global_Length = 0;

LinkedList* LinkedList_CreateNewNode(void)
{
	LinkedList* Id = 0;
	if (global_Length == 0)
	{
		Id = &Head;
	}
	else 
	{
		LinkedList *Last = (LinkedList *)malloc (sizeof(LinkedList));
		Id = Last;
		Last -> Next = NOTHING;
		LinkedList *Search = &Head;
		while (Search -> Next != NOTHING)
		{
			Search = Search -> Next;
		}
		Search -> Next = Last;
	}
	global_Length++;
	return Id;
}


LinkedList* LinkedList_Search (u8 * A_Value)
{
	LinkedList* Search = &Head;
	u16 local_Counter = 0;
	u8 Flag = 0;
	while (local_Counter < global_Length)
	{
		if ((strcmp ((u8*)&(Search -> BankId) ,A_Value)) == 0)
		{
			Flag ++;
			break;
		}
		else 
		{
			Search = Search ->Next;
		}
		local_Counter++;
	}
	if (Flag == 1)
	{
		return Search;
	}
	else 
	{
		return NOTHING;
	}
}