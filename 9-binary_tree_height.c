#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: height of binary tree or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	ssize_t left = -1;
	ssize_t right = -1;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left != NULL)
		left =  binary_tree_height(tree->left);
	if (tree->right != NULL)
		right = binary_tree_height(tree->right);
	if (left >= right && left != -1)
		return (left + 1);
	else
		return (right + 1);
}
