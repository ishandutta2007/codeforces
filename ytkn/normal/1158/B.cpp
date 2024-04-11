#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k;
    cin >> n >> k;
    int l = (n-k)/2;
    string s;
    for(int i = 0; i < l; i++) s += '1';
    s += '0';
    for(int i = 0; i < n; i++){
        cout << s[i%(l+1)];
    }
    cout << endl;
}