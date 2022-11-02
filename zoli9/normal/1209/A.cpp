#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int a[109];
bool was[109];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    while(1)
    {
        int mini=-1;
        for(int i=1; i<=n; i++)
        {
            if(was[i]) continue;
            if(mini==-1 || a[i]<a[mini])
            {
                mini=i;
            }
        }
        if(mini==-1) break;
        ans++;
        for(int i=1; i<=n; i++)
        {
            if(a[i]%a[mini]==0) was[i]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}