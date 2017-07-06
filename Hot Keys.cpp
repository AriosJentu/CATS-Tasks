#include <iostream>
#include <string>
using namespace std;

#define MAXCAPTS 10

int max_pos = -1;
int cur_pos = -1;
int min_sum;
int cur_sum = 0;

int key_pos[MAXCAPTS];
int key_bst[MAXCAPTS];

void search_best(int start, int count, string lines[], bool ischanged[]) {

	if (start < count) {

		for (int i = 0; i < lines[start].length(); i++) {

			if (max_pos < count-1 or cur_sum+i < min_sum) {

				int chr = lines[start][i]-'a';
				if (not ischanged[chr]) {

					ischanged[chr] = true;
					key_pos[start] = i;
					cur_pos++;
					cur_sum += i;

					if (cur_pos+count-start-1 >= max_pos) {
						search_best(start+1, count, lines, ischanged);
					}

					ischanged[chr] = false;
					key_pos[start] = -1;
					cur_pos--;
					cur_sum -= i;
				}
	
			} else {

				break;
			}
		}

		if (max_pos < count-1) {
			search_best(start+1, count, lines, ischanged);
		}

	} else {

		if ((cur_sum < min_sum && cur_pos == max_pos) || cur_pos > max_pos) {
		
			max_pos = cur_pos;
			min_sum = cur_sum;

			for (int i = 0; i < count; i++) {
		
				key_bst[i] =  key_pos[i];
			}
		}

	}
}


int main() {

	FILE* input_file = fopen("input.txt", "r");
	int count;
	fscanf(input_file, "%i", &count);
	
	string lines[count];
	for (int i = 0; i < count; i++) {
		char buf[144];
		fscanf(input_file, "%s", &buf);
		lines[i] = buf;
		key_pos[i] = -1;
		key_bst[i] = -1;
	}
	fclose(input_file);

	bool ischanged[26];
	for (int i = 0; i < 26; i++) {
		ischanged[i] = false;
	}
	min_sum = count*20;

	search_best(0, count, lines, ischanged);

	FILE* output_file = fopen("output.txt", "w");
	for (int i = 0; i < count; i++) {

		if (key_bst[i] != -1) {

			for (int j = 0; j < lines[i].length(); j++) {
				if (j == key_bst[i]) {
					fprintf(output_file, "&");
				}
				fprintf(output_file, "%c", lines[i][j]);
			}
			fprintf(output_file, "\n");

		} else {
			
			fprintf(output_file, "%s\n", lines[i].c_str());
		}

	}
}