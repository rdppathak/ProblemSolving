
def calculate_water_trapped(arr):
	array_size = len(arr)

	track_left = [0] * array_size
	track_right = [0] * array_size

	leftmax = 0
	for i in xrange(array_size):
		track_left[i] = leftmax

		if (arr[i]>leftmax):
			leftmax=arr[i]

	rightmax = 0
	for i in xrange(array_size):
		track_right[array_size-i-1] = rightmax

		if (arr[array_size-i-1] > rightmax):
			rightmax = arr[array_size-i-1]


	trapped_quantity = 0
	for i in xrange(array_size):
		trapped_quantity += max(0, min(track_left[i], track_right[i])-arr[i])

	print "Total water trapped: ", trapped_quantity

def main():
	arr= [0,1,0,2,1,0,1,3,2,1,2,1]
	calculate_water_trapped(arr)

if __name__ == '__main__':
	main()
