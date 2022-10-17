s = raw_input() + raw_input() + raw_input()
for i in range(5):
    if s[i] != s[8 - i]:
        print 'NO'
        exit()
print 'YES'