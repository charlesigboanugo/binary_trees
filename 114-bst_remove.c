#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent, *successor = NULL, *temp = NULL;

	for (parent = NULL; node && node->n != value; parent = node)
		node = (value < node->n) ? node->left : node->right;
	if (!node)
		return (root);
	if (!node->left && !node->right)
	{
		if (node == root)
			root = NULL;
		else if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(node);
	}
	else if (!node->left || !node->right)
	{
		if (node->left)
			temp = node->left;
		else
			temp = node->right;
		if (node == root)
			root = temp;
		else if (parent->left == node)
			parent->left = temp;
		else
			parent->right = temp;
		free(node);
	}
	else
	{
		successor = node->right;
		while (successor->left)
			successor = successor->left;
		node->n = successor->n;
		node->right = bst_remove(node->right, successor->n);
	}
	return (root);
}

