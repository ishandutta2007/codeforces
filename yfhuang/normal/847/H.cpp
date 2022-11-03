//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//long long n,k;
//
//int main(){
//    cin >> n >> k;
//
//    long long i = max(1LL,(long long)sqrt(k * 2LL) - 10);
//    while(i * (i - 1) / 2 < k) i++;
//    if(i > n){
//        printf("Impossible");
//    }else{
//        if(i * (i - 1) / 2 == k){
//            for(long long j = 1;j <= i;j++){
//                putchar('(');
//            }
//            for(long long j = 1;j <= i;j++){
//                putchar(')');
//            }
//            for(long long j = i + 1;j <= n;j++){
//                printf("()");
//            }
//            puts("");
//        }else{
//            long long d = i * (i - 1) / 2 - k;
//            for(long long j = 1;j <= i - 1;j++){
//                putchar('(');
//            }
//            for(long long j = 1;j <= i - 1;j++){
//                putchar(')');
//                if(j == d){
//                    printf("()");
//                }
//            }
//            for(long long j = i + 1;j <= n;j++){
//                printf("()");
//            }
//            puts("");
//        }
//    }
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn],c[maxn];
int n;
long long pre[maxn],suf[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n;i++){
        if(i == 1){
            b[i] = a[i];
            pre[i] = 0;
        }else{
            b[i] = max(a[i],b[i - 1] + 1);
            pre[i] = pre[i - 1] + b[i] - a[i];
        }
    }
    for(int i = n;i >= 1;i--){
        if(i == n){
            c[i] = a[i];
            suf[i] = 0;
        }
        else{
            c[i] = max(a[i],c[i + 1] + 1);
            suf[i] = suf[i + 1] + c[i] - a[i];
        }
    }
    long long ans = 1e18;
    for(int i = 1;i <= n;i++){
       ans = min(ans,pre[i - 1] + max(b[i],c[i]) - a[i] + suf[i + 1]);
    }
    cout << ans << endl;
    return 0;
}