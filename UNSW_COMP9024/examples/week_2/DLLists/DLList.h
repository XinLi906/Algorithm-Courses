#ifndef DLLIST_H
#define DLLIST_H

#include <stdio.h>
#include "DLList.h"

typedef struct DLListRep *DLList;

DLList newDLList();

void freeDLList(DLList);

void showDLList(DLList);

int DLListCurrent(DLList);

int DLListMoveTo(DLList, int);

void DLListBefore(DLList, int);

void DLListAfter(DLList, int);

void DLListDelete(DLList);

int DLListLength(DLList);

int DLListIsEmpty(DLList);

#endif