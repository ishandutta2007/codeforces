#include <bits/stdc++.h>
using namespace std;
int test;
long long k, n, b, a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>k>>n>>a>>b;
        if(k>n*b)
        {
            k-=n*b;
            long long d=a-b;
            k--;
            long long j=k/d;
            j=min(j, n);
            cout<<j<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }

    return 0;
}