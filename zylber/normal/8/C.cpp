#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define contains(mask, bit) ((mask & (1<<bit)) != 0)

int xs, ys, n;
int posx[32], posy[32];

int dp[(1<<24)];
pair<int, int> vengo[(1<<24)];

#define cuad(x) ((x)*(x))

int calcDist(int xa, int ya, int xb, int yb) {
    return cuad(xa-xb)+cuad(ya-yb);
}

bool esp;
void dfs(int e){
    if(e == 0) {
        return;
    }
    
    int ve = e;
    if(vengo[e].first == vengo[e].second)
        ve ^= (1<<vengo[e].first);
    else
        ve ^= (1<<vengo[e].first) | (1<<vengo[e].second);
    
    dfs(ve);
    
    if(esp) cout << " ";
    else esp = true;
    cout << "0 ";
    if(vengo[e].first == vengo[e].second)
        cout << vengo[e].first+1;
    else
        cout << vengo[e].first+1 << " " << vengo[e].second+1;
}

int main()
{
#ifdef ACMTUYO
    freopen("H.in", "r", stdin);
#endif

    cin >> xs >> ys >> n;
    
    forn(i,n) cin >> posx[i] >> posy[i];
    
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    forn(mask, (1<<n)-1) if(dp[mask] != -1){
        int a;
        forn(k,n) if(!contains(mask, k)){
            a = k;
            break;
        }
        forn (b,n) if(!contains(mask, b)) {
            //cout << "CASO: " << a << " " << b << " " << mask << " " << dp[mask] << endl;
            int dist;
            if(a == b) {
                dist = calcDist(xs, ys, posx[a], posy[a])*2;
            }else{
                dist = calcDist(xs, ys, posx[a], posy[a]) + calcDist(posx[a], posy[a], posx[b], posy[b]) + calcDist(posx[b], posy[b], xs, ys);
            }
            int mm = mask | (1<<a) | (1<<b);
            dist += dp[mask];
            //cout << dist << " " << mm << endl;
            if(dp[mm] == -1 || dp[mm] > dist){
                vengo[mm] = make_pair(a,b);
                dp[mm] = dist;
            }
        }
    }
    
    cout << dp[(1<<n)-1] << endl;
    esp = false;
    dfs((1<<n)-1);
    cout << " 0" << endl;
    return 0;
}