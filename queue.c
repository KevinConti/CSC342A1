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
    printf("running initQueue\n");
    self->head = NULL;
    self->tail = NULL;
    printf("InitQueue is completed\n");
}


void enQueue(Queue *self, data_t *data)
{
    printf("Running enQueue\n");
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
    printf("Enqueue complete\n");
}


QueueNode *frontNode(Queue *self)
{
    if(self->head != NULL){
        return self->head;
    } else {
    return NULL;
    }
}


data_t *frontValue(Queue *self)
{
    if(self->head != NULL){
        return self->head->data;
    } else {
        return NULL;
    }
}


data_t *deQueue(Queue *self)
{
    data_t *data = frontValue(self);
    if(self->head != NULL){
        if(self->head->next != NULL){
            self->head = self->head->next;
            free(self->head->prev);
            self->head->prev = NULL;
        } else if(self->tail != NULL){
            //self->head->next is null, therefore we are dequeing the final node
            free(self->head);
            self->head = NULL;
            self->tail = NULL; //TODO: This may cause an error, or maybe it's exactly right. Who knows
        }
    }
   return data;
}


void removeNode(Queue *self, QueueNode *p)
{
    //If both head and tail are null, then the node is not in the queue
    if(self->head == NULL && self->tail == NULL) return;
    //If p->prev and p->next are null, then this is the only object in the queue
    if(p->prev == NULL && p->next == NULL){
        self->head = NULL;
        self->tail = NULL;
    }
    //If p->prev is NULL, then this is the head
    else if(p->prev == NULL){
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
    QueueNode *currentNode;

    if(self->head!= NULL){
        currentNode = self->head;
        do{
            if (currentNode->data->key == data->key) break;
            if(currentNode->next == NULL){
                currentNode = NULL;
                break;
                }
            currentNode = currentNode->next;
        } while (currentNode->next != NULL);
        //Repeat block one more time in order to check the last value
        if(currentNode->data->key != data->key){
            currentNode = NULL;
        }
    } else currentNode = NULL;
    return currentNode;
}


data_t *findValue(Queue *self, data_t *data)
{
    QueueNode *foundNode = findNode(self, data);
    if(foundNode != NULL){
        return foundNode->data;
    } else return NULL;
}


void purge(Queue *self, data_t *data)
{
}


void printQ(Queue *self, char *label)
{
    printf("Kevin Conti's  :");
    if (self->head  == NULL && self->tail == NULL){
        puts("Empty but initialized Queue");
    } else {
        QueueNode *currentNode = self->head;
        printf("%s  ", toString(currentNode->data));
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            printf("%s   ", toString(currentNode->data));
        }
    /*
        printf("Break1\n");
        printf("Queue head: %s\n", toString(self->head->data));
        printf("Break2\n");
        printf("Queue tail: %s\n", toString(self->tail->data));
    */
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


/*
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

    //Test findValue method
    d2.key = 3;
    d2.value = 50;
    data_t *foundValue = findValue(&myQueue, &d2); 
    printf("foundData: %s\n", toString(foundValue));
}
*/


