#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int q, x;

const int maxn = 4e5 + 5;

int cnt[maxn];

int main(){
    cin >> q >> x;
    int now = 1;
    int cur = 0;
    for(int i = 1;i <= q;i++){
        int y;
        scanf("%d", &y);
        cnt[y % x]++;
        while(cnt[cur] >= now){
            cur++;
            if(cur == x){
                cur = 0;
                now++;
            }
        }
        cout << (now - 1) * x + cur << endl;
    }
    return 0;
}