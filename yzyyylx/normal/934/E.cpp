#include<bits/stdc++.h>
#define ll long long
#define db double
#define eps 1e-8
#define N 5
using namespace std;

ll n,ans;
db x[N],y[N],r[N],lt=1;
struct Node
{
    db x,y;
    Node operator + (const Node &u) const{return (Node){x+u.x,y+u.y};}
    Node operator - (const Node &u) const{return (Node){x-u.x,y-u.y};}
    db operator * (const Node &u) const{return x*u.x+y*u.y;}
};
struct Xn
{
    Node u,v;
};

inline db cj(Node u,Node v){return u.x*v.y-u.y*v.x;}
inline db lenf(Node u,Node v){return (u-v)*(u-v);}
inline db len(Node u,Node v){return sqrt(lenf(u,v));}
inline Node fz(Node u){return (Node){-u.y,u.x};}
inline Node move(Node u,Node v,db l){db b=l/sqrt(v*v);return (Node){u.x+v.x*b,u.y+v.y*b};}
inline void work(ll u,ll v)
{
    db d=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
    if(d>r[u]+r[v]+eps)
    {
	lt=0;
	return;
    }
    if(d+eps>r[u]+r[v]) return;
    if(d+min(r[u],r[v])+eps<max(r[u],r[v]))
    {
	lt=0;
	return;
    }
    if(d+min(r[u],r[v])<max(r[u],r[v])+eps) return;
    ans++;
}

inline void gd()
{
    Node a,b,c,res;
    Xn xn;
    db d;
    a=(Node){x[1],y[1]};
    b=(Node){x[2],y[2]};
    c=(Node){x[3],y[3]};
    xn=(Xn){a,b-a};
    d=len(a,b);
    db t=(r[1]*r[1]-r[2]*r[2]+lenf(a,b))/(d*2.0);
//    cerr<<" "<<t<<endl;
//    cerr<<xn.v.x<<"  "<<xn.v.y<<endl;
    xn.u=move(xn.u,xn.v,t);
    xn.v=fz(xn.v);
//    cerr<<xn.u.x<<"  "<<xn.u.y<<endl;
    t=sqrt(r[1]*r[1]-t*t);
    res=move(xn.u,xn.v,t);
//    cout<<res.x<<"   "<<res.y<<endl;
    if(abs(lenf(c,res)-r[3]*r[3])<eps) ans--;
    res=move(xn.u,xn.v,-t);
//    cout<<res.x<<"   "<<res.y<<endl;
    if(fabs(t)>eps&&abs(lenf(c,res)-r[3]*r[3])<eps) ans--;
}

int main()
{
    ll i,j,t,b;
    cin>>n;ans=n+1;
    for(i=1;i<=n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) work(i,j);
    if(n==3) gd();
    cout<<ans+(lt&&n==3);
}