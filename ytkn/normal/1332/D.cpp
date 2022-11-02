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
    int k;
    cin >> k;
    if(k == 0){
        cout << 1 << ' ' << 1 << endl;
        cout << 300000 << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i <= 22; i++){
        int m = (1<<i);
        if(k&m) cnt = i;
    }
    int M = (1<<(cnt+2))-1;
    int N = 1<<(cnt+1);
    cout << 3 << ' ' << 3 << endl;
    cout << M << ' ' << N << ' ' << M << endl;
    cout << k << ' ' << M << ' ' << M << endl;
    cout << M << ' ' << M << ' ' << k << endl;
}