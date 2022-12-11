#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
typedef long long ll;
struct sam
{
//	map<int,int> next[20010];
	int next[2000010][30];
	int fail[2000010];
	int len[2000010];
	ll s[2000010];
	int q[2000010];
	int b[2000010];
	int last;
	int n;
	sam()
	{
		memset(next,0,sizeof(next));
		memset(fail,0,sizeof(fail));
		memset(len,0,sizeof(len));
		memset(s,0,sizeof(s));
		last=1;
		n=1;
	}
	void insert(int x)
	{
		int np=++n;
		int p=last;
		s[np]=1;
		len[np]=len[p]+1;
		for(;p&&!next[p][x];p=fail[p])
			next[p][x]=np;
		if(!p)
			fail[np]=1;
		else
		{
			int q=next[p][x];
			if(len[q]==len[p]+1)
				fail[np]=q;
			else
			{
				int nq=++n;
				len[nq]=len[p]+1;
				memcpy(next[nq],next[q],sizeof(next[q]));
//				next[nq]=next[q];
				fail[nq]=fail[q];
				fail[q]=nq;
				fail[np]=nq;
				for(;next[p][x]==q;p=fail[p])
					next[p][x]=nq;
			}
		}
		last=np;
	}
	void count()
	{
		int i;
		for(i=1;i<=n;i++)
			b[len[i]]++;
		for(i=1;i<=n;i++)
			b[i]+=b[i-1];
		for(i=n;i>=1;i--)
			q[b[len[i]]--]=i;
		for(i=n;i>=1;i--)
			if(fail[q[i]])
				s[fail[q[i]]]+=s[q[i]];
	}
};
sam a;
char s[2000010];
int fail[2000010];
int main()
{
//	freopen("cf235c.in","r",stdin);
//	freopen("cf235c.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	int i;
	for(i=1;i<=n;i++)
		a.insert(s[i]-'a'+1);
	a.count();	
	int q,m,ans;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		fail[1]=0;
		int j;
		for(j=2;j<=m;j++)
		{
			fail[j]=fail[j-1];
			while(fail[j]&&s[fail[j]+1]!=s[j])
				fail[j]=fail[fail[j]];
			if(s[fail[j]+1]==s[j])
				fail[j]++;
		}
		ans=0;
		int per;
		if(2*fail[m]>=m&&m%(m-fail[m])==0)
			per=m-fail[m];
		else
			per=m;
		int now=1,len=0;
		for(j=1;j<=m;j++)
			s[j+m]=s[j];
		for(j=1;j<=m+per-1;j++)
		{
			while(now&&!a.next[now][s[j]-'a'+1])
			{
				now=a.fail[now];
				len=a.len[now];
			}
			if(!now)
			{
				now=1;
				len=0;
			}
			else
			{
				now=a.next[now][s[j]-'a'+1];
				len++;
			}
			while(a.len[a.fail[now]]>=m)
			{
				now=a.fail[now];
				len=a.len[now];
			}
			if(len>=m)
				ans+=a.s[now];
		}
		printf("%d\n",ans);
	}
	return 0;
}