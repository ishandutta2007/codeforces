#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int m,b;



int main(){
    cin >> m >> b;
    //b = m * b;
    long long ans = 0;
    for(int i = 0;i <= b;i++){
        long long h = 1LL * m * i;
        long long w = b - i;
        ans = max(ans,1LL * (h + 1) * (w + 1) *  (h + w)  / 2);
    }
    cout << ans << endl;
    return 0;
}

/*
 5 4 3
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 2 3 4
 2 3 1 2
 3 4 3 4
 */