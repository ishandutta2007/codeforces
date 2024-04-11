
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int t[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int mini=0;
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
        if(t[i]>=0) t[i]=-t[i]-1;
        mini=min(t[i], mini);
    }
    if(n%2==1)
    {


    for(int i=0; i<n; i++)
    {
        if(t[i]==mini)
        {
            t[i]=-t[i]-1;
            break;
        }
    }

    }

    for(int i=0; i<n; i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;

    return 0;
}