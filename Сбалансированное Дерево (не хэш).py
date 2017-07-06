with open('input.txt','r') as input_file:	
	input = [int(i) for i in input_file.read().split()]

size = len(input)
positives = []
index = 0
value = True

while value != 0 and index < size:
	value = input[index]
	if value > 0:
		positives.append(value)
	elif value < 0:
		if abs(value) in positives:
			positives.remove(abs(value))

	index += 1

sorted_array = sorted(set(positives))
result = ""
for i in sorted_array:
	result += "%s "%i

result = result[:-1]
with open('output.txt','w') as output_file:
	output_file.write(result)