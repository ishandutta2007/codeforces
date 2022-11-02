#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
int ri1[300009];
int ri2[300009];


int a[300009];

int ans[300009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    ri1[n]=n+1;
    ri2[n]=n+1;
    ans[n]=0;
    int maxi=a[n-1];
    int mini=a[n-1];
    for(int i=n-2; i>=1; i--)
    {
        if(a[i]>maxi && a[n]>maxi)
        {
            ans[i]=1;
        }
        if(a[i]<mini && a[n]<mini)
        {
            ans[i]=1;
        }
        mini=min(mini, a[i]);
        maxi=max(maxi, a[i]);
    }
    for(int i=n-1; i>=1; i--)
    {
        if(ans[i]==0) ans[i]=ans[i+1]+1;
        ri1[i]=i+1;
        int last=a[ri1[i]];
        while(ri1[i]<=n && a[ri1[i]]>a[i])
        {
            if(a[ri1[i]]<last) ans[i]=min(ans[i], ans[ri1[i]]+1);
            last=a[ri1[i]];
            ri1[i]=ri1[ri1[i]];
        }
        if(ri1[i]<=n) ans[i]=min(ans[i], ans[ri1[i]]+1);
        ri2[i]=i+1;
        last=a[ri2[i]];
        while(ri2[i]<=n && a[ri2[i]]<a[i])
        {
            if(a[ri2[i]]>last) ans[i]=min(ans[i], ans[ri2[i]]+1);
            last=a[ri2[i]];
            ri2[i]=ri2[ri2[i]];
        }
        if(ri2[i]<=n) ans[i]=min(ans[i], ans[ri2[i]]+1);
    }

    cout<<ans[1]<<endl;
    return 0;
}