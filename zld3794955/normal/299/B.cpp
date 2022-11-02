#include<bits/stdc++.h>
using namespace std;
const int L=200,N=300030;
int n,k;
char buf[L]={},ch[N]={};
int main()
{
	gets(buf);
	sscanf(buf,"%d%d",&n,&k);
	gets(ch+1);
	int l=0;
	for(int i=1;i<=n;++i)
	{
		if(i-l>k)
		{
			puts("NO");
			return 0;
		}
		if(ch[i]=='.')
			l=i;
	}
	puts("YES");
	return 0;
}