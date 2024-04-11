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
int n, k;
const int maxn = 1e5 + 5;

int a[maxn];
map<int, int> vis;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> k;
        bool flag = false;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(a[i] == k)
                flag = true;
        }
        if(n == 1 and a[1] == k){
            cout << "yes" << endl;
            continue;
        }
        if(!flag){
            cout << "no" << endl;
            continue;
        }else{
            bool ok = false;
            for(int i = 1;i < n;i++){
                if(a[i] >= k and a[i + 1] >= k){
                   ok = true; 
                } 
            }
            if(ok){
                cout << "yes" << endl;
                continue;
            }
            ok = false;
            vis.clear();
            int pre = 0;
            vis[pre] = 0;
            for(int i = 1;i <= n;i++){
                if(a[i] >= k){
                    pre++;
                }else{
                    pre--;
                }
                if(vis.count(pre - 1) and vis[pre - 1] != i - 1){
                    ok = true;
                }
                if(!vis.count(pre)){
                    vis[pre] = i;
                }
            }
            if(ok)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}