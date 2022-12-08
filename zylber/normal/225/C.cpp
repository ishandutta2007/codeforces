#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

int n,m,x,y, bl[1004], ne[1004];
string mapa[1004];

const int INF = 1010*1010;

int dp[1004][1004][2];
int calc(int pos, int ant, int blanco) {
    if(pos == m) {
        if((pos-ant) >= x && (pos-ant) <= y)
            return 0;
        else
            return INF;
    }
    
    int &ret = dp[pos][ant][blanco];
    if(ret != -1)
        return ret;
    
    ret = INF;
    if(pos == ant) {
        ret = min(ret, min(calc(pos+1,ant,1)+ne[pos], calc(pos+1, ant, 0)+bl[pos]));
    } else {
        if(blanco)
            ret = min(ret, ne[pos]+calc(pos+1,ant,1));
        else
            ret = min(ret, bl[pos]+calc(pos+1,ant,0));
        
        if((pos-ant) >= x && (pos-ant) <= y){
            if(blanco)
                ret = min(ret, bl[pos]+calc(pos+1,pos,0));
            else
                ret = min(ret, ne[pos]+calc(pos+1,pos,1));
        }
    }
    
    return ret;
}

int main() {
#ifdef ACMTUYO
    freopen("barcode.in", "r", stdin);
#endif
    cin >> n >> m >> x >> y;
    
    forn(i,n) cin >> mapa[i];
    
    memset(bl, 0, sizeof(bl));
    memset(ne, 0, sizeof(ne));
    
    forn(i,n) forn(j,m){
        if(mapa[i][j] == '#')
            ne[j]++;
        else
            bl[j]++;
    }
    
    /*forn(i,m) {
        cout << ne[i] << " " << bl[i] << endl;
    }*/
    
    memset(dp, -1, sizeof(dp));
    
    cout << calc(0,0,0) << endl;
    
    return 0;
}