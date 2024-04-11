#include <bits/stdc++.h>

using namespace std;

int a[444444];
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0);
int n,k; cin>>n>>k; int mx=0;
for(int i=0;i<n;i++) {cin>>a[i];mx=max(mx,a[i]);}
int lo=mx; int hi=5555555;
int ans=-1;
while(lo<=hi)
{
int mid=(lo+hi)>>1;
int prs=0;
int r=n-1;
for(int i=0;i<n;i++)
{
while(i<r&&a[i]+a[r]>mid) r--;
if(i<r)
{
prs++; r--;
}
}
if(n-prs<=k){ans=mid;hi=mid-1;}
else lo=mid+1;
}
cout<<ans<<'\n';
}