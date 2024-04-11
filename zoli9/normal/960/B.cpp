#include <bits/stdc++.h>
using namespace std;
long long k1, k2, k;
int n;
long long aa[100009];
long long bb[100009];
long long ans;
vector<long long> kul;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k1>>k2;
    k=k1+k2;
    for(int i=1; i<=n; i++)
    {
        cin>>aa[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>bb[i];
    }
    for(int i=1; i<=n; i++)
    {
        kul.push_back(abs(aa[i]-bb[i]));
    }
    sort(kul.begin(), kul.end());
    for(int i=1; i<=k; i++)
    {
        if(kul[n-1]==0)
        {
            kul[n-1]=1;
            continue;
        }
        kul[n-1]--;
        int cnt=n-2;
        while(cnt>=0 && kul[cnt]>kul[n-1]) cnt--;
        swap(kul[n-1], kul[cnt+1]);
    }
    for(int i=0; i<n; i++)
    {
        ans+=(kul[i]*kul[i]);
    }
    cout<<ans<<endl;
    return 0;
}