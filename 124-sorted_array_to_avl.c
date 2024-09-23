#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl_recur - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @parent: pointer to the parent node
 * @i: index of first element of array
 * @j: index of last element of array
 *
 * Return: root of the created AVL tree
 */
avl_t *sorted_array_to_avl_recur(int *array, avl_t *parent, size_t i, size_t j)
{
	avl_t *node;
	size_t index;

	index = (i + j) / 2;

	node = binary_tree_node(parent, array[index]);

	/* An error occured within binary_tree_node */
	if (!node)
		exit (EXIT_FAILURE);

	node->left = sorted_array_to_avl_recur(array, node, i, index - 1);
	node->right = sorted_array_to_avl_recur(array, node, index + 1, j);

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: root of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || size == 0)
		return (NULL);

	root = sorted_array_to_avl_recur(array, NULL, 0, size - 1);

	return (root);
}
