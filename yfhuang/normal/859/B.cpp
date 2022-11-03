#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

const int maxn = 30;

int r[maxn];
int K;

int main(){
    int n;
    cin >> n;
    int now = 1;
    while(now * now < n)
        now++;
    if(now * now == n){
        cout << 4 * now << endl;
    }else{
        int l = now - 1;
        int r = (n + l - 1) / l;
        cout << 2 * (l + r) << endl;
    }
    return 0;
}