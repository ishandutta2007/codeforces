#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())


const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

/////////////////////////////
int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}
/////////////////////////////


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string ss;
    cin >> n >> k >> ss;
    vector<int> jaw(k, 0);
    string jaw1 = "";
    for(int i = 0; i < n; i++) jaw1 += ss[i % k];
    if(jaw1 >= ss){
        cout << n << endl << jaw1 << endl;
        return 0;
    }
    jaw1 = "";
    for(int i = 0; i < k; i++) jaw1 += ss[i % k];
    int now = sz(jaw1) - 1;
    while(1){
        if(jaw1[now] == '9'){
            jaw1[now] = '0';
            now -= 1;
            continue;
        }
        jaw1[now] += 1;
        break;
    }
    string jaw2 = "";
    for(int i = 0; i < n; i++) jaw2 += jaw1[i % k];
    cout << n << endl << jaw2 << endl;
}