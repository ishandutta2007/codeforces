//
//  main.cpp
//  C
//
//  Created by  on 2017/4/17.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define F first
#define S second
using namespace std;

const int maxn = 2e5 + 5;

vector<pair<int,int> > dp;
vector<int> P;
vector<int> R;

vector<int> G[maxn];
int n,m;
bool vis[maxn];

typedef long long LL;

LL mod_pow(int a,int n){
    LL res = 1;
    LL b = a;
    while(n > 0){
        if(n & 1){
            res = res * b % m;
        }
        b = b * b % m;
        n >>= 1;
    }
    return res;
}

LL phi(int x){
    LL res = 1;
    for(int i = 2;i <= x;i++){
        if(x % i) continue;
        x /= i;
        res *= (i - 1);
        while(x % i == 0){
            x /= i;
            res *= i;
        }
    }
    return res;
}

int get(int a,int b,int c){
    int g = __gcd(a,b);
    a = a / g;
    b = b / g;
    return 1LL * b * mod_pow(a,c - 1) % m;
}

void print(){
    int power = (int)phi(m);
    reverse(R.begin(),R.end());
    printf("%d\n",(int)R.size() + (vis[0] == false));
    for(int i = 0;i < R.size();i++){
        if(i == 0){
            printf("%d",R[i]);
        }else{
            printf(" %d",get(R[i - 1],R[i],power));
        }
    }
    if(vis[0] == false) printf(" 0\n");
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int a;
        scanf("%d",&a);
        vis[a] = true;
    }
    for(int i = 1;i < m;i++){
        if(!vis[i]){
            G[__gcd(i,m)].push_back(i);
        }
    }
    for(int i = 1;i < m;i++){
        if(!G[i].empty()){
            P.push_back(i);
            dp.push_back(make_pair(G[i].size(),-1));
        }
    }int ret = 0;
    for(int i = 0;i < P.size();i++){
        for(int j = 0;j < i;j++){
            if(P[i] % P[j] == 0 && dp[i].F < dp[j].F + G[P[i]].size()){
                dp[i] = make_pair(dp[j].F + G[P[i]].size(),j);
            }
        }
        ret = max(ret,dp[i].F);
       // cout << dp[i].F << " " << dp[i].S << endl;
    }
  //  cout << "!" << endl;
    for(int i = 0;i < dp.size();i++){
        if(dp[i].F == ret){
            int tmp = i;
            while(tmp != -1){
                for(int j = 0;j < G[P[tmp]].size();j++){
                    R.push_back(G[P[tmp]][j]);
                }
                tmp = dp[tmp].S;
            }
            //cout << "!!" << endl;
            break;
        }
    }
//    for(int i = 0;i < R.size();i++){
//        printf("%d ",R[i]);
//    }
//    puts("");
    print();
    return 0;
}