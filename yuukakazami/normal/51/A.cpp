#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <numeric>
#include <cstdio>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;

int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    set<vi> S;
    REP(i,n)
    {
        string a,b;cin>>a>>b;
        vi v;v.PB(a[0]);v.PB(a[1]);v.PB(b[1]);v.PB(b[0]);
        vi Min=v;
        REP(i,4)
        {
            int t=*v.begin();
            v.erase(v.begin());
            v.PB(t);
            Min=min(Min,v);
        }
        S.insert(Min);
        cin>>a;
    }
    cout<<S.size()<<endl;
}