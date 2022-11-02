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
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
ll sufa[maxn], sufb[maxn];

bool check(int m){
    int N = n + m; 
    int k = max(0, N - N / 4 - m);
    ll ans1 = m * 100LL + sufa[n - k + 1] - sufa[n + 1]; 
    int k1 = min(n, N - N / 4);
    ll ans2 = sufb[n - k1 + 1] - sufb[n + 1];
    return ans1 >= ans2;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        sufa[n + 1] = 0;
        sufb[n + 1] = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for(int i = 1;i <= n;i++){
            cin >> b[i];
        }
        sort(b + 1, b + 1 + n);
        for(int i = n;i >= 1;i--){
            sufa[i] = sufa[i+1] + a[i];
            sufb[i] = sufb[i+1] + b[i];
        }
        int l = 0, r = n * 10;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}