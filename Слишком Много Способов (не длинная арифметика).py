from math import factorial

with open("input.txt", "r") as input_file:
	input = [int(i) for i in input_file.read().split()]

distance = [abs(input[i] - input[i+3]) for i in range(3)]
result = factorial(sum(distance)) // (factorial(distance[0]) * factorial(distance[1]) * factorial(distance[2]))

with open("output.txt", "w") as output_file:
	output_file.write(str(result%(10**9 + 7)))