#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>


void binary_tree_print(const binary_tree_t *root)
{
	const binary_tree_t *queue[100];
	const binary_tree_t **que = queue;
	const binary_tree_t **ptr = queue;

	if (root == NULL)
	       return;	

	queue[0] = root;
	for (; ptr <= que;)
	{
		printf("%i\n", (*ptr)->n);
		fflush(stdout);
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
