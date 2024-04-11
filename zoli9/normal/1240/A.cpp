#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
ll n;
vll v, w;
ll X, A, Y, B, K;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        v.resize(n);
        w.resize(n+1);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            v[i]/=100;
        }
        sort(v.begin(), v.end());
        w[0]=0;
        for(int i=1; i<=n; i++)
        {
            w[i]=w[i-1]+v[n-i];
        }
        cin>>X>>A;
        cin>>Y>>B;
        cin>>K;
        if(X<Y)
        {
            swap(A, B);
            swap(X, Y);
        }
        ll elso=1;
        ll utolso=n;
        while(elso<=utolso)
        {
            ll kozep=(elso+utolso)/2;
            ll AB=(A*B)/(__gcd(A, B));
            ll d1=kozep/AB;
            ll d2=kozep/A-d1;
            ll d3=kozep/B-d1;
            ll res=(w[d1]*(X+Y))+(w[d1+d2]-w[d1])*X+(w[d1+d2+d3]-w[d1+d2])*Y;
            if(res>=K) utolso=kozep-1;
            else elso=kozep+1;
        }
        if(elso>n) cout<<-1<<endl;
        else cout<<elso<<endl;
    }

    return 0;
}