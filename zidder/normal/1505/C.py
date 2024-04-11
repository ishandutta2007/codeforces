s = input()
for i in range(2, len(s)):
    if (ord(s[i-2]) + ord(s[i-1]) - 2 * ord('A')) % 26 != ord(s[i]) - ord('A'):
        print('NO')
        break
else:
    print('YES')