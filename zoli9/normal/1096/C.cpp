#include <bits/stdc++.h>
using namespace std;
int test;
int ans[200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=3; i<=360; i++)
    {
        //cout<<i<<"*"<<endl;
        int szaml=180;
        int nev=i;
        for(int j=1; j<=i-2; j++)
        {
            int sss=szaml*j;
            if(sss%nev==0)
            {
                //cout<<"!"<<endl;
                if(ans[sss/nev]==0) ans[sss/nev]=i;
            }
        }
    }
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        int qu;
        cin>>qu;
        if(ans[qu]>0) cout<<ans[qu]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}