#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

long long lefty[100010];
long long match[100010];

struct trip{
    long long a, b, i, l;
    bool operator<(const trip t) const
    {
        if(a!=t.a) return a<t.a;
        if(b!=t.b) return b<t.b;
        if(l!=t.l) return l<t.l;
        return i<t.i;
    }
};

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif
    int n;
    cin >> n;
    vector<trip> parts(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> parts[i].a >> parts[i].b;
        parts[i].i=i;
        parts[i].l=0;
    }
    parts[n].a=10000000000LL;
    parts[n].b=10000000000LL;
    parts[n].i=100000;
    
    int m;
    cin >> m;
    vector<trip> singers(m+1);
    for(int i=0; i<m; i++)
    {
        cin >> singers[i].a >> singers[i].b >> singers[i].l;
        lefty[i]=singers[i].l;
        singers[i].i=i;
    }
    singers[m].a=10000000010LL;
    singers[m].b=10000000010LL;
    singers[m].i=100000;
    
    sort(parts.begin(), parts.end());
    sort(singers.begin(), singers.end());
    
    int ip=0, is=0;
    //long long t=min(parts[ip].a, singers[ip].a);
    
    set<pair<long long, long long> > intervs;
    int ans=0;
    while(ip<n || is<m)
    {
        long long t=min(parts[ip].a, singers[is].a);
        //cout << t << endl;
        while(!intervs.empty() && t>(intervs.begin()->first))
        {
            intervs.erase(intervs.begin());
        }
        
        if(singers[is].a==t)
        {
            intervs.insert(make_pair(singers[is].b, singers[is].i));
            is++;
        }
        else
        {
            set<pair<long long, long long> >::iterator it=intervs.lower_bound(make_pair(parts[ip].b, -1));
            if(it!=intervs.end())
            {
                int i = it->second;
                lefty[i]--;
                if(lefty[i]==0) intervs.erase(it);
                ans++;
                match[parts[ip].i]=i+1  ;
            }
            ip++;
        }
    }
    
    if(ans==n){
        cout << "YES" << endl;
        for(int i=0; i<n; i++)
        {
            if(i) cout << " ";
            cout << match[i];
        }
        cout << endl;
    }    
    else cout << "NO" << endl;
}