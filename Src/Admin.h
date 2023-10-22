#ifndef _ADMIN_H_
#define _ADMIN_H_

void Admin_voidCreateAccount (u8 *A_Name , u8 *A_Address  , u8* A_Age , u8* A_NationalId );
void Admin_voidOpenExistingAcc (u8 *A_BankId);
void Admin_ExitAdminMode (void);
u8 Admin_u8UserCheck (u8 *PtrUser);
u8 Admin_u8PassCheck (u8 *PtrPass);
void RandomPasswordGenerator (u8 * Ptr_Pass);
void RandomBankIDGenerator (u8 * Ptr_ID);


#endif