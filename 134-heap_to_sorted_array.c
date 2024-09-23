#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left)
			+ binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t index;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(*size * sizeof(int));
	if (!array)
		return (NULL);

	for (index = *size; index > 0; index--)
	{
		array[index - 1] = heap_extract(&heap);
	}

	return (array);
}
