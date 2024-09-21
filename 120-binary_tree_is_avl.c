#include <stdlib.h>
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

	return (check_avl(tree, &height));
}

/**
 * check_avl - Helper function to check AVL property and height of the tree.
 * @tree: Pointer to the root node of the tree.
 * @height: Pointer to store the height of the tree.
 *
 * Return: 1 if the tree is AVL, 0 otherwise.
 */
int check_avl(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	if (!check_avl(tree->left, &left_height) ||
		!check_avl(tree->right, &right_height))
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;

	if (abs(left_height - right_height) > 1)
		return (0);

	if (tree->left && tree->left->n >= tree->n)
		return (0);
	if (tree->right && tree->right->n <= tree->n)
		return (0);

	return (1);
}
