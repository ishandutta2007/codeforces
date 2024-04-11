#include <bits/stdc++.h>
using namespace std;
long long hanyotos[1000009];
long long kum[1000009];
vector<long long> ans;
long long m;
int main()
{
    cin>>m;
    for(long long i=1; i<=1000000; i++)
    {
        long long akt=i;
        while(akt%5==0)
        {
            hanyotos[i]++;
            akt/=5;
        }
    }
    kum[0]=0;
    for(long long i=1; i<=1000000; i++)
    {
        kum[i]=kum[i-1]+hanyotos[i];
        if(kum[i]==m)
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}