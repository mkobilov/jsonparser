#include "list.h"

#include <stdlib.h>




pListIterator CreateBeginListIterator(pList lst);
ListIterator GetBeginListIterator(pList lst);
void DeleteListIterator(pListIterator* pIter);
void DeleteListElementByIterator(pListIterator iter);
int ListIteratorNext(pListIterator iter);
int ListIteratorHasNext(pListIterator iter);
int IsListIteratorNULL(pListIterator iter);
void* GetListIteratorValue(pListIterator iter);




void DeleteListElementByIterator(pListIterator itr){
	assert(itr->list != NULL);

	
	if(itr->current_value->prev == NULL)
		itr->list->first = itr->next;
	
	else
		itr->current_value->prev->next = itr->next;
	
	
	if(itr->next == NULL)	
		itr->list->last = itr->current_value->prev;
	
	else
		itr->next->prev = itr->current_value->prev;
	
	
	if(itr->current_value)
		free(itr->current_value);
	itr->current_value = NULL;
}

pListIterator CreateBeginListIterator(pList lst){
	assert(lst);
	assert(lst->first);			//checks if there is any elements in lst
	pListIterator iter = (pListIterator) calloc(1,sizeof(ListIterator));
	iter->current_value = lst->first;
	if(lst->first->next){
		iter->next = lst->first->next;
	}
	iter->list = lst;
	return iter;
}
ListIterator GetBeginListIterator(pList lst){
	if(!lst){
		ListIterator itr = { NULL, NULL,NULL };
		return itr;
	}
	
	ListIterator itr = {lst, lst->first, lst->first?lst->first->next:NULL};
	
	return itr;
}

void DeleteListIterator(pListIterator* pIter){
	assert(pIter);
	free(*pIter);
	pIter = NULL;
}

void* GetListIteratorValue(pListIterator iter){
	if(!iter->current_value)
		return NULL;
	return iter->current_value->value;
}
int ListIteratorNext(pListIterator iter){
	assert(iter);		// check iterator
	
	iter->current_value = iter->next;
	if(iter->next)
		iter->next = iter->current_value->next;
	
	
	return iter->current_value == NULL;

}

int IsListIteratorNULL(pListIterator iter){
	assert(iter);
	return iter->current_value == NULL;
}

int ListIteratorHasNext(pListIterator iter){
	assert(iter);
	if(iter->next)
		return 1;
	return 0;
}