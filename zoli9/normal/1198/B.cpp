#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
int money[200009];
int modtime[200009];
int balance[200009];
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>money[i];
    }
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int tip;
        cin>>tip;
        if(tip==1)
        {
            int p;
            int x;
            cin>>p>>x;
            modtime[p]=i;
            money[p]=x;
        }
        else
        {
            int x;
            cin>>x;
            balance[i]=x;
        }
    }
    for(int i=q-1; i>=0; i--)
    {
        balance[i]=max(balance[i], balance[i+1]);
    }
    for(int i=1; i<=n; i++)
    {
        int ans=max(money[i], balance[modtime[i]]);
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}