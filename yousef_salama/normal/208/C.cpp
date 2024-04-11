#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int n, m, u, v, D[105][105];
ll C[105][105];
int main(){
    scanf("%d %d", &n, &m);
//    memset(D, 63, sizeof D);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        D[i][j] = 1000;
    while(m--){
        scanf("%d %d", &u, &v);
        u--, v--;

        D[u][v] = D[v][u] = 1;
        C[u][v] = C[v][u] = 1;
    }
    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(D[i][k] + D[k][j] < D[i][j]){
            D[i][j] = D[i][k] + D[k][j];
            C[i][j] = C[i][k] * C[k][j];
        }
        else if(D[i][k] + D[k][j] == D[i][j])
            C[i][j] += C[i][k] * C[k][j];
    }

    double ret = 1.0;
    for(int i = 1; i < n - 1; i++)
        if(D[0][i] + D[i][n - 1] == D[0][n - 1])
            ret = max(ret, 2.0 * C[0][i] * C[i][n - 1] / C[0][n - 1]);
    printf("%.12f\n", ret);
}