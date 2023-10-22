#ifndef _USER_H_
#define _USER_H_

LinkedList* User_CheckClientid (u8 *A_UserId);
void User_ClientOn (LinkedList* Client);
void Admin_ExitUserMode (void);
#endif