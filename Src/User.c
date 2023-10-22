#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "LinkedList.h"
#include "User.h"
#include "Functions.h"
#include <string.h>

u8 extern Exit;

LinkedList* User_CheckClientid (u8 *A_UserId)
{
	u8 Password [4];
	static LinkedList* Client = 0;
	Client = LinkedList_Search (A_UserId);
	if (Client != NOTHING)
	{
		printf ("Enter Password : ");
		scanf (" %[^\n]s", &Password);
		if (strcmp (Password , (u8*)&(Client -> BankPassword)) == 0)
		{
			printf ("Welcome %s\n" , Client->Name);
		}
		else 
		{
			printf ("Wrong Password !\n");
			Client = NOTHING;
		}
	}	
	else
	{
		printf ("Wrong Bank ID !\n");
	}
	return Client;
}


void User_ClientOn (LinkedList* Client)
{
	u8 local_Choice [1];
	u8 Password [4];
	LinkedList* OtherClient = 0;
	u8 OtherId [10];
	u32 local_Money = 0;
	u8 local_Status = 0;
	u32 local_Cash = 0;
	u32 local_Deposite = 0;
	printf ("1)Make Transaction \n2)Change Account Password \n3)Get Cash \n4)Deposit In Account \n5)Return To Main Menu\n");
	printf ("Your Choice : ");
	scanf (" %s" , &local_Choice);
	switch (StringToNum(local_Choice))
	{
		case 1 :
			printf ("Bank Account ID you want to transfer money to : ");
			scanf (" %[^\n]s", OtherId);
			OtherClient = LinkedList_Search(OtherId);
			if (OtherClient != NOTHING)
			{
				printf ("Enter Amount Of Money To Send : ");
				u32ScanStrtoNum (&local_Money);
				while (local_Money == 0)
				{
					printf ("Wrong Entry!\n");
					printf ("Enter Amount Of Money To Send : ");
					u32ScanStrtoNum (&local_Money);
				}			
				if (Client -> Money >= local_Money && Client -> State == Active && OtherClient -> State == Active)
				{
					Client -> Money -= local_Money;
					OtherClient -> Money += local_Money;
					printf ("Succesful Transaction \n");
				}
				else 
				{
					printf ("No Enough Balance !\n");
				}
			}
			else 
			{
				printf ("Faild Transaction !\n");
			}
			break;
		case 2 :
			printf ("Enter Old Password : ");
			scanf (" %[^\n]s" , Password);
			if (strcmp((u8*)&(Client -> BankPassword) , Password) == 0)
			{
				printf ("Enter New Password : ");
				scanf ( " %[^\n]s", Password);
				strcpy ((u8*)&(Client -> BankPassword) , Password);
			}
			else
			{
				printf ("Wrong Password ! \n");
			}
			break;
		case 3 :
			printf ("Enter Desired Amount Of Cash : ");
			u32ScanStrtoNum (&local_Cash);
			while (local_Cash == 0)
			{
				printf ("Wrong Entry!\n");
				printf ("Enter Desired Amount Of Cash : ");
				u32ScanStrtoNum (&local_Cash);
			}				
			if (Client ->Money >=  local_Cash)
			{
				printf ("Succesful Transaction \n");
				Client ->Money -= local_Cash;
			}
			else
			{
				printf ("No Enough Cash In Account !\n");
			}
			break;
		case 4 :
			printf ("Enter Amount Of Deposition : ");
			u32ScanStrtoNum (&local_Deposite);
			while (local_Deposite == 0)
			{
				printf ("Wrong Entry!\n");
				printf ("Enter Amount Of Deposition : ");
				u32ScanStrtoNum (&local_Deposite);
			}			
			Client -> Money +=  local_Deposite;
			printf ("Succesful Deposition !\n");
			break;
		case 5 :
			Admin_ExitUserMode();
			break;
		default :
			printf ("Wrong Entry !\n");
	}
	
}


void Admin_ExitUserMode (void)
{
	Exit = 'Q';
}
