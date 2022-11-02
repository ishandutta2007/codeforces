#include <bits/stdc++.h>
using namespace std;
int test;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int ans=0;
        for(int i=0; i<8; i++)
        {
            vector<int> v1, v2;
            for(int j=1; j<=n; j++)
            {
                int z=j;
                if((z>>i)%2==1) v1.push_back(j);
                else v2.push_back(j);
            }
            if(v1.size()==0 || v2.size()==0) continue;
            cout<<v1.size()<<" "<<v2.size();
            for(int u=0; u<v1.size(); u++)
            {
                cout<<" "<<v1[u];
            }
            for(int u=0; u<v2.size(); u++)
            {
                cout<<" "<<v2[u];
            }
            cout<<endl;
            fflush(stdout);
            int qu;
            cin>>qu;
            ans=max(ans, qu);
        }
        cout<<-1<<" "<<ans<<endl;
        fflush(stdout);
    }
    return 0;
}