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
int a[maxn], x;

int q[maxn], front, rear;
ll pre[maxn];
int lef[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        cin >> x;
        for(int i = 1;i <= n;i++){
            a[i] -= x;
        }
        pre[0] = 0;
        for(int i = 1;i <= n;i++){
            pre[i] = pre[i-1] + a[i];
        }
        front = 1, rear = 0;
        pre[0] = 0;
        for(int i = 1;i <= n;i++){
            int l = 0, r = rear;
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(pre[q[mid]] > pre[i]){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(l > 0){
                lef[i] = q[l] + 2;
            }else{
                lef[i] = 1;
            }
            while(front <= rear and pre[i - 1] >= pre[q[rear]]){
                rear--;
            }
            q[++rear] = i-1;
        }
        int ans = 0;
        for(int i = 1, j = 1;i <= n;i = j + 2, j = i){
            while(j + 1 <= n and lef[j + 1] <= i){
                j++;
            }
            ans += j - i + 1;
        }
        cout << ans << endl;
    }
    return 0;
}