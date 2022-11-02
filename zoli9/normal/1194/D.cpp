#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test;
ll n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        if(k%3!=0)
        {
            if(n%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else
        {
            ll per=k+1;
            n=n%per;
            if(n==k)
            {
                cout<<"Alice"<<endl;
            }
            else
            {
                if(n%3==0)
                {
                    cout<<"Bob"<<endl;
                }
                else
                {
                    cout<<"Alice"<<endl;
                }
            }
        }
    }
    return 0;
}