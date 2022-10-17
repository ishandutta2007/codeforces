#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll T,n,ans;
vector<ll>a,b;

inline void ask()
{
    if(!a.size() || !b.size()) return;
    ll i,t;
    cout<<a.size()<<" "<<b.size()<<" ";
    for(i=0;i<a.size();i++) printf("%lld ",a[i]);
    for(i=0;i<b.size();i++) printf("%lld ",b[i]);
    puts("");
    fflush(stdout);
    scanf("%lld",&t);
    ans=max(ans,t);
}

int main()
{
    ll i,j;
    cin>>T;
    while(T--)
    {
	ans=0;
	scanf("%lld",&n);
	for(i=0;i<9;i++)
	{
	    a.clear(),b.clear();
	    for(j=1;j<=n;j++)
	    {
		if((1 << i)&j) a.push_back(j);
		else b.push_back(j);
	    }
	    ask();
	}
	printf("-1 %lld\n",ans);
	fflush(stdout);
    }
}