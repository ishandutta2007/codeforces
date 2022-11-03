#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <vector>
using namespace std;



int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        long long c = 1LL * a * b;
        long long l = 1,r = 1e6;
        while(l < r){
            long long mid = (l + r + 1) / 2;
            if(mid * mid  * mid <= c) l = mid;
            else r = mid - 1;
        }
        //cout << l << endl;
        if(l * l * l != 1LL * a * b) printf("NO\n");
        else{

            bool flag = true;
            if(a % l) flag = false;
            if(b % l) flag = false;
            if(a > l * l) flag = false;
            if(b > l * l) flag = false;
            long long x = a / l;
            long long y = b / l;
            //cout << flag << endl;
            if(l % x) flag = false;
            if(l % y) flag = false;
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}