#include<bits/stdc++.h>
using namespace std;
const int L=200,N=1000100;
char buf[L]={},s[N+N]={},t[N+N]={};
int n,a[3]={},v[2]={};
int main()
{	
	gets(buf);
	sscanf(buf,"%d",&n);
	gets(s+1);
	gets(t+1);
	for(int i=1;i<=n+n;++i)
	{
		if(s[i]=='1' && t[i]=='1')
			++a[2];
		else
			if(s[i]=='1')
				++a[0];
			else
				if(t[i]=='1')
					++a[1];
	}
	int turn=0;
	while(a[0] || a[1] || a[2])
	{
		if(a[2])
			--a[2],++v[turn];
		else
			if(a[turn])
				--a[turn],++v[turn];
			else
				--a[!turn];
		turn=!turn;
	}
	cerr<<"v1="<<v[0]<<" v2="<<v[1]<<endl;
	puts(v[0]>v[1] ? "First" : v[0]==v[1] ? "Draw" : "Second");
	return 0;
}