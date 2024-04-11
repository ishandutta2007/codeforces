#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
int a[305][305],b[305][305],x[305],y[305],n,m,p,q,t,d[305][305];
int px[305],py[305];
bool vis[305][305];
queue <pi> ok;
bool cmp(int x,int y){return x>y;}
bool emp(int x,int y){
    if (x<1||x>n||y<1||y>m) return 0;
    return b[x][y]==0;
}
void ins(int x,int y){
    if (b[x][y]) return;
    if (!px[x]||!py[y]) return;
    int d=0;
    if (px[x]>y) d+=emp(x,y+1); else d+=emp(x,y-1);
    if (py[y]>x) d+=emp(x+1,y); else d+=emp(x-1,y);
    if (d==0&&!vis[x][y]) ok.push((pi){x,y}),vis[x][y]=1;
}
void del(int x,int y){
    if (x>1) ins(x-1,y);
    if (x<n) ins(x+1,y);
    if (y>1) ins(x,y-1);
    if (y<m) ins(x,y+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        x[i]=max(x[i],a[i][j]);
        y[j]=max(y[j],a[i][j]);
    }
    sort(x+1,x+n+1,cmp);
    sort(y+1,y+m+1,cmp);
    p=1; q=1; t=n*m; px[1]=py[1]=1; b[1][1]=t;
    while (t>1){
        --t;
        if (x[p+1]==t&&y[q+1]==t){
            ++p; ++q;
            b[p][q]=t;
            px[p]=q; py[q]=p;
            for (int i=1;i<q;i++) ins(p,i);
            for (int i=1;i<p;i++) ins(i,q);
        } else if (x[p+1]==t){
            ++p;
            b[p][q]=t;
            px[p]=q;
            for (int i=1;i<q;i++) ins(p,i);
        } else if (y[q+1]==t){
            ++q;
            b[p][q]=t;
            py[q]=p;
            for (int i=1;i<p;i++) ins(i,q);
        } else {
            if (!ok.size()){puts("-1");return 0;}
            pi tmp=ok.front(); ok.pop();
            b[tmp.F][tmp.S]=t;
            del(tmp.F,tmp.S);
        }
        /*
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)cout<<b[i][j]<<' ';cout<<endl;
        }
        cout<<"-----------------"<<endl;
        */
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)cout<<b[i][j]<<' ';cout<<endl;
    }
}