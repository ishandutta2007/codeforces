#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n;
const int maxn = 1e3 + 5;
typedef long long LL;
LL x[maxn], y[maxn];
int cnt[2][2];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld", &x[i], &y[i]);
        x[i] += 1e6;
        y[i] += 1e6;
    }
    while(true){
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= n;i++){
            //cout << x[i] << " " << y[i] << endl;
            cnt[x[i]%2][y[i]%2]++;
        }
        if((cnt[0][0] + cnt[1][1]) > 0 and (cnt[1][0] + cnt[0][1]) > 0){
            vector<int> ans;
            for(int i = 1;i <= n;i++){
                if((x[i] + y[i]) % 2){
                    ans.push_back(i);
                }
            }
            cout << ans.size() << endl;
            for(auto it : ans){
                cout << it << " ";
            }
            cout << endl;
            return 0;
        } 
        if((cnt[0][0] + cnt[1][0]) > 0 and (cnt[1][1] + cnt[0][1]) > 0){
            vector<int> ans;
            for(int i = 1;i <= n;i++){
                if((y[i]) % 2){
                    ans.push_back(i);
                }
            }
            cout << ans.size() << endl;
            for(auto it : ans){
                cout << it << " ";
            }
            cout << endl;
            return 0;
        } 
        //for(int i = 0;i < 2;i++){
        //    for(int j = 0;j < 2;j++){
        //        if(cnt[i][j]){
        //            xx = i, yy = j;
        //        }
        //    }
        //}
        for(int i = 1;i <= n;i++){
            x[i] = (x[i]) / 2;
            y[i] = (y[i]) / 2;
        }
    }
    return 0;
}