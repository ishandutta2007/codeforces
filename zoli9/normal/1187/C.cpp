#include <bits/stdc++.h>
using namespace std;
int n, q;
bool sorted[1009];
vector<pair<int, int> > nos;
int ans[1009];
void re(int x, int y)
{
    while(x<y)
    {
        swap(ans[x], ans[y]);
        x++;
        y--;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int tt=1; tt<=q; tt++)
    {
        int tp, left, right;
        cin>>tp>>left>>right;
        if(tp==1)
        {
            for(int i=left; i<right; i++)
            {
                sorted[i]=true;
            }
        }
        else
        {
            nos.push_back({left, right});
        }
    }
    for(pair<int, int> pp: nos)
    {
        bool ok=false;
        for(int i=pp.first; i<pp.second; i++)
        {
            if(!sorted[i])
            {
                ok=true;
                break;
            }
        }
        if(!ok)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=1; i<=n; i++) ans[i]=i;
    int kezd=-1;
    for(int i=1; i<n; i++)
    {
        if(sorted[i])
        {
            if(kezd!=-1)
            {
                re(kezd, i);
                kezd=-1;
            }
        }
        else
        {
            if(kezd==-1)
            {
                kezd=i;
            }
        }
    }
    if(kezd!=-1)
    {
        re(kezd, n);
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}