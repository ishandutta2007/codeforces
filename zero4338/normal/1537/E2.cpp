#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5;
int n,k;
string s,ans;
int nxt[maxn],p;
int main()
{
	n=read();k=read();
	cin>>s;
	nxt[0]=n;
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)nxt[i]=min(nxt[i-l],r-i+1);
		while(i+nxt[i]<n&&s[i+nxt[i]]==s[nxt[i]])nxt[i]++;
		if(i+nxt[i]-1>r)l=i,r=i+nxt[i]-1;
	}
	p=0;
	for(int i=1;i<n;i++)
	{
		int now=i%(p+1);
		if(s[now]<s[i])break;
		if(s[now]>s[i]){p=i;continue;}
		now=(now+1)%(p+1);
		if(now+nxt[now]<=p)
		{
			if(s[now+nxt[now]]>s[nxt[now]])p=i;
		}
		else
		{
			now=(p-now+1)%(i+1);
			if(nxt[now]<=p&&now+nxt[now]<=i&&s[now+nxt[now]]<s[nxt[now]])p=i;
		}
	}
	string tmp=s.substr(0,p+1);
	while(ans.size()<k)ans+=tmp;
	while(ans.size()>k)ans.pop_back();
	puts(ans.c_str());
	return 0;
}