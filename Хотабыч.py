with open("input.txt", "r") as input_file:
	input = input_file.read().split()

count = int(input[0])
query = int(input[count+1])

colors = {}
for i in range(count):
	if input[i+1] in colors:
		colors[input[i+1]].append(i)
	else:
		colors[input[i+1]] = [i]

output_file = open("output.txt", "w")
for i in range(query):

	col_indx = count+2 + (2*i)
	col1, col2 = input[col_indx], input[col_indx+1]

	if (col1 not in colors) or (col2 not in colors):
		output_file.write("-1\n")
		continue

	if col1 == col2:

		if len(colors[col1]) == 1:
			output_file.write("-2\n")
			continue			

		min_dist = count+1
		for j in range(len(colors[col1])-1):
			min_dist = min(min_dist, colors[col1][j+1]-colors[col1][j])

		output_file.write("%i\n"%(min_dist-1))

	else:

		min_dist = count+1
		for j in range(len(colors[col1])):
			
			
			left, right = 0, len(colors[col2])-1
			while right-left > 1:

				mid = (left+right)//2
				
				if  colors[col1][j] > colors[col2][mid]:
					left = mid
				
				else:
					right = mid


			min_dist = min(min_dist, abs(colors[col1][j]-colors[col2][right]), abs(colors[col1][j]-colors[col2][left]))

		output_file.write("%i\n"%(min_dist-1))

output_file.close()