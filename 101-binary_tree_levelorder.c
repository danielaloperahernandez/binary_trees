#include "binary_trees.h"

/**
 * func_level - function that applies the function pointer
 * to each element of the level
 * a binary tree using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @level: level in the tree
 * @func: is a pointer to a function to call for each node
 */

void func_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		func_level(tree->left, level - 1, func);
		func_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	height =  binary_tree_height(tree);

	for (level = 0; level <= height; level++)
	{
		func_level(tree, level, func);
	}
}
