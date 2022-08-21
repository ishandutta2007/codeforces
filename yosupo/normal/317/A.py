# -*- coding: utf-8 -*-

def main():
	x, y, m = map(int, input().split())
	b1 = min(x, y)
	b2 = max(x, y)
	count = 0
	if b2 >= m:
		return 0
	if b2 <= 0:
		return -1
	if b1 < 0:
		count = (b2 - b1 + (b2 - 1)) // b2
		b = b2
		b2 = b1 + count * b2
		b1 = b
	while b2 < m:
		b = b1 + b2
		b1 = min(b2, b)
		b2 = max(b2, b)
		count += 1
	return count

if __name__ == '__main__':
	print('{:#d}'.format(main()))