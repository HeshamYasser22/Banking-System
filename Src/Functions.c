#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "Functions.h"

u32 StringToNum (u8 *Ptr_Str)
{
	u32 Result = 0;
	for (u8 i = 0 ; Ptr_Str[i] != '\0' ; i++)
	{
		if (i == 0)
		{
			Result = (Ptr_Str[i]-'0');
		}
		else 
		{
			Result = (Result*10) + (Ptr_Str[i]-'0'); 
		}
	}
	return Result;
}



void u8ScanStrtoNum (u8 *Ptr)
{
	u8 Array[15] ;
	scanf (" %[^\n]s" , Array);
	if (CheckDigit (Array) == 1)
	{
		*Ptr = StringToNum (Array);
	}
	else
	{
		*Ptr = 0;
	}
}


void u16ScanStrtoNum (u16 *Ptr)
{
	u8 Array[15] ;
	scanf (" %[^\n]s" , Array);
	if (CheckDigit (Array) == 1)
	{
		*Ptr = StringToNum (Array);
	}
	else
	{
		*Ptr = 0;
	}
}


void u32ScanStrtoNum (u32 *Ptr)
{
	u8 Array[15] ;
	scanf (" %[^\n]s" , Array);
	if (CheckDigit (Array) == 1)
	{
		*Ptr = StringToNum (Array);
	}
	else
	{
		*Ptr = 0;
	}
}


u8 CheckDigit (u8 * Ptr_Str)
{
	u8 Flag = 1;
	for (u8 i = 0 ; Ptr_Str[i] != '\0' ; i++)
	{
		if (Ptr_Str[i]<'0' || Ptr_Str[i] > '9' )
		{
			Flag = 0;
			break;
		}
	}
	return Flag;
}