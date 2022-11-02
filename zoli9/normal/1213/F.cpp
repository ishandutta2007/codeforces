#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, k;
int p[200009];
int q[200009];
int hanyas[200009];
int ans[200009];
int ans2[200009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
        hanyas[p[i]]=i;
    }
    int hatar=0;
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(i<=hatar)
        {
            ans[i]=cnt;
        }
        else
        {
            cnt++;
            ans[i]=cnt;
        }
        cin>>q[i];
        q[i]=hanyas[q[i]];
        hatar=max(hatar, q[i]);
    }
    for(int i=1; i<=n; i++)
    {
        ans2[p[i]]=ans[i];
    }
    if(cnt>=k)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++)
        {
            ans2[i]=min(ans2[i], k);
            cout<<(char)('a'+ans2[i]-1);
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}