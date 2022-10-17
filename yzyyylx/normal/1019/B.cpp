#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

int n,m,num[N];

inline int as(int u)
{
	int a,b;
	if(num[u]) return num[u];
	printf("? %d\n",u);fflush(stdout);
	scanf("%d",&a);
	return num[u]=a;
}

inline void pd(int u)
{
	if(as(u)==as(u+m))
	{
		printf("! %d\n",u);
		exit(0);
	}
}

int main()
{
	int i,j,l,r,mid,p,q;
	cin>>n;
	m=n/2;
	if(m%2)
	{
		puts("! -1");
		return 0;
	}
	as(1),as(m+1),pd(1);
	l=2,r=m;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		p=as(mid),q=as(mid+m);
		pd(mid);
		if((p>q)^(num[1]>num[m+1])) r=mid-1;
		else l=mid+1;
	}
}