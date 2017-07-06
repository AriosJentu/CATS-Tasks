#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAXINT 1000000

typedef struct {
	int end, weight;
} edge;

int main() {
	FILE* input_file = fopen("input.txt", "r");
	
	int verts, edges, start;
	fscanf(input_file, "%i %i %i", &verts, &edges, &start);

	int dynamic[verts];
	bool visited[verts];
	map <int, vector <edge>> graph;

	for (int i = 0; i < verts; i++) {
		dynamic[i] = MAXINT;
		visited[i] = false;
	}
	dynamic[start-1] = 0;

	for (int i = 0; i < edges; i++) {
		int start, end, weight;
		fscanf(input_file, "%i %i %i", &start, &end, &weight);
		edge x;
		x.end = end-1;
		x.weight = weight;
		graph[start-1].push_back(x);
	}
	fclose(input_file);

	for (int i = 0; i < verts; i++) {
		int vert = -1;
		for (int j = 0; j < verts; j++) {
			if (not visited[j] and (vert == -1 or dynamic[j] < dynamic[vert])) {
				vert = j;
			}
		}
		if (dynamic[vert] == MAXINT) {
			break;
		}
		visited[vert] = true;
		for (int j = 0; j < graph[vert].size(); j++) {
			int end = graph[vert][j].end;
			int weight = graph[vert][j].weight;

			if (dynamic[vert] + weight < dynamic[end]) {
				dynamic[end] = dynamic[vert] + weight;
			}
		}
	}

	FILE* output_file = fopen("output.txt", "w");
	for (int i = 0; i < verts; i++) {

		if (dynamic[i] == MAXINT) {
			fprintf(output_file, "-1 ");
		} else {
			fprintf(output_file, "%i ", dynamic[i]);
		}
	}
}