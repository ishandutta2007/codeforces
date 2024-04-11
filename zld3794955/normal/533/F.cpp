#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200020,M=200020;
const long long Base=233,mod=100000000000007ll;
struct num_cmp
{
	long long *a;
	num_cmp(long long *b): a(b) {}
	bool operator() (int x,int y)
	{
		return a[x]<a[y];
	}
};
char S[N]={},T[M]={};
int n,m,ans[N]={},tot=0;
long long Th[26]={},p=1;
void init()
{
	cin>>n>>m>>(S+1)>>(T+1);
	for(int i=1;i<=m;++i)
	{
		for(int c=0;c<26;++c)
			Th[c]=Th[c]*Base%mod;
		(Th[T[i]-'a']+=1)%=mod;
	}
	for(int i=1;i<=m;++i)
		p=p*Base%mod;
}
bool ok(long long *a,long long *b)
{
	int p1[26]={},p2[26]={};
	for(int i=0;i<26;++i)
		p1[i]=p2[i]=i;
	sort(p1,p1+26,num_cmp(a));
	sort(p2,p2+26,num_cmp(b));
	for(int i=25;i>=0;--i)
	{
		if(a[p1[i]]==0)
			break;
		if(a[p1[i]]!=b[p2[i]])
			return false;
		if(a[p2[i]]!=b[p1[i]])
			return false;
	}
	return true;
}
void work()
{
	long long now[26]={};
	for(int i=1;i<=m;++i)
	{
		for(int c=0;c<26;++c)
			now[c]=now[c]*Base%mod;
		(now[S[i]-'a']+=1)%=mod;
	}
	if(ok(now,Th))
		ans[++tot]=1;
	for(int i=m+1;i<=n;++i)
	{
		for(int c=0;c<26;++c)
			now[c]=now[c]*Base%mod;
		(now[S[i]-'a']+=1)%=mod;
		(now[S[i-m]-'a']+=mod-p)%=mod;
		if(ok(now,Th))
			ans[++tot]=i-m+1;
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
		cout<<ans[i]<<' ';	
	cout<<endl;
}
int main()
{
	init();
	work();
	return 0;
}