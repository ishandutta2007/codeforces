#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m;

int mah[333];
int ans[333];

int best = -1;

vector<int> grafin[333];
vector<int> grafout[333];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        if(c)
        {
            grafout[b].push_back(a);
            grafin[a].push_back(b);
        }
        else
        {
            grafout[a].push_back(b);
            grafout[b].push_back(a);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        bool change = 1;
        for(int j = 1; j <= n; j++)
            mah[j] = 1e9;
        mah[i] = 0;
        int iter = 0;
        bool ok = true;
        while(change)
        {
            change = false;
            for(int j = 1; j <= n; j++)
            {
                for(int e = 0; e < grafin[j].size(); e++)
                {
                    if(mah[grafin[j][e]]-1 < mah[j])
                    {
                        mah[j] = mah[grafin[j][e]]-1;
                        change = true;
                    }
                }
                for(int e = 0; e < grafout[j].size(); e++)
                {
                    if(mah[grafout[j][e]]+1 < mah[j])
                    {
                        mah[j] = mah[grafout[j][e]]+1;
                        change = true;
                    }
                }   
            }
            iter++;
            if(iter > n+2)
            {
                ok = false;
                break;
            }
        }
        for(int j = 1; j <= n; j++)
        {
            for(int e = 0; e < grafin[j].size(); e++)
                if(mah[j] == mah[grafin[j][e]])
                    ok = false;
            for(int e = 0; e < grafout[j].size(); e++)
                if(mah[j] == mah[grafout[j][e]])
                    ok = false;
        }
        int mi = 0;
        for(int j = 1; j <= n; j++)
            mi = min(mi, mah[j]);
        for(int j = 1; j <= n; j++)
            mah[j] -= mi;
        int ma = 0;
        for(int j = 1; j <= n; j++)
            ma = max(ma, mah[j]);
        if(ok && ma > best)
        {
            best = ma;
            for(int j = 1; j <= n; j++)
                ans[j] = mah[j];
        }
    }
    if(best == -1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<best<<endl;
        for(int j = 1; j <= n; j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
    
    return 0;
}