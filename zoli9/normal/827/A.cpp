#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
string s[100009];
vector<pair<int, int> > v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        int dbb;
        cin>>dbb;
        for(int j=1; j<=dbb; j++)
        {
            int kezd;
            cin>>kezd;
            v.push_back({kezd, i});
        }
    }
    sort(v.begin(), v.end());
    int akti=0;
    string w(2000009, 'a');
    for(int i=0; i<v.size(); i++)
    {
        akti=max(akti, v[i].F);
        while(akti<=v[i].F+s[v[i].S].size()-1)
        {
            w[akti]=s[v[i].S][akti-v[i].F];
            akti++;
        }
    }
    cout<<w.substr(1, akti-1)<<endl;
    return 0;
}