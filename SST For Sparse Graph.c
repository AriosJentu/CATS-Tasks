#include <stdio.h>
#include <stdlib.h>

#define MAXINT 100000

typedef struct {

	int from, to, weight;

} edge;

///

int edge_prnt[MAXINT];
edge edges_arr[MAXINT];

void ex_qsort(int left, int right) {

	int i = left, j = right;
	int mid = edges_arr[ (int) (i+j) / 2 ].weight;

	while (i <= j) {

		while (edges_arr[i].weight < mid) {

			i++;
		}

		while (mid < edges_arr[j].weight) {

			j--; 
		}

		if (i <= j) {

			edge tmp = edges_arr[i];
			edges_arr[i] = edges_arr[j];
			edges_arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j) {

		ex_qsort(left, j);
	}  

	if (i < right) {

		ex_qsort(i, right);
	}
}

int search(int edge_n) {

	printf("EDGE: %i\n", edge_n);
	if (edge_n == edge_prnt[edge_n]) {

		return edge_n;

	} else {

		edge_prnt[edge_n] = search(edge_prnt[edge_n]);
		return edge_prnt[edge_n];
	}

}

int main() {

	FILE* input_file = fopen("input.txt", "r");
	int n, m;
	fscanf(input_file, "%i %i", &n, &m);

	for (int i = 0; i < MAXINT; edge_prnt[i] = (++i));

	for (int i = 0; i < m; i++) {

		int start, end, weight;
		fscanf(input_file, "%i %i %i", &start, &end, &weight);

		edges_arr[i].from = start-1;
		edges_arr[i].to = end-1;
		edges_arr[i].weight = weight;

	}
	fclose(input_file);

	ex_qsort(0, m-1);

	int res_weight = 0, count = 1;
	for (int i = 0; i < m; i++) {

		if (search(edges_arr[i].from) != search(edges_arr[i].to)) {

			res_weight += edges_arr[i].weight;
			count++;

			edges_arr[i].from = search(edges_arr[i].from);
			edges_arr[i].to = search(edges_arr[i].to);

			if (edges_arr[i].from != edges_arr[i].to) {

				edge edge_n = edges_arr[i];
				edge_prnt[edge_n.to] = edge_n.from;
			}
		}
	}

	FILE* output_file = fopen("output.txt", "w");
	fprintf(output_file, "%i", count == n ? res_weight : -1);
	fclose(output_file);
}