#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
const int maxn = 4e5 + 5;
int sa[maxn], ea[maxn], sb[maxn], eb[maxn];

vector<int> in[maxn], out[maxn];
vector<int> all;
map<int, int> ID;
int stamp;


int maxv[maxn << 2];
int addv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    maxv[o] = 0;
    addv[o] = 0;
    if(l == r)
        return;
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
}

void update(int o, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

int querymax(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return maxv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    return max(querymax(lson, ql, qr), querymax(rson, ql, qr));
}

bool check(){
    for(int i = 1;i <= 4 * n;i++){
        in[i].clear();
        out[i].clear();
    }
    for(int i = 1;i <= n;i++){
        in[sa[i]].push_back(i);
        out[ea[i]].push_back(i);
    }
    build(1, 1, 4 * n);
    for(int i = 1;i <= 4 * n;i++){
        for(auto id : in[i]){
            if(querymax(1, 1, 4 * n, sb[id], eb[id]) > 0){
                return false;
            }
        }
        for(auto id : out[i]){
            update(1, 1, 4 * n, sb[id], eb[id], 1);
        }
    }
    return true;
}

int main(){
    cin >> n;
    stamp = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
        all.push_back(sa[i]);
        all.push_back(ea[i]);
        all.push_back(sb[i]);
        all.push_back(eb[i]);
    }
    sort(all.begin(), all.end());
    for(auto it : all){
        if(ID.find(it) == ID.end()){
            ID[it] = ++stamp;
        }
    }
    for(int i = 1;i <= n;i++){
        sa[i] = ID[sa[i]];
        ea[i] = ID[ea[i]];
        sb[i] = ID[sb[i]];
        eb[i] = ID[eb[i]];
    }
    bool flag = true;
    if(!check()){
        flag = false;
    }
    for(int i = 1;i <= n;i++){
        swap(sa[i], sb[i]);
        swap(ea[i], eb[i]);
    }
    if(!check()){
        flag = false;
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}