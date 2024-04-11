#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int test;
int n, m;
int col[500009];
int row[500009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++) row[i]=0;
        for(int i=0; i<m; i++) col[i]=0;
        vector<vector<bool> > v;
        for(int i=0; i<n; i++)
        {
            vector<bool> w(m);
            for(int j=0; j<m; j++)
            {
                char ccc;
                cin>>ccc;
                if(ccc=='*')
                {
                    row[i]++;
                    col[j]++;
                    w[j]=true;
                }
                else w[j]=false;
            }
            v.push_back(w);
        }
        int bestans=n+m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int aktans=n+m-row[i]-col[j];
                if(!v[i][j]) aktans--;
                bestans=min(bestans, aktans);
            }
        }
        cout<<bestans<<endl;
    }
    return 0;
}