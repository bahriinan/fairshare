#include "stdio.h"

#include "test.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//task struct
struct node *head = NULL;
struct node *current = NULL;

//userstruct
struct unode *uhead = NULL;
struct unode *ucurrent = NULL;

void uinsertFirst(int uid,int pnumber)
{
   //create a link
   struct unode *link = (struct unode*) malloc(sizeof(struct unode));
	

   link->uid = uid;
   link->pnumber = pnumber;
	
   //point it to old first node
   link->next = uhead;
	
   //point first to new first node
   uhead = link;
}

void insertFirst(int pid, int uid, int gid)
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->pid = pid;
   link->uid = uid;
   link->gid = gid;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

void printList()
{
   struct node *ptr = head;
   
   //start from the beginning
   while(ptr != NULL)
	{        
      printf("(%d,%d,%d)\n",ptr->pid,ptr->uid,ptr->gid);
      ptr = ptr->next;
   }
	
   
}

int main(void)
{

 //task_structı doldur

 insertFirst(1,3,1);
	insertFirst (11,14,3);
 insertFirst(2,3,1);
  insertFirst(3,2,1);
   insertFirst(4,4,1);
    insertFirst(5,4,1);
    
     insertFirst(6,12,2);
     	insertFirst (7,13,7);
     insertFirst (8,11,2);
	insertFirst (9,11,2);
	insertFirst (10,17,3);
		insertFirst (11,17,3);
		
		
		
	//user_sturctı doldur
	uinsertFirst(3,2);
	uinsertFirst(14,1);
	uinsertFirst(2,1);
	uinsertFirst(4,2);
	uinsertFirst(12,1);
	uinsertFirst(13,1);
	uinsertFirst(11,2);
	uinsertFirst(17,2);
	
	
	
	
	
	
	
	
		
		
		
///buraaaa üst dogru calısıyor alttakileri ekleyince bozuluyor
/*
 insertFirst (1,1,2);
	insertFirst (1,2,2);
 */
 /*
 //user strcutı doldur
 //yukarıya baglı dolduruldu
 uinsertFirst(1,2);
 uinsertFirst(2,1);
 uinsertFirst(3,2);
 
*/
 /*
 printf("task_struct contenti\n");
 

	printList();
	*/
	
	
	
printf("\nProcessler\n");
 process(head,uhead);
    return 0;
}

