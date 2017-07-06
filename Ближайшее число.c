#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* InputFile = fopen("input.txt", "r");
	int Count;
	fscanf(InputFile, "%d", &Count);

	int* Numbers = malloc(Count*sizeof(int));

	for (int i = 0; i < Count; i++) {
		fscanf(InputFile, "%d", &Numbers[i]);
	}
	fclose(InputFile);

	int* Maximal = malloc(Count*sizeof(int));
	int MaxIndex = 0;

	Maximal[0] = Numbers[Count-1];

	int* Result = malloc(Count*sizeof(int));
	
	Result[Count-1] = Numbers[Count-1];

	for (int i = Count-2; i >= 0; i--) {
		int x = Numbers[i];

		if (Numbers[i] < Maximal[MaxIndex]) {
			
			x = Maximal[MaxIndex];
			Maximal[++MaxIndex] = Numbers[i];
		
		} else if (Numbers[i] >= Maximal[MaxIndex]) {

			int left = 0, right = MaxIndex;

			if (Maximal[0] <= Numbers[i]) {
				right = 0;
			} else if (Numbers[i] == Maximal[MaxIndex]) {
				left = MaxIndex;
			}

			while ((right-left) > 1) {
				int mid = (int) ((right+left)/2);

				if (Maximal[mid] > Numbers[i]) {
					left = mid;
				} else {
					right = mid;
				}
			}

			MaxIndex = right;
			Maximal[right] = Numbers[i];

			if (right > 0) {
				x = Maximal[right-1];
			} else {
				x = Maximal[0];
			}

		}

		Result[i] = x;
	}
	free(Numbers);
	free(Maximal);

	char Res[5];
	FILE* OutputFile = fopen("output.txt", "w");
	for (int i = 0; i < Count; i++) {
		sprintf(Res, "%i ", Result[i]);
		fputs(Res, OutputFile);
	}
	free(Result);
	fclose(OutputFile);
}