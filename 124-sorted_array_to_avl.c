#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_arr_to_avl_recur - builds an AVL tree from a sorted array
 * @arr: pointer to the first element of the array
 * @parent: pointer to the parent node
 * @i: index of first element of array
 * @j: index of last element of array
 *
 * Return: root of the created AVL tree
 */
avl_t *sorted_arr_to_avl_recur(int *arr, avl_t *parent, size_t i, size_t j)
{
	avl_t *node = NULL;
	size_t index;

	index = (i + j) / 2;

	node = binary_tree_node(parent, arr[index]);

	if (i < index)
		node->left = sorted_arr_to_avl_recur(arr, node, i, index - 1);

	if (j > index)
		node->right = sorted_arr_to_avl_recur(arr, node, index + 1, j);

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
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = sorted_arr_to_avl_recur(array, NULL, 0, size - 1);
	if (!root)
		return (NULL);

	return (root);
}
