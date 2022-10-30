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

LL sum[maxn];

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
        fail[y]=ch[getfail(fail[x])][w];
        ch[x][w]=y;
        diff[y]=len[y]-len[fail[y]];
        anc[y]=(diff[y]==diff[fail[y]]?anc[fail[y]]:fail[y]);
    }
    last=ch[x][w];
}

int n;
char s[maxn],t[maxn];

LL dp[maxn];

int main()  {
    scanf("%s",s+1),n=strlen(s+1);
    if (n&1) return puts("0"),0;

    for (int i=1;i<=n/2;++i) t[i*2-1]=s[i];
    for (int i=n;i>n/2;--i) t[(n-i+1)*2]=s[i];
    // printf("%s\n",t+1);

    init();
    dp[0]=1;
    for (int i=1;i<=n;++i)  {
        // cout<<"i:"<<i<<endl;
        extend(t[i]-'a');
        for (int j=last;len[j]>0;j=anc[j])  {
            // cout<<"pro:"<<i<<" "<<j<<endl;
            sum[j]=dp[i-len[anc[j]]-diff[j]];
            if (diff[j]==diff[fail[j]])
                sum[j]=(sum[j]+sum[fail[j]])%modu;
            if (~i&1)
                dp[i]=(dp[i]+sum[j])%modu;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}