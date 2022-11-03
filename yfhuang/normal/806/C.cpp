//
//  main.cpp
//  C
//
//  Created by  on 2017/5/8.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;
typedef long long LL;
LL a[maxn];
LL p2[maxn];
int n;

LL num[100];
map<LL,int> mp;
LL b[maxn];
int p[maxn];

bool check(int x){
    LL num1[100];
    for(int i = 0;i < 99;i++) num1[i] = num[i];
    if(x > num1[0]) return false;
    priority_queue<int> q,p;
    for(int j = 1;j <= x;j++){
        for(int k = 0;k < 99;k++){
            if(num1[k] > 0){
                num1[k]--;
            }else{
               // if(x == 2)cout << k << endl;
                q.push(k);
                break;
            }
        }
    }
    
    for(int j = 0;j < 99;j++){
        for(int i = 1;i <= num1[j];i++){
            p.push(j);
            //if(x == 2) cout << j << endl;
        }
    }
    //if(x == 2) cout << p.size() << endl;
    while(true){
        if(q.empty() && !p.empty()) return false;
        if(p.empty()) break;
        int x = q.top();
        int y = p.top();
        if(y > x) return false;
        q.pop();
        p.pop();
        
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    LL r = 1;
    mp.clear();
    memset(num,0,sizeof(num));
    for(int i = 0;;i++){
        if(r > 1e12) break;
        mp[r] = i + 1;
        r *= 2;
    }
    int m = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
      //  cout << mp[a[i]] << " ";
        if(mp[a[i]] == 0){
            b[++m] = a[i];
            
        }else{
            num[mp[a[i]] - 1]++;
        }
    }
   // cout << endl;
   //for(int i = 0;i < 10;i++) cout << num[i] << endl;
    p2[0] = 1;
    for(int i = 1;i <= 60;i++){
        p2[i] = p2[i - 1] * 2;
    }
    //cout << m << endl;
    for(int i = 1;i <= m;i++){
       int power = lower_bound(p2 + 1,p2 + 1 + 60,b[i]) - p2;
        //cout << power << endl;
        p[i] = power;
        for(int j = 0;j < power;j++){
            num[j]--;
            if(num[j] < 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = p[i];j < 100;j++){
            if(num[j] > 0) num[j]--;
            else break;
        }
    }
//    for(int i = 0;i < 10;i++){
//        cout << num[i] << endl;
//    }
//    for(int i = 0;i < 99;i++){
//        if(num[i + 1] > num[i]){
//            cout << -1 << endl;
//            return 0;
//        }
//    }
    int L = 0,R = num[0];
    while(L < R){
        int mid = (L + R) / 2;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    //cout << L << endl;
    if(check(L) == false){
        cout << -1 << endl;
        return 0;
    }
    for(int i = m + L;i <= m + num[0];i++){
        printf("%d ",i);
    }
    return 0;
}