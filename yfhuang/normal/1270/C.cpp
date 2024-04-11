#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int t;
int n;
const int maxn = 1e5 + 5;
typedef long long LL;

LL a[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        LL sum = 0;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        LL b[3];
        b[0] = (1LL << 50);
        if(sum & 1){
            b[0]++;
        }
        sum += b[0];
        LL Xor = 0;
        for(int i = 1;i <= n;i++){
            Xor ^= a[i];
        }
        Xor ^= b[0];
        b[1] = b[2] = (2LL * Xor - sum) / 2;
        printf("3\n");
        for(int i = 0;i < 3;i++){
            printf("%lld%c", b[i], i == 2 ? '\n' : ' ');
        }
    }
    return 0;
}