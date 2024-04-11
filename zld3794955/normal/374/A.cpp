#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,m,i,j,a,b,ans=0x7fffffff;
int main()
{	
	scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
	if((i==1 && j==1) || (i==1 && j==m) || (i==n && j==1) || (i==n && j==m))
	{
		printf("0\n");
		return 0;
	}
	if((i-1)%a==0 && (j-1)%b==0 && (((i-1)/a)^((j-1)/b))%2==0 && (i+a<=n || i-a>=1) && (j-b>=1 || j+b<=m))
		ans=min(ans,max((i-1)/a,(j-1)/b));
	if((i-1)%a==0 && (m-j)%b==0 && (((i-1)/a)^((m-j)/b))%2==0 && (i+a<=n || i-a>=1) && (j-b>=1 || j+b<=m))
		ans=min(ans,max((i-1)/a,(m-j)/b));
	if((n-i)%a==0 && (j-1)%b==0 && (((n-i)/a)^((j-1)/b))%2==0 && (i+a<=n || i-a>=1) && (j-b>=1 || j+b<=m))
		ans=min(ans,max((n-i)/a,(j-1)/b));
	if((n-i)%a==0 && (m-j)%b==0 && (((n-i)/a)^((m-j)/b))%2==0 && (i+a<=n || i-a>=1) && (j-b>=1 || j+b<=m))
		ans=min(ans,max((n-i)/a,(m-j)/b));
	if(ans==0x7fffffff)
		puts("Poor Inna and pony!");
	else
		printf("%d\n",ans);
	return 0;
}