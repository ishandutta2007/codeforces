#include<bits/stdc++.h>
#define ll long long
#define N 300100
#define M 1050000
using namespace std;

ll n,now,ans,cnt[M][2];

int main()
{
    ll i,j,t;
    cin>>n;
    cnt[0][0]=1;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&t);
	now^=t;
	ans+=cnt[now][i&1];
	cnt[now][i&1]++;
    }
    cout<<ans;
}