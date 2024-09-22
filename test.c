#include <stdlib.h>
#include "binary_trees.h"


/**
 * avl_balance_node_removal - balances an unbalanced node after node removal
 * @node: Pointer to the node to balance.
 * @value: value removed from tree
 *
 * Return: pointer to the balanced node
 */
avl_t *avl_balance_node_removal(avl_t *node, int value)
{
	int balance;

	balance = binary_tree_balance(node);
	if (balance > 1 && value > node->right->n)
		node = binary_tree_rotate_right(node);
	else if (balance > 1 && value < node->right->n)
		node->right = binary_tree_rotate_right(node->right);
	else if (balance < -1 && value < node->left->n)
		node = binary_tree_rotate_left(node);
	else if (balance < -1 && value > node->left->n)
		node->left = binary_tree_rotate_left(node->left);
	return (node);
}

/**
 * avl_remove_node_with_2_child - Removes a node that has two children from an
 * AVL tree without actually deleting the node (by swapping values)
 * @node: Pointer to the node to remove
 * @successor: successor to node
 *
 * Return: new successor to node
 */
avl_t *avl_remove_node_with_2_child(avl_t *node, bst_t *successor)
{
	bst_t *temp = NULL;
	int value;

	if (!successor->left)
	{
		node->n = successor->n;
		value = successor->n;
		temp = successor->right;
		if (temp)
			temp->parent = successor->parent;
		free(successor)
		return (temp)
	}
	successor->left = avl_remove_node_with_2_child(node, successor->left);
	successor = avl_balance_node_removal(successor, value);
	return (successor);
}

/**
 * avl_remove_recursion - Removes a node from an AVL Tree.
 * @node: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * @value_found: indicates whether a node is removed.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
avl_t *avl_remove_recursion(bst_t *node, int value, int *value_found)
{
	bst_t *temp = node;

	if (!node)
		return (node);
	if (value > node->n)
		node->right = avl_remove_recursion(node->right, value);
	else if (value < node->n)
		node->left = avl_remove_recursion(node->left, value);
	else
	{
		*value_found = 1;
		if (!node->left && !node->right)
		{
			node = NULL;
			free(temp);
		}
		else if (!node->left || !node->right)
		{
			node = node->left ? node->left : node->right;
			node->parent = temp->parent;
			free(temp);
		}
		else
		{
			temp = avl_remove_node_with_2_child(node, node->right);
			node->right = temp;
		}
	}
	if (value_found)
		node = avl_balance_node_removal(node, value);
	return (node);
}

/**
 * avl_remove - wrapper for avl_remove_recursion.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
avl_t *avl_remove(bst_t *root, int value)
{
	int value_found = 0;

	if (!node)
		return (NULL);
	return (avl_remove_recursion(root, value, &value_found));
}
