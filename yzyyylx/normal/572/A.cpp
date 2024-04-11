#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int m,n,k,l,a[N],b[N],x,y,i;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&l);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	for(i=1;i<=m;i++){scanf("%d",&b[i]);}
	a[k]>=b[m-l+1]?cout<<"NO\n":cout<<"YES\n";
}