#include<bits/stdc++.h>
using namespace std;
const int L=50050,N=2626;
char ch[L]={},ans[N]={};
int n,f[N][N]={},tot=0;
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	if(n>=2575)
	{
		int t[26]={};
		for(int i=1;i<=n;++i)
			++t[ch[i]-'a'];
		int ansc=max_element(t,t+26)-t;
		for(int i=1;i<=100;++i)
			putchar(ansc+'a');
		putchar('\n');
	}
	else
	{
		for(int i=1;i<=n;++i)
			f[i][i]=1;
		for(int d=1;d<n;++d)
			for(int i=1;i<=n-d;++i)
			{
				int j=i+d;
				if(ch[i]==ch[j])
					f[i][j]=f[i+1][j-1]+2;
				f[i][j]=max(f[i+1][j],f[i][j]);
				f[i][j]=max(f[i][j-1],f[i][j]);
			}
		int l=1,r=n,tot=0;
		while(l<r)
		{
			if(ch[l]==ch[r] && f[l+1][r-1]==f[l][r]-2)
				ans[++tot]=ch[l],++l,--r;
			else if(f[l][r-1]==f[l][r])
				--r;
			else if(f[l+1][r]==f[l][r])
				++l;
		}
		for(int i=1;i<=min(50,tot);++i)
			putchar(ans[i]);
		if(l==r && tot<=49)
			putchar(ch[l]);
		for(int i=min(50,tot);i>=1;--i)
			putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}