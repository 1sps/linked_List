/* 
# This file has C code of answers for problems 1-18 found in http://cslibrary.stanford.edu/105/LinkedListProblems.pdf 
# Written by: SPS
# Last modified: 19-Apr-2015
*/

/* Including the required header files */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Defining the structure of a node in the linked-list */
struct node
{
	int data;
	struct node *next;
};
typedef struct node * List;

/*Function prototype declarations*/
struct node *BuildOneTwoThree();
int Length(struct node *);
int Count(struct node *, int );
void CountTest();
int GetNth(struct node *, int );
void GetNthTest();
void DeleteList(struct node **);
void DeleteListTest();
int Pop(struct node **);
void PopTest();
void InsertNthTest();
void InsertNth(struct node **, int, int);
void SortedInsert_Test();
void SortedInsert(struct node **, struct node *);
void InsertSort_Test();
void InsertSort(struct node **);
void AppendTest();
void Append(struct node ** , struct node ** );
void FrontBackSplit_Test();
void FrontBackSplit(struct node *, struct node **, struct node **);
void RemoveDuplicatesTest();
void RemoveDuplicates(struct node *);
void MoveNodeTest();
void MoveNode(struct node **, struct node **);
void AlternatingSplit_Test();
void AlternatingSplit(struct node *, struct node **, struct node **);
void ShuffleMergeTest();
struct node *ShuffleMerge(struct node *, struct node *);
void MoveToLast(struct node **, struct node **);
void SortedMergeTest();
struct node *SortedMerge(struct node *, struct  node *);
struct node *SortedMerge_1(struct node *, struct  node *);
void MergeSortTest();
void MergeSort(struct node **);
void MergeSort_1(struct node **);
void SortedIntersectTest();
struct node *SortedIntersect(struct node *, struct node *);
void ReverseTest();
void Reverse(struct node **);
void RecursiveReverseTest();
void RecursiveReverse(struct node **);


/*-----------------------*/
/*---------main()--------*/
/*-----------------------*/
int main()
{
	printf("\n");
	CountTest();
	GetNthTest();
	DeleteListTest();
	PopTest();
	InsertNthTest();
	SortedInsert_Test();
	InsertSort_Test();
	AppendTest();	
	FrontBackSplit_Test();
	RemoveDuplicatesTest();
	MoveNodeTest();	
	AlternatingSplit_Test();
	ShuffleMergeTest();	
	SortedMergeTest();
	MergeSortTest();
	SortedIntersectTest();
	ReverseTest();
	RecursiveReverseTest();

	printf("\nA good learning, and many thanks to one who made the questions available !!\n\n");
	return 0;
}

/*-----------------Length(struct node *)-----------------*/

/*
   Given a linked list head pointer, 
   compute and return the number of nodes in the list
*/
int Length (struct node *head)
{
	struct node *current = head;
	int count = 0;	
	
	while ( current != NULL )
	{
		count++;
		current = current->next;
	}	
	return (count);

}


/*-----------------BuildOneTwoThree()-----------------*/
/*
Build the list {1,2,3} in the heap and store its head pointer in a local stack variable. 
Return the head pointer to the caller.
*/
struct node *BuildOneTwoThree()
{
	struct node *head = NULL;
	struct node *first = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	/*Allocate three nodes in heap.*/
	first = malloc(sizeof(struct node));
	if (first == NULL)
		exit (1);
	second = malloc(sizeof(struct node));
	if (second == NULL)
		exit (2);
	third = malloc(sizeof(struct node));
	if (third == NULL)
		exit (3);

	/*set up first node*/	
	first->data = 1 ; 
	first->next = second;
	/*set up second node*/	
	second->data = 2 ; 
	second->next = third;
	/*set up third node*/
	third->data = 3 ; 
	third->next = NULL;
	/*make head point to first node*/
	head = first ;
	
	/*At this point, the linked list will be referenced by "head"*/
	/*return head to caller*/
	return (head);
}

