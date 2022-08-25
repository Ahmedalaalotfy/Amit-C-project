#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define  NUM 3
typedef unsigned int uint8 ;
int entryno =0 ;
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades) ;
bool SDB_ReadEntry(uint8 id);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void) ;

struct SimpleDb
{
    uint8 student_ID ;
    uint8 student_Year ;
    uint8 Course_1_ID ;
    uint8 Course_1_Grade ;
    uint8 Course_2_ID ;
    uint8 Course_2_Grade ;
    uint8 Course_3_ID ;
    uint8 Course_3_Grade ;

} ent[NUM];

int main()
{
    unsigned int tsk ;
    uint8 i , x , y;
    uint8  year , id ;
    uint8 subjects[3] , grades [3] ;

Tasks :
    printf("\n\nChoose Task To Accomplish :");
    printf("\n1- Check if the database is full");
    printf("\n2- Get the number of entries in the database");
    printf("\n3- Add new entry to the database");
    printf("\n4- Delete the entry with the given ID");
    printf("\n5- Read an entry matching the provided ID");
    printf("\n6- Get the list of IDs of the students");
    printf("\n7- Checks if the the provided student ID exists");
    printf("\n8- End of program\n");

    scanf("%d",&tsk);


     switch (tsk)

      {
        case 1 :
Task_1 :

        x = SDB_IsFull();
        if (x==1)
        {
            printf("\nList is full");
        }
        else if (x==0)
        {
            printf("\nList is not full");
        }

         goto Tasks ;
         break ;

         case 2 :
Task_2 :
        x = SDB_GetUsedSize();
        printf("The number of entries is : %d",x);
         goto Tasks ;
         break ;
         case 3 :
Task_3 :

            printf("\nStudent ID   : ");
            scanf ("%d",&id);
               while (id==0)
                {
                  printf("\nID can not be zero , try again : ");
                  scanf("%d",&id);
                }

            printf("StudentYear : ");
            scanf ("%d",&year);

            for ( i=0 ; i<3 ; i++)
            {
               printf("Course %d ID : ",i+1) ;
               scanf("%d",&subjects[i]);

               printf("Course %d grade : ",i+1) ;
               scanf("%d",&grades[i]);
                 while (grades[i] > 100)
                 {
                   printf("\nGrade is not correct , try again : ");
                   scanf("%d",&grades[i]);
                 }

            }
    int check = SDB_AddEntry(id,year,subjects,grades) ;
            if (check == 1)
            {
               printf("\nthe entry is added successfully .");
               entryno++ ;
            }
            else
            {
               printf("\nthe entry is not added .");
            }

            printf("\nDo you want to add another student ? (1/0) ");
            scanf("%d",&x);
            if (x == 1)
            {
                goto Task_3 ;
            }
            else
            {
                goto Tasks ;
            }

         goto Tasks ;
         break ;
         case 4 :
Task_4 :
         //void SDB_DeleteEntry(uint8 id)
         break ;

         case 5 :
Task_5:

         printf("\nPlease Enter ID to display data :");
         scanf("%d",&x);
        while (x==0)
           {
                  printf("\nID can not be zero , try again : ");
                  scanf("%d",&x);
           }
         y = SDB_ReadEntry(x) ;

         if (y==0)
         {
             printf("\nNot founded ! , try again :");
             goto Task_5 ;
         }

         goto Tasks ;
         break ;

         case 6 :
Task_6 :
         //void SDB_GetIdList(uint8* count, uint8* list)

         break ;

         case 7 :
Task_7 :
         //bool SDB_IsIdExist(uint8 ID)

         break ;

         case 8 :
Task_8 :
        printf("Say my name !");
        break ;

        default :
        goto Tasks ;
      }




    return 0 ;
}


bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
   ent[entryno].student_ID = id ;
   ent[entryno].student_Year = year ;
   ent[entryno].Course_1_ID = *subjects ;
   ent[entryno].Course_1_Grade = *grades ;
   ent[entryno].Course_2_ID = *(subjects+1) ;
   ent[entryno].Course_2_Grade = *(grades+1) ;
   ent[entryno].Course_3_ID = *(subjects+2) ;
   ent[entryno].Course_3_Grade = *(grades+2) ;

   return true ;
}

bool SDB_ReadEntry(uint8 id)
{
  int i , n =0 ;
  for (i = 0 ; i<NUM ;i++)
  {
      if (ent[i].student_ID==id)
      {
          n= 1;
          printf("\nfounded !");
          printf("\n student ID       : %d",ent[i].student_ID);
          printf("\n student year     : %d",ent[i].student_Year);
          printf("\n course 1 ID      : %d",ent[i].Course_1_ID);
          printf("\n course 1 degree  : %d",ent[i].Course_1_Grade);
          printf("\n course 2 ID      : %d",ent[i].Course_2_ID);
          printf("\n course 2 degree  : %d",ent[i].Course_2_Grade);
          printf("\n course 3 ID      : %d",ent[i].Course_3_ID);
          printf("\n course 3 degree  : %d",ent[i].Course_3_Grade);
          return n ;
      }

  }
  return n ;
}

bool SDB_IsFull(void)
{
   int i , n =0;
   for (i=0 ; i<NUM ; i++)
   {
       if (ent[i].student_ID!=0)
       {
          n++ ;
       }
   }

   if (n==NUM)
   {
       return true ;
   }
   else
   {
       return false ;
   }
}

uint8 SDB_GetUsedSize(void)
{
   int i , n =0;
   for (i=0 ; i<NUM ; i++)
   {
       if (ent[i].student_ID!=0)
       {
          n++ ;
       }
   }
   return n ;
}
