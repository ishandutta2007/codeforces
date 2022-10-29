ls = ["Danil", "Olya", "Slava", "Ann" , "Nikita"]
s=input()
cnt = 0
for i in ls :
    cnt += s.count(i)
if cnt == 1:
    print('YES')
else :
    print('NO')