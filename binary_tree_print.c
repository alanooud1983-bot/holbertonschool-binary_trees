#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Function prototypes */
void binary_tree_print(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail);
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);

/**
* binary_tree_print - Prints a binary tree.
* @tree: A pointer to the root node of the tree to print.
*/
void binary_tree_print(const binary_tree_t *tree)
{
levelorder_queue_t *head, *tail;
int printed = 0;

if (tree == NULL)
return;

head = tail = create_node((binary_tree_t *)tree);
if (head == NULL)
return;

while (head != NULL)
{
if (head->node->left != NULL)
push(head->node->left, head, &tail);
else
printed += printf("--");
if (head->node->right != NULL)
push(head->node->right, head, &tail);
else
printed += printf("--");
printf("%d", head->node->n);
printed += printf(" ");
pop(&head);
}
printf("\n");
free_queue(head);
}

/**
* create_node - Creates a new levelorder queue node.
* @node: The binary tree node for the new queue node.
*
* Return: A pointer to the new node, or NULL on failure.
*/
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *new;

new = malloc(sizeof(levelorder_queue_t));
if (new == NULL)
return (NULL);

new->node = node;
new->next = NULL;

return (new);
}

/**
* push - Pushes a node to the levelorder queue.
* @node: The binary tree node to push.
* @head: The head of the queue.
* @tail: The tail of the queue.
*/
void push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail)
{
levelorder_queue_t *new;

new = create_node(node);
if (new == NULL)
{
free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}

/**
* free_queue - Frees a levelorder queue.
* @head: The head of the queue.
*/
void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *tmp;

while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}

/**
* pop - Pops a node from the levelorder queue.
* @head: The head of the queue.
*/
void pop(levelorder_queue_t **head)
{
levelorder_queue_t *tmp;

tmp = (*head)->next;
free(*head);
*head = tmp;
}
