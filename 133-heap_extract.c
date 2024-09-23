#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_last_node - Finds the last node in a binary heap using level-order traversal.
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
