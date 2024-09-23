#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_last_node - Finds the last node in a binary heap using level-order
 * traversal.
 * @root: The root of the heap.
 *
 * Return: A pointer to the last node.
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *last = NULL;
	heap_t **queue;
	size_t front = 0, back = 0;

	if (!root)
		return (NULL);

	/*
	 * Allocate space for the queue based on an estimate of the tree's
	 * depth
	 */
	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	/* Enqueue the root node */
	queue[back++] = root;

	while (front < back)
	{
		last = queue[front++];

		/* Enqueue left and right children (if they exist) */
		if (last->left)
			queue[back++] = last->left;
		if (last->right)
			queue[back++] = last->right;
	}

	free(queue);
	return (last);
}

/**
 * swap_values - Swap the values of two nodes in the binary heap.
 * @node1: The first node.
 * @node2: The second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - Rebuilds the heap by sifting the new root down.
 * @node: The node to heapify down from.
 */
void heapify_down(heap_t *node)
{
	heap_t *largest;

	if (!node)
		return;

	while (node->left)
	{
		largest = node->left;
		if (node->right && node->right->n > node->left->n)
			largest = node->right;

		if (node->n >= largest->n)
			break;

		swap_values(node, largest);
		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: A double pointer to the root of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *last;
	int value;

	if (!root || !*root)
		return (0);

	node = *root;
	value = node->n;
	last = find_last_node(node);

	if (last == node)
	{
		free(node);
		*root = NULL;
		return (value);
	}

	swap_values(node, last);

	/* Remove the last node */
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	/* Rebuild the heap */
	heapify_down(node);

	return (value);
}
