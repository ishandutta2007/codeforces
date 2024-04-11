#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n;
long long TI;
vector<pair<pair<int, long long>, int> > s;
vector<long long> akt;
vector<pair<long long, int> > w;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>TI;
    for(int i=1; i<=n; i++)
    {
        int aa, tt;
        cin>>aa>>tt;
        s.push_back({{aa, tt}, i});
    }
    sort(s.begin(), s.end());
    int elso=0;
    int utolso=n;
    while(elso<=utolso)
    {
        int kozep=(elso+utolso)/2;
        akt.clear();
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i].F.F<kozep) break;
            akt.push_back(s[i].F.S);
        }
        if(akt.size()<kozep)
        {
            utolso=kozep-1;
            continue;
        }
        sort(akt.begin(), akt.end());
        long long sum=0;
        for(int u=0; u<kozep; u++) sum+=akt[u];
        if(sum<=TI) elso=kozep+1;
        else utolso=kozep-1;
    }
    cout<<utolso<<endl;
    cout<<utolso<<endl;
    w.clear();
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i].F.F<utolso) break;
        w.push_back({s[i].F.S, s[i].S});
    }
    sort(w.begin(), w.end());
    for(int u=0; u<utolso; u++)
    {
        cout<<w[u].S<<" ";
    }
    cout<<endl;
    return 0;
}