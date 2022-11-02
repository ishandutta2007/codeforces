#include <bits/stdc++.h>
using namespace std;
long long kob[100009];
long long m;
pair<long long, long long> mennyi(long long x)
{
    if(x<8) return make_pair(x, x);
    int legfhely=0;
    while(kob[legfhely]<=x) legfhely++;
    legfhely--;
    pair<long long, long long> fe=mennyi(x-kob[legfhely]);
    pair<long long, long long> al=mennyi(kob[legfhely]-1-kob[legfhely-1]);
    if(fe.first>=al.first) return make_pair(fe.first+1, kob[legfhely]+fe.second);
    return make_pair(al.first+1, kob[legfhely-1]+al.second);
}
int main()
{
    cin>>m;
    for(long long i=0; i<=100001; i++)
    {
        kob[i]=i*i*i;
    }
    pair<long long, long long> ans=mennyi(m);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}