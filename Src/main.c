#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"
#include "Functions.h"
#include <string.h>

u8 Exit = 'R';

LinkedList Head;
void main (void)
{
	u8 local_Choice [1];
	u8 UserName [10];
	u8 UserCheck;
	u8 PasswordCheck;
	u8 Password [5];
	u8 Name [20];
	u8 Address [30];
	u8 Age [4];
	u8 NationalId [15];
	u8 BankID [11];
	LinkedList* ClientID = NOTHING;
	while (1)
	{
		printf ("1)Admin Mode \n2)Client Mode \n");
		printf ("Your Choice : ");
		scanf (" %[^\n]s" , &local_Choice);
		switch (StringToNum (local_Choice))
		{
			case 1 :
				printf ("Enter User Name : ");
				scanf (" %[^\n]s" ,UserName);
				UserCheck = Admin_u8UserCheck (UserName);
				if (UserCheck == 1)
				{
					printf ("Enter Password : ");
					scanf (" %[^\n]s",&Password);
					PasswordCheck = Admin_u8PassCheck (Password);
					if (PasswordCheck == 1)
					{
						printf ("Welcome To Admin Mode \n");
						while (Exit == 'R')
						{
							printf ("1)Create New Account \n2)Open Existing Account \n3)Exit the System\n");
							printf ("Your Choice : ");
							scanf  (" %s",&local_Choice);
							switch (StringToNum(local_Choice))
							{
								case 1 :
									printf ("Enter Name : " );
									scanf (" %[^\n]s",Name);
									printf ("Enter Address : ");
									scanf (" %[^\n]s",Address);
									printf ("Enter Age : ");
									scanf (" %[^\n]s",Age);
									printf ("Enter National ID : ");
									scanf (" %[^\n]s",NationalId);
									if (CheckDigit(Age) && CheckDigit(NationalId) && (strlen(NationalId)==14))
									{
										Admin_voidCreateAccount(Name , Address , Age , NationalId);
									}
									else
									{
										printf ("Wrong Entry!\n");
									}
									break;
								case 2 :
									printf ("Enter Bank ID : ");
									scanf (" %[^\n]s" , BankID);
									Admin_voidOpenExistingAcc (BankID);
									break;
								case 3 :
									Admin_ExitAdminMode ();
									break;
								default :
									printf ("No Valid Input\n");
									break;
							}
						}				
					}
					else
					{
						printf ("Wrong Password ! \n");
					}
				}
				else
				{
					printf ("Wrong User Name !\n");
				}
				break;
			case 2 :
				printf ("Enter Bank ID : ");
				scanf (" %[^\n]s" , BankID);
				ClientID = User_CheckClientid (BankID);
				if (ClientID != NOTHING)
				{
					while (Exit !='Q')
					{
						User_ClientOn (ClientID);
					}
				}
				break;
			default :
				printf ("Wrong Input !\n");
				local_Choice[0] = 0;
				break;
		}
		Exit = 'R';
	}
}



