#include "list.h"

#include <stdlib.h>


typedef struct _list_iterator
{
	pListElement current_value;
	pListElement next;
} ListIterator, *pListIterator;

pListIterator CreateBeginListIterator(pList);
void DeleteListIterator(pListIterator*);
void ListIteratorNext(pListIterator*);
void* GetListIteratorValue(pListIterator);


pListIterator CreateBeginListIterator(pList lst)
{
	if(lst->first == NULL)	// list empty
	{
		return NULL;
	}
	
	pListIterator iter = (pListIterator) malloc(sizeof(ListIterator));
	
	iter->next = lst->first->next;
	iter->current_value = lst->first;
	
	return iter;
}

void DeleteListIterator(pListIterator *pIter)
{
	free(*pIter);
	*pIter = NULL;
}

void ListIteratorNext(pListIterator *pIter)
{
	pListIterator iter = *pIter;
	
	iter->current_value = iter->next;
	
	if(iter->next != NULL)	// not at the end
	{
		iter->next = iter->next->next;
		return;
	}
	
	DeleteListIterator(pIter);
}

void* GetListIteratorValue(pListIterator iter)
{
	if(iter == NULL)
	{
		return NULL;
	}
	
	return iter->current_value->value;
}
