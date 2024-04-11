n = int(input())
for i in range (0, n):
    s = input()
    l = len(s)
    if l <= 10:
        print(s)
        continue
    print(f"{s[0]}{l - 2}{s[-1]}")