#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=100010,C=150;
char ch[L]={};
int l,t[C]={},zero=0,ans=1;
int main()
{
	gets(ch+1);
	l=strlen(ch+1);
	for(int i=1,s=10;i<=l;++i)
	{
		if(ch[i]=='?')
			++zero;
		if(isalpha(ch[i]) && t[(int)ch[i]]==0)
		{
			++t[(int)ch[i]];
			ans*=s;
			--s;
		}
	}
	while(ans%10==0)
		ans/=10,++zero;
	if(!isdigit(ch[1]))
		--zero,ans*=9;
	printf("%d",ans);
	for(int i=1;i<=zero;++i)
		printf("0");
	printf("\n");
	return 0;
}