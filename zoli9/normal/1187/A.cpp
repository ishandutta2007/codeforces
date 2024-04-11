#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    long long n, s, t;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>s>>t;
        long long kozos=s+t-n;
        s-=kozos;
        t-=kozos;
        cout<<max(s, t)+1<<endl;
    }

    return 0;
}