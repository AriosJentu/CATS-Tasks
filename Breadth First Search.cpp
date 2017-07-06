#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    FILE* InputFile = fopen("input.txt", "r");
    int Edges, Verts, Start;
    fscanf(InputFile, "%i %i %i", &Verts, &Edges, &Start);

    vector <vector <int> > Graph(Verts);

    for (int i = 0; i < Edges; i++) {

        int Source, End;
        fscanf(InputFile, "%i %i", &Source, &End);

        Graph[Source-1].push_back(End-1);
        Graph[End-1].push_back(Source-1);
    }
    fclose(InputFile);

    queue <int> VertxQueue;
    int Result[Verts];

    bool Used[Verts];

    for (int i = 0; i < Verts; i++) {

        Used[i] = false;
    }

    VertxQueue.push(Start-1);
    Used[Start - 1] = true;
    int index = 0;
    Result[0] = Start;

    while (!VertxQueue.empty()) {

        int CurrentVertx = VertxQueue.front();
        VertxQueue.pop();

        for (int i = 0; i < Graph[CurrentVertx].size(); i++) {

            int Dest = Graph[CurrentVertx][i];

            if (!Used[Dest]) {

                VertxQueue.push(Dest);
                index++;
                Result[index] = Dest+1;
                Used[Dest] = true;
            }
        }
    }

    FILE* OutputFile = fopen("output.txt", "w");
    if (index+1 == Verts) {
        for (int i = 0; i < Verts; i++) {
            printf("%i ", Result[i]);
            fprintf(OutputFile, "%i ", Result[i]);
        }
    } else {
        printf("-1");
        fprintf(OutputFile, "-1");
    }
    fclose(OutputFile);
}