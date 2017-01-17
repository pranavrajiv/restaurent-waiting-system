#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1.h"

void addToList(stackptr* hd,char *nam,int siz)                                  //function that adds to the new group
{
stackptr temp;
temp=(stackptr)malloc(sizeof(stack));
strcpy(temp->name,nam);
temp->size=siz;
temp->st=wai;
temp->next=*hd;
*hd=temp;




if(DebugMode==TRUE)
{
printf("\nGroup Name=%s\n",temp->name);
printf("Group Size=%d\n",temp->size);
printf("Group Status= Wating in the restaurent \n\n");

}


}    


int doesNameExist(stackptr hd,char *nam)                                        //function that checks if the name exist
{

    
    
    
int strcomp=1;    
while(strcomp!=0)
{    
strcomp = strcmp(hd->name,nam);
if(strcomp==0)
 if(DebugMode==TRUE)
 {                                         
     printf("\nName exist\n");
 }

   if(strcomp==0)
    break;    
                                        
if(hd->next != NULL)
hd=hd->next;
else
break;    
}

if(strcomp==0)
return 1;
else 
return 0;

}    


int updateStatus(stackptr* hd,char *nam)                                          //function that update the waiting status
{       stackptr b=*hd;
        int strcomp=1;
            while(strcomp!=0)
                    {
                                 strcomp = strcmp(b->name,nam);


                                          if(strcomp==0)
                                                       {   if(b->st==cal)
                                                           { b->st=calwai;
                                                            
                                                               if(DebugMode==TRUE)
                                                                printf("\nStatus changed\n");   
                                                               return 1;;
                                                           }
                                                           else 
                                                           { 
                                                            if(DebugMode==TRUE)
                                                            printf("\nStatus Not changed changed\n");

                                                           return 0;    
                                                           }
                                                        }
                                                          if(b->next != NULL)
                                                          b=b->next;


                                                        
                                                                              
                                                                                                         
                    }                           
    


}    
    
    
char *retrieveAndRemove(stackptr **hd,int size)                                             //function that revomes the group
{ char na[100];
stackptr b;
stackptr c;
stackptr d=(**hd);
stackptr e;





for(int i=0;d!=NULL;i++)
{    


if((d->next!=NULL)&&(size>=d->next->size))
c=d;

if(size>=d->size)
e=d;
if(d->next==NULL)
break;    
else
d=d->next;   

}



if((size>=e->size)&&(e==(**hd)))
{  b=(**hd);
    **hd=(**hd)->next;
    strcpy(na,e->name);
    free(b);
    if(DebugMode==TRUE)
    {printf("\nRemoving \n");

    printf("\nGroup Name=%s\n",(**hd)->name);
    printf("Group Size=%d\n",(**hd)->size);
    if((**hd)->st==0)
            printf("\Status = Waiting in the restaurent");
    else
        if((**hd)->st==1)
                        printf("Status = Called Ahead \n");

        else
            if((**hd)->st==2)

                    printf("\nStatus = Called Ahead and waiting \n");
        
    
    }
    return na;




}    





strcpy(na,e->name);
b=e;
if(e->next!=NULL)
c->next=e->next;
                                                

if(e->next==NULL)
{
    b=c->next;
    c->next=NULL;   

    if(DebugMode==TRUE)
            {printf("\nRemoving \n");

                    printf("\nGroup Name=%s\n",(b)->name);
                        printf("Group Size=%d\n",(b)->size);
                            if((b)->st==0)
                                            printf("\nStatus = Waiting in the restaurent");
                                else
                                            if((b)->st==1)
                                                                        printf("\nStatus = Called Ahead \n");

                                        else
                                                        if(b->st==2)

                                                                                printf("\nStatus = Called Ahead and waiting \n");
                                            
                                    
                                    }
    
    
    
    
    
    free(b);
}                                            
return na;
}   



int countGroupAhead(stackptr hd,char *nam)                                                  //function that counts teh number of groups ahead    
{ 
stackptr a=hd;

int strcomp;
strcomp = strcmp(a->name,nam);
while(strcomp!=0)
{
     strcomp = strcmp(a->name,nam);
    
     if((a->next != NULL)&&(strcomp!=0))
         a=a->next;   
     else
     break;
 
}

int j=0;   
while(a!=NULL)
{    
if(a->next!=NULL)
{a=a->next;
++j;
}
    else 
break;
}
if(DebugMode==TRUE)
printf("There are %d group ahead",j);
return j;


}





void displayGroupSizeAhead(stackptr hd,char *nam,stackptr recur,int nu,int count)                   //function that displays the size of teh groups ahead
{
    stackptr a=hd;
    if(count==-1)
    {
    int i;
    for(i=0;a!=NULL;i++)
    {if(a->next!=NULL)
        a=a->next;
        
    else
        break;    
    }    
    count=i+1;

    }
if(recur->next!=NULL)
{count--;
    recur=recur->next;
displayGroupSizeAhead(hd,nam,recur,nu,count);
if(count<=nu)
printf("\nGroup %d has a size of %d \n",count,recur->size);
}

}




void displayListInformation(stackptr hd,stackptr recur,int count)                                   //function that displays the whole list
{    

stackptr a=hd;
int i=0;    
if(count==-1)
    {
    
    for(i=0;a!=NULL;i++)
       {if(a->next!=NULL)
            a=a->next;                 
        else
            break;
       }    
     count=i+1;                           
     i=-1;

    printf("\nThe number of groups in the waiting list = %d\n",count);
    
    }   

if(recur->next!=NULL)
{
count--;
recur=recur->next;
displayListInformation(hd,recur,count);
printf("\n\nGroup %d ",count);
printf("\nName %s ",recur->name);
printf("\nSize %d ",recur->size);
if(recur->st==0)
    printf("\nStatus = Waiting in the restaurent");
else
if(recur->st==1)
            printf("\nStatus = Called Ahead \n"); 

else
if(recur->st==2)
    
    printf("\nStatus = Called Ahead and waiting \n");
else 
    printf("\nStatus = %d \n",hd->st);
  

printf("\n\n");
}
if(i==-1)
{ 
if(count != 1)    
count++;
printf("\n\nGroup %d ",count);
printf("\nName %s ",hd->name);
printf("\nSize %d ",hd->size);
if(hd->st==0)
        printf("\nStatus = Waiting in the restaurent");
else
if(hd->st==1)
        printf("\nStatus = Called Ahead \n"); 

else
    if(hd->st==2)

            printf("\nStatus = Called Ahead and waiting \n");
    else 
            printf("\nStatus = %d \n",hd->st);
  


printf("\n\n");


}




}



