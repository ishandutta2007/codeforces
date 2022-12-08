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

string names[128];

int pre[32][32];
int isin[26];

int main()
{
#ifdef ACMTUYO
    freopen("A.in","r",stdin);
#endif

    int n;
    cin >> n;
    
    forn(i, n)
    {
        cin >> names[i];
    }
    
    forn(i, n)
    forn(k, i)
    {
        int j=0;
        int js=min(names[i].size(), names[k].size());
        while(j<js && names[i][j]==names[k][j]) j++;
        
        if(j==js && names[i].size()<names[k].size())
        {
            cout << "Impossible" << endl;
            return 0;
        }
        if(j<js) pre[names[i][j]-'a'][names[k][j]-'a']++;
    }
    
    string ans="";
    int in=0, meti=1;
    while(in<26 && meti)
    {
        meti=0;
        forn(i, 26)
        if(!isin[i])
        {
            int deg=0;
            forn(j, 26) if(pre[i][j] && !isin[j]) deg++;
            
            if(deg==0)
            {
                ans+='a'+i;
                meti=1;
                in++;
                isin[i]=1;
            }
        }
    }
    
    if(in==26)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    
    return 0;
}