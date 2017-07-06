#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (a<b?a:b)

int main() {
	FILE* InputFile = fopen("input.txt", "r");
	int Count;
	fscanf(InputFile, "%i", &Count);

	int Numbers[Count], Stack[Count], Coordinates[Count], Result[Count];
	for (int i = 0; i < Count; i++) {
		fscanf(InputFile, "%i", &Numbers[i]);
		Stack[i] = 0;
		Result[i] = 0;
	}
	fclose(InputFile);

	int Index = 0;
	Stack[Index] = Numbers[Count-1];
	Coordinates[Index] = Count-1;

	for (int i = Count-2; i >= 0; i--) {

		if (Numbers[i] < Stack[Index]) {
			Index++;

		} else {
			
			while (Index > -1 && Numbers[i] >= Stack[Index]) {
				Index--;
			}
			Index++;
		}
		if (Index > 0) {

			if (Result[i] > 0) {
				Result[i] = min(Result[i], abs(Coordinates[Index-1] - i));
			
			} else {
				Result[i] = abs(Coordinates[Index-1] - i);
			}
		}
		Stack[Index] = Numbers[i];
		Coordinates[Index] = i;

	}

	Stack[Index = 0] = Numbers[0];
	Coordinates[Index] = 0;

	for (int i = 1; i < Count; i++) {

		if (Numbers[i] < Stack[Index]) {
			Index++;
		
		} else {
			
			while (Index > -1 && Numbers[i] >= Stack[Index]) {
				Index--;
			}
			Index++;
		}
		if (Index > 0) {
			
			if (Result[i] > 0) {
				Result[i] = min(Result[i], i - Coordinates[Index-1]);

			} else {	
				Result[i] = i - Coordinates[Index-1];
			}
		}
		Stack[Index] = Numbers[i];
		Coordinates[Index] = i;
	}

	FILE* OutputFile = fopen("output.txt", "w");
	for (int i = 0; i < Count; i++) {
		//printf("%i ", Result[i]);
		fprintf(OutputFile, "%i ", Result[i]);
	}
	//printf("\n");
	fclose(OutputFile);
}