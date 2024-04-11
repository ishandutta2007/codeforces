#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
ll t[200009];
ll mini;
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>t[i];
        }
        mini=-1;
        int minhely=1;
        for(int i=1; i+k<=n; i++)
        {
            if(mini==-1 || t[i+k]-t[i]<mini)
            {
                mini=t[i+k]-t[i];
                minhely=i;
            }
        }
        cout<<(t[minhely]+mini/2)<<endl;
    }
    return 0;
}