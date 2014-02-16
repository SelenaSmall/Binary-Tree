#include <stdlib.h> /* TC: malloc() and free() need stdlib */
#include <stdio.h> /* TC: printf() needs stdio */
#include "btree.h"

int main()
{
	bt_node* root = NULL;	/* TC: Although NULL is 0, use NULL for clarity. */
	
	printf("Creating Root Node:\n");

	/* TC: A string literal in C is just a char* pointer. We have to cast it to
	void* because that's what bc_create_node expects. */
	root = bc_create_node(1,(void*)"One");

	/* Good check :) Impressed! */
	if (root == NULL)
	{
		printf("No Memory! \n");
		return -1; /* Returning non-0 tells terminal the program 'failed' */
	}

	/* TC: You can put parameters to functions on different lines for clarity.
	Note all the casts. Yes, we do spend a lot of time casting in C. */
	printf(
		"Root Node has address 0x%010lX and has key %d and value '%s'\n",
		(unsigned long)root,
		root->key,
		(char*)root->value
	);

	printf("Destroying root node.\n");
	bc_destroy_node(root);

	return 0; /* TC: For stuff that runs in the terminal, it's good practice to 
	return 0 from main() if the program 'succeeded' */
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
		return bc_find_node(node->right, value);
	} else {
		return bc_find_node(node->left, value);
	}
}

/* TC: The actual function implementations */
bt_node* bc_create_node (int key, void* value)
{
	/* TC: malloc() allocates a given continuous chunk of memory from the 
	operating system. It returns an address for the new chunk, if there's enough 
	memory. You need to pass that address to free() when you're done with it. */

	/* malloc returns the address, which is of type void*. We need to return a 
	bt_node pointer, so we need to cast it. sizeof is a built-in c function that 
	calculates the byte size of a type. */
	bt_node* node = (bt_node*)malloc(sizeof(bt_node));
	node->key = key;
	node->value = value;
	return node; 
}

void bc_destroy_node (bt_node* node)
{
	/* TC: When you're done with memory you need to give it back to the system. */
	/* If you don't it can cause a memory leak, reducing available memory to both */
	/* your code and the rest of the system. */

	if (node==NULL) return;

	free(node);
}




