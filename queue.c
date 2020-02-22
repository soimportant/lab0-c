#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));

    if (!q)
        return NULL;

    /* initialize fields */
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */

    if (!q)
        return;

    /* point to the node that want to free now */
    list_ele_t *now = q->head;

    while (now != NULL) {
        list_ele_t *tmp = now->next;
        free(now->value);
        free(now);
        now = tmp;
    }

    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;

    if (!q)
        return false;

    newh = malloc(sizeof(list_ele_t));

    if (!newh)
        return false;

    newh->value = malloc(strlen(s) + 1);

    if (!newh->value) {
        free(newh);
        return false;
    }

    /* copy string */
    size_t i = 0;
    for (i = 0; i < strlen(s); i++)
        newh->value[i] = s[i];
    newh->value[i] = '\0';

    newh->next = q->head;
    q->head = newh;

    /* if list is empty --> head == tail */
    if (q->size == 0) {
        q->tail = q->head;
    }

    /* increase size of q */
    q->size++;

    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */

    if (!q)
        return false;

    list_ele_t *newt = malloc(sizeof(list_ele_t));

    if (!newt)
        return false;

    newt->value = malloc(strlen(s) + 1);
    newt->next = NULL;

    if (!newt->value) {
        free(newt);
        return false;
    }

    size_t i = 0;
    for (i = 0; i < strlen(s); i++)
        newt->value[i] = s[i];
    newt->value[i] = '\0';

    if (q->size == 0) {
        q->head = q->tail = newt;
    } else {
        q->tail->next = newt;
        q->tail = newt;
    }

    q->size++;

    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */

    if (!q || !q->size)
        return false;

    list_ele_t *del = q->head;

    if (sp) {
        /* make bufsize be the limit of string length */
        size_t len = strlen(del->value);
        if (len < bufsize)
            bufsize = len;
        else
            bufsize--;

        for (size_t i = 0; i < bufsize; i++)
            sp[i] = del->value[i];

        sp[bufsize] = '\0';
    }

    q->head = del->next;

    free(del->value);
    free(del);

    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q)
        return 0;

    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
