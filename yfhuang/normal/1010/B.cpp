#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int m, n;

int ask(int x){
    x = min(m, x);
    cout << x << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int a[100];

int main(){
    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        a[i] = ask(m);
        if(a[i] == 0){
            return 0;
        }
    } 
    int base = 0;
    int j = 0;
    while((1LL << (j + 1)) <= m){
        j++;
    }
    for(int i = 1, k = j;i <= j + 1;i++,k--){
        int b = ask(base + (1 << k));
        if(b == 0){
            return 0;
        }
        int x = (i - 1) % n + 1;
        b *= a[x];
        if(b > 0){
             
        }else{
            base += (1 << k);
        }
    }
    return 0;
}