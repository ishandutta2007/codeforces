#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[30];
int rendez(const void *a, const void *b)
{
    return (*(long long*)a)-(*(long long*)b);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    qsort(t+1, n, sizeof(long long), rendez);
    long long ans=0;
    long long maxi=t[n];
    for(int i=n; i>=1; i--)
    {
        ans+=min(maxi, t[i]);
        maxi=min(t[i]-1, maxi-1);
        if(maxi<0) maxi=0;
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}