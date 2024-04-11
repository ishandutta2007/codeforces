#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
ll n;
vector<ll> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        v.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        ll answer=v[0]*v.back();
        int c1=0;
        int c2=n-1;
        bool jo=true;
        while(c1<=c2)
        {
            if(v[c1]*v[c2]!=answer)
            {
                jo=false;
                break;
            }
            c1++;
            c2--;
        }
        if(!jo)
        {
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        for(ll i=2; i<=1000000; i++)
        {
            if(i==answer) break;
            if(answer%i==0)
            {
                if(v[cnt]==i)
                {
                    cnt++;
                }
                else
                {
                    jo=false;
                    break;
                }
            }
        }
        if(jo)
        {
            cout<<answer<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}