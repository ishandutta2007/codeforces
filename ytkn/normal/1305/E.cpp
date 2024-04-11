#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int cnt[5005];
int ans[5005];

vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N, M;
    cin >> N >> M;
    if(N <= 2){
        if(M != 0){
            cout << -1 << endl;
            return 0;
        }else{
            for(int i = 0; i < N; i++) cout << i+1 << ' ';
            cout << endl;
            return 0;  
        }
    }
    for(int i = 3; i <= N+3; i++){
        cnt[i] = cnt[i-1]+(i-1)/2;
    }
    if(cnt[N] < M){
        cout << -1 << endl;
        return 0;
    }
    int m;
    for(int i = 2; i <= N+1; i++){
        if(cnt[i] > M) {
            m = i-1;
            break;
        }
    }
    for(int i = 0; i < m; i++){
        ans[i] = i+1;
    }
    int rem = M-cnt[m];
    // cout << cnt[3] << ' ' << cnt[4] << ' ' << cnt[5] << endl;
    // cout << m << ' ' << rem << endl;
    ans[m] = 2*m-(rem*2)+1;
    // cout << ans[m] << endl;
    for(int i = m+1; i < N; i++){
        ans[i] = 2*ans[m]*N+(i-m)*2*ans[m];
    }
    for(int i = 0; i < N; i++) cout << ans[i] << ' ';
    cout << endl;
}