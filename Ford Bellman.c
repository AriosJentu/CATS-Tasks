#include <stdio.h>

#define MAXINT 1000000

#define SRT 0
#define END 1
#define WEI 2

int min(int a, int b) {
	return (a < b ? a : b);
}

int main() {

	FILE* InputFile = fopen("input.txt", "r");
	int Verts, Edges, Start;
	fscanf(InputFile, "%i %i %i", &Verts, &Edges, &Start);
	Start--;

	int Graph[Edges][3];
	for (int i = 0; i < Edges; i++) {

		int StartPoint, EndPoint, Weight;
		fscanf(InputFile, "%i %i %i", &StartPoint, &EndPoint, &Weight);
		Graph[i][SRT] = StartPoint-1;
		Graph[i][END] = EndPoint-1;
		Graph[i][WEI] = Weight;
	}

	int Answers[Verts];

	for (int i = 0; i < Verts; i++) {

		Answers[i] = MAXINT;
	}
	Answers[Start] = 0;

	for (int i = 0; i < Verts-1; i++) {

		for (int j = 0; j < Edges; j++) {

			if (Answers[ Graph[j][SRT] ] < MAXINT) {

				int AnothMin = Answers[ Graph[j][SRT] ] + Graph[j][WEI];
				Answers[ Graph[j][END] ] = min(Answers[ Graph[j][END] ], AnothMin);
			}
		}
	}

	FILE* OutputFile = fopen("output.txt", "w");
	for (int i = 0; i < Verts; i++) {

		if (Answers[i] != MAXINT) {

			fprintf(OutputFile, "%i ", Answers[i]);

		} else {

			fprintf(OutputFile, "  ");
		}
	}

	return 0;
}