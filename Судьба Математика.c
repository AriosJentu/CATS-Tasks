#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 6
#define MAX_NUMBER 999999

typedef struct conds {
	int Left;
	int Right;
	char Sign[3];
} conds;

/*int get_num(int InnerNum, int Index) {

	char Number[6];
	sprintf(Number, "%i\0", InnerNum);

	int Len = strlen(Number);
	if (MAX_LENGTH - Index > Len) {
		return 0;
	} else {
		return Number[Index - (6-Len)] - '0';
	}
}*/

void ConvertNumber(int Number, char* Result) {

	if (Number > ( (int) MAX_NUMBER/10 )) {

		sprintf(Result, "%i\0", Number);
		return;
	}

	char str[MAX_LENGTH];
	sprintf(str, "%i\0", Number);

	int indx = 0;
	for (int i = 0; i < MAX_LENGTH-strlen(str); i++) {
		Result[indx] = '0';
		indx++;
	}
	for (int i = 0; i < strlen(str); i++) {
		Result[indx] = str[i];
		indx++;
	}
	Result[indx] = '\0';
}

int main() {

	FILE* InputFile = fopen("input.txt", "r");
	char Line[4];
	int ArSize = 0;

	conds Array[30];

	while (fscanf(InputFile, "%s", Line) != EOF) {
	
		Array[ArSize].Left = Line[0]-'1';
		if (strlen(Line) == 3) {
			Array[ArSize].Right = Line[2]-'1';
			Array[ArSize].Sign[0] = Line[1];
			Array[ArSize].Sign[1] = '\0';
		} else {
			Array[ArSize].Right = Line[3]-'1';
			Array[ArSize].Sign[0] = Line[1];
			Array[ArSize].Sign[1] = Line[2];
			Array[ArSize].Sign[2] = '\0';
		}
		ArSize++;

	}
	fclose(InputFile);
	char StrNumber[6];
	
	int IsProper;

	int Result = 0;
	for (int i = 0; i <= MAX_NUMBER; i++) {
		
		ConvertNumber(i, StrNumber);
		IsProper = 1;

		for (int j = 0; j <= ArSize; ++j) {

			if (Array[j].Sign[0] == '>' && Array[j].Sign[1] == '=') {
				
				IsProper = (StrNumber[ Array[j].Left ] >= StrNumber[ Array[j].Right ] ? 1 : 0);
			
			} else if (Array[j].Sign[0] == '<' && Array[j].Sign[1] == '=') {
				
				IsProper = (StrNumber[ Array[j].Left ] <= StrNumber[ Array[j].Right ] ? 1 : 0);

			} else if (Array[j].Sign[0] == '<' && Array[j].Sign[1] == '>') {
			
				IsProper = (StrNumber[ Array[j].Left ] != StrNumber[ Array[j].Right ] ? 1 : 0);
			
			} else if (Array[j].Sign[0] == '>') {
				
				IsProper = (StrNumber[ Array[j].Left ] > StrNumber[ Array[j].Right ] ? 1 : 0);
			
			} else if (Array[j].Sign[0] == '<') {
				
				IsProper = (StrNumber[ Array[j].Left ] < StrNumber[ Array[j].Right ] ? 1 : 0);

			} else if (Array[j].Sign[0] == '=') {
			
				IsProper = (StrNumber[ Array[j].Left ] == StrNumber[ Array[j].Right ] ? 1 : 0);
			}

			if (IsProper == 0) {
				break;
			}
		}

		if (IsProper == 1) {
			Result++;
		}
	}
	printf("%i\n", Result);

	FILE* OutputFile = fopen("output.txt", "w");
	fprintf(OutputFile, "%i\0", Result);
	fclose(OutputFile);
}