#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int b, g, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>b>>g>>n;
    /*b=min(b, n);
    g=min(g, n);
    int maxi=max(b, g);
    int i=n;
    int sum=0;
    int cnt=0;
    while(sum<maxi)
    {
        sum+=i;
        i--;
        cnt++;
    }
    int alap=(g+b)/n+1;
    if((g+b)%n==0) alap--;
    int ans=max(cnt, alap);
    cout<<ans<<endl;*/
    int maxg=min(n, g);
    int maxb=min(n, b);

    int ming=n-maxb;
    cout<<maxg-ming+1<<endl;


    return 0;
}