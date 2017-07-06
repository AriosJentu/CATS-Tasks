#include <stdio.h>

typedef struct {
	int width, height;
} figure;

figure figures[100];

int get_edges_scale(int width, int height) {
	return (2*width*height + width + height);
}

void set_result(FILE* output_file, int count_) {

	fprintf(output_file, "%i", count_);

	for (int i = 0; i < count_; i++) {
		fprintf(output_file, " %i %i", figures[i+1].height, figures[i+1].width);
	}

	fprintf(output_file, "\n");
}

void step(FILE* output_file, int width, int height, int depth, int border, int unused_count) {

	figures[depth].width = width;
	figures[depth].height = height;

	if (unused_count == 0) {
		set_result(output_file, depth);
	}

	for (int i = height; i < border+1; i++) {
		while (unused_count - get_edges_scale(i, width) >= 0) {
			if (i <= width) {
				step(output_file, width, i, depth+1, border, unused_count - get_edges_scale(width, i));
			}
			width++;
		}
		width = height + 1;
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	FILE* input_file = fopen("input.txt", "r");
	FILE* output_file = fopen("output.txt", "w");

	
	int count;
	int border;

	fscanf(input_file, "%i", &count);
	//cin >> count;

	while (get_edges_scale(border, border) < count) {
		border++;
	}
	step(output_file, 1, 1, 0, border, count);

	fclose(input_file);
	fclose(output_file);
}