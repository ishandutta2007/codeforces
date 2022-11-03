#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int maxn = 30;

int r[maxn];
int K;

int main(){
    cin >> K;
    for(int i = 1;i <= K;i++){
        scanf("%d",r + i);
    }
    sort(r + 1,r + 1 + K);
    cout << max(0,r[K] - 25) << endl;
    return 0;
}