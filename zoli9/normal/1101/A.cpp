#include <bits/stdc++.h>
using namespace std;
int q;
long long l, r, d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        cin>>l>>r>>d;
        if(d<l)
        {
            cout<<d<<endl;
            continue;
        }
        long long m=r/d;
        cout<<(m+1)*d<<endl;
    }
    return 0;
}