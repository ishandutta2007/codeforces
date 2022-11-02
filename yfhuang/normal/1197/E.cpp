#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;
bool vis[maxn];

int n;
int l[maxn], r[maxn];
int ans[maxn], dp[maxn];
const int mod = 1e9 + 7;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

pair<int, int> itv[maxn];
map<int, int> cnt;
int main(){
    cin >> n;
    set<pair<int, int> > s;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &r[i], &l[i]);
        itv[i] = make_pair(r[i], l[i]);
    }
    sort(itv + 1, itv + n + 1);
    set<int> s1;
    for(int i = n;i >= 1;i--){
         while(s.size()){
             auto it = s.rbegin();
             int pos = it->first;
             int val = it->second;
             if(pos >= itv[i].first){
                 s1.insert(val);
                 s.erase(*it);
             }else{
                 break;
             }
         } 
         if(s1.size()){
            auto it = s1.begin();
            ans[i] = *it - (itv[i].first - itv[i].second);
            s.insert(make_pair(itv[i].second, ans[i]));
         }else{
            ans[i] = itv[i].second;
            s.insert(make_pair(itv[i].second, ans[i]));
         }
    } 
    s.clear();
    s1.clear();
    for(int i = n;i >= 1;i--){
         while(s.size()){
             auto it = s.rbegin();
             int pos = it->first;
             int id = it->second;
             if(pos >= itv[i].first){
                 s1.insert(ans[id]);
                 add(cnt[ans[id]], dp[id]);
                 s.erase(*it);
             }else{
                 break;
             }
         } 
         if(s1.size()){
            auto it = s1.begin();
            dp[i] = cnt[*it];
            s.insert(make_pair(itv[i].second, i));
         }else{
            dp[i] = 1; 
            s.insert(make_pair(itv[i].second, i));
         }
    } 
    //for(int i = 1;i <= n;i++){
    //    cout << itv[i].second << " " << itv[i].first << " " << ans[i] << " " << dp[i] << endl;
    //}
    int mx = 1e9 + 5;
    int mx1 = 1e9 + 5;
    for(int i = 1;i <= n;i++){
        mx = min(itv[i].first, mx);
    }
    int ret = 0;
    for(int i = 1;i <= n;i++){
        if(itv[i].second < mx){
            mx1 = min(ans[i], mx1);
        }
    }
    for(int i = 1;i <= n;i++){
        if(itv[i].second < mx and ans[i] == mx1){
            add(ret, dp[i]);
        }
    }
    cout << ret << endl;
    return 0;
}