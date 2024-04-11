#include <bits/stdc++.h>
using namespace std;
int n;
long long s;
vector<int> G[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout<<fixed;
    cin>>n>>s;
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    if(n==2)
    {
        cout<<s<<endl;
        return 0;
    }
    long long levelek=0;
    for(int i=1; i<=n; i++)
    {
        if(G[i].size()==1) levelek++;
    }
    //cout<<levelek<<endl;
    long double ans=(long double)(s)/(long double)(levelek);
    ans*=2;
    cout<<ans<<endl;
    return 0;
}