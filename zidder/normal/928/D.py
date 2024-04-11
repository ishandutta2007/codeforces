class Ddict:
    def __init__(self):
        self.dicts={}
    def add(self,key):
        d=self.dicts
        for i in key:
            if i not in d:
                d[i]={}
            d=d[i]
        d[' ']=''
    def find(self,key):
        if key=='':
            return '',''
        d=self.dicts
        q=[]
        h=[key[0]]
        for i in key:
            if i not in d:
                if ' ' in d and len(d)==1:
                    return ''.join(q),''.join(h)
                return '',''
            q.append(i)
            if len(d)!=1:
                h=q[:]
            d=d[i]
        if ' ' in d and len(d)==1:
            return ''.join(q),''.join(h)
        return '',''
words = Ddict()
ans=0
while True:
    try:
        x=input()
        if not x:
            break
    except:
        break
    ans+=len(x)+1
    ws=[[]]
    for i in x:
        if i in '.,?!\'- ':
            if ws[-1]:
                ws.append([])
        else:
            ws[-1].append(i)
    ws=list(map(lambda e:''.join(e),ws))
    for w in ws:
        next_word,helped_word = words.find(w)
        if next_word and next_word!=helped_word:
            ans-=len(next_word)-len(helped_word)-1
        words.add(w)
print(ans)