#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

LL n,a,c,h;
int m;

int K=1;

int main()
{
//	freopen("c.in","r",stdin);
	
	scanf("%I64d%d",&n,&m);
	for (int k=1;k<=m;++k)
	{
		scanf("%I64d",&a);
		LL t=(n/a)*a;
//		cout<<k<<" "<<t<<endl;
		if (t>c)
			c=t,K=k,h=n/a;
	}
	printf("%d %I64d\n",K,h);
	return 0;
}