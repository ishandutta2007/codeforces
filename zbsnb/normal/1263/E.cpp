#include <cstdio>
#include <bitset>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
const int maxn = 1e6 + 7;
struct nd {
    int l, r, v, v2, lz;
} seg[maxn << 2];
int n;
inline void pushup(int rt) {
    seg[rt].v = max(seg[rt << 1].v, seg[rt << 1 | 1].v);
    seg[rt].v2 = min(seg[rt << 1].v2, seg[rt << 1 | 1].v2);
}
void pushdown(int rt) {
    if(seg[rt].lz) {
        seg[rt << 1].lz += seg[rt].lz;
        seg[rt << 1 | 1].lz += seg[rt].lz;
        seg[rt << 1].v += seg[rt].lz;
        seg[rt << 1].v2 += seg[rt].lz;
        seg[rt << 1 | 1].v += seg[rt].lz;
        seg[rt << 1 | 1].v2 += seg[rt].lz;
        seg[rt].lz = 0;
    }
}
void Update(int l, int r, int xx, int b = 1, int e = n, int rt = 1) {
    if(l <= b && e <= r) {
        seg[rt].lz += xx;
        seg[rt].v += xx;
        seg[rt].v2 += xx;
        return ;
    }
    pushdown(rt);
    int m = b + e >> 1;
    if(l <= m)
        Update(l, r, xx, b, m, rt << 1);
    if(r > m)
        Update(l, r, xx, m + 1, e, rt << 1 | 1);
    pushup(rt);
}
int query1(int l, int r, int b = 1, int e = n, int rt = 1) {
    if(l <= b && e <= r) {
        return seg[rt].v;
    }
    pushdown(rt);
    int m = b + e >> 1;
    int re = 0;
    if(l <= m)
        re = max(re, query1(l, r, b, m, rt << 1));
    if(r > m)
        re = max(re, query1(l, r, m + 1, e, rt << 1 | 1));
    return re;
}
int query2(int l, int r, int b = 1, int e = n, int rt = 1) {
    if(l <= b && e <= r) {
        return seg[rt].v2;
    }
    pushdown(rt);
    int m = b + e >> 1;
    int re = 0;
    if(l <= m)
        re = min(re, query2(l, r, b, m, rt << 1));
    if(r > m)
        re = min(re, query2(l, r, m + 1, e, rt << 1 | 1));
    return re;
}

char s[1000010];
char x[1000010];
int ans[1000010];
int main(){
    cin>>n;
    cin>>s;
    int now=1;
    int tot=0;
    for(int i=0;i<n;i++){
        // cout<<s[i]<<endl;
        if(s[i]>='a'&&s[i]<='z'){
            if(x[now]==')'){
                Update(now,n,1);
                x[now]=0;
                tot++;
            }
            if(x[now]=='('){
                Update(now,n,-1);
                x[now]=0;
                tot--;
            }
        }
        else if(s[i]=='L')now=now==1?1:now-1;
        else if(s[i]=='R')now++;
        else if(s[i]=='('){
            if(x[now]==0){
                Update(now,n,1);
                x[now]='(';
                tot+=1;
            }
            if(x[now]==')'){
                Update(now,n,2);
                x[now]='(';
                tot+=2;
            }
        }
        else if(s[i]==')'){
            if(x[now]==0){
                Update(now,n,-1);
                x[now]=')';
                tot-=1;
            }
            if(x[now]=='('){
                Update(now,n,-2);
                x[now]=')';
                tot-=2;
            }
        }

        int tmp1=query1(1,n);
        int tmp2=query2(1,n);
        if(tmp2<0||tot!=0){
            ans[i]=-1;
        }
        else{
            ans[i]=tmp1;
        }

        // cout<<i<<" "<<tmp1<<" "<<tmp2<<" "<<tot<<endl;

        // cout<<now<<endl;
        // for(int i=1;i<=10;i++)cout<<x[i]<<" ";cout<<endl;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}