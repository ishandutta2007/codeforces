#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 505;
const long long INF = (long long)1e18;
long long Lx[maxn], Ly[maxn], W[maxn][maxn], slack[maxn];
bool S[maxn], T[maxn];
int Left[maxn];
int n;
int a[maxn], b[maxn], k[maxn];

bool match(int u){
    S[u] = true;
    for(int i = 1;i <= n;i++){
        if(T[i]) continue;
        long long t = Lx[u] + Ly[i] - W[u][i];
        if(!t){
            T[i] = true;
            if((Left[i] == -1) || match(Left[i])){
                Left[i] = u;
                return true;
            }
        }else slack[i] = min(slack[i], t);
    }
    return false;
}

void update(){
    long long d = INF;
    for(int i = 1;i <= n;i++){
        if(!T[i]) d = min(d, slack[i]);
    }
    for(int i = 1;i <= n;i++){
        if(S[i]) Lx[i] -= d;
        if(T[i]) Ly[i] += d;
    }
}

void KM(){
    for(int i = 1;i <= n;i++){
        Lx[i] = Ly[i] = 0;
        Left[i] = -1;
        for(int j = 1;j <= n;j++){
            Lx[i] = max(Lx[i], W[i][j]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            slack[j] = INF;
        }
        while(true){
            for(int j = 1;j <= n;j++)
                S[j] = T[j] = false;
            if(match(i)){
                break;
            }
            else update();
        }
    }
}


int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            cin >> a[i] >> b[i] >> k[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                W[i][j] = max(0LL, a[i] - 1LL * min((j - 1), k[i]) * b[i]); 
            }
        }
        KM();
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            ans += Lx[i] + Ly[i];
        }
        cout << ans << endl;
    }
    return 0;
}