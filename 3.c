#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1.h"

void doAdd (stackptr  *hd)
{   
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Add command requires an integer value of at least 1\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

int a=0;
if(*hd!=NULL)
a = doesNameExist(*hd,name);
if(a==0)
{printf ("Adding group \"%s\" of size %d\n", name, size);
addToList(hd,name,size);
}
    else                                                                                     // add code to perform this operation here
printf("\nName already exist,please enter a different name\n");

}


void doCallAhead (stackptr* hd)
{
 /* get group size from input */
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 1\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <size> <name>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    printf ("         <name> is the name of the group making the reservation\n");
    return;
   }



stackptr b;
b=*hd;
int a=1;
if(*hd!=NULL)
    a = doesNameExist(*hd,name);
if(a==1)
{ 



    int strcomp=1;
    while(strcomp!=0)
    {    
         strcomp = strcmp(b->name,name);
  
    
         if(strcomp==0)
         {           if(b->st==0)
                     b->st=1;
         break;
        

         }           
                if(b->next != NULL)
                            b=b->next;


         if(strcomp==0)
          break;   
                                            
}
printf("\nstatus =%d\n",b->st);

}
    else                                                                                     // add code to perform this operation here
    printf("\nName does not exist,please enter a different name\n");

    

                                                                            
}
void doWaiting (stackptr hd)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }

 printf ("Waiting group \"%s\" is now in the restaurant\n", name);

 int a=1;
 if(hd!=NULL)
         a = doesNameExist(hd,name);
 if(a==1)
 {
        updateStatus(&hd,name); 
 }
     else                                                                                     // add code to perform this operation here
             printf("\nName does not exist,please enter a different name\n");




}



void doRetrieve (stackptr *hd)
{
 /* get table size from input*/
 int size = getPosInt();
 if (size < 1)
   {
    printf ("Error: Retrieve command requires an integer value of at least 1\n");
    printf ("Retrieve command is of form: r <size>\n");
    printf ("  where: <size> is the size of the group making the reservation\n");
    return;
   }
 clearToEoln();
 printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);

printf("\nGroup %s\n",retrieveAndRemove(&hd,size));                                                                               // add code to perform this operation here


}

void doList (stackptr hd)
{
 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the group to inquire about\n");
    return;
   }
int a=1;
if(hd!=NULL)
        a = doesNameExist(hd,name);
if(a==1)
{
        printf ("Group \"%s\" is behind the following groups\n", name);

        printf("\nNumeber of groups ahead= %d\n", countGroupAhead(hd,name)); 
        printf("\nThese groups have sizes as follows:\n");
        displayGroupSizeAhead(hd,name,hd,countGroupAhead(hd,name),-1);

}
    else                                                                                     // add code to perform this operation here
        printf("\nName does not  exist,please enter a different name\n");


}
 
void doDisplay (stackptr hd)
{
 clearToEoln();
 printf ("Display information about all groups\n");

displayListInformation(hd,hd,-1);                                                                                                 // add code to perform this operation here
}
