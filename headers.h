#ifndef headers_H_
#define headers_H_

typedef unsigned int uint8 ;

bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades) ;
bool SDB_ReadEntry(uint8 id);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void) ;
bool SDB_IsIdExist(uint8 id) ;
void SDB_DeleteEntry(uint8 id);
void SDB_GetIdList(uint8* count, uint8* list);

#endif
