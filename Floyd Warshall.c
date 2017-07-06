#include <stdio.h>

#define MAXINT 1000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    FILE* InputFile = fopen("input.txt", "r");

    int Verts, Edgs;
    fscanf(InputFile, "%i %i", &Verts, &Edgs);

    int Graph[Verts][Verts];
    for (int i = 0; i < Verts; i++) {

        for (int j = 0; j  < Verts; j++) {

            Graph[i][j] = MAXINT;
        }

        Graph[i][i] = 0;
    }

    for (int i = 0; i < Edgs; i++) {

        int VertS, VertE, Weight;
        fscanf(InputFile, "%i %i %i", &VertS, &VertE, &Weight);
        Graph[VertS-1][VertE-1] = Weight;
    }
    fclose(InputFile);

    for (int i = 0; i < Verts; i++) {

        for (int j = 0; j < Verts; j++) {

            for (int k = 0; k < Verts; k++) {

                if (Graph[j][i] < MAXINT && Graph[i][k] < MAXINT) {

                    Graph[j][k] = min( Graph[j][k], Graph[j][i] + Graph[i][k]);
                }
            }
        }
    }

    FILE* OutputFile = fopen("output.txt", "w");
    for (int i = 0; i < Verts; i++) {

        for (int j = 0; j < Verts; j++) {

            if (Graph[i][j] != MAXINT) {

                printf("%i ", Graph[i][j]);
                fprintf(OutputFile, "%i ", Graph[i][j]);
            } else {

                printf("  ");
                fprintf(OutputFile, "  ");
            }
        }
        printf("\n");
        fprintf(OutputFile, "\n");
    }

    return 0;
}