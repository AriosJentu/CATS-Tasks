#include <stdio.h>
#include <stdlib.h>
 
void quicksort(int* array,int first,int last){
    int Pivot, j, Temporary, i;
 
    if(first < last){
        Pivot = first;
        i = first;
        j = last;
 
        while (i < j){
 
            while (array[i] <= array[Pivot] && i<last) {
                i++;
            }
 
            while (array[j] > array[Pivot]) {
                j--;
            }
 
            if (i < j) {
                Temporary = array[i];
                array[i] = array[j];
                array[j] = Temporary;
            }
        }
 
        Temporary = array[Pivot];
        array[Pivot] = array[j];
        array[j] = Temporary;
         
        quicksort(array, first, j-1);
        quicksort(array, j+1, last);
    }
}
 
 
 
int main() {
    int Count;
    FILE* InputFile = fopen("input.txt", "r");
    fscanf(InputFile, "%d", &Count);
 
    int* Numbers = malloc(Count*sizeof(int));
    for (int i = 0; i < Count; i++) {
        fscanf(InputFile, "%d", &Numbers[i]);
    }
 
    quicksort(Numbers, 0, Count-1);
    FILE* OutputFile = fopen("output.txt", "w");
    for (int i = 0; i < Count; i++) {
        fprintf(OutputFile, "%d ", Numbers[i]);
    }
    free(Numbers);
}