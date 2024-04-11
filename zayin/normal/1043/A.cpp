#include<bits/stdc++.h>
#define maxn 105
using namespace std;
typedef long long LL;

int n,m;
int a[maxn],sum;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]),sum+=a[i],m=max(m,a[i]);
	for (;m*n-sum<=sum;++m);
	cout<<m<<endl;
	return 0;
}