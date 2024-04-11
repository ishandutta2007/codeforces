#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int N;
set<int> st;
int cnt[500005];
int deleted[500005];
int cur;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    cur = N;
    for(int i = N; i >= 1; i--){
        cnt[i] = cur;
        for(int j = 2; i*j <= N; j++){
            if(!deleted[i*j]){
                cur--;
                deleted[i*j] = true;
            }
        }
    }
    // for(int i = 1; i <= N; i++) cout << cnt[i] << ' ';
    // cout << endl;
    for(int i = 2; i <= N; i++){
        auto p = lower_bound(cnt+1, cnt+N+1, i);
        cout << p-cnt << ' ';
    }
    cout << endl;
}