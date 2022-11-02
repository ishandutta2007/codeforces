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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 2005 + 5;

int n;
typedef long long LL;
struct P{
    LL x, y;
    P(){}
    P(LL _x, LL _y):x(_x), y(_y){}
    P operator - (P p) {return P(x - p.x, y - p.y);}
    LL det(P p){return x * p.y - y * p.x;}
    int quad() const{
        return (y > 0) || (y == 0 and x > 0); 
    }
    bool operator < (P p){
        if(quad() != p.quad()){
            return quad() < p.quad();
        }else{
            return det(p) > 0;
        }
    }
}p[maxn];

pair<int, int> dir[maxn * maxn];

LL S;
int tot;

bool cmp(int a, int b){
    return p[a].y > p[b].y;
}
bool cmp1(pair<int, int> a, pair<int, int> b){
    return (p[a.second] - p[a.first]) < (p[b.second] - p[b.first]);
}

int ord[maxn];
int pos[maxn];
int main(){
    scanf("%d%lld", &n, &S);
    for(int i = 1;i <= n;i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    } 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(j != i)
                dir[++tot] = make_pair(j, i);
        }
    }
    sort(dir + 1, dir + 1 + tot, cmp1);
    for(int i = 1;i <= n;i++){
        ord[i] = i;
    }
    sort(ord + 1, ord + 1 + n, cmp);
    for(int i = 1;i <= n;i++){
        pos[ord[i]] = i;
        //cout << ord[i] << endl;
    }
    for(int i = 1;i <= tot;i++){
        int j = dir[i].first;
        int k = dir[i].second; 
        //cout << "!!!" << j << " " << k << endl;
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if((p[k] - p[j]).det(p[ord[mid]] - p[j]) >= 2 * S){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if((p[k] - p[j]).det(p[ord[l]] - p[j]) == 2 * S){
            cout << "Yes" << endl;
            cout << p[ord[l]].x << " " << p[ord[l]].y << endl;
            cout << p[j].x << " " << p[j].y << endl;
            cout << p[k].x << " " << p[k].y << endl;
            return 0;
        }
        swap(ord[pos[j]], ord[pos[k]]);
        swap(pos[j], pos[k]);
        //cout << "!!!" << endl;
        //for(int j = 1;j <= n;j++){
        //    cout << ord[j] << " ";
        //}
        //cout << endl;
    }
    cout << "No" << endl;
    return 0;
}