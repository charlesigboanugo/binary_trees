#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Restores the max heap property by "bubbling up"
 * the inserted node.
 * @node: The node to heapify up.
 *
 * Return: Pointer to the node after heapify (could be root).
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert_helper - Helper function to insert a node in the heap.
 * @root: The root of the heap.
 * @value: The value to store in the new node.
 *
 * Return: Pointer to the new node.
 */
heap_t *heap_insert_helper(heap_t *root, int value)
{
	heap_t *new_node = NULL;
	heap_t *queue[1024];
	int front = 0, rear = 0;

	/* Level order traversal to find the first available spot */
	queue[rear++] = root;
	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (!current->left)
		{
			new_node = binary_tree_node(current, value);
			if (!new_node)
				return (NULL);
			current->left = new_node;
			return (new_node);
		}
		else
			queue[rear++] = current->left;

		if (!current->right)
		{
			new_node = binary_tree_node(current, value);
			if (!new_node)
				return (NULL);
			current->right = new_node;
			return (new_node);
		}
		else
			queue[rear++] = current->right;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert in the heap.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new_node = heap_insert_helper(*root, value);
	if (!new_node)
		return (NULL);

	/* Restore the max heap property */
	return (heapify_up(new_node));
}

