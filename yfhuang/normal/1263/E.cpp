#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;
int maxv[maxn << 2];
int addv[maxn << 2];
int minv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
    minv[o] = min(minv[o*2],minv[o*2+1]);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        minv[o*2] += addv[o];
        minv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    maxv[o] = 0;
    addv[o] = 0;
    minv[o] = 0;
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
        minv[o] += v;
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

int querymin(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return minv[o];
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymin(lson, ql, qr);
    if(ql > mid)
        return querymin(rson, ql, qr);
    return min(querymin(lson, ql, qr), querymin(rson, ql, qr));
}

int n;

void output(){
        if(querymin(1, 1, n, 1, n) < 0){
            printf("-1 ");
            return;
        }
        if(querymin(1, 1, n, n, n) != 0){
            printf("-1 ");
            return;
        }
        printf("%d ", querymax(1, 1, n, 1, n));
}

char s[maxn];
char a[maxn];
int main(){
    cin >> n;
    scanf("%s", s + 1);
    int cursor = 1;
    memset(a, 0, sizeof(a));
    build(1, 1, n);
    for(int i = 1;i <= n;i++){
        if(s[i] == 'L'){
            cursor = max(1, cursor - 1);
            output();
            continue;
        }
        if(s[i] == 'R'){
            cursor += 1;
            output();
            continue;
        }
        if(a[cursor] == '('){
            update(1, 1, n, cursor, n, -1);            
        }
        else if(a[cursor] == ')'){
            update(1, 1, n, cursor, n, 1);
        }
        a[cursor] = s[i];
        if(a[cursor] == '('){
            update(1, 1, n, cursor, n, 1);            
        }
        else if(a[cursor] == ')'){
            update(1, 1, n, cursor, n, -1);
        }
        output();
    }
    return 0;
}