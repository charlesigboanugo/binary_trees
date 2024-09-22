#include <stdlib.h>
#include "binary_trees.h"


/**
 * avl_balance_node - balances an unbalanced node after node
 * @node: Pointer to the node to balance.
 *
 * Return: pointer to the balanced node
 */
avl_t *avl_balance_node(avl_t *node)
{
	int balance;

	balance = binary_tree_balance(node);

	if (balance > 1)
	{
		if (binary_tree_balance(node->left) >= 0)
			node = binary_tree_rotate_right(node);
		else
		{
			node->left = binary_tree_rotate_left(node->left);
			node = binary_tree_rotate_right(node);
		}
	}
	if (balance < -1)
	{
		if (binary_tree_balance(node->right) <= 0)
			node = binary_tree_rotate_left(node);
		else
		{
			node->right = binary_tree_rotate_right(node->right);
			node = binary_tree_rotate_left(node);
		}
	}
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

	if (!successor->left)
	{
		node->n = successor->n;
		temp = successor->right;
		if (temp)
			temp->parent = successor->parent;
		free(successor);
		return (temp);
	}
	successor->left = avl_remove_node_with_2_child(node, successor->left);
	successor = avl_balance_node(successor);
	return (successor);
}

/**
 * avl_remove_recursion - Removes a node from an AVL Tree.
 * @node: Pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * @found: indicates whether a node is removed.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
avl_t *avl_remove_recursion(bst_t *node, int value, int *found)
{
	bst_t *temp = node;

	if (!node)
		return (node);
	if (value > node->n)
		node->right = avl_remove_recursion(node->right, value, found);
	else if (value < node->n)
		node->left = avl_remove_recursion(node->left, value, found);
	else
	{
		*found = 1;
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
	if (node && *found)
		node = avl_balance_node(node);
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
	int found = 0;

	if (!root)
		return (NULL);
	return (avl_remove_recursion(root, value, &found));
}
