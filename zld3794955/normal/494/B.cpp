#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=100010,mod=1000000007;
char s[L]={},t[L]={};
int n,m,f[L]={},next[L]={},sum[L]={},sum2[L]={},pos[L]={};
int main()
{	
	gets(s+1);
	gets(t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=2,k=0;i<=m;++i)
	{
		while(k && t[k+1]!=t[i])
			k=next[k];
		if(t[k+1]==t[i])
			++k;
		next[i]=k;
	}
	for(int i=1,now=0;i<=n;++i)
	{
		while(now && t[now+1]!=s[i])
			now=next[now];
		if(t[now+1]==s[i])
			++now;
		if(now>=m)
			pos[i]=i,now=next[now];
		else
			pos[i]=pos[i-1];
		//cout<<"i="<<i<<" now="<<now<<endl;
	}
	//for(int i=1;i<=n;++i)
	//	cout<<pos[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=n;++i)
	{
		if(pos[i])
			f[i]=(sum2[pos[i]-m]+pos[i]-m+1)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		sum2[i]=(sum2[i-1]+sum[i])%mod;
	}
	/* 
	for(int i=1;i<=n;++i)
		cout<<f[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<sum[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<sum2[i]<<' ';
	cout<<endl;
	*/
	cout<<sum[n]<<endl;
	return 0;
}