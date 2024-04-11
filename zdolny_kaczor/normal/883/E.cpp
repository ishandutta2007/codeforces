#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
string wzo;
int n;
char ods[150];

int il = 0;
int cnt[150];
void add(string s)
    {
    set<int> S;
    il++;
    REP(i, s.size())
        {
        if(!ods[s[i]])
            {
            if(S.count(s[i]))continue;
            S.insert(s[i]);
            cnt[s[i]]++;
            }
        }
    }

int main()
    {
    cin>>n;
    cin>>wzo;
    REP(i, wzo.size())
        {
        if(wzo[i] != '*')ods[wzo[i]]=1;
        }
    int k;
    cin>>k;
    REP(i, k)
        {
        string s;
        cin>>s;
        
        string s2;
        REP(j, s.size())
            {
            s2 += ods[s[j]] ? s[j] : '*';
            }
        if(s2 == wzo)
            {
            add(s);
            }
        }
    int r = 0;
    
    FOR(i, 'a', 'z')
        {
        if(il == cnt[i])r++;
        }
    cout<<r<<endl;
    }