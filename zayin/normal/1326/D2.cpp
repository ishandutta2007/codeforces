#include<bits/stdc++.h>
#define maxc 26
#define maxn 1000060
#define modu 1000000007
using namespace std;
typedef long long LL;

int all,text[maxn];
int sz,last;

int len[maxn],diff[maxn];
int fail[maxn],anc[maxn];
int ch[maxn][maxc];

int occ[maxn];
bool occur[maxn][maxc];

int info[maxn];

int newnode(int l)  {
    len[sz]=l;
    fail[sz]=anc[sz]=diff[sz]=0;
    memset(ch[sz],0,sizeof(ch[sz]));
    return sz++;
}

void init() {
    sz=last=all=0;
    newnode(0),newnode(-1);
    fail[0]=1;
    text[0]=-1;
}

int getfail(int x)  {
    for (;text[all-1-len[x]]!=text[all];) 
        x=fail[x];
    return x;
}

void extend(int w)  {
    text[++all]=w;
    int x=getfail(last);
    if (!ch[x][w])  {
        int y=newnode(len[x]+2);
        memcpy(occur[y],occur[x],sizeof(occur[y]));
        occ[y]=occ[x]+!occur[y][w],occur[y][w]=1;

        fail[y]=ch[getfail(fail[x])][w];
        ch[x][w]=y;
        diff[y]=len[y]-len[fail[y]];
        anc[y]=(diff[y]==diff[fail[y]]?anc[fail[y]]:fail[y]);
    }
    last=ch[x][w];
}

int n;
char s[maxn],t[maxn];
int ed[maxn];

int find(int i,int lim) {
    for (int j=ed[i];len[j]>0;j=anc[j])  {
        if (len[j]<=lim) return len[j];
        int t=len[anc[j]]+diff[j];
        if (t<=lim) return t+(lim-t)/diff[j]*diff[j];
    }
    assert(0);
}

int main()  {

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1),n=strlen(s+1);


        int l=1,r=n;
        while (l<=n&&s[l]==s[r])    ++l,--r;

        if (l>n)
            printf("%s\n",s+1);
        else    {

            int pl=l,pr=r;

            init();
            for (int i=1;i<=n;++i)  
                extend(s[i]-'a'),ed[i]=last;
            if (len[last]>n-(pr-pl+1))
                pl=1,pr=n-len[last];
            
            for (int i=r+1;i<=n;++i)    {
                int t=find(i-1,n-2*(n-i+1));
                if (2*(n-i+1)+t>n-(pr-pl+1))
                    pl=n-i+2,pr=i-t-1;
            }

            reverse(s+1,s+n+1);
            init();
            for (int i=1;i<=n;++i)  
                extend(s[i]-'a'),ed[i]=last;
            if (len[last]>n-(pr-pl+1))
                pl=len[last]+1,pr=n;
            
            for (int i=r+1;i<=n;++i)    {
                int t=find(i-1,n-2*(n-i+1));

                if (2*(n-i+1)+t>n-(pr-pl+1))
                    pr=n-(n-i+2)+1,pl=n-(i-t-1)+1;

            }
            
            reverse(s+1,s+n+1);

            for (int i=1;i<=n;++i)  {
                if (pl<=i&&i<=pr) continue;
                putchar(s[i]);
            }
            puts("");

        }
    }
    return 0;
}