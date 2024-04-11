#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
int n, k;
ll a[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        ll sum=0;
        int dbptl=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(a[i]%2) dbptl++;
        }
        if(sum%2==k%2 && dbptl>=k)
        {
            cout<<"YES"<<endl;
            int darab=1;
            for(int i=1; i<=n; i++)
            {
                if(darab==k) break;
                if(a[i]%2)
                {
                    cout<<i<<" ";
                    darab++;
                }
            }
            cout<<n<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}