#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

void solve(){
    int n;
    cin >> n;
    vector<int> c(n), cnt(n, 0);
    int mini = 1e9;
    vector<int> non_zero;
    for(int &i : c){
        cin >> i;
        i -= 1;
        cnt[i] += 1;
    }
    for(int i = 0; i < n; i++){
        if(cnt[i] > 0){
            mini = min(mini, cnt[i]);
            non_zero.push_back(i);
        }
    }
    int jaw = 1e9;
    for(int s = 2; s <= mini + 1; s++){
        int ans = 0;
        for(int i : non_zero){
            if(cnt[i] % s == 0){
                ans += cnt[i] / s;
            }
            // else if(s == 2){
            //     ans += (cnt[i] + 1) / 2;
            // }
            else{
                int brp = cnt[i] / (s - 1);
                int sisa = cnt[i] % (s - 1);
                int apa = -1;
                if(sisa <= brp){
                    apa = brp;
                }
                brp = cnt[i] / s;
                sisa = cnt[i] % s;
                int kurang = s - 1 - sisa;
                if(brp >= kurang){
                    if(apa == -1) apa = brp + 1;
                    else apa = min(apa, brp + 1);
                }
                if(apa == -1){
                    ans = -1;
                    break;
                }
                ans += apa;
            }
        }
        if(ans != -1) jaw = min(jaw, ans);
    }
    cout << jaw << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}