import random


def random_int_element():
	return random.randint(-10, 10000)


if __name__ == '__main__':
	path = input('Enter file name: ')
	amount = int(input('Enter amount of numbers: '))
	new_int_string = open(path,'w')
	for number in range(amount-1):
		new_int_string.write(str(random_int_element()) + ' ')
	new_int_string.write(str(random_int_element()))
	new_int_string.close()
