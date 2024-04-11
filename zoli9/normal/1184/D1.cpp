#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>m>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int tp;
        int idx;
        cin>>tp>>idx;
        if(tp==1)
        {
            n++;
            if(idx<=k) k++;
        }
        else
        {
            if(idx<k)
            {
                n=n-idx;
                k=k-idx;
            }
            else
            {
                n=idx;
            }
        }
        cout<<n<<" "<<k<<'\n';
    }
    return 0;
}