/*-----------------CountTest()-----------------*/

/* Tests the Count() function*/
void CountTest()
{
	List myList = BuildOneTwoThree(); // build {1,2,3}
		
	int count = Count(myList, 2); // returns 1 since there's 1 '2' in the list
	if (count == 1)
		printf("1-- CountTest() passed !\n");
	else
		printf("1-- CountTest() failed !\n");
	//printf("Total count: %d\n",count);	
}

/*-----------------Count(struct node*, int)-----------------*/
/*
 Given a list and an int, return the number of times that int occurs
 in the list.
*/
int Count(struct node *head, int searchFor)
{
	int count = 0;
	if (head == NULL)
		return (count);
	while( head != NULL )
	{
		if (head->data == searchFor)
			count++;
		head = head->next;
	}	
	
	return (count);
}

/*-----------------GetNthTest()-----------------*/

/* Tests the GetNth() function*/
void GetNthTest()
{
	List myList = BuildOneTwoThree();
	int key = GetNth(myList, 2); // returns the value 3
	if (key == 3)
		printf("2-- GetNthTest() passed !\n");
	else
		printf("2-- GetNthTest() failed !\n");
	//printf("Element in index 2: %d\n",key); 
}

/*-----------------GetNth(struct node*, int)-----------------*/
/* 
   Given the linked list head pointer and index
   Return the data present in that index
*/
int GetNth(struct node *head, int index)
{
	struct node *node_Pointer = head;
	int i;
	for(i=0;i<index;i++)
	{
		node_Pointer = node_Pointer->next;
	}
	return (node_Pointer->data);
}

/*-----------------DeleteListTest()-----------------*/

/* Tests the DeleteList() function*/
void DeleteListTest()
{
	struct node *myList = BuildOneTwoThree();
	DeleteList(&myList);
	if(myList == NULL)
		printf("3-- DeleteListTest() passed !\n");
	else
		printf("3-- DeleteListTest() failed !\n");
}


/*-----------------DeleteList(struct node**, int)-----------------*/
/* 
   Given the linked list head pointer,
   1. deallocates all of the memory used by linked list,
   2. Sets its head pointer to NULL
*/
void DeleteList(struct node **headRef)
{
	struct node *head, *head1;
	head = *headRef;	
	while (head != NULL)	
	{
		head1 = head;
		head = head->next;
		free(head1);
	}
	*headRef = NULL;
	//printf("-- list deleted\n");
}


/*----------------PopTest()-----------------*/

/* Tests the Pop() function*/
void PopTest()
{
	struct node *head = BuildOneTwoThree();
	int a = Pop(&head); // deletes "1" node and returns 1
	int b = Pop(&head); // deletes "2" node and returns 2
	int c = Pop(&head); // deletes "3" node and returns 3
	int len = 100;
	len = Length(head);
	if ((len == 0) && (a==1) && (b==2) && (c==3))
		printf("4-- PopTest() passed ! \n");
	else
		printf("4-- PopTest() failed !\n");	
}

/*-----------------Pop(struct node**)-----------------*/
/* 
   The opposite of Push(). Takes a non-empty list
   and removes the front node, and returns the data
   which was in that node.
*/
int Pop(struct node **headRef)
{
	struct node *current, *to_Delete;
	current = *headRef;
	assert(current != NULL);
	
	int head_Data;		
	head_Data = current->data;
	to_Delete = current;
	current = current->next;
	*headRef = current;
	free(to_Delete);
	return (head_Data);
}

/*----------------InsertNthTest()-----------------*/

/* Tests the InsertNth() function*/

void InsertNthTest() 
{
struct node* head = NULL;
InsertNth(&head, 0, 13);
InsertNth(&head, 1, 42);
InsertNth(&head, 1, 5);
struct node *current;
current = head;
/*
while(current != NULL)
{
	printf("%d ",current->data);
	current = current->next;
}
printf("\n");
*/
DeleteList(&head);
printf("5-- InertNthTest() passed ??\n");
}

