p = [0, 5, 3, 2, 4, 1]
# p = [0, 3, 5, 2, 4, 1]
s = bin(int(input()))[2:].zfill(6)
print(int("".join([s[x] for x in p]), 2))