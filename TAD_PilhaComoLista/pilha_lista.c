#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.h"

SLList *SLLCreate(){
    SLList *list = (SLList*)malloc(sizeof(SLList));
    if(list != NULL){
        list->first = NULL;            
        return list;
    } else{
        return NULL;
    }
}

int SLLDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    } 
    return FALSE;
}

int SLLAddNode(SLList *l, void *data){
    if(l != NULL){
        SLNode *node = (SLNode*)malloc(sizeof(SLNode));
        if(node != NULL){
            node->data = data;
            node->next = l->first;
            l->first = node;
            return TRUE;
        }
    } 
    return FALSE;
}

void *SLLRemoveNode(SLList *l){
    void *data;
    SLNode *current;
    if(l != NULL){
        current = l->first;
        if(current != NULL){
            data = current->data;
            l->first = current->next;
            free(current);
            return data;
        }
    } 
    return NULL;
}

void *SLLFirstNode(SLList *l){
    void *data;
    SLNode *current;
    if(l != NULL){
        if(l->first != NULL){
            current = l->first;
            data = current->data;
            return data;
        }
    } 
    return NULL;
}