/*-----------------Pop(struct node**, int, int)-----------------*/
/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
*/
void InsertNth(struct node** headRef, int index, int data)
{
	struct node *current, *previous;
	struct node *new_Node;
	current = *headRef;
	previous = NULL;
	int i = 0;
	while(i < index)
	{
		previous = current;		
		current = current->next;
		i++;
	}
	if (previous == NULL)
	{
		new_Node = malloc(sizeof(struct node));
		new_Node->data = data;
		new_Node->next = *headRef;
		*headRef = new_Node;
	}
	else
	{
		new_Node = malloc(sizeof(struct node));
		new_Node->data = data;
		new_Node->next = current;
		previous->next = new_Node;
	}
	
}


/*----------------SortedInsert_Test()-----------------*/

/* Tests the SortedInsert() function*/

void SortedInsert_Test() 
{
	struct node *head = NULL;
	struct node *newNode;
	struct node *another_List_Pointer;
	int i;
	for(i=0;i<5;i++)
	{
		newNode = malloc(sizeof(struct node));
		newNode->data = 4 - i;
		newNode->next = head;
		head = newNode;		
	}
	another_List_Pointer = head;
	/*
	while (another_List_Pointer != NULL)
	{
		printf("%d ",another_List_Pointer->data);
		another_List_Pointer = another_List_Pointer->next;
	}
	printf("\n");
	*/
	newNode = malloc(sizeof(struct node));
	newNode->data = 5;
	newNode->next = NULL;
	SortedInsert(&head, newNode);
	another_List_Pointer = head;
	/*
	while (another_List_Pointer != NULL)
	{
		printf("%d ",another_List_Pointer->data);
		another_List_Pointer = another_List_Pointer->next;
	}
	*/
	printf("6-- SortedInsert_Test() completed !\n");
}

/*-----------------SortedInsert(struct node**, struct node *)-----------------*/
/*
Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.
*/
void SortedInsert(struct node  **headRef, struct node *newNode)
{
	struct node *current;
	struct node *previous;
	current = *headRef;
	int i = 0;

	if(*headRef == NULL)
	{
		*headRef = newNode;
	}
	else
	{
		while ( current != NULL)
		{
			if(newNode->data <= current->data)
			{
		
				//printf("asidjasdasd\n");
				//InsertNth(headRef, i, data);
				newNode->next = current;
				if(i>0)
					previous->next = newNode;
				else
					*headRef = newNode;
					
				break;
			}
			previous = current;
			current = current->next;	
			i++;
		
		}
		//printf("Here\n");
		i = 0;
		if (current == NULL)
		{
			//printf("nHere\n");
			current = *headRef;
			while(current != NULL)
			{
				
				//printf("%d\nUP\n",current->data);
				//if(i != 0)
				 previous = current;
				i++;
				current = current->next;
			}
		
			previous->next = newNode;
		}
	}	
}

/*----------------InsertSort_Test()-----------------*/

/* Tests the InsertSort() function*/

void InsertSort_Test()
{
	struct node *head = NULL;
	head = malloc(sizeof(struct node));
	head->data = 2;
	head->next = NULL;
	struct node *current = head;
	int i;
	for(i = 0; i<10; i++)
	{
		current->next = malloc(sizeof(struct node));
		current = current->next;
		
		if(i%2 == 0)
			current->data = -1;
		else
			current->data = 2;
			
			
	}
	//head->next->data = 4;
	//head->next->next = NULL;
	InsertSort(&head);
	current = head;
	/*
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	*/
	printf("7-- InserSort_Test() completed !\n");
}

