#include "list.h"

#include <stdlib.h>

pList CreateList(){						// Create empty list
	pList lst = (pList) malloc(sizeof(List));
	
	lst->first = NULL;
	lst->last = NULL;
	
	return lst;
}

void DeleteList(pList* lst){
	if(lst == NULL){
		return;
	}
	
	ListIterator iter = GetBeginListIterator(*lst);
	while(!IsListIteratorNULL(&iter)){
		DeleteListElementByIterator(&iter);
		ListIteratorNext(&iter);
	}
	
	free(*lst);
	*lst = NULL;
}

void PushBackToList(pList lst, void *value){			//Adding elem to the end of the list
	pListElement newElem = (pListElement) malloc(sizeof(ListElement));
	
	newElem->value = value;
	
	newElem->prev = lst->last;
	newElem->next = NULL;
	
	if(lst->first == NULL)	
		lst->first = newElem;
	
	else
		lst->last->next = newElem;
	
	
	lst->last = newElem;
}
