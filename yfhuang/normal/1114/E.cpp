#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <random>
#include <chrono>
using namespace std;


int a[65];
const int maxn = 1e6 + 5;
int id[maxn];

int gcd(int x, int y){
    return y == 0 ? x:gcd(y, x % y);
}

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    int l = 0, r = 1e9;
    int cnt = 0;
    while(l < r){
        int mid = (l + r) / 2;
        cout << "> " << mid << endl;
        fflush(stdout);
        int num;
        cin >> num;
        if(num == 0)
            r = mid;
        else l = mid + 1;
        cnt++;
    } 
    if(n == 1){
        cout << "! " << l << " " << 0 << endl;
        fflush(stdout);
        return 0;
    }
    for(int i = 1;i <= n;i++){
        id[i] = i;
    }
    shuffle(id + 1, id + 1 + n, rng);
    int m = min(60 - cnt, n);
    for(int i = 1;i <= m;i++){
        cout << "? " << id[i] << endl;
        fflush(stdout);
        int num;
        cin >> num;
        a[i] = num;
    } 
    sort(a + 1,a + 1 + m);
    if(a[m] != l){
        a[++m] = l;
    }
    int d = 0;
    for(int i = 2;i <= m;i++){
        d = gcd(d, a[i] - a[i - 1]);
    }
    cout << "! " << l - (n - 1) * d << " " << d << endl;
    fflush(stdout);
    return 0;
}