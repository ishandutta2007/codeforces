#include<bits/stdc++.h>
using namespace std;
const int L=30,S=45,ansL=6,v[3]={0,4,7};
int l,a[S][ansL]={},ok[S]={},f[L][10]={},now=0;
long long ans[ansL]={},p10[L]={1};
char ch[L]={};
void package()
{
	for(int i=1;i<=18;++i)
		p10[i]=p10[i-1]*10;
	int p[ansL]={};
	for(p[0]=0;p[0]<3;++p[0]) for(p[1]=0;p[1]<3;++p[1])
	for(p[2]=0;p[2]<3;++p[2]) for(p[3]=0;p[3]<3;++p[3])
	for(p[4]=0;p[4]<3;++p[4]) for(p[5]=0;p[5]<3;++p[5])
	{
		int w=0;
		for(int i=0;i<ansL;++i)
			w+=v[p[i]];
		ok[w]=true;
		for(int i=0;i<ansL;++i)
			a[w][i]=v[p[i]];
	}
}
bool dfs(int t,int s)
{
	if(t==l)
		return s==0;
	if(s>=10 || s<0)
		return false;
	for(int k=0;k<S;++k)
		if(ok[k] && dfs(t+1,s*10+ch[t+1]-'0'-k))
		{
			for(int i=0;i<6;++i)
				ans[i]+=p10[l-t-1]*a[k][i];
			return true;
		}
	return false;
}
int main()
{
	package();
	int T;
	cin>>T;
	while(T--)
	{
		cin>>(ch+1);
		l=strlen(ch+1);
		++now;
		for(int i=0;i<ansL;++i)
			ans[i]=0;
		if(!dfs(0,0))
			puts("-1");
		else
		{
			for(int i=0;i<ansL;++i)
				cout<<ans[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}