/*-----------------InsertSort(struct node**)-----------------*/
/*
Given a list, change it to be in sorted order (using SortedInsert()).
*/
void InsertSort(struct node **headRef)
{
	struct node *newNode;
	struct node *current = *headRef;
	/*We will make a new list which will be sorted*/
	struct node *sorted_List = NULL;
	
	/* Make one pass through the list*/
	/* At every pass, copy the node's data to newNode and Insert the newNode to sorted_List*/
	/* sorted_List is trivially sorted when it is empty*/
	/* So every SortedInsert to sorted_List will result in a sorted list*/	
	while (current != NULL)
	{
		/**/		
		newNode = malloc(sizeof(struct node));
		newNode->data = current->data;
		newNode->next = NULL;
		SortedInsert(&(sorted_List), newNode);		
		current = current->next;
	}
	
	/*By now the original unsorted list is copied into sorted_list in sorted order*/	
	/*Next, below code frees the memory used by original list*/
	struct node *cleanup_Pointer;
	struct node *cleanup_Pointer1;
	cleanup_Pointer = *headRef;
	while(cleanup_Pointer != NULL)
	{
		cleanup_Pointer1 = cleanup_Pointer;
		cleanup_Pointer = cleanup_Pointer->next;
		free(cleanup_Pointer1);
	}
	
	/*make the head of caller point to first node of sorted_List*/	
	*headRef = sorted_List;
	
}

/*----------------AppendTest()-----------------*/

/* Tests the Append() function*/

void AppendTest()
{
	struct node *list_A = BuildOneTwoThree();
	struct node *list_B = BuildOneTwoThree();

	Append(&list_A, &list_B);
	
	struct node *current = list_A;
	/*
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	*/
	printf("8-- AppendTest() completed !\n");
}

/*-----------------Append(struct node**, struct node **)-----------------*/
/*
 Append 'b' onto the end of 'a', and then set 'b' to NULL.
*/

void Append(struct node **a_Ref, struct node **b_Ref)
{
	struct node *a_ptr = *a_Ref;
	struct node *a_ptr_hold;
	struct node *b_ptr = *b_Ref;
	
	if(*a_Ref == NULL)
		*a_Ref = *b_Ref;
	else
	{
		/* Below part is commented*/
		/* Please see the alternative approach below it.*/
		/*while(a_ptr != NULL)
		{
			a_ptr_hold = a_ptr;
			a_ptr = a_ptr->next;
		}	
		a_ptr_hold->next = *b_Ref;*/

		/*Alternative approach here*/
		while(a_ptr->next != NULL)
		{
			a_ptr = a_ptr->next;
		}
		a_ptr->next = *b_Ref;
	}
	*b_Ref = NULL;
}

/*----------------FrontBackSplit_Test()-----------------*/

/* Tests the FrontBackSplit() function*/

void FrontBackSplit_Test()
{
	int i;	
	struct node *head = BuildOneTwoThree();
	struct node *front_List = NULL;
	struct node *back_List = NULL;
	struct node *current = NULL;
	/*For test with length == 4*/
	/*
	current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = malloc(sizeof(struct node));
	current->next->data = 13;
	current->next->next = NULL;i
	*/	
	current = head;	

	/*For test for length == 2*/
	//current->next->next = NULL;

	/*For test for length == 1*/
	//current->next = NULL;

	FrontBackSplit(head, &front_List, &back_List);

	/*
	printf("Front list:\n");
	current = head;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");

	printf("Back list:\n");
	current = back_List;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
	*/

	printf("9-- FrontBackSplit_Test() completed !\n");
}

/*-----------------FrontBackSplit(struct node **, struct node **)-----------------*/
/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
void FrontBackSplit(struct node *head, struct node **frontRef, struct node **backRef)
{
	int i, odd;
	int front_count, back_count;
	struct node *current, *current1;
	current = head;
	i = 0;
	while(current != NULL)
	{
		i++;
		current = current->next;
	}	
	
	if(i==0)
	{
		*frontRef = NULL;
		*backRef = NULL;
	}
	else
	{
		if( i == 1)
		{
			*frontRef = head;
			*backRef = NULL;
		}
		else if(i == 2)
		{
			/*current = *headRef;*/
			//current = current->next;
			/*current1 = current->next;
			current->next = NULL;
			*backRef = current1;*/

			//need to make *frontRef = head
			current = head;
			current1 = current->next;
			current->next = NULL;
			*frontRef = current;
			*backRef = current1; 
		}
		else
		{
			odd = i%2;
			front_count = i / 2;
			if (odd)
				front_count++;
			current = head;
			for(i=1; i<front_count; i++)
			{
				current = current->next;
			}
			current1 = current->next;
			current->next = NULL;
			*frontRef = head;
			*backRef = current1;			
		}
	}
}

