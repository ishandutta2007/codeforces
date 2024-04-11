#include<bits/stdc++.h>
#define ll long long
#define db doble
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

ll n,m,x,y,ans;

int main()
{
	int i,j;
	cin>>n>>m;
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		if((x+y)&1)
		{
			if(n&1)
			{
				printf("%lld\n",(x-1)*n/2+(y+1)/2+n*n/2+1);
			}
			else
			{
				printf("%lld\n",(x-1)*n/2+(y+1)/2+n*n/2);
			}
		}
		else
		{
			if(n&1)
			{
				printf("%lld\n",(x-1)*n/2+(x%2==0)+(y+1)/2);
			}
			else
			{
				printf("%lld\n",(x-1)*n/2+(y+1)/2);
			}
		}
	}
}