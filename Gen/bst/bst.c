#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
	{/*if(root!=NULL)
		{printf("%d,",root->key);
		}*/
		
	if(root==NULL)
		{return;}
	//printf("Hello\n");
	inOrder(root->left);
	printf("%d,",root->key);
	inOrder(root->right);
	}

struct node *insert(struct node * root,int ele)
	{struct node *temp=newNode(ele);
	
	struct node *tree=root;
	
	struct node *saver;
	
	if(root==NULL)
		{root=temp;
		//printf("%d NULL\n",root->key);
		}
	else
		{//printf("%d",root->key);
		while(tree!=NULL)
			{saver=tree;		//STORES THE PARENT
			if(ele<tree->key)
				{tree=tree->left;
				}
			else
				{tree=tree->right;
				}
		
			}
		if(ele<saver->key)
			{saver->left=temp;
			//printf("%d\n",(saver->left)->key);
			}
		else
			{saver->right=temp;
			//printf("%d\n",(saver->right)->key);
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
	if(temp==NULL)
		{printf("No such element\n");
		}
	else 
		{if(temp->left==NULL && temp->right==NULL)
			{struct node *tree=root;
			struct node *saver;
				while(tree!=NULL)
				{saver=tree;
					if(ele<tree->key)
						{tree=tree->left;
						}
					else if(ele>tree->key)
						{tree=tree->right;
						}
					else 
						break;
				}
			if(saver->left!=NULL)
				saver->left=NULL;
			if(saver->right!=NULL)
				saver->right=NULL;
			free(temp);
			}
		else if(temp->left!=NULL && temp->right!=NULL)
			{struct node *tree=root;
			struct node *tree2=root;
			struct node *saver,*saver2;
				while(tree!=NULL)
				{saver=tree;
					if(ele<tree->key)
						{tree=tree->left;
						}
					else if(ele>tree->key)
						{tree=tree->right;
						}
					else 
						break;
				}
				struct node* newChild=findMax(temp->left);
				int ele2=newChild->key;
				while(tree2!=NULL)
				{saver2=tree2;
					if(ele2<tree2->key)
						{tree2=tree2->left;
						}
					else if(ele2>tree2->key)
						{tree2=tree2->right;
						}
					else 
						break;
				}
				if(saver2->left==newChild)
					saver2->left=NULL;
				else if(saver2->right==newChild)
					saver2->right=NULL;
				if(saver->left==temp)
					saver->left=newChild;
				else if(saver->right==temp)
					saver->right=newChild;
					free(temp);
			
			}
		else if(temp->left!=NULL)
			{struct node *tree=root;
			struct node *saver;
				while(tree!=NULL)
				{saver=tree;
					if(ele<tree->key)
						{tree=tree->left;
						}
					else if(ele>tree->key)
						{tree=tree->right;
						}
					else 
						break;
				}
			struct node *tree2=root,*saver2;
			int ele2=saver->
			while(tree2!=NULL)
				{saver2=tree2;
					if(ele2<tree2->key)
						{tree2=tree2->left;
						}
					else if(ele2>tree2->key)
						{tree2=tree2->right;
						}
					else 
						break;
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
{struct node* root=(struct node*)malloc(sizeof(struct node*));

srand(time(0));
int first=rand()%1000;

root=insert(root,first);
for(int i=0;i<10;i++)
	{insert(root,rand()%1000);
	}

inOrder(root);printf("\n");

struct node *max=(struct node*)malloc(sizeof(struct node*));
max=findMax(root);
printf("Max:%d\n",max->key);

struct node *min=(struct node*)malloc(sizeof(struct node*));
min=findMin(root);
printf("Min:%d\n",min->key);
struct node *find=(struct node*)malloc(sizeof(struct node*));
find=search(root,rand()%1000);
if(find==NULL)
	printf("Not found\n");
else
	printf("Found :%d\n",find->key);
return 0;


}
