/****************************************************************************/
/* File: queue.c
 */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*              Simple Queue ADT                                            */
/*                                                                          */
/*              Implementation                                              */
/*                                                                          */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "osp.h"
#include "queue.h"



void initQueue(Queue *self)
{
	self->head = null;
	self->tail = null;
}


void enQueue(Queue *self, data_t *data)
{
}


QueueNode *frontNode(Queue *self)
{
}


data_t *frontValue(Queue *self)
{
}


data_t *deQueue(Queue *self)
{
}


void removeNode(Queue *self, QueueNode *p)
{
}



QueueNode *findNode(Queue *self, data_t *data)
{
}


data_t *findValue(Queue *self, data_t *data)
{
}


void purge(Queue *self, data_t *data)
{
}


void printQ(Queue *self, char *label)
{
}


char *toString(data_t *d)
{
    static char result[BUFSIZ];

    if (d == NULL)
        sprintf (result, "NULL");
    else
        sprintf (result, "key=%d(data=%d) ", d->key, d->value);
    return result;
}



int main ()
{
    Queue myQueue;
    QueueNode *p;
    data_t data[10], d2;
    int i;

    initQueue (&myQueue);
/*
    for (i = 0; i < 10; i++) {

        data[i].key = i;
        data[i].value = 10*i;

        enQueue (&myQueue, &data[i]);
    }

    printQ (&myQueue, "MyQueue:" );

}
*/




