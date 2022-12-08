#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <map>
#include <set>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

#define MAXN 30010

set<int> dep[MAXN];
int n, m;

int main() {
#ifdef ACMTUYO
    freopen("awards.in", "r", stdin);
#endif
    cin >> n >> m;
    forn(i,n) dep[i].clear();
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        dep[a].insert(b);
    }
    
    list<int> ret;
    
    ret.push_back(0);
    
    forsn(i,1,n){
        int ant = -1;
        bool listo = false;
        forall(it, ret){
            if(!dep[i].count(*it))
                if(ant == -1 || !dep[ant].count(i)){
                    ret.insert(it, i);
                    listo = true;
                    break;
                }
        }
        if(!listo)
            ret.push_back(i);
    }
    
    forall(it, ret) {
        if(it != ret.begin())
            cout << " ";
        cout << *it+1;
    }
    cout << endl;
    
    return 0;
}