#include<bits/stdc++.h> 
#define maxn 1050
using namespace std;
typedef long long LL;

int n,m;

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d",&n);
	for (m=1;m*m<=n;++m)	;
	--m;
//	cout<<m<<endl;
	for (int i=1;i<=n;i+=m)
	{
		int j=min(i+m-1,n);
		while (j>=i)
			printf("%d ",j--);
	}
	return 0;
}