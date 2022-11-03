#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

const int mx = 203;
int memo[mx][mx];
int tanya(int i, int j){
    if(memo[i][j] != 0) return memo[i][j];
    cout << "? " << i << ' ' << j << endl;
    char x;
    cin >> x;
    if(x == '<') memo[i][j] = -1;
    else memo[i][j] = 1;
    return memo[i][j];
}


void solve(){
    memset(memo, 0, sizeof memo);
    int n;
    cin >> n;
    vector<int> besar, kecil;
    for(int i = 1; i <= n; i++){
        auto aa = tanya(i, i + n);
        if(aa == 1){
            besar.push_back(i);
            kecil.push_back(i + n);
        }
        else{
            besar.push_back(i + n);
            kecil.push_back(i);
        }
    }
    sort(kecil.begin(), kecil.end(), [&](int i, int j){
        return tanya(i, j) == 1;
    });
    for(int i = 0; i < n; i++){
        int x = kecil[0];
        if(x <= n) x += n;
        else x -= n;
        if(besar[i] == x){
            swap(besar[i], besar[n - 1]);
            besar.pop_back();
            break;
        }
    }
    sort(besar.begin(), besar.end(), [&](int i, int j){
        return tanya(i, j) == 1;
    });
    while(besar.size() + kecil.size() >= n){
        if(kecil.size() == 0){
            besar.pop_back();
        }
        else if(besar.size() == 0){
            kecil.pop_back();
        }
        else{
            if(tanya(kecil.back(), besar.back()) == -1) kecil.pop_back();
            else besar.pop_back();
        }
    }
    cout << "!" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}