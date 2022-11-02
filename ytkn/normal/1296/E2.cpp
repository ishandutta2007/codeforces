#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<int> v[26];
vector<int> c[26];
int col[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        char s;
        cin >> s;
        v[s-'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++){
        int idx = 0;
        for(int j = i; j < 26; j++){
            int next_end = idx;
            for(int k = v[j].size()-1; k >= 0; k--){
                if(v[j][k] < idx) break;
                c[i].push_back(v[j][k]);
                next_end = max(next_end, v[j][k]);
                col[v[j][k]] = i+1;
                v[j].pop_back();
            }
            idx = next_end;
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(c[i].size() != 0) ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++){
        cout << col[i] << ' ';
    }
    cout << endl;
}