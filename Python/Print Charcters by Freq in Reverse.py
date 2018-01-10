str = input()

arr = {}
for char in str:
	if not char in arr:
		arr[char] = 1
	else:
		arr[char] += 1

arr = sorted(arr.items(), key=lambda x: (-x[1], x[0]))

for k,v in arr:
	print(k*v)