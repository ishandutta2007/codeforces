#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

int k, n;
vector<int> ret[1010];
int stooled[1010];
int cheaper[1010];

int main() {
#ifdef ACMTUYO
    freopen("B.in", "r", stdin);
#endif
    
    cin >> n >> k;
    vector<pair<int, int> > pencils, stools;
    
    double sum=0;
    forn(i, n) {
        int c, t;
        cin >> c >> t;
        sum+=c;
        if(t == 1)
            stools.push_back(make_pair(c, i));
        else
            pencils.push_back(make_pair(c, i));
    }
    
    sort(stools.rbegin(), stools.rend());
    sort(pencils.rbegin(), pencils.rend());
    int ss= stools.size(), ps=pencils.size();
    
    
    memset(cheaper, 0x3f, sizeof(cheaper));
    memset(stooled, 0, sizeof(stooled));
    int si=0, pi = 0;
    while(si<min(ss,k))
    {
        ret[si].push_back(stools[si].second);
        cheaper[si]=min(cheaper[si], stools[si].first);
        stooled[si]=1;
        si++;
    }
    
    while(si+pi<k && pi<ps)
    {
        ret[si+pi].push_back(pencils[pi].second);
        cheaper[si+pi]=min(cheaper[si+pi], pencils[pi].first);
        pi++;
    }
    
    while(si<ss)
    {
        ret[k-1].push_back(stools[si].second);
        cheaper[k-1]=min(cheaper[k-1], stools[si].first);
        si++;
    }
    
    while(pi<ps)
    {
        ret[k-1].push_back(pencils[pi].second);
        cheaper[k-1]=min(cheaper[k-1], pencils[pi].first);
        pi++;
    }
    
    for(int i=0; i<k; i++) if(stooled[i]){ sum-=cheaper[i]/2.0;} 
    printf("%.1f\n", sum);
    for(int i=0; i<k; i++)
    {
        int ks=ret[i].size();
        cout << ks;
        for(int j=0; j<ks; j++) cout << " " << ret[i][j]+1;
        cout << endl;
    }
    
    return 0;
}