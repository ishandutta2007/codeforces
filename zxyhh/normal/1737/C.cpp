#include<bits/stdc++.h>
#define ll long long 
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
#define maxn 100005
void solve() {
    int x1,y1,x2,y2,x3,y3;
    int xt,yt;
    int n;
    n=rd();
    x1=rd(),y1=rd(),x2=rd(),y2=rd(),x3=rd(),y3=rd();
    xt=rd(),yt=rd();
    int X,Y;
    if (x1==x2) X=x1;
    if (x1==x3) X=x1;
    if (x2==x3) X=x2;
    if (y1==y2) Y=y1;
    if (y1==y3) Y=y1;
    if (y2==y3) Y=y3;
    if ((X==1||X==n)&&(Y==1||Y==n)) {
        if (xt==X||yt==Y) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        return ;
    }
    if (xt%2==X%2||yt%2==Y%2) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}
int main() {
    // freopen("test.in","r",stdin);
    int T=rd();
    while(T--) {
        solve();
    }
}