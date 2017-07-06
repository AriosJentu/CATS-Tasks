class maximals:
    def __init__(self):
        self.indexes = {}
        self.values = {}
        self.left = 0
        self.right = 0

with open("input.txt", "r") as input_file:
	input = input_file.read().split()

count = int(input[0])
queries = int(input[count+1])
numbers = [int(i) for i in input[1:count+1]]

maxes = maximals()
maxes.indexes[0] = 0
maxes.values[0] = numbers[0]
maxes.right += 1

left_s, right_s = 0, 0

with open("output.txt", "w") as output_file:
	for i in input[-1]:
		if i == "L":
                    
			if maxes.indexes[maxes.left] == left_s:
				maxes.left += 1
			left_s += 1

		else:

			right_s += 1
			while maxes.right-maxes.left > 0 and (maxes.values[maxes.right-1] < numbers[right_s]):
				maxes.right -= 1

			maxes.indexes[maxes.right] = right_s
			maxes.values[maxes.right] = numbers[right_s]
			maxes.right += 1

		output_file.write("%i "%(maxes.values[maxes.left]))