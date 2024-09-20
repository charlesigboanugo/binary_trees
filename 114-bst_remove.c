#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_remove_node_with_2_child - Removes a node that has two children from a
 * binary search tree without actually deleting the node (by swapping values)
 * @node: Pointer to the node to remove
 */
void bst_remove_node_with_2_child(bst_t *node)
{
	bst_t *successor = NULL;
	bst_t *parent = NULL;

	successor = node->right;
	parent = node;
	while (successor->left)
	{
		parent = successor;
		successor = successor->left;
	}
	node->n = successor->n;
	if (parent == node)
		parent->right = successor->right;
	else
		parent->left = successor->right;
	if (successor->right)
		successor->right->parent = parent;
	free(successor);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent = NULL, *temp = NULL;

	while (node && node->n != value)
	{
		parent = node;
		node = (value < node->n) ? node->left : node->right;
	}
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
		temp = node->left ? node->left : node->right;
		if (node == root)
			root = temp;
		else if (parent->left == node)
			parent->left = temp;
		else
			parent->right = temp;
		temp->parent = parent;
		free(node);
	}
	else
		bst_remove_node_with_2_child(node);

	return (root);
}
