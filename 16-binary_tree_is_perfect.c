#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_height_recur - counts the leaves in a binary tree
 * @tree: parent node
 * @height: parent node
 *
 * Return: returns the number of leave nodes
 */
size_t binary_tree_height_recur(const binary_tree_t *tree, size_t height)
{
	size_t left;
	size_t right;

	if (tree == NULL)
		return (height);
	height++;
	left = binary_tree_height_recur(tree->left, height);
	right = binary_tree_height_recur(tree->right, height);
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * binary_tree_height - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height_recur(tree, 0) - 1);
}


/**
 * powerof - return
 * @base: h
 * @exp: h
 *
 * Return: returns the number of leave nodes
 */
size_t powerof(size_t base, size_t exp)
{
	size_t result = 1;

	while (exp > 0)
	{
		result *= base;
		exp--;
	}

	return (result);
}

/**
 * binary_tree_is_perfect - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height;
	size_t no_of_leaves;

	if (!tree)
		return (0);

	tree_height = binary_tree_height(tree);
	no_of_leaves = binary_tree_leaves(tree);

	if (powerof(2, tree_height) == no_of_leaves)
		return (1);
	else
		return (0);
}
