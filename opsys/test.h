#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
//grouplarý tutmak icin linked list

struct gnode  
{
	int counter;
   int gid;
   struct gnode *next;
};


//groub and user node
struct gunode {
	int uid;
	int gid;
	struct gunode *next;
};














///user structure

struct unode  
{
	int pnumber;//this show that the user runnig how many process
   int uid;
   struct unode *next;
};

////task_struct
struct node  
{
   int pid;
   int uid;
   int gid;
   struct node *next;
};


int process(struct node *head,struct unode *head1);

#endif
