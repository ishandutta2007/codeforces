#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int q;
typedef long long LL;

LL cal1(LL x){
    LL ret = 0;
    LL digit = 0;
    for(LL i = 1;;i *= 10){
        digit++;
        if(i > x)
            break;
        LL r = min(10 * i - 1LL, x);
        LL num1 = (r - i + 1);
        num1 = num1 * (num1 + 1) / 2;
        ret += num1 * digit;
        ret += (x - r) * digit * (r - i + 1);
    }
    return ret;
}

LL cal2(LL x){
    LL ret = 0;
    LL digit = 0;
    for(LL i = 1;;i *= 10){
        digit++;
        if(i > x)
            break;
        LL r = min(10 * i - 1LL, x);
        ret += (r - i + 1) * digit;
    }
    return ret;
}

int main(){
    cin >> q;
    while(q--){
        LL k;
        cin >> k;
        LL l = 1, r = 1e9;
        while(l < r){
            LL mid = (l + r) / 2;
            if(cal1(mid) >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        } 
        k -= cal1(l - 1);
        l = 1, r = 1e9;
        while(l < r){
            LL mid = (l + r) / 2;
            if(cal2(mid) >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        k -= cal2(l - 1);
        vector<int> digits;
        LL tmp = l;
        while(l > 0){
            digits.push_back(l % 10);
            l /= 10;
        }
        reverse(digits.begin(), digits.end());
        printf("%d\n", digits[k - 1]);
    }
    return 0;
}