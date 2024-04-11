#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t;
int n, d;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> d;
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            int a;
            scanf("%d", &a);
            if(i == 1){
                ans += a;
            }else{
                int dis = (i - 1);
                int tmp = min(a, d / dis);
                d -= tmp * dis;
                ans += tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}