#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 *
 * A complete binary tree means every level is fully filled, except possibly
 * the last level. The last level must have all nodes as far left as possible.
 * The tree is incomplete if a non-NULL node if found after a NULL node in the
 * loop
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	const binary_tree_t *current;
	size_t front = 0, rear = 0, capacity = 1024;
	bool found_incomplete_node = false;

	if (!tree)
		return (0);

	queue = malloc(capacity * sizeof(*queue));
	if (!queue)
		return (0);

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
			found_incomplete_node = true;
		else
		{
			if (found_incomplete_node)
			{
				free(queue);
				return (0);
			}
			if (rear == capacity)
			{
				capacity *= 2;
				queue = realloc(queue, capacity * sizeof(*queue));
				if (!queue)
					return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	free(queue);
	return (1);
}
