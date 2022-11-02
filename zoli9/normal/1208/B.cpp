#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t[2009];
bool was[2009];
map<int, int> ma;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int id=0;
    bool semmi=true;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(ma[t[i]]>0)
        {
            semmi=false;
        }
        else
        {
            id++;
            ma[t[i]]=id;
        }
    }
    if(semmi)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        t[i]=ma[t[i]];
    }
    int ans=n;
    for(int l=1; l<=n; l++)
    {
        for(int i=1; i<=id; i++) was[i]=false;
        bool ok=true;
        for(int i=1; i<l; i++)
        {
            if(was[t[i]])
            {
                ok=false;
                break;
            }
            was[t[i]]=true;
        }
        if(!ok) continue;
        int j=n;
        while(j>=l)
        {
            if(was[t[j]])
            {
                break;
            }
            was[t[j]]=true;
            j--;
        }
        ans=min(ans, j-l+1);
    }
    cout<<ans<<endl;



    return 0;
}