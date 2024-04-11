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



struct caso{
    tint size;
    tint hash;
    int pos;
    char r;

    bool operator<(const caso c) const
    {
        if(size!=c.size) return size<c.size;
        if(hash!=c.hash) return hash<c.hash;
        if(pos!=c.pos) return pos<c.pos;
        return r<c.r;
    }
};

tint diff(string s, string g)
{
    tint res=0;
    int ss=s.size();
    forn(i, ss) res+=(s[i]!=g[i]);
    return res;
}

map<caso, vector<int> > trie;

string ss[300010];;

int main()
{
#ifdef ACMTUYO
    freopen("291C.in","r",stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n)
    {
        caso c;
        cin >> ss[i];
        c.size= ss[i].size();
        c.hash=0;
        
        tint pot=1;
        forn(j, c.size)
        {
            c.hash+=pot*(tint)(ss[i][j]-'a');
            c.hash%=MOD;
            pot=(pot*3)%MOD;
        }
        
        pot=1;
        forn(j, c.size)
        {
            c.r=ss[i][j];
            c.pos=j;
            c.hash-=(pot*(tint) (ss[i][j]-'a'))%MOD;
            c.hash=(c.hash+MOD)%MOD;
            trie[c].push_back(i);
            c.hash+=(pot*(tint) (ss[i][j]-'a'))%MOD;
            c.hash%=MOD;
            
            pot=(pot*3)%MOD;
        }
    }
    
    forn(i, m)
    {
        string q;
        cin >> q;
        caso c;
        c.hash=0;
        c.size=q.size();
        
        tint pot=1;
        forn(j, c.size)
        {
            c.hash+=pot*(tint)(q[j]-'a');
            c.hash%=MOD;
            pot=(pot*3)%MOD;
        }
        
        pot=1;
        int found=0;
        forn(j, c.size)
        {
            c.pos=j;
            c.hash-=(pot*(tint) (q[j]-'a'))%MOD;
            c.hash=(c.hash+MOD)%MOD;
            
            int k=q[j]-'a';
            forn(i, 2)
            {
                k=(k+1)%3;
                c.r='a'+k;
                
                if(trie.count(c))
                {
                    
                    vector<int>::iterator it=trie[c].begin();
                    while(it!=trie[c].end()) 
                    {
                        if(diff(ss[(*it)], q)==1)
                        {
                            found=1;
                            break;
                        }
                        it++;
                    }
                }
            }
            if(found) break;
            
            c.hash+=(pot*(tint) (q[j]-'a'))%MOD;
            c.hash%=MOD;
            
            pot=(pot*3)%MOD;
        }
        
        if(found) cout << "YES" << endl; else cout << "NO" << endl;
    }
    
    return 0;
}