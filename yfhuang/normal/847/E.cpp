#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 5;
char str[maxn];
int n;

bool check(int mid){
    for(int i = 1;i <= n;i++){
        if(str[i] == 'P'){
            int j = i;
            for(;j <= i && j <= n;j++){
                if(str[j] == 'P'){
                    i = j + mid;
                }
            }
        }else if(str[i] == '*'){
            int j;
            for(j = i + 1;j <= n;j++){
                if(str[j] == 'P')
                    break;
            }
            if(j == n + 1) return false;
            if(j - i > mid) return false;
            int k = i;
            int d = j - i;
            int r = max(i,max(i + mid - d,j + (mid - d) / 2));
            for(;k <= r && k <= n;k++){
                if(k == j) continue;
                if(str[k] == 'P'){
                    r = k + mid;
                }
            }
            i = r;
        }
    }
    return true;
}

int main(){
    cin >> n;
    scanf("%s",str + 1);
    int l = 1,r = 2 * n;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}