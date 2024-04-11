n=int(raw_input())
fs=[]
for i in range(n):
	s=raw_input().strip()
	s=s[4:].strip()
	name=s[:s.find('(')].strip()
	lst=s[s.find('(')+1:s.find(')')].split(',')
	lst=map(lambda a:a.strip(),lst)
	fs.append((name,lst))
	#print name,lst
	
m=int(raw_input())
tp={}
for i in range(m):
	a,b=raw_input().split()
	tp[b]=a
k=int(raw_input())
for i in range(k):
	s=raw_input().strip()
	name=s[:s.find('(')].strip()
	lst=s[s.find('(')+1:s.find(')')].split(',')
	lst=map(lambda a:tp[a.strip()],lst)
	#print name,lst
	ret=0
	for a,b in fs:
		if a!=name or len(b) != len(lst):
			continue
		for i in range(len(b)):
			if b[i]!='T' and b[i]!=lst[i]:
				break
		else:
			ret+=1
	print ret