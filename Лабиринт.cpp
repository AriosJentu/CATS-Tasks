#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	
	int start;
	int end; 
	int depth;

} edge; 

bool is_valid(string matrix[], int start, int end) {
	return (matrix[start][end] != '#');
}

int main() {
	FILE* input_file = fopen("input.txt", "r");
	int count;
	fscanf(input_file, "%i", &count);

	string matrix[count];
	bool visited[count][count];

	for (int i = 0; i < count; i++) {
	
		char x[count];
		fscanf(input_file, "%s\n", &x);
		matrix[i] = x;
		
		for (int j = 0; j < count; j++) {
			visited[i][j] = false;
		}
	}
	fclose(input_file);

	visited[0][0] = true;

	//start, end, depth

	queue <edge> mat_que;
	edge x;
	x.start = 0;
	x.end = 0;
	x.depth = 0;
	mat_que.push(x);

	bool found = false;
	FILE* output_file = fopen("output.txt", "w");
	while (mat_que.size() > 0) {

		edge x = mat_que.front();
		int start = x.start;
		int end = x.end;
		int depth = x.depth;
		mat_que.pop();

		if (start == count-1 && end == count-1) {
			fprintf(output_file, "%i", depth);
			found = true;
			break;
		}

		if (start > 0 && is_valid(matrix, start-1, end)) {
			if (not visited[start-1][end]) {
				visited[start-1][end] = true;
				x.start = start-1;
				x.end = end;
				x.depth = depth+1;
				mat_que.push(x);
			}
		}

		if (end > 0 && is_valid(matrix, start, end-1)) {
			if (not visited[start][end-1]) {
				visited[start][end-1] = true;
				x.start = start;
				x.end = end-1;
				x.depth = depth+1;
				mat_que.push(x);
			}
		}

		if (start < count-1 && is_valid(matrix, start+1, end)) {
			if (not visited[start+1][end]) {
				visited[start+1][end] = true;
				x.start = start+1;
				x.end = end;
				x.depth = depth+1;
				mat_que.push(x);
			}
		}
		
		if (end < count-1 && is_valid(matrix, start, end+1)) {
			if (not visited[start][end+1]) {
				visited[start][end+1] = true;
				x.start = start;
				x.end = end+1;
				x.depth = depth+1;
				mat_que.push(x);
			}
		}
	}

	if (not found) {
		
		fprintf(output_file, "-1");
	}
	fclose(output_file);
} 