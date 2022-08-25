#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"
#define  NUM 4

uint8 counter=0 ;

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
    uint8 i , x , y , z , a;
    uint8  year , id ;
    uint8 subjects[3] , grades [3] ;
    uint8 list[NUM] ;

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
            z = SDB_IsFull();
            if (z==1)
            {
                printf("Database is Full \nyou can delete IDs");
                printf("\ntype (1) to Delete An Existing ID");
                printf("\ntype (0) to Return to Tasks : ");
                scanf("%d",&a);
                if(a==1)
                {
                    goto Task_4;
                }
                else
                {
                    goto Tasks ;
                }
            }

            printf("\nStudent ID   : ");
            scanf ("%d",&id);
               while (id==0)
                {
                  printf("\nID can not be zero , try again : ");
                  scanf("%d",&id);
                }
               y = SDB_IsIdExist(id);

               if (y==1)
                {
                  printf("\nID is already exists , try again : ");
                  goto Task_3;
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
               counter++ ;
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
         printf("\nPlease Enter ID to Delete : ");
         scanf("%d",&x);
          while (x==0)
         {
          printf("\nID can not be zero , try again : ");
          scanf("%d",&x);
         }
         y = SDB_IsIdExist(x) ;

         if (y==1)
         {
              SDB_DeleteEntry(x) ;
              counter-- ;
         }
         else if (y==0)
         {
             printf("\nID %d is Not exsit",x);
             goto Tasks ;
         }

         goto Tasks ;
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
             printf("\nNot founded !");
             goto Tasks ;
         }

         goto Tasks ;
         break ;

         case 6 :
Task_6 :
         for(i=0 ; i< NUM ; i++)
         {
             list[i]=0 ;
         }

         SDB_GetIdList(&counter , list) ;
         printf("\nThe List Of IDs : ");

         int n=1;
         for (i=0 ; i<NUM ; i++)
         {
             if (list[i]!=0)
             {
                printf("\n ID Of (%d) : %d ",n++,list[i]);
             }
         }
         goto  Tasks ;
         break ;

         case 7 :
Task_7 :

    printf("\nPlease Enter ID to check : ");
    scanf("%d",&x);
    while (x==0)
    {
      printf("\nID Can Not Be Zero ,Please Enter ID to check : ");
      scanf("%d",&x);
    }

         y = SDB_IsIdExist(x) ;

         if (y==1)
         {
             printf("\nID %d is exsit",x);
         }
         else if (y==0)
         {
             printf("\nID %d is Not exsit",x);
         }
         goto Tasks;
         break ;

         case 8 :
Task_8 :
        printf("Say my name !");
        return 0 ;
        break ;

        default :
        goto Tasks ;
      }




    return 0 ;
}


bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    int i ;
    for (i=0 ; i<NUM ; i++)
    {
        if(ent[i].student_ID==0)
        {
            break ;
        }
    }
   ent[i].student_ID = id ;
   ent[i].student_Year = year ;
   ent[i].Course_1_ID = *subjects ;
   ent[i].Course_1_Grade = *grades ;
   ent[i].Course_2_ID = *(subjects+1) ;
   ent[i].Course_2_Grade = *(grades+1) ;
   ent[i].Course_3_ID = *(subjects+2) ;
   ent[i].Course_3_Grade = *(grades+2) ;


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

bool SDB_IsIdExist(uint8 id)
{
    int i ;
    for (i=0 ; i<NUM ;i++)
    {
        if(id==ent[i].student_ID)
        {
            return true ;
        }
    }
    return false ;
}

void SDB_DeleteEntry(uint8 id)
{
    int i , temp ;
    for ( i =0 ; i<NUM ; i++)
    {
        if(id==ent[i].student_ID)
        {
            temp = ent[i].student_ID ;
            ent[i].student_ID = 0 ;
            ent[i].student_Year = 0 ;
            ent[i].Course_1_ID = 0 ;
            ent[i].Course_1_Grade = 0 ;
            ent[i].Course_2_ID = 0 ;
            ent[i].Course_2_Grade = 0 ;
            ent[i].Course_3_ID = 0 ;
            ent[i].Course_3_Grade = 0 ;
            break;
        }
    }
    printf("\nID %d is Deleted",temp);
}

void SDB_GetIdList(uint8* count, uint8* list)
{
    int i ;
    for ( i = 0 ; i <NUM ; i++)
    {
        if(ent[i].student_ID!=0)
        {
           *(count) ++ ;
           list[i]=ent[i].student_ID ;
        }
    }
}
