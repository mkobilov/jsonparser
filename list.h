#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct _list_element
{
	void *value;
	struct _list_element *next;
	struct _list_element *prev;
} ListElement, *pListElement;

typedef struct _list
{
	pListElement first;
	pListElement last;
} List, *pList;

pList CreateList();
void DeleteList(pList*);

void PushBackToList(pList, void*);

typedef struct _list_iterator
{
	pList list;
	pListElement current_value;
	pListElement next;
	pListElement prev;
} ListIterator, *pListIterator;

pListIterator CreateBeginListIterator(pList);
ListIterator GetBeginListIterator(pList);
void DeleteListIterator(pListIterator*);
void DeleteListElementByIterator(pListIterator);
int ListIteratorNext(pListIterator);
int ListIteratorHasNext(pListIterator);
int IsListIteratorNULL(pListIterator);
void* GetListIteratorValue(pListIterator);


#endif	//__LIST_H__
