#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> mp;
unordered_map<string,bool> mp1;

const int maxn = 70005;
string a[maxn];
string ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        mp1.clear();
        cin >> a[i];
        for(int j = 0;j < 9;j++){
            for(int len = 1;j + len - 1 < 9;len++){
                if(!mp1.count(a[i].substr(j,len)))mp[a[i].substr(j,len)]++,mp1[a[i].substr(j,len)] = 1;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        bool flag = false;
        for(int len = 1;len <= 9;len++)if(!flag){
            for(int j = 0;j + len - 1 < 9;j++)if(!flag){
                if(mp[a[i].substr(j,len)] == 1){
                    ans[i] = a[i].substr(j,len);
                    flag = true;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}