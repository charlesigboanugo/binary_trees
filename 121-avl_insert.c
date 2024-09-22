#include <stdlib.h>
#include "binary_trees.h"

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
	int balance;

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
	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (new_node);
}
