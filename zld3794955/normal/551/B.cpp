#include<bits/stdc++.h>
using namespace std;
const int N=100100,C=26;
int n,l1,l2,a[C]={},b[C]={},c[C]={},v1=0,v2=0;
char ch[N]={},t1[N]={},t2[N]={},ans[N]={};
int main()
{	
	cin>>(ch+1)>>(t1+1)>>(t2+1);
	n=strlen(ch+1);
	l1=strlen(t1+1);
	l2=strlen(t2+1);
	for(int i=1;i<=n;++i)
		++a[ch[i]-'a'];
	for(int i=l1;i>=1;--i)
		++b[t1[i]-'a'];
	for(int i=l2;i>=1;--i)
		++c[t2[i]-'a'];
	for(int x=0; ; ++x)
	{
		int y=1<<20;
		bool flag=false;
		for(int i=0;i<C;++i)
		{
			if(a[i]-b[i]*x<0)
			{
				flag=true;
				break;
			}
			if(c[i])
				y=min(y,(a[i]-b[i]*x)/c[i]);
		}
		if(flag)
			break;
		if(x+y>v1+v2)
			v1=x,v2=y;
	}
	int tot=0;
	for(int i=1;i<=v1;++i)
		for(int j=1;j<=l1;++j)
			ans[++tot]=t1[j],--a[t1[j]-'a'];
	for(int i=1;i<=v2;++i)
		for(int j=1;j<=l2;++j)
			ans[++tot]=t2[j],--a[t2[j]-'a'];
	for(int j=0;j<C;++j)
		while(a[j]--)
			ans[++tot]=j+'a';
	puts(ans+1);
	return 0;
}