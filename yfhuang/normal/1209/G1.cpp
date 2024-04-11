#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
const int maxn = 2e5 + 5;
int a[maxn];
int lst[maxn];
int num[maxn];

int main(){
    while(cin >> n >> q){
        memset(num, 0, sizeof(num));
        memset(lst, 0, sizeof(lst));
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            lst[a[i]] = max(lst[a[i]], i);
            num[a[i]]++;
        } 
        int r = 0;
        int m = 0;
        int sum = 0;
        for(int i = 1;i <= n;i++){
            r = max(r, lst[a[i]]);
            m = max(m, num[a[i]]);
            if(r == i){
                sum += m;
                m = 0;
                r = 0;
            }
        } 
        cout << n - sum << endl;
    }
    return 0;
}