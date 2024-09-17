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
		return (0);

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

/**
 * dept_deepest_leaf - counts the leaves in a binary tree
 * @tree: parent node
 * @dept: dept of tree
 *
 * Return: returns the number of leave nodes
 */
ssize_t dept_deepest_leaf(const binary_tree_t *tree, ssize_t dept)
{
	ssize_t left_d;
	ssize_t right_d;

	if (tree == NULL)
		return (dept);
	dept++;
	left_d = dept_deepest_leaf(tree->left, dept);
	right_d = dept_deepest_leaf(tree->right, dept);
	if (left_d > right_d)
		return (left_d);
	else
		return (right_d);
}

/**
 * binary_tree_balance - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t dept_deepest_l;
	size_t dept_deepest_r;

	if (tree == NULL)
		return (0);
	dept_deepest_l = dept_deepest_leaf(tree->left, -1) + 1;
	dept_deepest_r = dept_deepest_leaf(tree->right, -1) + 1;

	return (dept_deepest_l - dept_deepest_r);
}

/**
 * binary_tree_is_perfect - counts the leaves in a binary tree
 * @tree: parent node
 *
 * Return: returns the number of leave nodes
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int balance_factor;
	int full;

	if (!tree)
		return (0);

	balance_factor = binary_tree_balance(tree);
	full = binary_tree_is_full(tree);
	if (balance_factor == 0 && full == 1)
		return (1);
	else
		return (0);
}
