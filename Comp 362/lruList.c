/**
 * This implements the LRU page-replacement algorithm.
* Name: kadejha Jones 
* Lab/task: Lab 10
* Date: 10/31/2022
 */

#include "../inc/lruList.h"

int *referenceString;
int refStringLength;

FRAME *pageTableTop;
FRAME *leastRecentlyUsed;
int pageTableSize;

int numberOfFramesPerProcess = 0;

// statistics
int nummberOfFaults = 0;

int hitPageNumber;

/*
 * insert pages from a reference string into a page table and measure
 * the page fault rate
 */
int testLRU(int numOfFrames, int *refString, int refStrLen)
{
    referenceString = refString;
    refStringLength = refStrLen;

    pageTableSize = numOfFrames;

    for(int i = 0; i < refStrLen; i++){
    	insertLRU(refString[i]);
	displayLRU();
    }
    return nummberOfFaults;
}

/*
 *	try to insert a page into the page table
 */
void insertLRU(int pageNumber)
{
    FRAME *found = searchLRU(pageNumber);
    if(found){
	   if(found != pageTableTop){
	        hitPageNumber = 0;
	        if(found == leastRecentlyUsed){
	           leastRecentlyUsed = leastRecentlyUsed->up;
	        }
	        if(found->up != NULL){
	           found->up->down = found->down; 
	        }
	        if(found->down != NULL){
	           found->down->up = found->up;
	        }
	        found->down = pageTableTop;
	        found->up = NULL;
       	        pageTableTop->up = found; 
	        pageTableTop = found;
        	return;
	   }
    }
    else{
       //if(numberOfFramesPerProcess > pageTableSize){
          FRAME *current = malloc(sizeof(FRAME*));
          current->up = NULL;
          current->down = pageTableTop;
	  current->pageNumber = pageNumber; 

          //removing the last one 
         // FRAME *temp = leastRecentlyUsed;
         // leastRecentlyUsed->down = leastRecentlyUsed->up;
          //free(temp);
          nummberOfFaults++;
          numberOfFramesPerProcess++;
       //}
    }
}

/**
 * Searches for page pageNumber in the page frame list
 * returns NULL if a frame with pageNumber was not found
 * otherwise, returns a reference to the frame with pageNumber
 */
FRAME *searchLRU(int pageNumber)
{
    //implement
    //create a loop in linkedList 
    //return a pointer to current section
   FRAME *current = pageTableTop;
   

   while(current != NULL){
        if(current->pageNumber == pageNumber){
	   return current;
	}
	current = current->down;
   }
    return NULL;
}

void displayLRU()
{
    FRAME *current = pageTableTop;
    //implement
    while(current != NULL){
    	printf("\t %d", current->pageNumber);
	printf("\n");
        current = current->down;
    }
}

void freePageTableLRU()
{
    //implement
    //
}

