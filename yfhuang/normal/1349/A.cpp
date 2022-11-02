#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;

vector<int> Div[maxn];
bool vis[maxn];

vector<int> cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vis[1] = 1;
    for(int i = 2;i < maxn;i++){
        if(!vis[i]){
            Div[i].push_back(i);
            for(int j = i * 2;j < maxn;j += i){
                vis[j] = 1;
                Div[j].push_back(i);
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        int tmp = a;
        for(auto d : Div[a]){
            int c = 0;
            int num = 1;
            while(tmp % d == 0){
                c++;
                tmp /= d;
                num *= d;
            }
            cnt[d].push_back(num);
        }
    }
    long long ans = 1;
    for(int i = 1;i < maxn;i++){
        if(!vis[i]){
            sort(cnt[i].begin(), cnt[i].end());
            int zero = n - cnt[i].size();
            if(zero >= 2){
                continue;
            }else if(zero == 1){
                ans = ans * cnt[i][0];
            }else{
                ans = ans * cnt[i][1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}