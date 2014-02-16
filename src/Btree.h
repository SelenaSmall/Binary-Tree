/* Binary Tree Hashmap */

/* TC: Yours was almost correct. The typedef style is more common and allows you
to drop the 'struct' from the rest of your code. */

typedef struct bt_node	/*define the structure with key, value left & right*/
{
	/* We'll be building a hashmap with the btree, so the key and value are seperate. */
	int key;
	void* value;

	/* You need the 'struct' here because it isn't defined yet (We're in the middle of defining it) */
	struct bt_node* left; 
	struct bt_node* right;
} bt_node;

/* TC: These declare the functions so you can use them. */
bt_node* bc_create_node (int key, void* value);
bt_node* bc_find_node(bt_node* root, int value);	 
void bc_destroy_node (bt_node* node);
void bc_add_node(bt_node* root, bt_node* node);
void bc_print_tree(bt_node* root);