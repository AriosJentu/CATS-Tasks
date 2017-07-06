with open("diploma.in", "r") as input_file:
	count, width, height = [int(i) for i in input_file.read().split()]
	

a = 10e14
low = 0
rang = a

result = ""

#Binary Search
#while rang-low > 1:
#	middle = (low+rang)//2
#	if (middle//width)*(middle//height) < count:
#		low = middle
#	else:
#		rang = middle
#	print(low, rang)
#else:
#	result = int(rang)

def cycle(l, r, w=width, h=height, c=count):
	if r-l > 1:
		mid = (l+r)//2
		if (mid//w)*(mid//h) < c:
			return cycle(mid, r, w, h, c)
		else:
			return cycle(l, mid, w, h, c)
	else:
		return int(r)

with open("diploma.out", "w") as output_file:
	output_file.write(str(cycle(low, rang)))
