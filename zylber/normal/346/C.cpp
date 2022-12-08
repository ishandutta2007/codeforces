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
using namespace std;

int main()
{
#ifdef ACMTUYO
    freopen("201.C.in","r",stdin);
#endif
    
    int n;
    cin >> n;
    set<int> numbers;
    
    forn(i, n){ int a; cin >> a; numbers.insert(a); }
    
    int a, b; cin >> a >> b;
    
    int ans=0;
    while(a!=b)// && !numbers.empty())
    {
        int bestnext=a-1;
        //cout << a << endl;
        ans++;
        
        for(set<int>::iterator it=numbers.begin(); it!=numbers.end(); it++)
        {
            int m=(*it);
            while(it!=numbers.end() && a-a%m<b)
            {
                numbers.erase(it++);
                if(it==numbers.end()) break;
                m=(*it);
            }
            if(it==numbers.end()) break;
            bestnext=min(bestnext, a-a%m);
        }
        a=bestnext;
    }
    cout << ans << endl;
    
    return 0;
}