#include <stdlib.h>
#include "binary_trees.h"
#include <stdbool.h>

/**
 * is_complete_tree - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_tree(const binary_tree_t *tree)
{
	const binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	bool encountered_null = false;

	if (!tree)
		return (1);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *node = queue[front++];

		if (!node)
		{
			encountered_null = true;
		}
		else
		{
			if (encountered_null)
				return (0);
			queue[rear++] = node->left;
			queue[rear++] = node->right;
		}
	}
	return (1);
}

/**
 * is_max_heap - Checks if a binary tree satisfies the max-heap property.
 * @tree: Pointer to the root node of the tree.
 *
 * This function assumes the tree is already a complete binary tree.
 * It verifies that every node is greater than or equal to its children
 * (max-heap property), but does not check for completeness.
 *
 * Return: 1 if the tree satisfies the max-heap property, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);

	if (tree->right == NULL)
		return (tree->n >= tree->left->n);

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (is_max_heap(tree->left) && is_max_heap(tree->right));

	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_complete_tree(tree))
		return (0);

	return (is_max_heap(tree));
}

