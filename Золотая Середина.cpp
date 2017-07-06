#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

int min(int a, int b) {
	return (a < b ? a : b);
}
int max(int a, int b) {
	return (a > b ? a : b);
}

vector <int> minheap;
vector <int> maxheap;

void max_sift_up(int element) {

	maxheap.push_back(element);
	int indx = maxheap.size()-1;
	int div_indx = (int) (indx-1)/2;

	while (maxheap[indx] > maxheap[div_indx]) {
		
		swap(&maxheap[indx], &maxheap[div_indx]);
		indx = div_indx;
		div_indx = (int) (indx-1)/2;

		if (indx <= 0) {
			break;
		}
	}	
}

void min_sift_up(int element) {
	minheap.push_back(element);
	int indx = minheap.size()-1;
	int div_indx = (int) (indx-1)/2;

	while (minheap[indx] < minheap[div_indx]) {
		
		swap(&minheap[indx], &minheap[div_indx]);
		indx = div_indx;
		div_indx = (int) (indx-1)/2;

		if (indx <= 0) {
			break;
		}
	}	
}

void max_sift_down() {

	min_sift_up(maxheap[0]);
	
	swap(&maxheap.front(), &maxheap.back());
	maxheap.pop_back();

	int indx = 0;
	while (2*indx+1 < maxheap.size()) {

		int max_child = maxheap[2*indx+1];
		int chld_indx = 2*indx+1;
		if (2*indx+2 < maxheap.size()) {

			max_child = max(max_child, maxheap[2*indx+2]);
			
			if (max_child == maxheap[2*indx+2]) {
				chld_indx = 2*indx+2;
			}
		}

		if (max_child >= maxheap[indx]) {
			swap(&maxheap[chld_indx], &maxheap[indx]);
			indx = chld_indx;
	
		} else {

			break;
		} 

	}
}

void min_sift_down() {

	max_sift_up(minheap[0]);
	
	swap(&minheap.front(), &minheap.back());
	minheap.pop_back();

	int indx = 0;
	while (2*indx+1 < minheap.size()) {

		int min_child = minheap[2*indx+1];
		int chld_indx = 2*indx+1;
		if (2*indx+2 < minheap.size()) {

			min_child = min(min_child, minheap[2*indx+2]);
			
			if (min_child == minheap[2*indx+2]) {
				chld_indx = 2*indx+2;
			}
		}

		if (min_child <= minheap[indx]) {
			swap(&minheap[chld_indx], &minheap[indx]);
			indx = chld_indx;
	
		} else {

			break;
		} 

	}
}

int main() {
	FILE* input_file = fopen("input.txt", "r");
	FILE* output_file = fopen("output.txt", "w");

	int count;
	fscanf(input_file, "%i", &count);

	int element;
	fscanf(input_file, "%i", &element);
	maxheap.push_back(element);
	
	fprintf(output_file, "%i ", element);

	for (int i = 0; i < count-1; i++) {
		fscanf(input_file, "%i", &element);

		if (maxheap[0] > element) {
			
			max_sift_up(element);
			if (maxheap.size() > minheap.size()+1) {
			
				max_sift_down();
			}

		} else {
			
			min_sift_up(element);
			if (maxheap.size() < minheap.size()) {
			
				min_sift_down();
			}

		}

		fprintf(output_file, "%i ", maxheap[0]);
	}
	fclose(input_file);
	fclose(output_file);

}