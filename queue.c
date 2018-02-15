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
		newNode->next = NULL;
		newNode->prev = self->tail;
		newNode->data = data;
		self->tail->next = newNode;
		self->tail = newNode;
	}
}


QueueNode *frontNode(Queue *self)
{
    return self->head;
}


data_t *frontValue(Queue *self)
{
    return self->head->data;
}


data_t *deQueue(Queue *self)
{
    data_t *data = frontValue(self);
    printf("self->head->next is:");
    printNode(self->head->next);
    self->head = self->head->next;
    free(self->head->prev);
    self->head->prev = NULL;
    return data;
}


void removeNode(Queue *self, QueueNode *p)
{
    //If both head and tail are null, then the node is not in the queue
    if(self->head == NULL && self->tail == NULL) return;
    //If p->prev is NULL, then this is the head
    if(p->prev == NULL){
        self->head = self->head->next;
        p->next->prev = p->prev;
    }
    //if p->next is NULL, then this is the tail
    else if(p->next == NULL){
        self->tail = self->tail->prev;
        p->prev->next = p->next;
    }
    else{
        //Do standard removal
        printf("Break four\n");
        p->prev->next = p->next;
        printf("Break five\n");
        p->next->prev = p->prev;
        printf("Break six\n");
     }    
     free(p);
    
}



QueueNode *findNode(Queue *self, data_t *data)
{
    QueueNode *currentNode = self->head;
    do{
        if (currentNode->data->key == data->key) break;
        currentNode = currentNode->next;
        if(currentNode->next == NULL){
            currentNode = NULL;
            break;
        }
    } while (currentNode->next != NULL);
    return currentNode;
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
        printf("QueueNode data: %s\n", toString(self->data));
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
    QueueNode *p, *node1, *node2, *node3, *head;
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
    printf("frontValue: %s\n", toString(frontValue(&myQueue)));
    deQueue(&myQueue);
    printf("New frontNode: ");
    printNode(frontNode(&myQueue));

    //Test removeNode Method
    d2.key = 1;
    node1 = findNode(&myQueue, &d2);
    d2.key = 2;
    node2 = findNode(&myQueue, &d2);
    d2.key = 3;
    node3 = findNode(&myQueue, &d2);
    removeNode(&myQueue, node2);
    //node1.next should point to node 3
    printf("Node 1 -> next = ");
    printNode(node1->next);
    //node3.prev should point to node 1
    printf("Node 3 -> prev = ");
    printNode(node3->prev);
    //When a head node is removed, the head is properly moved
    printf("Old head: ");
    head = myQueue.head;
    printNode(head);
    removeNode(&myQueue, node1); 
    printf("New head: ");
    head = myQueue.head;
    printNode(head);

    
    //Test findNode method
    d2.key = 3;
    d2.value = 50;
    QueueNode *foundNode = findNode(&myQueue, &d2);
    printf("foundNode: ");
    printNode(foundNode);
}



