#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 
#define M 
using namespace std;

ll l,r;

int main()
{
	ll i,j;
	cin>>l>>r;
	puts("YES");
	for(i=l;i<=r;i+=2)
	{
		printf("%lld %lld\n",i,i+1);
	}
}