#include <iostream>
#include <cstdio>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

int sol[1004][1004];

int main() {
#ifdef ACMTUYO
    //freopen("coder.in", "r", stdin);
#endif
    int n;
    cin >> n;
    
    int ret=0;
    bool empe = true, nn = true;
    
    forn(i,n) {
        if(empe) nn = true;
        else nn = false;
        
        forn(j,n) {
            sol[i][j] = nn;
            ret += nn;
            nn = !nn;
        }
        empe = !empe;
    }
    
    cout << ret << endl;
    forn(i,n){
        forn(j,n){
            if(sol[i][j])
                cout << "C";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}