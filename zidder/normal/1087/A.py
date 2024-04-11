def main(s):
	s=list(s)
	q = [0] * len(s)
	start = (len(s)-1)//2
	d = 1
	q = []
	for i in range(len(s)):
		q.append(s[start])
		start += d
		d = (abs(d) + 1) * (-1 if d>0 else 1)
	return ''.join(q)

t = 1 # int(input())
for i in range(t):
	s=input()
	print(main(s))