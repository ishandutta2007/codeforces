#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int nxt[1000010][30];
int fail[1000010];
int len[1000010];
int trans[1000010];
int a[1000010];
int f[1000010];
int cnt[1000010];
ll ans[1000010];
int p;
int n;
int last;
void init(int x)
{
    int i;
    for(i=1;i<=26;i++)
        nxt[x][i]=2;
}
void add(int x)
{
    a[++n]=x;
    while(a[n-len[last]-1]!=a[n])
        last=fail[last];
    int cur=last;
    if(nxt[cur][x]==2)
    {
        int now=++p;
        init(p);
        len[now]=len[cur]+2;
        last=fail[last];
        while(a[n-len[last]-1]!=a[n])
            last=fail[last];
        fail[now]=nxt[last][x];
        if(len[fail[now]]<=len[now]/2)//AC 
            trans[now]=fail[now];
        else
        {
            last=trans[cur];
            while(len[last]+2>len[now]/2||a[n-len[last]-1]!=a[n])
                last=fail[last];
            trans[now]=nxt[last][x];
        }
        nxt[cur][x]=now;
    }
    last=nxt[cur][x];
    cnt[last]++;
}
void solve()
{
    f[1]=0;
    f[2]=0;
    int i;
    for(i=3;i<=p;i++)
    	if(len[trans[i]]==len[i]/2)
	    	f[i]=f[trans[i]]+1;
	    else
	    	f[i]=1;
    for(i=p;i>=3;i--)
    	cnt[fail[i]]+=cnt[i];
    for(i=3;i<=p;i++)
    	ans[f[i]]+=cnt[i];
}
char s[100010];
int main()
{
//  freopen("necklace.in","r",stdin);
//  freopen("necklace.out","w",stdout);
    p=0;
    n=0;
    init(++p);
    fail[p]=2;
    len[p]=-1;
    trans[p]=2;
    init(++p);
    fail[p]=1;
    len[p]=0;
    a[0]=-1;
    trans[p]=1;
    last=p;
    int m;
    scanf("%s",s+1);
    m=strlen(s+1);
    int i;
    for(i=1;i<=m;i++)
        add(s[i]-'a'+1);
    solve();
    for(i=m-1;i>=1;i--)
    	ans[i]+=ans[i+1];
    for(i=1;i<=m;i++)
    	printf("%I64d ",ans[i]);
    return 0;
}