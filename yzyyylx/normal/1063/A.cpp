#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 100100
#define M 
using namespace std;

ll n,cnt[130];
char str[N];
vector<char>have;

int main()
{
	ll i,j;
	cin>>n;
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(!cnt[str[i]]) have.push_back(str[i]);
		cnt[str[i]]++;
	}
	for(i=0;i<have.size();i++)
	{
		for(j=1;j<=cnt[have[i]];j++)
		{
			printf("%c",have[i]);
		}
	}
//	if(n==100000) while(1);
}