#ifndef ARRAY_H
#define ARRAY_H
#include <malloc.h>
#include <memory.h>
int memSize(int nItem, int szItem);
void* data_address(void* origin_address);
void* origin_address(void* data_address);
void* size_item_address(void* data_address);
void* arrInit(int nItem, int szItem);
int arr_size(void* data_address);
int arr_item_size(void* data_address);
void* arrResize(void* aData, int nItem);
int arrPushback(void** aData, void* x);
void* arrPopback(void** aData);
void arrFree(void* aData);
#endif