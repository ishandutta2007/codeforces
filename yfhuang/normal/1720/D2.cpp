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
const int maxn = 3e5 + 5;
int a[maxn];

int tot;
int ch[maxn * 60][2];
int val[maxn * 60][2];
const int MAXB = 30;
const int INF = 1e9;

void init(){
    tot = 0;
    memset(ch[tot], -1, sizeof(ch[tot]));
}

void insert(int i, int ai, int X){
    int cur = 0;
    int v = i ^ ai;
    for(int b = MAXB - 1;b >= 0;b--){
        int bit = (v >> b) & 1; 
        if(ch[cur][bit] == -1){
            ch[cur][bit] = ++tot;
            memset(ch[tot], -1, sizeof(ch[tot]));
            val[tot][0] = val[tot][1] = 0;
        }
        cur = ch[cur][bit];
        int bit1 = (ai >> b) & 1;
        val[cur][bit1] = max(val[cur][bit1], X); 
    }
}   

int query(int i, int ai){
    int cur = 0;
    int v = i ^ ai;
    int ans = 0;
    for(int b = MAXB - 1;b >= 0;b--){
        int bit = (v >> b) & 1;
        int bit1 = (i >> b) & 1;
        if(ch[cur][bit ^ 1] != -1){
            int to = ch[cur][bit ^ 1];
            ans = max(ans, val[to][bit1]);
        }
        if(ch[cur][bit] == -1)
            break;
        cur = ch[cur][bit];
    } 
    ans++;
    return ans;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        tot = 0;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        int ans = 0;
        init();
        for(int i = 0;i < n;i++){
            int dp = query(i, a[i]);
            ans = max(ans, dp);
            insert(i, a[i], dp); 
        }
        cout << ans << endl;
    }
    return 0;
}