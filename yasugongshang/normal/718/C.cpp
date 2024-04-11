#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define mo 1000000007
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

struct mat{
    ll a[2][2];
}tmp,now;

struct note{
    mat x,add;
}t[maxn * 4];

int n,m;

ll p[maxn],q[maxn];

int a[maxn];

mat mulx(mat x,mat y){
    mat ret;
    mem(ret.a,0);
    fo(i,0,1)
        fo(j,0,1)
            fo(k,0,1) {
                ret.a[i][j]=(ret.a[i][j]+x.a[i][k]*y.a[k][j]) % mo;
            }
    return ret;
}

mat mul(mat x,ll y){
    mat ret;
    mem(ret.a,0);
    ret.a[0][0]=ret.a[1][1]=1;
    while (y) {
        if (y % 2==1) ret=mulx(ret,x);
        x=mulx(x,x);
        y /= 2;
    }
    return ret;
}

mat operator+ (mat x,mat y){
    mat ret;
    mem(ret.a,0);
    fo(i,0,1)
        fo(j,0,1) {
            ret.a[i][j]=(x.a[i][j]+y.a[i][j]) % mo;
        }
    return ret;
}

void build(int v,int l,int r){
    if (l==r) {
        t[v].x.a[0][0]=p[l];
        t[v].x.a[0][1]=q[l];
        t[v].add.a[0][0]=t[v].add.a[1][1]=1;
        return;
    }
    int mid=(l+r) >> 1;
    build(v << 1,l,mid);
    build(v << 1 | 1,mid+1,r);
    t[v].x=t[v << 1].x+t[v << 1 | 1].x;
    t[v].add.a[0][0]=t[v].add.a[1][1]=1;
}

void update(int v){
    t[v << 1].x=mulx(t[v << 1].x,t[v].add);
    t[v << 1 | 1].x=mulx(t[v << 1 | 1].x,t[v].add);
    t[v << 1].add=mulx(t[v << 1].add,t[v].add);
    t[v << 1 | 1].add=mulx(t[v << 1 | 1].add,t[v].add);
    mem(t[v].add.a,0);
    t[v].add.a[0][0]=t[v].add.a[1][1]=1;
}

void change(int v,int l,int r,int x,int y){
    if (l!=r) update(v);
    if (l==x && r==y) {
        t[v].x=mulx(t[v].x,now);
        t[v].add=mulx(t[v].add,now);
        return;
    }
    int mid=(l+r) >> 1;
    if (y<=mid) change(v << 1,l,mid,x,y);
    else if (x>mid) change(v << 1 | 1,mid+1,r,x,y);
    else change(v << 1,l,mid,x,mid),change(v << 1 | 1,mid+1,r,mid+1,y);
    t[v].x=t[v << 1].x+t[v << 1 | 1].x;
}

mat query(int v,int l,int r,int x,int y){
    if (l!=r) update(v);
    if (l==x && r==y) {
        return t[v].x;
    }
    int mid=(l+r) >> 1;
    if (y<=mid) return query(v << 1,l,mid,x,y);
    else if (x>mid) return query(v << 1 | 1,mid+1,r,x,y);
    else return query(v << 1,l,mid,x,mid)+query(v << 1 | 1,mid+1,r,mid+1,y);
}

int main(){
    scanf("%d%d",&n,&m);
    fo(i,1,n) {
        scanf("%d",&a[i]);
        if (a[i]==1) {
            p[i]=1;
            q[i]=0;
        }
        else if (a[i]==2){
            p[i]=q[i]=1;
        }
        else {
            mat tmp;
            mem(tmp.a,0);
            tmp.a[0][0]=tmp.a[0][1]=tmp.a[1][0]=1;
            tmp=mul(tmp,a[i]-1);
            p[i]=tmp.a[0][0];
            q[i]=tmp.a[1][0];
        }
    }
    build(1,1,n);
    while (m--) {
        int Type,x,y,z;
        scanf("%d",&Type);
        if (Type==1) {
            scanf("%d%d%d",&x,&y,&z);
            mat tmp;
            tmp.a[0][0]=tmp.a[0][1]=tmp.a[1][0]=1;
            tmp.a[1][1]=0;
            now=mul(tmp,z);
            change(1,1,n,x,y);
        }
        else {
            scanf("%d%d",&x,&y);
            mat ans=query(1,1,n,x,y);
            printf("%I64d\n",ans.a[0][0]);
        }
    }
    return 0;
}