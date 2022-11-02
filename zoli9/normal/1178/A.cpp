
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int apow=0;
    int opp=0;
    int alice;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        if(i==1)
        {
            alice=szam;
            apow+=alice;
            v.push_back(i);
        }
        else
        {
            if(alice>=2*szam)
            {
                v.push_back(i);
                apow+=szam;
            }
            else
            {
                opp+=szam;
            }
        }
    }
    if(apow>opp)
    {
        cout<<v.size()<<endl;
        for(int x: v) cout<<x<<" ";
        cout<<endl;
    }
    else
    {
        cout<<0<<endl;
    }

    return 0;
}