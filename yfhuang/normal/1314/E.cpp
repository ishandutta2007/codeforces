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

const int mod = 998244353;
const int maxn = 2050;
int n, k;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if(a < 0)
        a += mod;
}

int dp1[maxn][maxn];

int solve1(){
    dp1[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++){
            add(dp1[i][j], dp1[i - 1][j]); 
        }
        for(int j = i;j <= n;j++){
            add(dp1[i][j], dp1[i][j - i]);
        }
        //for(int j = 0;j <= n;j++){
        //    cout << i << " " << j << " " << dp1[i][j] << endl;
        //}
    }
    int ans = 0;
    for(int j = 1;j <= n;j++){
        add(ans, dp1[n][j]);
    }
    return ans;
}

int dp2[maxn][maxn];

int solve2(){
    dp2[0][0] = 1;
    for(int i = n;i >= 1;i--){
        int border = n / i;
        for(int sum = 0;sum <= n - i;sum++){
            for(int j = 0;j <= border;j++){
                int sum1 = sum + (j + 1) * i;
                add(dp2[sum1][j + 1], dp2[sum][j]);
            }
        }
    } 
    int ans = 0;
    for(int sum = 0; sum <= n;sum++){
        for(int j = 1;j <= n;j++){
            add(ans, dp2[sum][j]);
        }
    }
    return ans;
}

long long func(long long dep, vector<long long> v){
    if(dep == 3){
        long long S = 0;
        int num = 0;
        for(int i = 0;i < v.size();i++){
            int occ = v.size() - i;
            for(int j = 0;j < v[i];j++){
                num++;
                S += 1LL * num * occ; 
            }
        }
        return S;
    }else{
        vector<long long> vec2;
        for(int i = v.size() - 1;i >= 0;i--){
            for(int j = 0;j < v[i];j++){
                vec2.push_back(v.size() - i);
                if(vec2.size() > n) return n + 1;
            }
        } 
        return func(dep - 1, vec2);
    }
}

int cnt;

void dfs(vector<long long> vec, long long dep){
    for(int i = dep;i <= n;i++){
        vector<long long> vec2 = vec;
        vec2.push_back(i);
        if(func(k, vec2) > n) break;
        cnt++;
        dfs(vec2, i);
    }
}

int main(){
    cin >> n >> k;
    if(k == 1){
        printf("%d\n", solve1());
    }else if(k == 2){
        printf("%d\n", solve2());
    }else{
        cnt = 0;
        dfs({}, 1);
        printf("%d\n", cnt);
    }    
    return 0;
}