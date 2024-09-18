#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: The value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 *
 * If the tree is empty, the new node becomes the root.
 * If the value is already present in the tree, it is ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current;
	bst_t *new_node;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	current = *tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);
				if (new_node == NULL)
					return (NULL);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}
	return (NULL);
}
