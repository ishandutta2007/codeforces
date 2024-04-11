#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int n;

ll k,x,a[N];

vector<ll>v;

int main()
{
    scanf("%d",&n);
    scanf("%lld%lld",&k,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    for(int i=2;i<=n;i++)
        v.push_back((a[i]-a[i-1]-1)/x);
    sort(v.begin(),v.end());
    int ans=n;
    for(auto x:v)
        if(k>=x)
            k-=x,ans--;
    printf("%d\n",ans);
}