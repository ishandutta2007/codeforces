#include<bits/stdc++.h>
using namespace std;
const int N=606;
int n,l[N]={},r[N]={},p[N]={},s[N]={},top=0,tot=0;
char ch[N+N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>l[i]>>r[i];
		ch[++tot]='(';
		s[++top]=i;
		p[i]=tot;
		while(top && p[s[top]]+l[s[top]]<=tot+1)
		{
			if(p[s[top]]+r[s[top]]<tot+1)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
			else
			{
				ch[++tot]=')';
				--top;
			}
		}
	}
	puts(top ? "IMPOSSIBLE" : ch+1);
	return 0;
}