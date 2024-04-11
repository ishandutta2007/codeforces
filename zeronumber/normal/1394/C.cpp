#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int x[maxn],y[maxn],n,l,r,mid,ansx,ansy;
int minx,maxx,miny,maxy,mind,maxd;
string s;
bool ok(int x,int y){
    if (x<0||y<0) return 0;
    if (x==0&&y==0) return ok(1,1)||ok(1,0)||ok(0,1);
    if (x>maxx||x<minx) return 0;
    if (y>maxy||y<miny) return 0;
    if (x-y>maxd||x-y<mind) return 0;
    ansx=x; ansy=y;
    return 1;
}
bool check(int d){
    maxx=minx=x[1];
    maxy=miny=y[1];
    maxd=mind=x[1]-y[1];
    for (int i=2;i<=n;i++){
        maxx=min(maxx,x[i]);
        minx=max(minx,x[i]);
        maxy=min(maxy,y[i]);
        miny=max(miny,y[i]);
        maxd=min(maxd,x[i]-y[i]);
        mind=max(mind,x[i]-y[i]);
    }
    maxx+=d; maxy+=d; maxd+=d;
    minx-=d; miny-=d; mind-=d;
    if (ok(minx,miny)) return 1;
    if (ok(maxx,miny)) return 1;
    if (ok(minx,maxy)) return 1;
    if (ok(maxx,maxy)) return 1;
    if (ok(minx,minx-mind)) return 1;
    if (ok(maxx,maxx-mind)) return 1;
    if (ok(minx,minx-maxd)) return 1;
    if (ok(maxx,maxx-maxd)) return 1;
    if (ok(miny+mind,miny)) return 1;
    if (ok(maxy+mind,maxy)) return 1;
    if (ok(miny+maxd,miny)) return 1;
    if (ok(maxy+maxd,maxy)) return 1;
    return 0;
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> s;
        int a=0,b=0;
        for (int j=0;j<s.size();j++) if (s[j]=='B') ++a; else ++b;
        x[i]=a; y[i]=b;
    }
    l=-1; r=5e5+5;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) r=mid; else l=mid;
    }
    check(r);
    printf("%d\n",r);
    for (int i=0;i<ansx;i++) printf("B");
    for (int i=0;i<ansy;i++) printf("N");
    puts("");
    return 0;
}