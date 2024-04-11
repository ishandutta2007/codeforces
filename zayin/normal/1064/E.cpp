#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL l=1,r=2E9;

void point(LL p)
{
	LL x=p/2,y=p-x;
	cout<<x<<" "<<y<<endl;
}

void print(LL p)
{
	LL x=p/2,y=p-x;
	cout<<x<<" "<<y<<" "<<x+1<<" "<<y-1<<endl;
}

char s[10],t[10];

int main()
{
//	freopen("c.in","r",stdin); 
	int n;
	scanf("%d",&n);
	point(0);
	scanf("%s",t);
	
	while (--n)
	{
		LL mid=(l+r)>>1;
		point(mid);
		scanf("%s",s);
		if (*s==*t)
			l=mid+1;
		else
			r=mid-1;
	}
	
	print((l+r)>>1);
	return 0;
}