/*----------------RemoveDuplicatesTest()-----------------*/

/* Tests the RemoveDuplicates() function*/

void RemoveDuplicatesTest()
{
	struct node *head = BuildOneTwoThree();
	head->next->next->next = BuildOneTwoThree();
	InsertSort(&head);
	struct node *current;
	current = head;
	/*
	printf("---RemoveDupliactesTest-----\n");
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
	*/
	RemoveDuplicates(head);
	/*
	current = head;
	printf("After removing duplicate nodes---\n");
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	*/
	printf("10-- RemoveDuplicatesTest() completed !\n");
}

/*-----------------RemoveDuplicates(struct node *)-----------------*/

/*
Remove duplicates from a sorted list.
*/
void RemoveDuplicates(struct node *head)
{
	struct node *current, *current1, *previous;
	current = head;
	int hold = NULL;
	/*If list is empty*/
	if (head == NULL)
		return;
	/*Else if non-empty list*/
	else
	{
		while(current != NULL)
		{
			if (current->data == hold)
			{
				current1 = current;
				current = current->next;
				previous->next = current1->next;
				free(current1);
			}
			else
			{
				hold = current->data;
				previous = current;
				current = current->next;
			}
		}
	}
}

void MoveNodeTest() 
{
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	// the list {1, 2, 3}
	MoveNode(&a, &b);
	// a == {1, 1, 2, 3}
	// b == {2, 3}
	struct node *current;
	current = a;
	/*
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	*/
	printf("11-- MoveNodeTest() completed !\n");
}

/*
Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.
*/
void MoveNode(struct node **destRef, struct node **sourceRef)
{
	// Your code
	struct node *newNode = *sourceRef;
	assert(newNode != NULL);
	
	*sourceRef = newNode->next;
	
	newNode->next = *destRef;
	*destRef = newNode;
}

void AlternatingSplit_Test()
{
	struct node *head = BuildOneTwoThree();
	head->next->next->next = BuildOneTwoThree();
	struct node *current = head;
	struct node *aRef = NULL;
	struct node *bRef = NULL;

	//head->next->next->next = NULL;
	AlternatingSplit(head, &aRef, &bRef);
	printf("12-- AlternatingSplitTest() comleted !\n");
}

void AlternatingSplit(struct node *head, struct node **aRef, struct node **bRef)
{
	int i = 0;
	struct node *current = head;
	struct node *previous_odd, *previous_even;
	struct node *last_odd, *last_even;
	last_odd = NULL;
	last_even = NULL;
	previous_odd = NULL;
	previous_even = NULL;
	if (current == NULL)
		return ;
	while(current != NULL)
	{
		i++;
		if( i%2 == 1)
		{
			if ( i == 1)
			{
				*aRef = current;
				previous_odd = current;
				if ((current->next != NULL) && (current->next->next == NULL))
				{
					//*aRef->next = NULL; This cannot be done ! extra for future.
					last_odd = current;
					current = current->next;
					last_odd->next = NULL;
					continue;
				}
			}
			else
			{
				previous_odd->next = current;
				previous_odd = current;
				if ((current->next != NULL) && (current->next->next == NULL))
				{
					last_odd = current;
					current = current->next;
					last_odd->next = NULL;
					continue;
				}
			}
		}
		else
		{
			if ( i == 2)
			{
				*bRef = current;
				previous_even = current;
				if ((current->next != NULL) && (current->next->next == NULL))
				{
					//*bRef->next = NULL; This cannot be done ! extra for future.
					last_even = current;
					current = current->next;
					last_even->next = NULL;
					continue;
				}
			}
			else
			{
				previous_even->next = current;
				previous_even = current;
				if ((current->next != NULL) && (current->next->next == NULL))
				{
					last_even = current;
					current = current->next;
					last_even->next = NULL;
					continue;
				}
			}
		}
		current = current->next;
	}
}

