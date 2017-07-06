from math import ceil

with open("input.txt", "r") as input_file:
	input = [int(i) for i in input_file.read().split()]

print(input)
count = input[0]
del input[0]
MAXINT = 1000000000
max_index = 0

increm_seq = [MAXINT for _ in range(count+1)]
input_indexes = [0 for _ in range(count+1)]
sequience_indexes = [0 for _ in range(count+1)]
result = ""

if count > 1:
	increm_seq[0] = -MAXINT

	for i in range(count):
		left, right = 0, count

		while right-left > 1:
			middle = int(ceil((left+right) // 2))

			if increm_seq[middle] >= input[i]:
				right = middle
			else:
				left = middle

		input_indexes[i] = sequience_indexes[right-1]
		input_indexes[0] = -1
		sequience_indexes[right] = i
		increm_seq[right] = input[i]

		if right > max_index:
			max_index = right

	result = str(max_index)
	for i in range(max_index, 0, -1):
		sequience_indexes[i-1] = input_indexes[sequience_indexes[i]]
	for i in range(1, max_index+1):
		result += " "+str(sequience_indexes[i]+1)

else:
	if count == 1:
		result = "1 " + str(input[0])
	else:
		result = "0"

print(increm_seq)
print(input_indexes)
print(sequience_indexes)

print(result)
with open("output.txt", "w") as output_file:
	output_file.write(result)