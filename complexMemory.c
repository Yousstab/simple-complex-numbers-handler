#include"complexMemory.h"
// add error handling in new module
void initializeComplexMemory(ComplexMemory* complexMemory){
  for(int i=0;i<MAXSLOTS;i++){
    complexMemory->occupiedSlots[i] = FALSE;
  }
  //might add startup values in input
}

void clearAllComplexMemory(ComplexMemory* complexMemory){
  for(int i=0;i<MAXSLOTS;i++){
    complexMemory->occupiedSlots[i] = FALSE;
  }
}

void clearSlotComplexMemory(ComplexMemory* complexMemory,int slot){
  if(slot < MAXSLOTS&&slot >= 0){
    complexMemory->occupiedSlots[slot] = FALSE;
  }else{
    //error
  }
}

void loadIntoSlotComplexMemory(ComplexMemory* complexMemory, complex_number* complexNumber,int slot){
  //add check overwrite if slot occupied
  if(slot < MAXSLOTS&&slot >= 0){
    complexMemory->slots[slot] = *complexNumber;
    complexMemory->occupiedSlots[slot] = TRUE;
  }
  else{
    //error
  }
}

void loadIntoMultipleSlotComplexMemory(ComplexMemory* complexMemory, complex_number* complexNumbers,int* slots, int count){
  for(int i=0;i<count;i++){
    loadIntoSlotComplexMemory(complexMemory, &complexNumbers[i], slots[i]);
  }
}

void getSlotComplexMemory(ComplexMemory* complexMemory, complex_number* output,int slot){
  if(slot < MAXSLOTS&&slot >= 0){
    if(complexMemory->occupiedSlots[slot]==TRUE){
    *output=complexMemory->slots[slot];
    }else{
      //error, posible garbage value
    }
  }else{
  //error
  }
}
bool isSlotOccupied(ComplexMemory* complexMemory, int slot){
  if(slot < MAXSLOTS&&slot >= 0){
    return complexMemory->occupiedSlots[slot];
  }else{
    //error
    return FALSE;
  }
}