void ShuffleMergeTest()
{
	struct node *head1 = BuildOneTwoThree();
	struct node *head2 = malloc(sizeof(struct node));
	struct node *result = NULL;
	head2->data = 4;
	head2->next = malloc(sizeof(struct node));
	head2->next->data = 5,
	head2->next->next = NULL;
	head2->next->next = malloc(sizeof(struct node));
	head2->next->next->data = 6;
	head2->next->next->next = NULL,
	result = ShuffleMerge(head1, head2);
	struct node *current = result;
	//while(current != NULL)
	//{
	//	printf("%d ",current->data);
	//	current = current->next;
	//}
	printf("13-- ShuffleMergeTest() completed !\n");
}

//struct ex
//{
//	int age;
//	int height;
//}

/*
struct ex sample;

sample.age = 25;
sample.height = 6;

struct ex *head;
head = &sample;
head->age = 26;
*/

/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/

struct node *ShuffleMerge(struct node *a, struct node *b )
{
	/* create a new lsit 'result'*/
	/* This will be returned at the end*/
	struct node *result = NULL;
	
	struct node *current_a_head = a;
	struct node *current_b_head = b;
	
	while(1)
	{
		if(current_a_head != NULL)
			MoveToLast(&result, &current_a_head);
		if(current_b_head != NULL)
			MoveToLast(&result, &current_b_head);
		if((current_a_head == NULL) && (current_b_head == NULL))
			break;
	}
	return (result);
}

void MoveToLast(struct node **resultRef, struct node **source)
{
	if(*source == NULL)
		return ;
	struct node *source1;
	source1 = *source;
	
	*source = source1->next;
	source1->next = NULL;

	struct node *current1;
	current1 = *resultRef;
	if(current1 == NULL)
	{
		source1->next = *resultRef;
		*resultRef = source1;
		
	}
	else
	{
		while(current1->next != NULL)
		{
			current1 = current1->next;
		}
		current1->next = source1;
	}
}

void SortedMergeTest()
{
	struct node *a = BuildOneTwoThree();
	struct node *b = BuildOneTwoThree();

	b->data = 4;
	b->next->data = 5;
	b->next->next->data = 6;
	b->next->next->next =  malloc(sizeof(struct node));
	b->next->next->next->data =  7;
	b->next->next->next->next = NULL;
	

	struct node *merged = SortedMerge(a, b);

	struct node *current = merged;
	
	if(current == NULL)
		printf("am NULL\n");

	//while(current != NULL)
	//{
	//	printf("%d ",current->data);
	//	current = current->next;
	//}
	printf("14-- SortedMergeTest() completed !\n");
}

struct node *SortedMerge(struct node *a, struct node *b)
{
	struct node *current_a = a;
	struct node *current_b = b;
	struct node *c = NULL;
	struct node **cRef = &c;

	int flag_a, flag_b;
	flag_a = 0;
	flag_b = 0;
	
	if(a == NULL)
	{
		c = b;
		flag_a = 1;
	}
	if(b == NULL)
	{
		c = a;
		flag_b = 1;
	}
	
	//If none of the list were empty
	if((flag_a == 0) && (flag_b == 0))
	{
		//While at least one node remaining in both lists
		while((a != NULL) && (b != NULL))
		{
			if(current_a->data < current_b->data)
			{
				MoveNode(cRef, &a);
				cRef = &((*cRef)->next);
			}
			else
			{
				MoveNode(cRef, &b);
				cRef = &((*cRef)->next);
			}
		}
		if(a == NULL)
			*cRef = b;
		if(b == NULL)
			*cRef = a;
	}
	return (c);
}

