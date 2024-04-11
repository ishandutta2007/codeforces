#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int ans[200009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        if(i%2)
        {
            ans[i]=2*i-1;
            ans[i+n]=2*i;
        }
        else
        {
            ans[i]=2*i;
            ans[i+n]=2*i-1;
        }
    }
    for(int i=1; i<=2*n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}