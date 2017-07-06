#include <stdio.h>
#include <stdlib.h>

#define MAXINT 1000000

int min(int x, int y) {
	return (x < y ? x : y);
}

int max(int x, int y) {
	return (x > y ? x : y);
}

int main() {

	FILE* InputFile = fopen("input.txt", "r");
	int EmptyW, FullW, Count;
	fscanf(InputFile, "%i %i %i", &EmptyW, &FullW, &Count);

	int Weight[Count];
	int Nominal[Count];

	for (int i = 0; i < Count; i++) {

		fscanf(InputFile, "%i %i", &Nominal[i], &Weight[i]);
	}
	fclose(InputFile);

	int DiffW = FullW - EmptyW;
	int MinSum[Count+1][DiffW+1];

	MinSum[0][0] = 0;
	for (int i = 1; i <= DiffW; i++) {		
		MinSum[0][i] = MAXINT;
	}

	for (int i = 1; i <= Count; i++) {
		
		for (int j = 0; j <= DiffW; j++) {
			
			MinSum[i][j] = MinSum[i-1][j];
			int start = j/Weight[i-1];

			for (int k = start; k > 0; k--) {
		
				if (k*Weight[i-1] <= j) {
		
					int minimal = MinSum[i-1][j - k*Weight[i-1]] + k*Nominal[i-1];
					MinSum[i][j] = min(MinSum[i][j], minimal);
				}
			}
		}
	}

	FILE* OutputFile = fopen("output.txt", "w");
 	
	printf("%i\n", MinSum[Count][DiffW]);
	if (MinSum[Count][DiffW] != MAXINT) {

		fprintf(OutputFile, "%i", MinSum[Count][DiffW]);
	} else {

		fprintf(OutputFile, "-1");
	}
	fclose(OutputFile);
}