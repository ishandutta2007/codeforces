#include<bits/stdc++.h>
#define maxs 3
#define maxn 200050
using namespace std;

const char* Str="PRS";

int n,m;

char s[maxn],t[10];

struct node
{
    set<int> pos;
    int T[maxn];

    node()  {
        pos.clear();
        memset(T,0,sizeof(T));
    }

    int size()  const {   return pos.size();  }
    int left()  const {   return *pos.begin();  }
    int right() const {   return *pos.rbegin();  }

    int lowbit(int x)   const { return x&(-x);  }

    int count(int l,int r) const {
        if (l>r)    return 0;
        int ans=0;
        for (;r;r-=lowbit(r))
            ans+=T[r];
        for (--l;l;l-=lowbit(l))
            ans-=T[l];
        return ans;
    }

    void insert(int x)  {
        pos.insert(x);
        for (;x<=n;x+=lowbit(x))
            ++T[x];
    }

    void erase(int x)   {
        pos.erase(x);
        for (;x<=n;x+=lowbit(x))
            --T[x];
    }

} S[3];

int chr(char c)
{
    for (int i=0;i<maxs;++i)
        if (Str[i]==c)
            return i;
}

void init()
{
    scanf("%d%d%s",&n,&m,s+1);
    for (int i=1;i<=n;++i)
        S[chr(s[i])].insert(i);
}

int calc(const node& A,const node& B,const node& C)
{
    if (!C.size())  return A.size();
    if (!B.size())  return 0;
    int l1=C.left(),r1=C.right();
    int l2=B.left(),r2=B.right();

    // cout<<"("<<l1<<","<<r1<<") ("<<l2<<","<<r2<<")"<<endl;
    return A.size()-A.count(l1,l2)-A.count(r2,r1);
}

int Ans()
{
    return calc(S[0],S[1],S[2])+calc(S[1],S[2],S[0])+calc(S[2],S[0],S[1]);
}

void solve()
{
    printf("%d\n",Ans());
    while (m--)
    {
        int i;
        scanf("%d%s",&i,t);
        S[chr(s[i])].erase(i);
        s[i]=*t;
        S[chr(s[i])].insert(i);

        printf("%d\n",Ans());
    }
}

int main()
{
    init();
    solve();
    return 0;
}