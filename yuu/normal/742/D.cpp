#include <stdio.h>
#include <algorithm>
using namespace std;
int sw[1001];
int sb[1001];
bool d[1001][1001];
int f[1001][1001];
int sc=0;
int n, m, W, x, y;
int s[1001];
int w[1001];
int b[1001];
int sp[1001];
struct hos{
    int w, b, r;
} h[1001];
int root(int u){
    if(s[u]<0) return u;
    return s[u]=root(s[u]);
}
void uni(int u, int v){
    int r1=root(u), r2=root(v);
    if(r1!=r2){
        if(s[r1]>s[r2])
            swap(r1, r2);
        s[r1]+=s[r2];
        s[r2]=r1;
    }
}
int F(int i, int we){//Xet den nhom thu i va con trong luong cho phep la w
    if(we<0) return -999999999;
    if(d[i][we]) return f[i][we];
    d[i][we]=1;
    if(h[i].r!=h[i+1].r)//Neu la dau day
        return f[i][we]=max(max(F(i-1, we), F(sp[h[i].r]-1, we-h[i].w)+h[i].b), F(sp[h[i].r]-1, we-(w[i]-w[sp[h[i].r]-1]))+(b[i]-b[sp[h[i].r]-1]));
    else return f[i][we]=max(F(i-1, we), F(sp[h[i].r]-1, we-h[i].w)+h[i].b);
}
bool cmp(hos a, hos b){
    return a.r<b.r;
}
int main(){
    //freopen("D.INP", "r", stdin);
    scanf("%i%i%i", &n, &m, &W);
    for(int i=1; i<=n; i++)
        scanf("%i", &h[i].w);
    for(int i=1; i<=n; i++)
        scanf("%i", &h[i].b);
    for(int i=1; i<=n; i++)
        s[i]=-1;
    for(int i=1; i<=m; i++){
        scanf("%i%i", &x, &y);
        uni(x, y);
    }
    int temp=0;
    for(int i=1; i<=n; i++)
        h[i].r=root(i);
    sort(h+1, h+n+1, cmp);
    for(int i=1; i<=n; i++){
        if(h[i].r!=h[i-1].r)
            sp[h[i].r]=i;
        w[i]=w[i-1]+h[i].w;
        b[i]=b[i-1]+h[i].b;
    }
    for(int i=0; i<=1000; i++)
        d[0][i]=d[i][0]=1;
    printf("%d", F(n, W));
}