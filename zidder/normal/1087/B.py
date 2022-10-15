def main():
	n, k =map(int, input().split())
	for i in reversed(range(1,k)):
		if n%i == 0:
			print(n//i*k+i)
			return
t = 1 # int(input())
for i in range(t):
	main()