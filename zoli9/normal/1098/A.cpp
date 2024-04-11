#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[100009];
int apa[100009];
long long A[100009];
long long S[100009];
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        int pare;
        cin>>pare;
        G[pare].push_back(i);
        apa[i]=pare;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>S[i];
    }
    apa[1]=-1;
    for(int i=1; i<=n; i++)
    {
        if(S[i]==-1)
        {
            if(G[i].size()==0)
            {
                S[i]=S[apa[i]];
            }
            else
            {
                S[i]=S[G[i][0]];
                for(int j=1; j<G[i].size(); j++)
                {
                    S[i]=min(S[i], S[G[i][j]]);
                }
            }
        }
    }
    A[1]=S[1];
    ans=A[1];
    for(int i=2; i<=n; i++)
    {
        A[i]=S[i]-S[apa[i]];
        if(A[i]<0)
        {
            cout<<-1<<endl;
            return 0;
        }
        ans+=A[i];
    }
    cout<<ans<<endl;
    return 0;
}