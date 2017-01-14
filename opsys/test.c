#include "stdio.h"
#include "test.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//total groubs
double tgroub=0;
//group node
struct gnode *ghead = NULL;
struct gnode *gcurrent = NULL;
//groub and user node
struct gunode *guhead = NULL;
struct gunode *gucurrent = NULL;
//addgu bodoslama ekler dddd
int addgu(int gid,int uid){
		 struct gunode *link = (struct gunode*) malloc(sizeof(struct gunode));
	printf("GU tablosuna ekle gid->%d,uid->%d\n",gid,uid);
  link->gid=gid;
  link->uid=uid;
	
   //point it to old first node
   link->next = guhead;
	printf("G-U add->gid=%d,uid=%d\n",gid,uid);
   //point first to new first node
   guhead = link;
}
void displaygu(){
	printf("\nGU struct\n");
	struct gunode *ptr=guhead;
	int statu=0;
	while(ptr != NULL)
	{        
	printf("Gid->%d\nUID->%d\n",ptr->gid,ptr->uid );
     
      
      ptr = ptr->next;
   }
  
}
//gexists varmý gid + uid bak yoksa gu tablosuna bak
int guexists(int gid,int uid){
	struct gunode *ptr=guhead;
	int statu=0;
		printf("\nExistence Control\n");
		
	printf("Beklenen-gid->%d,uid->%d\n\n",gid,uid);
	while(ptr != NULL)
	{        
	
		printf("gelen->guid%d,uid%d\n",ptr->gid,ptr->uid);
		//u + g varmý kontrol edelim linked listi
      if(ptr->gid==gid && ptr->uid==uid)
      {
      //daha önce varmýþ
      	printf("**varmýþ->%d,%d\n",gid,uid);
      		 displaygu();
		  ///groublama u + g
		   return 1;
      	 break;
		} 
      
      ptr = ptr->next;
   }
   printf("GU tablosunda yok guid->%d,uid->%d\n",gid,uid);
   //yokmuþ
   addgu(gid,uid);
   displaygu();
//  printf("statu->%d\n",statu);
   return statu;
}

//add group list
int addglist(int gid){
	 struct gnode *link = (struct gnode*) malloc(sizeof(struct gnode));
	
  link->counter=1;
   link->gid = gid;
	
   //point it to old first node
   link->next = ghead;
	
   //point first to new first node
   ghead = link;
   tgroub++;
}

//search group list
int searchglist(int gid,int uid){
	struct gnode *ptr=ghead;
	int statu=0;
	printf("control search->gid %d\n",gid);
	while(ptr != NULL)
	{        
	
      if(gid==ptr->gid)
      {
      	//groub varmýþ useri yenimi diye bakalým
      	
      	printf("**groub ->%d varmýþ ,user-> kontrol %d\n",gid,uid);
       if(	guexists(gid,uid)==0)
    		ptr->counter++;   
	
		   statu=1;
      	 break;
		} 
      
      ptr = ptr->next;
   }
   printf("control bitti->gid->%d statu->%d\n",gid,statu);
  // printf("statu->%d\n",statu);
   return statu;
}
//combine desing for groups
void fillglist(int gid,int uid){

	//search et yoksa 0 döner
	//varsa zaten üstüne ekler
	printf("gid->%d control ediliyor\n",gid);
	if(!searchglist(gid,uid)){
		printf("yokmus ekleyicez grouba add->%d\n",gid);
		guexists(gid,uid);
		printf("GU tablosunada eklendi gid->%d,uid->%d\n",gid,uid);
		addglist(gid);
		
	}
}


void displayg(){
	printf("\nGroup struct\n");
	struct gnode *ptr=ghead;
	int statu=0;
	while(ptr != NULL)
	{        
	printf("Gid->%d\nsayac->%d\n",ptr->gid,ptr->counter);
     
      
      ptr = ptr->next;
   }
  
}
//find number of process under this struct

//atomic_read(&(p->user->processes));
int fnpUS(struct unode*user_struct,int uid){
		struct unode *ptr2=user_struct;
	///processleri ayýkla ve groub struct olustur

	 while(ptr2 != NULL)
	{        
//	 printf("pid->%d,pnumber->%d\n",ptr2->uid,ptr2->pnumber);
      if(ptr2->uid==uid)
      		return ptr2->pnumber;
      	
      ptr2 = ptr2->next;
   }

}
int findgroub(int gid){
	struct gnode *ptr=ghead;
	while(ptr!=NULL){
		
		if(gid==ptr->gid){
			return ptr->counter;
		}
		ptr=ptr->next;
	}
}


int process(struct node *task_struct,struct unode *user_struct)
{
		struct node *ptr=task_struct;
	///processleri ayýkla ve groub struct olustur

 
	 while(ptr != NULL)
	{        
	
      fillglist(ptr->gid,ptr->uid);
      	printf("\n\n");
      
      	
      	printf("\n\n");
      ptr = ptr->next;
   }
	displayg();
 //ddisplaying groub linkedlist
//calculate percentage per process
//re search task_struct processes
displaygu();

//calculate percentage with re scan

printf("----------------\nPercentages calculation\n--------------------\n");
ptr=task_struct;

	 while(ptr != NULL)
	{        
	//finding users number in the grop which has the process
    double userno = findgroub(ptr->gid);
    //percentage per user for this process
    double ppu=(100/tgroub)/userno;
    //find number of process under this user
    int fnp=fnpUS(user_struct,ptr->uid);
    
   ppu=ppu/fnp;
      	printf("pid->%d,uid->%d,gid->%d,percentage->%f\n",ptr->pid,ptr->uid,ptr->gid,ppu);
      
      ptr = ptr->next;
   }

}
