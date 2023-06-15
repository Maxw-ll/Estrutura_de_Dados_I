

#define TRUE 1
#define FALSE 0

typedef struct sl_node{
    void *data;
    struct sl_node *next;
}SLNode;

typedef struct sl_list{
    SLNode *first;
}SLList;


SLList *SLLCreate();
int SLLDestroy(SLList *l);
int SLLAddNode(SLList *l, void *data);
void *SLLRemoveNode(SLList *l);
void *SLLFirstNode(SLList *l);



