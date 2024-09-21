#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

int check_avl(const binary_tree_t *tree, int *height);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (check_avl(tree, &height, INT_MIN, INT_MAX));
}

/**
 * check_avl - Helper function to check AVL property and height of the tree.
 * @tree: Pointer to the root node of the tree.
 * @height: Pointer to store the height of the tree.
 * @low: non inclusive lower bound for value of a node.
 * @high: non inclusive upper bound for value of a node.
 *
 * Return: 1 if the tree is AVL, 0 otherwise.
 */
int check_avl(const binary_tree_t *tree, int *height, int low, int high)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	if (!check_avl(tree->left, &left_height, low, tree->n) ||
		!check_avl(tree->right, &right_height, tree->n, high))
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;

	if (abs(left_height - right_height) > 1)
		return (0);

	if (tree->n <= low || tree->n >= high)
		return (0);

	return (1);
}
