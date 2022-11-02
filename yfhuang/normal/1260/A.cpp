#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(){
    cin >> n;
    int c, sum;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &c, &sum);
        int num1 = sum / c;
        int num2 = num1 + 1;
        int num3 = sum % c;
        int num4 = c - num3;
        long long ans = 1LL * num1 * num1 * num4 + 1LL * num2 * num2 * num3;
        cout << ans << endl;
    }
    return 0;
}