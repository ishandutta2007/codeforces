#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;
char s[maxn];

int L[maxn],R[maxn];

int main()
{
	scanf("%d%s",&n,s+1);
	
	for (int i=1;i<=n;++i)
		m+=s[i]=='G';
	
	for (int i=1;i<=n;++i)
		if (s[i]=='G')
			L[i]=L[i-1]+1;
	
	for (int i=n;i;--i)
		if (s[i]=='G')
			R[i]=R[i+1]+1;
	
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		ans=max(ans,L[i]);
		if (s[i]=='S'&&(L[i-1]||R[i+1]))
			ans=max(ans,L[i-1]+R[i+1]+(L[i-1]+R[i+1]<m));
	}
	
	printf("%d\n",ans);
	
	return 0;
}