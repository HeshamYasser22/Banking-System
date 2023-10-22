#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "LinkedList.h"
#include "Admin.h"
#include <string.h>
#include "time.h"
#include "Functions.h"

u8 User_Arr [5][8] = {"Hesham1" , "Hossam2" , "Ziad123" , "Ahmed64" , "Admin22"};
u8 Password_Arr [5][5] = {"2211" , "1512" , "1070" , "2080" , "1234"};
u32 NumberofClients = 100;
u8 User_Index ;

extern u8 Exit ;

void Admin_voidCreateAccount (u8 *A_Name , u8 *A_Address  , u8* A_Age , u8* A_NationalId )
{
	srand (time(0));
	u8 GID [15] = {'A'};
	LinkedList * Id = LinkedList_CreateNewNode ();
	strcpy ((u8 *)&(Id->Name) , A_Name );
	strcpy ((u8*)&(Id->Address) , A_Address );
	strcpy ((u8 *)&(Id->Age) , A_Age );
	strcpy ((u8 *)&(Id->NationalId) , A_NationalId );
	if (StringToNum(A_Age) < 21)
	{
		while (CheckDigit(GID) ==0 || (strlen(GID) != 14))
		{
			printf ("Enter Guardian National Id : ");
			scanf  (" %[^\n]s" , GID);
			if (CheckDigit(GID) ==0 || (strlen(GID) != 14))
			{
				printf ("Wrong Entry !\n");
			}
		}
		strcpy ((u8 *)&(Id->GuardianId) , GID );
	}
	RandomBankIDGenerator((u8*)&(Id -> BankId));
	RandomPasswordGenerator((u8*)&(Id -> BankPassword));
	printf ("ID : %s\n" , Id -> BankId);
	printf ("Password : %s\n" , Id -> BankPassword);
	Id -> State = Active;
	NumberofClients++;
}



void Admin_voidOpenExistingAcc (u8 *A_BankId)
{
	LinkedList* Client = LinkedList_Search (A_BankId);
	LinkedList* OtherClient = 0;
	u8 local_Choice [1];
	u8 OtherId [10];
	u32 local_Money = 0;
	u8 local_Status = 0;
	u32 local_Cash = 0;
	u32 local_Deposite = 0;
	Exit = 0;
	if (Client != NOTHING)
	{
		while (Exit != 'R')
		{
			printf ("1)Make Transaction \n2)Change Account Status \n3)Get Cash \n4)Deposit in Account \n5)Return To Main Menu \nYour Choice : ");
			scanf  (" %s" , &local_Choice);
			switch (StringToNum(local_Choice))
			{
				case 1 :
					printf ("Bank Account ID you want to transfer money to : ");
					scanf (" %[^\n]s" , OtherId);
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
							printf ( "Faild Transaction !\n");
						}
					}
					else 
					{
						printf ("Faild Transaction !\n");
					}
					break;
				case 2 :
					printf ("1)Active \n2)Restricted \n3)Closed \n");
					printf ("Desired Status : ");
					u8ScanStrtoNum (&local_Status);
					if (local_Status >0 && local_Status < 4)
					{
						Client -> State = local_Status;
					}
					else 
					{
						printf ("Wrong Input ! \n");
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
					Exit = 'R';
					break;	
			}			
		}
	}
	else 
	{
		printf ("Wrong Account ID !\n");
	}
}



void Admin_ExitAdminMode (void)
{
	Exit = 'Q';
}


u8 Admin_u8UserCheck (u8 *PtrUser)
{
	u8 Flag = 0;
	for (u8 i = 0 ; i < 5 ; i++)
	{
		if (strcmpi (PtrUser , User_Arr[i]) == 0)
		{
			Flag = 1;
			break;
		}
	}
	return Flag;
}

u8 Admin_u8PassCheck (u8 *PtrPass)
{
	u8 Flag = 0;
	for (u8 i = 0 ; i < 5 ; i++)
	{
		if (strcmp (PtrPass , Password_Arr[i]) == 0)
		{
			Flag = 1;
			break;
		}
	}
	return Flag;
}


void RandomPasswordGenerator (u8 * Ptr_Pass)
{
	srand (time(0));
	u8 Digits [10] = {'4','1','8','2','0','7','5','3','6','9'};
	for (u8 i = 0 ; i < 4 ; i++)
	{
		Ptr_Pass[i] = Digits [rand()%10];
	}
}

void RandomBankIDGenerator (u8 * Ptr_ID )
{
	LinkedList* Search ;
	srand (time(0));
	u8 Digits [10] = {'0','1','2','3','4','5','6','7','8','9'};
	static u8 Test [10] ;
	while (Search != NOTHING)
	{
		for (u8 i = 0 ; i < 10 ; i++)
		{
			Test[i] = Digits [rand()%10];
		}
		Search = LinkedList_Search(Test);
	}
	for (u8 i = 0 ; i < 10 ; i++)
	{
		Ptr_ID[i] = Test [i];
	}
}