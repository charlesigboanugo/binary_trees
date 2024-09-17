#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else if (tree->left != NULL && tree->right != NULL)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
	}
	else
		return (0);

	if (left && right)
		return (1);
	else
		return (0);
}
