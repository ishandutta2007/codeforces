#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
int osszesen=0;
int k[200009];
vector<int> akcio[200009];
int darabk[400009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>k[i];
        osszesen+=k[i];
    }
    for(int i=1; i<=m; i++)
    {
        int dd, tt;
        cin>>dd>>tt;
        akcio[tt].push_back(dd);
    }
    for(int i=1; i<=n; i++)
    {
        sort(akcio[i].begin(), akcio[i].end());
    }
    int elso=1;
    int utolso=400009;
    while(elso<=utolso)
    {
        int kozep=(elso+utolso)/2;
        for(int i=0; i<=400000; i++)
        {
            darabk[i]=0;
        }
        for(int i=1; i<=n; i++)
        {
            int utolso=-1;
            for(int j=0; j<akcio[i].size(); j++)
            {
                if(akcio[i][j]<=kozep)
                {
                    utolso=akcio[i][j];
                }
                else
                {
                    break;
                }
            }
            if(utolso==-1) continue;
            darabk[utolso]+=k[i];
        }
        int penz=0;
        int marad=osszesen;
        for(int i=1; i<=kozep; i++)
        {
            penz++;
            int vesz=min(penz, darabk[i]);
            penz-=vesz;
            marad-=vesz;
        }
        if(penz>=2*marad)
        {
            utolso=kozep-1;
        }
        else
        {
            elso=kozep+1;
        }
    }
    cout<<elso<<endl;
    return 0;
}