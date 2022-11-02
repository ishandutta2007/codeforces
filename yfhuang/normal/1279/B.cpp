#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

int t;
int n;
LL s;
const int maxn = 1e5 + 5;

LL a[maxn];
LL pre[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        pre[0] = 0;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            pre[i] = pre[i - 1] + a[i];
        } 
        int ans = -1;
        int ansid = -1;
        for(int i = 0;i <= n;i++){
            LL sum1;
            int num1;
            if(i == 0){
                sum1 = 0;
                num1 = 0;
            }
            else {
                sum1 = pre[i - 1];
                num1 = i - 1;
            }
            int l = i, r = n;
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(pre[mid] - pre[i] + sum1 <= s){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(pre[l] - pre[i] + sum1 > s){
                continue;
            }
            if(ans == -1){
                ans = num1 + (l - i);
                ansid = i;
            }else{
                if(num1 + (l - i) > ans){
                    ans = num1 + (l - i);
                    ansid = i;
                }
            }
        }
        //cout << ans << endl;
        cout << ansid << endl;
    }
    return 0;
}