void MergeSortTest()
{
	//Create a list, and pass its head's address to MergeSort()
	struct node *head = BuildOneTwoThree();
	head->next->next->next = BuildOneTwoThree();
	head->next->next->next->data = 2;
	head->next->next->next->next->data = 1;
	head->next->next->next->next->next->data = -3;

	MergeSort_1(&head);
	struct node *current = head;
	/*while (current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");*/
	printf("15-- MergeSortTest() completed !\n");
}

void MergeSort(struct node **headRef)
{
	if((*headRef)->next == NULL)	
	{
		//Base case, only one node pointing to null
		return;
	}
	else
	{
		//struct node *left_half = *headRef;
		struct node *sublist_1 = NULL;
		//struct node *right_half = NULL;	
		struct node *sublist_2 = NULL;

		FrontBackSplit( *headRef, &sublist_1, &sublist_2);
		
		MergeSort(&sublist_1);
		MergeSort(&sublist_2);

		*headRef = SortedMerge(sublist_1, sublist_2);
	}
}


void MergeSort_1(struct node **headRef)
{
	if ((*headRef)->next == NULL)
		return;

	else
	{
		struct node *sublist_1 = NULL;
		struct node *sublist_2 = NULL;
		
		FrontBackSplit(*headRef, &sublist_1, &sublist_2);

		MergeSort_1(&sublist_1);
		MergeSort_1(&sublist_2);

		*headRef = SortedMerge_1(sublist_1, sublist_2);
	}
}

struct node *SortedMerge_1(struct node *sublist_1, struct node *sublist_2)
{
	struct node *result_head = NULL;
	
	struct node *result_current = NULL;

	int first_flag = 0;	
	
	if (sublist_1 == NULL)
	{
		result_head = sublist_2;
		return (result_head);
	}
	else if (sublist_2 == NULL)
	{
		result_head = sublist_1;
		return (result_head);		
	}
	

	while((sublist_1 != NULL) && (sublist_2 != NULL))
	{
		if (first_flag == 0)
		{
			if(sublist_1->data < sublist_2->data)
			{
				result_head = sublist_1;
				sublist_1 = sublist_1->next;
				result_head->next = NULL;
				result_current = result_head;
			}
			else
			{
				result_head = sublist_2;
				sublist_2 = sublist_2->next;
				result_head->next = NULL;
				result_current = result_head;
		
			}
		}
		else
		{
			if(sublist_1->data < sublist_2->data)
			{
				result_current->next = sublist_1;
				sublist_1 = sublist_1->next;
				result_current = result_current->next;
				result_current->next = NULL;
			}
			else
			{
				result_current->next = sublist_2;
				sublist_2 = sublist_2->next;
				result_current = result_current->next;
				result_current->next = NULL;			
			}
		}
		first_flag++;
	}
	if (sublist_1 == NULL)
	{
		result_current->next = sublist_2;
	}
	if (sublist_2 == NULL)
	{
		result_current->next = sublist_1;
	}
	return (result_head);
}


/* SortedIntersectTest()*/



void SortedIntersectTest()
{
	//Create a list, and pass its head's address to MergeSort()
	struct node *head1 = BuildOneTwoThree();
	//head->next->next->next = BuildOneTwoThree();
	//head->next->next->next->data = 2;
	//head->next->next->next->next->data = 1;
	//head->next->next->next->next->next->data = -3;
	struct node *head2 = BuildOneTwoThree();
	head2->data = -1;
	head2->next->data = 0; 
	head2->next->next->data = 2; 
	head2->next->next->next = malloc(sizeof(struct node));
	head2->next->next->next->data = 5;
	head2->next->next->next->next = NULL;

 
	
	struct node *intersect = SortedIntersect(head1, head2);

	struct node *current = intersect;
	if(current != NULL)
	{
		/*while(current != NULL)
		{
			printf("%d ",current->data);
			current = current->next;
		}
		printf("\n");*/
	}	
	else
		printf("No common element.\n");
	printf("16-- SortedIntersectTest() completed !\n");
}


