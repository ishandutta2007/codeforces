#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int n, k;
const int maxn = 2e5 + 5;
int a[maxn];


pair<bool, long long> check(long long d){
    int lst = 0;
    long long p = 0;
    bool flag = false;
    for(int i = 1;i <= n;i++){
        while(lst + 1 <= n && a[lst + 1] + d < a[i] - d){
            lst++;
        }
        if(i - lst >= k + 1){
            flag = true;
            p = a[i] - d;
        }
    }
    return make_pair(flag, p);
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        long long l = 0, r = 1e15;
        while(l < r){
            long long mid = (l + r) / 2;
            if(check(mid).first){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << check(l).second << endl; 
    }
    return 0;
}