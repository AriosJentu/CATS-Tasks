def convert_to_binary(index, code_size):
	result = ""
	while index != 0:
		result = str(index%2) + result
		index //= 2

	if len(result) <= code_size:
		result = ("0"*(code_size-len(result))) + result
	else:
		return False

	return result.replace("0", "-").replace("1", "+")

def similar_count(str1, str2):
	sim_count = 0
	for i in range(len(str1)):
		if str1[i] == str2[i]:
			sim_count += 1

	return sim_count

with open("input.txt", "r") as input_file:
	input = input_file.read().split()

code_size = int(input[1])
responces = []
for i in range(2, len(input), 2):
	responces.append([input[i], int(input[i+1])])

#print(responces)

iteration = 0
is_found = False
result = ""
while not is_found and iteration < 2**code_size:
	
	responce = convert_to_binary(iteration, code_size)
	iteration += 1
	flag = False

	for i in responces:
		if similar_count(responce, i[0]) != i[1]:
			flag = True
			break

	if not flag:
		result = responce
		is_found = True

#print(result)
with open("output.txt", "w") as output_file:
	output_file.write(result)
