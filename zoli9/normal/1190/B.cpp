#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
ll board=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        board+=v[i];
    }
    sort(v.begin(), v.end());
    int rossz=0;
    for(int i=1; i<n; i++)
    {
        if(v[i]==v[i-1])
        {
            rossz++;
            if(v[i]==0)
            {
                rossz++;
                break;
            }
            if(i>1 && v[i-2]>=v[i]-1)
            {
                rossz++;
                break;
            }
        }
    }
    if(rossz>=2)
    {
        cout<<"cslnb"<<endl;
        return 0;
    }
    ll mini=(n-1)*n/2;
    if((board-mini)%2)
    {
        cout<<"sjfnb"<<endl;
    }
    else cout<<"cslnb"<<endl;

    return 0;
}