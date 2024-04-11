#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n, x;
bool volt[1000009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x;
    if(x>=(1<<n))
    {
        cout<<((1<<n)-1)<<endl;
        for(int i=1; i<(1<<n); i++)
        {
            cout<<(i^(i-1))<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<((1<<n)-2)/2<<endl;
        int last=0;
        for(int i=1; i<(1<<n); i++)
        {
            if(i==x || volt[i]) continue;
            cout<<(i^last)<<" ";
            volt[i^x]=true;
            last=i;
        }
        cout<<endl;
    }
    return 0;
}