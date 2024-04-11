#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int T;
int n;
string A, B;

int g[30][30];

int fa[30];

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        cin >> A >> B;
        memset(g, 0, sizeof(g));
        for(int i = 0;i < 20;i++){
            fa[i] = i;
        }
        bool flag = true;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(A[i] > B[i]){
                flag = false;
            }else if(A[i] < B[i]){
                int a = A[i] - 'a';
                int b = B[i] - 'a';
                int fx = Find(a);
                int fy = Find(b);
                if(fx != fy){
                    cnt++;
                    fa[fx] = fy;
                }
            }
        }
        if(flag){
            cout << cnt << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}