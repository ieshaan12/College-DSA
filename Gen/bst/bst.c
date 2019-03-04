#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
struct node{
	int key;
	struct node *left,*right;
};
struct node* newNode(int ele)
	{struct node *temp=(struct node*)malloc(sizeof(struct node*));
	temp->key=ele;
	temp->left=temp->right=NULL;
	return temp;
	}

void inOrder(struct node* root)
		{
		if(root==NULL)
			{return;}
		inOrder(root->left);
		printf("Key:%d,Pointer:%p\n",root->key,root);
		inOrder(root->right);
		}

struct node *insert(struct node * root,int ele)
	{struct node *temp=newNode(ele);
	
	struct node *tree=root;
	
	struct node *saver;
	
	if(tree==NULL)
		{saver=temp;
		}
	else
		{
		while(tree!=NULL)
			{saver=tree;		
			if(ele<tree->key)
				{tree=tree->left;
				}
			else
				{tree=tree->right;
				}
		
			}
		if(ele<saver->key)
			{saver->left=temp;
			}
		else
			{saver->right=temp;
			}
		}
	
	return saver;
	}
struct node *findMax(struct node* emp)
	{struct node *root=emp;
	if(root==NULL)
		return root;
	else
		while(root->right!=NULL)
			{root=root->right;
			 }
	return root;
	}
struct node *findMin(struct node* emp)
	{struct node *root=emp;
	if(root==NULL)
		return root;
	else
		while(root->left!=NULL)
			{root=root->left;
			 }
	return root;
	}

struct node *search(struct node* root,int ele)
	{struct node *temp=newNode(ele);
	
	struct node *tree=root;
	
	struct node *saver;
	
	if(tree==NULL)
		{return NULL;
		//printf("%d NULL\n",root->key);
		}
	else
		{//printf("%d",root->key);
		while(tree!=NULL)
			{saver=tree;
			if(ele<tree->key)
				{tree=tree->left;
				}
			else if(ele>tree->key)
				{tree=tree->right;
				}
			else 
				return tree;
			}
		}
	return NULL;
	}
struct node * delete(struct node * root, int ele)
	{struct node* tree=root;
	struct node* temp=search(root,ele);
	int f;// f=1 if right, f=0 if left
	if(temp==NULL)
		{printf("No such element\n");
		}
	else 
		{if(temp->left==NULL && temp->right==NULL)
			{printf("0 Child Condition\n");
			struct node *tree=root;
			struct node *saver;
				while(tree!=NULL)
				{
					if(ele<tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->left;
						}
					else if(ele>tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->right;
						}
				}
			if(saver->left==temp)
				saver->left=NULL;
			if(saver->right==temp)
				saver->right=NULL;
			free(temp);
			}
		else if(temp->left!=NULL && temp->right!=NULL)
			{printf("2 Child Condition\n");
			struct node *tree=root;
			struct node *tree2=root;
			struct node *saver,*saver2;
				while(tree!=NULL)
				{
					if(ele<tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->left;
						
						}
					else if(ele>tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->right;
						}
					else 
						break;
				}
				struct node* newChild=findMax(temp->left);
				int ele2=newChild->key;
				tree2=temp;
				while(tree2!=NULL)
				{	
					if(ele2<tree2->key)
						{if(tree2->right!=NULL &&(tree2->right)->key==ele2)
							{
							saver2=tree2;f=1;break;}
						else if(tree2->left!=NULL &&(tree2->left)->key==ele2)
							{saver2=tree2;f=0;break;}
						tree2=tree2->left;
						}
					else if(ele2>tree2->key)
						{if(tree2->right!=NULL &&(tree2->right)->key==ele2)
							{saver2=tree2;f=1;break;}
						else if(tree2->left!=NULL &&(tree2->left)->key==ele2)
							{saver2=tree2;f=0;break;}
						tree2=tree2->right;
						}
				}
				//printf("Saver:%d,Saver2:%d,Ele:%d,Ele2:%d\n",saver->key,saver2->key,ele,ele2);
				if(saver2->left==newChild)
					saver2->left=newChild->left;
				else if(saver2->right==newChild)
					saver2->right=newChild->right;
				if(saver->left==temp)
					saver->left=newChild;
				else if(saver->right==temp)
					saver->right=newChild;
				newChild->right=temp->right;
				newChild->left=temp->left;
				free(temp);

			
			}
		else{	printf("1 Child Condition\n");
			if(temp->left!=NULL)
				{printf("Left Child\n");
				struct node *tree=root;
				struct node *saver;
				while(tree!=NULL)
				{
					if(ele<tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->left;
						}
					else if(ele>tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->right;
						}
					else 
						break;
				}
			if(saver->left==temp)
				saver->left=temp->left;
			if(saver->right==temp)
				saver->right=temp->left;
			free(temp);
			}
			else{	printf("Right Child\n");
				struct node *tree=root;
				struct node *saver;
				while(tree!=NULL)
				{
					if(ele<tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->left;
						}
					else if(ele>tree->key)
						{if(tree->right!=NULL &&(tree->right)->key==ele)
							{saver=tree;f=1;break;}
						else if(tree->left!=NULL &&(tree->left)->key==ele)
							{saver=tree;f=0;break;}
						tree=tree->right;
						}
					else 
						break;
				}
			printf("Parent,%d,To-delete:,%d,Child:%d\n",saver->key,temp->key,(temp->right)->key);
			if(saver->left==temp)
				saver->left=temp->right;
			if(saver->right==temp)
				saver->right=temp->right;
			free(temp);
			}
			
		}
		
		}
	
	}
/* 
struct node *findNext(struct node* root,int ele)
	{
	}
*/
int main()
{struct node* root=NULL;

root=insert(root,7);
insert(root,4);
insert(root,10);
insert(root,3);
insert(root,5);
insert(root,1);
insert(root,2);
insert(root,0);
insert(root,8);
insert(root,14);
insert(root,6);
insert(root,9);
insert(root,16);
insert(root,12);
insert(root,15);
insert(root,17);
inOrder(root);printf("\n");
delete(root,7);
inOrder(root);printf("\n");
//delete(root,10);
/*

srand(time(0));
int first=rand()%100;

root=insert(root,first);
for(int i=0;i<100;i++)
	{insert(root,rand()%100);
	}

inOrder(root);printf("\n");

struct node *max=(struct node*)malloc(sizeof(struct node*));
max=findMax(root);
printf("Max:%d\n",max->key);

struct node *min=(struct node*)malloc(sizeof(struct node*));
min=findMin(root);
printf("Min:%d\n",min->key);
struct node *find=(struct node*)malloc(sizeof(struct node*));
find=search(root,rand()%100);
if(find==NULL)
	printf("Not found\n");
else
	{printf("Found :%d\n",find->key);
	delete(root,find->key);
	}
inOrder(root);printf("\n");
return 0;*/


}
