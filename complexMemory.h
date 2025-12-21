

#ifndef COMPLEXMEMORY_H
#define COMPLEXMEMORY_H
#define MAXSLOTS 10
#include "complexFunctionsLib.h"
typedef struct  {
  complex_number slots[MAXSLOTS];
  bool occupiedSlots[MAXSLOTS];
}ComplexMemory;

void initializeComplexMemory(ComplexMemory* complexMemory);

void clearAllComplexMemory(ComplexMemory* complexMemory);
void clearSlotComplexMemory(ComplexMemory* complexMemory, int slot);

void loadIntoSlotComplexMemory(ComplexMemory* complexMemory, complex_number* complexNumber,int slot);
void loadIntoMultipleSlotComplexMemory(ComplexMemory* complexMemory, complex_number* complexNumbers,int* slots, int count);

void getSlotComplexMemory(ComplexMemory* complexMemory, complex_number* output,int slot);
bool isSlotOccupied(ComplexMemory* complexMemory, int slot);

#endif //COMPLEXMEMORY_H
