#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;typedef long long ll;typedef pair<int,int> pii;void open(const char *s){
#ifndef ONLINE_JUDGE
char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}int rd(){int s,c;while((c=getchar())<'0'||c>'9');s=c-'0';while((c=getchar())>='0'&&c<='9')s=s*10+c-'0';return s;}
const int N=1000010;
char s1[N],s2[N],s[N];
pii ans[N];
namespace pam
{
	int next[N][30];
	int fail[N];
	int len[N];
	int last;
	int n;
	int cnt;
	int a[N];
	int diff[N];
	int slink[N];
	void init()
	{
		cnt=1;
		len[1]=-1;
		fail[0]=1;
		fail[1]=0;
		diff[0]=-1;
		diff[1]=-1;
		last=0;
	}
	void insert(int v)
	{
		a[++n]=v;
		while(a[n-len[last]-1]!=a[n])
			last=fail[last];
		int now=last;
		if(!next[now][v])
		{
			int cur=++cnt;
			len[cur]=len[last]+2;
			last=fail[last];
			while(a[n-len[last]-1]!=a[n])
				last=fail[last];
			fail[cur]=next[last][v];
			diff[cur]=len[cur]-len[fail[cur]];
			if(diff[cur]==diff[fail[cur]])
				slink[cur]=slink[fail[cur]];
			else
				slink[cur]=fail[cur];
			next[now][v]=cur;
		}
		last=next[now][v];
	}
	pii s0[N],s1[N];
	void gao(int x)
	{
		ans[x].first=0x3fffffff;
		for(int i=last;len[i]>0;i=slink[i])
		{
			s0[i]=s1[i]=pii(0x3fffffff,0);
			if((x-(len[slink[i]]+diff[i]))&1)
				s1[i]=pii(ans[x-(len[slink[i]]+diff[i])].first,x-(len[slink[i]]+diff[i]));
			else
				s0[i]=pii(ans[x-(len[slink[i]]+diff[i])].first,x-(len[slink[i]]+diff[i]));
			if(diff[i]==diff[fail[i]])
			{
				s0[i]=min(s0[i],s0[fail[i]]);
				s1[i]=min(s1[i],s1[fail[i]]);
			}
			if(x&1)
				ans[x]=min(ans[x],pii(s1[i].first+1,s1[i].second));
			else
				ans[x]=min(ans[x],pii(s0[i].first+1,s0[i].second));
		}
	}
}
int main()
{
	open("xsy3225");
	scanf("%s",s1+1);
	scanf("%s",s2+1);
//	if(s1[1]=='b'&&s1[2]=='a'&&s1[3]=='a'&&s1[4]=='a'&&s1[5]=='a')
//		printf("%s\n",s2+1);
	int n=strlen(s1+1);
	for(int i=1;i<=n;i++)
	{
		s[2*i-1]=s1[i];
		s[2*i]=s2[i];
	}
	n*=2;
	pam::init();
	for(int i=1;i<=n;i++)
	{
		if(i==292)
			int xxx=1;
		pam::insert(s[i]-'a'+1);
		pam::gao(i);
		if(!(i&1)&&s[i-1]==s[i])
			ans[i]=min(ans[i],ans[i-2]);
	}
	if(ans[n].first>=0x3fffffff)
		printf("-1\n");
	else
	{
		printf("%d\n",ans[n].first);
		for(int i=n;i>=1;)
			if(ans[i].first==ans[i-2].first&&s[i-1]==s[i])
				i-=2;
			else
			{
				printf("%d %d\n",ans[i].second/2+1,i/2);
				i=ans[i].second;
			}
	}
	return 0;
}