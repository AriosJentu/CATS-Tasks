input = []
with open("input.txt", "r") as input_file:
	for i in input_file:
		input.append([int(j) for j in i.split()])

count, size = input[0]
numbers = input[1]

result = [0 for _ in range(count)]
max_lin_seq = [[0 for _ in range(size+1)] for _ in range(count+1)]

for i in range(1, count+1):
	
	for j in range(size+1):
		
		if numbers[i-1] <= j:

			max_lin_seq[i][j] = max(max_lin_seq[i-1][j], max_lin_seq[i-1][j-numbers[i-1]] + numbers[i-1])
	
		else:
	
			max_lin_seq[i][j] = max_lin_seq[i-1][j]

horz_index, vert_index = count, size

with open("output.txt", "w") as output_file:
	if max_lin_seq[count][size] == size:
		while max_lin_seq[horz_index][vert_index] != 0:

			if max_lin_seq[horz_index-1][vert_index] == max_lin_seq[horz_index][vert_index]:
	
				horz_index -= 1

			else:

				result[horz_index-1] = 1
				vert_index -= numbers[horz_index-1]
				horz_index -= 1

		for i in range(count):

			output_file.write(str(result[i]) + " ")
	else:
		output_file.write("-1")