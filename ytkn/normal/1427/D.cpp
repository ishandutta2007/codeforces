#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

int n;
vector<int> d, ord;

vector<vector<int>> ope;

// dord
void operate(vector<int> op){
    vector<int> buf(n);
    for(int i = 0; i < n; i++) buf[i] = d[i];
    int cur = 0;
    int idx = n-1;
    for(int len : op){
        for(int i = cur+len-1; i >= cur; i--){
            d[idx] = buf[i];
            idx--;
        }
        cur += len;
    }
    for(int i = 0; i < n; i++) ord[d[i]] = i;
}

// m, m+1
void concat(int m){
    vector<int> cur_op;
    if(ord[m+1] != 0) cur_op.push_back(ord[m+1]);
    int cnt = 1;
    for(int i = ord[m+1]; ; i++){
        if(d[i]+1 != d[i+1]) break;
        cnt++;
    }
    cur_op.push_back(cnt);
    cur_op.push_back(ord[m]-ord[m+1]-(cnt-1));
    if(ord[m] != n-1) cur_op.push_back(n-1-ord[m]);
    ope.push_back(cur_op);
    operate(cur_op);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    d = vector<int>(n);
    ord = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i]; d[i]--;
    }
    for(int i = 0; i < n; i++) ord[d[i]] = i;

    while(true){
        bool find = false;
        for(int i = 0; i < n-1; i++){
            if(ord[i] > ord[i+1]){
                find = true;
                concat(i);
                break;
            }
        }
        // for(int i : d)cout << i << ' ';
        // cout << endl;
        if(!find) break;
    }
    cout << ope.size() << endl;
    for(auto v : ope){
        cout << v.size() << ' ';
        for(int i : v) cout << i << ' ';
        cout << endl;
    }
}