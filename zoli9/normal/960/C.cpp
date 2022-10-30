#include <bits/stdc++.h>
using namespace std;
long long X, D;
long long h2[34];
vector<long long> ans;
long long val;
int main()
{
    ios::sync_with_stdio(false);
    cin>>X>>D;
    h2[0]=1;
    val=1;
    for(long long i=1; i<34; i++)
    {
        h2[i]=2*h2[i-1];
    }
    while(X>0)
    {
        int cnt=0;
        for(int i=0; i<34; i++)
        {
            if(h2[i]-1<=X) cnt=i;
            else break;
        }
        for(int i=1; i<=cnt; i++)
        {
            ans.push_back(val);
        }
        X-=(h2[cnt]-1);
        val+=(D+1);
        //cout<<X<<endl;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}