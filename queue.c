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
	self->head = NULL;
	self->tail = NULL;
}


void enQueue(Queue *self, data_t *data)
{
	if(self == NULL) return;
	if(self->head == NULL){
		//Should run only when an empty queue exists
		self->head = self->tail = (QueueNode *)calloc(1,sizeof(QueueNode));
		self->head->prev = NULL;
		self->head->next = NULL;
		self->head->data = data;
	}
	else {
		QueueNode *newNode = (QueueNode *) calloc(1, sizeof(QueueNode));
		newNode->next = self->head;
		newNode->prev = NULL;
		newNode->data = data;
		self->head->prev = newNode;
		self->head = newNode;
	}
}


QueueNode *frontNode(Queue *self)
{
    return self->head;
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
    if (self == NULL){
        puts("NULL");
    } else {
        printf("Queue head: %s\n", toString(self->head->data));
        printf("Queue tail: %s\n", toString(self->tail->data));
    }
    
}

void printNode(QueueNode *self){
    if (self == NULL) puts("NULL");
    else{
        printf("QueueNode data: %s", toString(self->data));
    }
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
    for (i = 0; i < 10; i++) {

        data[i].key = i;
        data[i].value = 10*i;

        enQueue (&myQueue, &data[i]);
    }
    printQ (&myQueue, "MyQueue:" );
    printf("frontNode: ");
    printNode(frontNode(&myQueue));
}



