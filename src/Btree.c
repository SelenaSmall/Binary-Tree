#include <stdlib.h> /* TC: malloc() and free() need stdlib */
#include <stdio.h> /* TC: printf() needs stdio */
#include "btree.h"

int main()
{
	bt_node* root = NULL;	/* TC: Although NULL is 0, use NULL for clarity. */
	
	char buffer[1024];

	for (int i=0; i<6; i++)
	{
		printf("Type a Number: ");
		
		gets( (char*)&buffer );

		int a = atoi( ( (char*)&buffer ));

		bt_node* node = bc_create_node(a, NULL);

		if (root == NULL)
		{
		 	root = node;
		} else {
			bc_add_node (root,node);
		}
	}	

	bc_print_tree(root);
	printf ("\r\n");

	return 0; 
}

void bc_add_node(bt_node* root, bt_node* node)
{  
    if(node->key > root->key)
    {
        if(root->right == NULL) 
        {	root->right = node; 
        } else { bc_add_node(root->right, node);
   		}
    }
    else  
    {
        if(root->left == NULL) 
        {	root->left = node; 
        } else { bc_add_node(root->left, node);
    	}
    }
}

bt_node* bc_find_node(bt_node* root, int value)
{
	if(root == NULL) return NULL;
	if(root->key == value) return root;
	if(value > root->key)
	{
		return bc_find_node(root->right, value);
	} else {
		return bc_find_node(root->left, value);
	}
}

bt_node* bc_create_node (int key, void* value)
{
	bt_node* node = (bt_node*)malloc(sizeof(bt_node));
	node->key = key;
	node->value = value;
	node->left = NULL;
	node-> right = NULL;
	return node; 
}

void bc_destroy_node (bt_node* node)
{

	if (node==NULL) return;

	free(node);
}

void bc_print_tree(bt_node* root)
{
	if(root == NULL) return;
	bc_print_tree(root->left);

	printf("%d ", root->key);

	bc_print_tree(root->right);
}


