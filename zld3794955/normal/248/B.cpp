#include<bits/stdc++.h>
using namespace std;
const int N=100010;
char ch[N]={};
int n,r=0;
int main()
{
	cin>>n;
	if(n<=2)
		ch[1]='-',ch[2]='1';
	else
	{
		ch[1]='1';
		r=1;
		for(int i=2;i<=n;++i)
			ch[i]='0',r=r*10%21;
	}
	while(r)
	{
		if(ch[n-1]=='9')
			++ch[n-2],ch[n-1]='0';
		else
			++ch[n-1];
		r=(r+10)%21;
	}
	if(r==0)
		puts(ch+1);
}