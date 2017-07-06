#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

void AddChar(char* str, char chr, int len) {
	for (int i = len-1; i >= 0; i--) {
		*(str+i+1) = *(str+i);
	} 
	*(str) = chr;
}

void MaximalLength(int** InputArr, char* str1, char* str2, int l1, int l2) {

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			
			if (str1[i] == str2[j]){
				InputArr[i+1][j+1] = max(InputArr[i][j]+1, InputArr[i+1][j+1]);
			}

			InputArr[i+1][j+1] = max(InputArr[i+1][j], InputArr[i+1][j+1]);
			InputArr[i+1][j+1] = max(InputArr[i][j +1], InputArr[i+1][j+1]);
		}
	}
}

int main() {

	FILE* InputFile = fopen("input.txt", "r");

	char Line1[1001];
	char Line2[1001];

	fscanf(InputFile, "%s\n", Line1);
	fscanf(InputFile, "%s", Line2);
	fclose(InputFile);

	int Len1 = strlen(Line1); 
	int Len2 = strlen(Line2);

	int** Array = (int**) calloc((Len1+1), sizeof(int*));
	for (int i = 0; i <= Len1; i++) {
		
		Array[i] = (int*) calloc((Len2+1), sizeof(int));
		Array[i][0] = 0;
	
	}
 
	for (int i = 0; i < Len2; i++){
		Array[0][i] = 0;
	}
 
 	MaximalLength(Array, Line1, Line2, Len1, Len2);
 	int Iterations = Array[Len1][Len2];
 	int StrSize = Iterations;
	char Result[StrSize];

	int It1 = Len1-1;
	int It2 = Len2-1;
 
	while (Iterations != 0 && It1 >= 0 && It2 >= 0) {
		if (Line1[It1] == Line2[It2]) {

			AddChar(Result, Line1[It1], StrSize);
			printf("%c\n", Line1[It1]);
			It1--; 
			It2--; 
			Iterations--;

		} else {

			if (Array[It1+1][It2+1] == Array[It1][It2+1]){
				It1--;
			
			} else if (Array[It1+1][It2+1] == Array[It1+1][It2]) {			
				It2--;
			}
		}
	}
	Result[StrSize] = '\0';

	printf("Res: '%s'\n", Result);
	FILE* OutputFile = fopen("output.txt", "w");
	fprintf(OutputFile, "%s", Result);
	fclose(OutputFile);
 
}