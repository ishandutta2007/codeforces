#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
const int maxn = 2e5 + 5;
int a[maxn];
int pre[maxn];
map<int,int> mp;
vector<int> b;
int main(){
    cin >> n;
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", a + i);
        pre[i] = pre[i - 1] ^ a[i];
    }
    if(pre[n] == 0){
        puts("-1");
    }else{
        for(int i = 1;i <= n;i++){
            if(pre[i] == 0){
                continue;
            }else{
                mp[pre[i]] = 1;
            }
        }
        for(pair<int, int> x:mp){
            b.push_back(x.first);
        }
        int cnt = 0;
        for(int i = 29;i >= 0;i--){
            for(int j = cnt;j < b.size();j++){
                if(b[j] & (1 << i)){
                    swap(b[cnt], b[j]);
                    for(int k = cnt + 1;k < b.size();k++){
                        if(b[k] & (1 << i))
                            b[k] ^= b[cnt];
                    }
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}