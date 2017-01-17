#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
typedef enum {wai = 0,cal= 1,calwai=2} status;

boolean DebugMode;
typedef struct stackStruct                                                              //node creating
{
     char name[100];
     int size;
     status st;
     struct stackStruct* next;                                                      //stores the address of the previous node 
}stru; 

typedef struct stackStruct stack;
typedef stack* stackptr;


void addToList(stackptr* hd,char *nam,int siz);
int doesNameExist(stackptr hd,char *nam);
int updateStatus(stackptr* hd,char *nam);
char *retrieveAndRemove(stackptr **hd,int size);
int countGroupAhead(stackptr hd,char *nam);
void displayGroupSizeAhead(stackptr hd,char *nam,stackptr recur,int nu,int count);
void displayListInformation(stackptr hd,stackptr recur,int count);
int getNextNWSChar ();
int getPosInt ();
char *getName();
void clearToEoln();
void printCommands();
void doAdd (stackptr  *hd);
void doCallAhead (stackptr* hd);
void doWaiting (stackptr hd);
void doRetrieve (stackptr *hd);
void doList (stackptr hd);
void doDisplay (stackptr hd);
