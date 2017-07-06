#include <stdio.h>
#include <stdlib.h>

#define MAXINT 1000000000

int min(int x, int y) {
	return (x < y ? x : y);
}

int max(int x, int y) {
	return (x > y ? x : y);
}

int main() {

	FILE* InputFile = fopen("input.txt", "r");

	int Count, RemoveCount;
	fscanf(InputFile, "%i %i", &Count, &RemoveCount);

	int Aquariums[Count];
	for (int i = 0; i < Count; i++) {

		fscanf(InputFile, "%i", &Aquariums[i]);
	}

	int AquaMaxSeq[400][400];
	for (int i = 1; i <= RemoveCount; i++) {
	
		AquaMaxSeq[0][i] = MAXINT;
	}

	for (int i = 1; i < Count; i++) {
		for (int j = 0; j <= RemoveCount; j++) {

			AquaMaxSeq[i][j] = MAXINT;
			
			for (int k = 0; k <= min(i-1, j); k++) {
			
				int maximal = max(AquaMaxSeq[i-1-k][j-k], Aquariums[i]-Aquariums[i-1-k]);
				AquaMaxSeq[i][j] = min(AquaMaxSeq[i][j], maximal);
			}
		}
	}

	FILE* OutputFile = fopen("output.txt", "w");
	fprintf(OutputFile, "%i", AquaMaxSeq[Count-1][RemoveCount]);
	fclose(OutputFile);
}