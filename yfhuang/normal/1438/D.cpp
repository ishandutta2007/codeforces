#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum ^= a[i];
    }
    if(n & 1){
        vector<int> op;
        for(int i = 1;i + 2 <= n;i += 2){
            op.push_back(i);
            op.push_back(i + 1);
            op.push_back(i + 2);
        }
        for(int i = n - 1;i >= 1;i -= 2){
            op.push_back(i - 1);
            op.push_back(i);
            op.push_back(n);
        }
        cout << "YES" << endl;
        cout << op.size() / 3 << endl;
        for(int i = 0;i < op.size();i += 3){
            cout << op[i] << " " << op[i + 1] << " " << op[i + 2] << endl;
        }
    }else{
        if(sum != 0){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        vector<int> op;
        for(int i = 2;i + 2 <= n;i += 2){
            op.push_back(i);
            op.push_back(i + 1);
            op.push_back(i + 2);
            op.push_back(1);
            op.push_back(i);
            op.push_back(i + 1);
        }
        cout << op.size() / 3 << endl;
        for(int i = 0;i < op.size();i += 3){
            cout << op[i] << " " << op[i + 1] << " " << op[i + 2] << endl;
        }
    }
    return 0;
}