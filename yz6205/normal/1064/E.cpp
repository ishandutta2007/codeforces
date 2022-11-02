#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int main(){
    string fst;
    int step = 1 << (N - 2);
    int now = 0;
    int mx = 0;
    int n;
    cin >> n;
    cout << now << ' ' << now << endl;
    string get;
    cin >> get;
    fst = get;
    now += step;
    step >>= 1;
    for (int i=2;i<=n;i++){
        cout << now << ' ' << now << endl;
        cin >> get;
        if (get == fst){
            mx = now;
            now += step;
        }else{
            now -= step;
        }
        step >>= 1;
    }
    cout << mx << ' ' << mx + 1 << ' ' << mx + 1 << ' ' << mx << endl;
    return 0;
}