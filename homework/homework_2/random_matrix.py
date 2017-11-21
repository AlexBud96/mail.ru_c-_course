import random


def matrix_element():
	random_array = [random.uniform(-100, 100) for i in range(4)]
	random_array.append(0)
	element = random.choice(random_array)
	return element

def create_matrix(row, col):
	Matrix = [[0 for x in range(col)] for y in range(row)] 
	for i in range(row):
		for j in range(col):
			Matrix[i][j] = matrix_element()
	return Matrix


if __name__ == '__main__':
	path = input('Enter file name: ')
	row = int(input('Enter the number of rows: '))
	col = int(input('Enter the number of columns: '))
	new_matrix = open(path,'w')
	new_matrix.write(str(row) + '\n')
	new_matrix.write(str(col) + '\n')
	Matrix = create_matrix(row, col)
	for i in range(row):
		for j in range(col):
			new_matrix.write('%.2f ' % (Matrix[i][j]))
		new_matrix.write('\n')
	new_matrix.close()
