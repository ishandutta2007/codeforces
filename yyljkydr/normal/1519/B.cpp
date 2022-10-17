#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,u[N],x[N];

vector<int>v[N];

typedef long long ll;

vector<ll> s[N];

ll ans[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        cout<<(k==n*m-1?"Yes":"No")<<endl;
    }
}