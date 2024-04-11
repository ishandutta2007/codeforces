#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
int n;
const int maxn = 1005;
int a[maxn][maxn];

int color[maxn];
int fa[maxn];

int Find(int x){
    if(x == fa[x])
        return fa[x];
    else{
        int newfa = Find(fa[x]);
        color[x] ^= color[fa[x]];
        fa[x] = newfa;
        return fa[x];
    }
}

bool ok(int x, int y, int c){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy){
        return (color[x] ^ color[y]) == c; 
    }else{
        return true;
    }
}

void merge(int x, int y, int c){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy){
        return;
    }else{
        fa[fx] = fy;
        color[fx] = c^color[x]^color[y];
    }
}

void init(){
    memset(color, 0, sizeof(color));
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        init();
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(a[i][j] > a[j][i]){
                    if(ok(i, j, 1)){
                        merge(i, j, 1); 
                        swap(a[i][j], a[j][i]);
                    }
                }else if(a[i][j] < a[j][i]){
                    if(ok(i, j, 0)){
                        merge(i, j, 0);
                    }else{
                        swap(a[i][j], a[j][i]);
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cout << a[i][j] << " \n"[j == n];
            }
        }
    }
    return 0;
}