/*
Compute a new sorted list that represents the intersection
of the two given sorted lists.
*/
struct node *SortedIntersect(struct node *a, struct node *b)
{
	struct node *result = NULL;
	struct node *result_current = result;
	struct node *current_a = a;
	struct node *current_b = b;

	struct node *newNode = NULL;

	int last_hold;

	int big_flag_a, big_flag_b, equal_flag;
	big_flag_a = 0;
	big_flag_b = 0;
	equal_flag = 0;

	int flag_first_common = 0;
	int flag_common = NULL;
	int common_value;
	

	while((current_a != NULL) && (current_b != NULL))
	{
		//You can do like this
		//Start a,b
		//compare a and b
		//if equal, copy node to result, go to next a untill a becomes bigger
		//else if a is bigger, set big_flag_a and see next node of b
		//else if b is bigger, set big_flag_b and see next node of a

		// if both equal, copy the node to new list, then go to next node till it increments
		//else, if a is small, see next element of a
		//go to next elements of a untill either a is equal or bigger than b
		//if a is equal to b , go to next a untill a increments
		//once a is bigger, start same thing with b
		//else, if b is small, see next element of b
		//go to next elements of b untill either b is equal or bigger than a
		//if b is equal to a , go to next a untill b increments
		//once b is bigger, start same thing with a

		if(current_a->data == current_b->data)
		{
			flag_first_common++;
			//flag_common = 1;
			//if(flag_common == 1)
			{
				if(common_value == current_a->data)
				{
					current_a = current_a->next;
					current_b = current_b->next;
					continue;
				}
			}
			//if(flag_fist_common)
			common_value = current_a->data;

			newNode = malloc(sizeof(struct node));
			newNode->data = current_a->data;
			newNode->next = NULL;

			if(flag_first_common == 1)
			{
				result = newNode;
				result_current = result;
			}
			else
			{
				result_current->next = newNode;
				result_current = result_current->next;
			}
			current_a = current_a->next;
			current_b = current_b->next;


		}
		else if (current_a->data > current_b->data)
		{
			current_b = current_b->next;
		}
		else if(current_b->data > current_a->data)
		{
			current_a = current_a->next;
		}

		//if((current_a == NULL) || (current_b == NULL))
		//	break;
		
	}
			

	//while ();
	return (result);
}

void ReverseTest()
{
	struct node *head = BuildOneTwoThree();

	Reverse(&head);

	struct node *current = head;
	/*while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");*/
	printf("17-- ReverseTest() completed !\n");
}

void Reverse(struct node **headRef)
{
	if(*headRef == NULL)
		return;
	
	struct node *new_Head = NULL;
	//struct node *new_list_current = NULL;
	
	struct node *current = *headRef;
	struct node *current1 = NULL;

	int i = 0;

	while(current != NULL)
	{
		i++;
		current1 = current->next;
		current->next = NULL;
		if(i == 1)
		{
			*headRef = current;
			//new_list_current = *headRef;
		}
		else
		{
			current->next = *headRef;
			*headRef = current;
		}
		current = current1;
	}

}

void RecursiveReverseTest()
{
	struct node *head = BuildOneTwoThree();
	head->next->next->next = malloc(sizeof(struct node));
	head->next->next->next->data = -76;
	head->next->next->next->next = NULL;
	
	//head = NULL;

	RecursiveReverse(&head);

	struct node *current = head;
/*	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
*/
	printf("18-- RecursiveReverseTest() completed !\n");
	
}

void RecursiveReverse(struct node **headRef)
{
	if(*headRef == NULL)
		return;

	if(((*headRef)->next) == NULL)
		return;
	struct node *current, *special;
	current = *headRef;
	current = current->next;
	special = current;
	RecursiveReverse(&current);

	special->next = *headRef;
	(*headRef)->next = NULL;

	*headRef = current;
}
