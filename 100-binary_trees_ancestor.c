#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_is_decendant - counts the leaves in a binary tree
 * @node1: parent node
 * @node2: parent node
 *
 * Return: returns the number of leave nodes
 */
const binary_tree_t *binary_trees_is_decendant(const binary_tree_t *node1,
						const binary_tree_t *node2)
{
	const binary_tree_t *left;
	const binary_tree_t *right;

	if (node1 == NULL)
		return (NULL);
	if (node1 == node2)
		return (node1);
	left = binary_trees_is_decendant(node1->left, node2);
	right = binary_trees_is_decendant(node1->right, node2);
	if (left != NULL || right != NULL)
		return (node1);
	else
		return (NULL);
}

/**
 * binary_trees_ancestor - counts the leaves in a binary tree
 * @first: parent node
 * @second: parent node
 *
 * Return: returns the number of leave nodes
 */
const binary_tree_t *binary_trees_ancestor_recur(const binary_tree_t *first,
						const binary_tree_t *second)
{
	const binary_tree_t *is_decendant;

	if (first == NULL)
		return (NULL);
	is_decendant = binary_trees_is_decendant(first, second);
	if (is_decendant == NULL)
		return (binary_trees_ancestor_recur(first->parent, second));
	return (first);

}

/**
 * binary_trees_ancestor - counts the leaves in a binary tree
 * @first: parent node
 * @second: parent node
 *
 * Return: returns the number of leave nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);
	return ((binary_tree_t *) binary_trees_ancestor_recur(first, second));
}
