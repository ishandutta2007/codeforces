#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

const int maxn = 305;
int n;
int b,a,k,f;
map<string,int> name;
map<pair<int,int>,long long> ways;
int tot;
int u[305],v[305],c[305];
long long cost[305];
int main(){
    cin >> n >> a >> b >> k >> f;
    tot = 0;
    for(int i = 1;i <= n;i++){
        string aa,bb;
        cin >> aa >> bb;
        if(!name.count(aa)) name[aa] = ++tot;
        if(!name.count(bb)) name[bb] = ++tot;
        u[i] = name[aa],v[i] = name[bb];
        if(i == 1) c[i] = a;
        else{
            if(u[i] == v[i - 1]) c[i] = b;
            else c[i] = a;
        }
        ways[make_pair(min(u[i],v[i]),max(u[i],v[i]))] += c[i];
    }
    int m = 0;
    long long ans = 0;
    for(auto v : ways){
        cost[++m] = v.second;
        ans += v.second;
    }
    sort(cost + 1,cost + 1 + m);
    for(int i = m;m - i + 1 <= k && i >= 1;i--){
        if(cost[i] > f){
            ans -= cost[i];
            ans += f;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}