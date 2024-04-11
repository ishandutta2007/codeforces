#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        int p, b, f;
        int h, c;
        cin>>b>>p>>f;
        cin>>h>>c;
        int ans=0;
        if(h>=c)
        {
            while(b>=2 && p>=1)
            {
                ans+=h;
                b-=2;
                p-=1;
            }
            while(b>=2 && f>=1)
            {
                ans+=c;
                b-=2;
                f-=1;
            }
        }
        else
        {
            while(b>=2 && f>=1)
            {
                ans+=c;
                b-=2;
                f-=1;
            }
            while(b>=2 && p>=1)
            {
                ans+=h;
                b-=2;
                p-=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}