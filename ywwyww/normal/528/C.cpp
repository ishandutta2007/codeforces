/*
Author: yww
Language: C++
Mail: weeerrr720@qq.com
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
template <class T>
int upmin(T &a, const T &b){return (b<a?a=b,1:0);}
template <class T>
int upmax(T &a, const T &b){return (b>a?a=b,1:0);}
namespace io
{
    const int SIZE=(1<<20)+1;
    char ibuf[SIZE],*iS,*iT;
    char obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1;
    int getc()
    {
        (iS==iT?iS=ibuf,iT=ibuf+fread(ibuf,1,SIZE,stdin):0);
        return iS==iT?EOF:*(iS++);
    }
    int f;
    char c;
    template <class T>
    void get(T &x)
    {
        f=1;
        for(c=getc();(c<'0'||c>'9')&&c!='-';c=getc());
        (c=='-'?f=-1,c=getc():0);
        x=0;
        for(;c>='0'&&c<='9';c=getc())
            x=x*10+c-'0';
        x*=f;
    }
    void flush()
    {
        fwrite(obuf,1,oS-obuf,stdout);
        oS=obuf;
    }
    void putc(char x)
    {
        *(oS++)=x;
        if(oS==oT)
            flush();
    }
    int a[55],t;
    template <class T>
    void put(T x)
    {
        if(!x)
            putc('0');
        x<0?putc('-'),x=-x:0;
        while(x)
        {
            a[++t]=x%10;
            x/=10;
        }
        while(t)
            putc(a[t--]+'0');
    }
    void space()
    {
        putc(' ');
    }
    void enter()
    {
        putc('\n');
    }
    struct flusher
    {
        ~flusher()
        {
            flush();
        }
    }
    io_flusher;
}
const int infi=0x3fffffff;
const ll infll=0x3fffffffffffffffll;
const int N=100010;
vector<pii> g[N];
int b[6*N];
int n,m;
int flag;
int d[N];
void dfs(int x)
{
	while(g[x].size())
	{
		int i = g[x].size()-1;
		if(!b[g[x][i].second])
		{
			int v=g[x][i].first;
			int id=g[x][i].second;
			g[x].pop_back();
			b[id]=1;
			dfs(v);
			if(flag)
				printf("%d %d\n",v,x);
			else
				printf("%d %d\n",x,v);
			flag^=1;
		}
		else
			g[x].pop_back();
	}
}
int main()
{
	open("CF528C");
	scanf("%d%d",&n,&m);
	int x,y;
	int t=m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(pii(y,i));
		g[y].push_back(pii(x,i));
		d[x]++;
		d[y]++;
	}
	int last=0;
	for(int i=1;i<=n;i++)
		if(d[i]&1)
		{
			if(last)
			{
				t++;
				g[last].push_back(pii(i,t));
				g[i].push_back(pii(last,t));
				last=0;
			}
			else
				last=i;
		}
	if(t&1)
	{
		t++;
		g[1].push_back(pii(1,t));
		g[1].push_back(pii(1,t));
	}
	printf("%d\n",t);
	dfs(1);
	return 0;
}