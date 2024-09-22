#include <stdlib.h>
#include "binary_trees.h"


/**
 * avl_balance_node_insertion - balances an unbalanced node after node
 * insertion
 * @node: Pointer to the node to balance.
 * @value: value inserted into the tree
 *
 * Return: pointer to the balanced node
 */
avl_t *avl_balance_node_insertion(avl_t *node, int value)
{
	int balance;

	balance = binary_tree_balance(node);

	if (balance > 1 && value < node->left->n)
		node = binary_tree_rotate_right(node);
	else if (balance < -1 && value > node->right->n)
		node = binary_tree_rotate_left(node);
	else if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}

/**
 * avl_insert - Inserts a value into an AVL Tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	/* Insert the new node like in a regular BST */
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
			new_node = (*tree)->left = binary_tree_node(*tree, value);
	else
		new_node = avl_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
			new_node = (*tree)->right = binary_tree_node(*tree, value);
		else
			new_node = avl_insert(&(*tree)->right, value);
	}
	else
		return (NULL);

	/* Balance the tree after insertion */
	*tree = avl_balance_node_insertion(*tree, value);

	return (new_node);
}
