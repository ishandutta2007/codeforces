#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
int main()
{
    short int n,m,K;
    cin>>n>>m>>K;
    int L[m],R[m],i,j,k;
    for(int i=0; i<m; i++)
        cin>>L[i]>>R[i];
 
    int ans =0,mx=0;
    for(i=1; i<=n-K+1; i++)
    {
        for(j =i; j<=n-K+1; j++)
        {
            ans = 0;
            for(k=0; k<m; k++)
            {
                ans+=max(max(min(R[k],i+K-1)+1-max(i,L[k]),min(R[k],j+K-1)+1-max(j,L[k])),0);
            }
            mx = max(mx,ans);
        }
    }
    cout<<mx;
}