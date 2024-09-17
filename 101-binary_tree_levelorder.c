#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: tree to print
 * @func: helper
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *queue[100];
	const binary_tree_t **que = queue;
	const binary_tree_t **ptr = queue;

	if (tree == NULL)
		return;

	queue[0] = tree;
	for (; ptr <= que;)
	{
		func((*ptr)->n);
		if ((*ptr)->left != NULL)
		{
			que++;
			*que = (*ptr)->left;
		}
		if ((*ptr)->right != NULL)
		{
			que++;
			*que = (*ptr)->right;
		}
		ptr++;
	}
}
