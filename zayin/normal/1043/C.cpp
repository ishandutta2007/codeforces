#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
char s[maxn],t[maxn];

int ans[maxn];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	
	int d=0;
	for (int i=n;i;--i)
	{
//		cout<<i<<" "<<d<<endl;
		if (d==0)
		{
			if (s[i]=='a')
				ans[i]=1,d=1;
			else
				ans[i]=0;
		} else
		if (d==1)
		{
			if (s[i]=='a')
				ans[i]=0;
			else
				ans[i]=1,d=0;
		}
	}
	
	for (int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
	return 0;
}