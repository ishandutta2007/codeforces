#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, t;
const int maxn = 105;

int s[maxn], d[maxn];

int main(){
    cin >> n >> t;
    int mx = 1e9;
    int id = 0;
    for(int i = 1;i <= n;i++){
        cin >> s[i] >> d[i];
        int now = (t - s[i] + d[i] - 1) / d[i] * d[i] + s[i];
        if(s[i] >= t){
            now = s[i];
        }
        if(now < mx){
            mx = now;
            id = i;
        }
    }
    cout << id << endl;
    return 0;
}