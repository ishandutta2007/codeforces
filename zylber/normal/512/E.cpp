#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

set<int> diags[1028];
set<int> goal[1028];
int next[1028], prev[1028];
int isfix[1028];

vector<pair<int, int> > ans;

int main()
{
#ifdef ACMTUYO
    freopen("E.in","r",stdin);
#endif

    int n;
    cin >> n;
    
    forn(i, n)
    {
        next[i]=(i+n-1)%n;
        prev[i]=(i+1)%n;
        diags[i].insert((i+n-1)%n);
        diags[i].insert((i+1)%n);
        goal[i]=diags[i];
    }
    
    forn(i, n-3)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        diags[a].insert(b);
        diags[b].insert(a);
    }
    
    forn(i, n-3)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        goal[a].insert(b);
        goal[b].insert(a);
    }
    
    int fixed=0;
    while(fixed<n-3)
    {
        forn(i, n)
        if(!isfix[i])
        {
            if(fixed==n-3) break;
            
            if(goal[i].size()==2)
            {
                int ds=diags[i].size();
                while(ds>2)
                {
                    set<int>::iterator it=diags[i].lower_bound(prev[i]);
                    int a=(*it);
                    it++; if(it==diags[i].end()) it=diags[i].begin();
                    int op=(*it);
                    it++; if(it==diags[i].end()) it=diags[i].begin();
                    int b=(*it);
                    
                    ans.push_back(make_pair(i+1, op+1));
                    diags[i].erase(op);
                    diags[op].erase(i);
                    diags[a].insert(b);
                    diags[b].insert(a);
                    ds--;
                }
                
                diags[prev[i]].erase(i);
                diags[next[i]].erase(i);
                goal[prev[i]].erase(i);
                goal[next[i]].erase(i);
                next[prev[i]]=next[i];
                prev[next[i]]=prev[i];
                
                isfix[i]=1;
                fixed++;
            }
        }
    }
    
    int as=ans.size();
    cout << as << endl;
    forn(i, as)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    return 0;
}