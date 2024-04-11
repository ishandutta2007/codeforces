#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <vector>
using namespace std;

int t;
typedef long long LL;

LL n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        LL tmp = n;
        vector<int> ans;
        for(LL i = 2;i * i <= n;i++){
            if(tmp % i == 0){
                ans.push_back(i);
                tmp /= i;
            }
            if(ans.size() == 2)
                break;
        }
        ans.push_back(tmp);
        sort(ans.begin(), ans.end());
        bool flag = true;
        if(ans.size() != 3)
            flag = false;
        if(flag){
            for(int i = 0;i < 2;i++){
                if(ans[i] == ans[i + 1])
                    flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
            for(int i = 0;i < 3;i++){
                printf("%d%c", ans[i], i == 2 ? '\n' : ' ');
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}