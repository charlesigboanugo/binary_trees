#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - Helper function to validate BST properties.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowable value for the node.
 * @max: Maximum allowable value for the node.
 *
 * Return: 1 if the subtree is valid, and 0 otherwise.
 */
int bst_helper(const binary_tree_t *tree, long min, long max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (bst_helper(tree->left, min, tree->n) &&
		bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (bst_helper(tree, LONG_MIN, LONG_MAX));
}
