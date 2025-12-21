

#ifndef COMPLEXMEMORY_H
#define COMPLEXMEMORY_H
#define MAXSLOTS 10
#include "complexFunctionsLib.h"
typedef struct  {
  complex_number slots[MAXSLOTS];
  bool occupiedSlots[MAXSLOTS];
}complex_memory;

void initializeComplexMemory(complex_memory* complexMemory);

void clearAllComplexMemory(complex_memory* complexMemory);
void clearSlotComplexMemory(complex_memory* complexMemory, int slot);

void loadIntoSlotComplexMemory(complex_memory* complexMemory, complex_number* complexNumber,int slot);
void loadIntoMultipleSlotComplexMemory(complex_memory* complexMemory, complex_number* complexNumbers,int* slots, int count);

void getSlotComplexMemory(complex_memory* complexMemory, complex_number* output,int slot);
bool isSlotOccupied(complex_memory* complexMemory, int slot);

#endif //COMPLEXMEMORY_H
