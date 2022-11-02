#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n;
char s[maxn];

int x,y;

int main()
{
	scanf("%d%s",&n,s);
	for (int i=0;i<n;++i)
		if (s[i]=='8')
			++x;
		else
			++y;
	int ans=0;
	for (ans=x;ans;--ans)
		if (ans&&(x-ans+y)>=10*ans)
			break;
	cout<<ans<<endl;
	return 0;
}