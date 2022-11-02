#include <bits/stdc++.h>
using namespace std;
int n, m;
int db[5009];
int kozel[5009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        kozel[i]=-1;
    }
    for(int i=1; i<=m; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        aa--;
        bb--;
        db[aa]++;
        int akttav=(bb-aa+n)%n;
        if(kozel[aa]==-1 || akttav<kozel[aa])
        {
            kozel[aa]=akttav;
        }
    }
    for(int i=0; i<n; i++)
    {
        int ans=0;
        for(int j=0; j<n; j++)
        {
            if(db[j]==0) continue;
            int tt=(j-i+n)%n;
            int atav=n*(db[j]-1)+tt+kozel[j];
            ans=max(ans, atav);

        }
                    cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}