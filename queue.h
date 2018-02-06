/****************************************************************************/
/* File: queue.h
 */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*              Simple Queue ADT                                            */
/*                                                                          */
/*              Declaration                                                 */
/*                                                                          */
/****************************************************************************/


typedef struct {
    int key;
    int value;
} data_t;

typedef struct queueNode {
    struct queueNode *next, *prev;
    data_t *data;
} QueueNode;

typedef struct queueType {
    QueueNode *head;
    QueueNode *tail;
} Queue;




/****************************************************************************/
/* Function Prototypes/Declarations                                         */
/****************************************************************************/
void initQueue(Queue *self);
void enQueue(Queue *self, data_t *data);
QueueNode *frontNode(Queue *self);
data_t *frontValue(Queue *self);
data_t *deQueue(Queue *self);
void removeNode(Queue *self, QueueNode *p);
QueueNode *findNode(Queue *self, data_t *data);
data_t *findValue(Queue *self, data_t *data);
void purge(Queue *self, data_t *data);
void printQ(Queue *self, char *label);
char *toString(data_t *d);

