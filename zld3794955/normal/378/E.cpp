#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110,M=25,S=1<<20,Inf=1<<30,Unknown=-1<<30,Maximize=1,Minimize=2;
int n,m,a[N]={},turn[M]={},f[S]={},g[S]={};
char ch[M]={};
inline int compare(int a,int b,int p)
{
	return p==Maximize ? max(a,b) : min(a,b);
}
void init()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;++i)
		cin>>ch[i]>>turn[i];
	sort(a,a+n);
	reverse(a,a+n);
	fill(f+1,f+(1<<m),Unknown);
	fill(g+1,g+(1<<m),Unknown);
	f[0]=g[0]=0;
}
int work(int t,int s)
{
	int &now=(turn[t]==Maximize ? f[s] : g[s]);
	if(now!=Unknown)
		return now;
	int tmpv=turn[t]==Maximize ? -Inf : Inf;
	int r=ch[t]=='b' ? 0 : (turn[t]==Maximize ? 1 : -1);
	for(int i=0;i<m;++i)
		if(s&(1<<i))
			tmpv=compare(tmpv,work(t+1,s^(1<<i))+a[i]*r,turn[t]);
	return now=tmpv;
}
int main()
{	
	init();
	cout<<work(1,(1<<m)-1)<<endl;
	return 0;
}