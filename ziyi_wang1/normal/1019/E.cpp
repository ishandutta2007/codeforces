 
#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
typedef __int128 LL; 
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
    res=0;register D g=1;register char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
template<class D>I write(D X)
{
    if(X<0) {X=~(X-1); putchar('-');}
    if(X>9) write(X/10);
    putchar(X%10+'0');
}
const int INF=1e9+7;
typedef pair<ll,ll>pii;
struct P{
    ll x,y;
    P(ll _x=0,ll _y=0){x=_x;y=_y;}
    friend P operator + (P a,P b){return P(a.x+b.x,a.y+b.y);}
    friend P operator - (P a,P b){return P(a.x-b.x,a.y-b.y);}
    friend LL operator ^ (P a,P b){return (LL)a.x*b.y-(LL)a.y*b.x;}
    friend bool operator < (P a,P b){return a.x==b.x?a.y<b.y:a.x<b.x;}
    inline ll get(ll w){return x*w+y;}
}p[4040000],st[4040000];
struct Edge{
    int x,y;ll a,b;
    Edge(int _x=0,int _y=0,ll _a=0,ll _b=0){x=_x;y=_y;a=_a;b=_b;}
};
vector<Edge>vec;
struct E{
    int to,nt;ll a,b;bool v;
}e[808000];
#define T e[k].to
int n,m,M,maxi,cnt,head[404000],num[101000],tot,X,Y,A,B,siz[404000];
P t1[404000],t2[404000];
int cnt1,cnt2;
I add(int x,int y,ll nowa,ll nowb){
    //cout<<x<<" "<<y<<" "<<nowa<<" "<<nowb<<endl;
    e[++tot].to=y;e[tot].nt=head[x];head[x]=tot;e[tot].a=nowa;e[tot].b=nowb;
}
I insert(int x,int y,ll nowa,ll nowb){
    ++cnt;
    vec.emplace_back(Edge(num[x],cnt,0,0));
    vec.emplace_back(Edge(cnt,y,nowa,nowb));
    num[x]=cnt;
}
I D_1(int x,int fa){
    for(re k=head[x];k!=-1;k=e[k].nt){
        if(T==fa)continue;
        insert(x,T,e[k].a,e[k].b);D_1(T,x);
    }
}
I D_2(int x,int fa){
    siz[x]=1;
    for(re k=head[x];k!=-1;k=e[k].nt){
        if(T==fa||e[k].v)continue;
        D_2(T,x);siz[x]+=siz[T];
    }
}
I findroot(int x,int fa,int N){
    for(re k=head[x];k!=-1;k=e[k].nt){
        if(T==fa||e[k].v)continue;
        findroot(T,x,N);
        re now=max(siz[T],N-siz[T]);
        if(maxi>now)maxi=now,M=k;
    }
}
I D_3(int x,int fa,ll suma,ll sumb){
    //cout<<"!"<<x<<" "<<fa<<" "<<suma<<" "<<sumb<<endl;
    if(suma||sumb)t1[++cnt1]=P(suma,sumb);
    for(re k=head[x];k!=-1;k=e[k].nt){
        if(T==fa||e[k].v)continue;
        D_3(T,x,suma+e[k].a,sumb+e[k].b);
    }
}
I D_4(int x,int fa,ll suma,ll sumb){
    //  cout<<"!"<<x<<" "<<fa<<" "<<suma<<" "<<sumb<<endl;
    if(suma||sumb)t2[++cnt2]=P(suma,sumb);
    for(re k=head[x];k!=-1;k=e[k].nt){
        if(T==fa||e[k].v)continue;
        D_4(T,x,suma+e[k].a,sumb+e[k].b);
    }
}
I build(P *t,int &sum){
    sort(t+1,t+1+sum);re top=0;
    F(i,1,sum){
        while(top>1&&(P(st[top]-st[top-1])^P(t[i]-st[top-1]))>=(LL)0)--top;
        st[++top]=t[i];
    }
    sum=top;
    //cout<<"Convex:"<<endl;
    F(i,1,sum)t[i]=st[i];//,cout<<"("<<t[i].x<<" "<<t[i].y<<")"<<endl;
}
I merge(){
    re j=min(1,cnt1),k=min(1,cnt2);re las=cnt+1;
    p[++cnt]=t1[j]+t2[k];
    while(j<cnt1&&k<cnt2){
        if((P(t2[k+1]-t2[k])^P(t1[j+1]-t1[j]))>=(LL)0)p[++cnt]=P(t1[++j]+t2[k]);
        else p[++cnt]=P(t1[j]+t2[++k]);
    }
    while(j<cnt1)p[++cnt]=P(t1[++j]+t2[cnt2]);
    while(k<cnt2)p[++cnt]=P(t1[cnt1]+t2[++k]);
    //cout<<"new:"<<endl;
    //F(i,las,cnt)cout<<"("<<p[i].x<<" "<<p[i].y<<")"<<endl;
}
I solve(int x){
    //cout<<x<<" ";
    D_2(x,0);if(siz[x]==1)return;
    maxi=INF;findroot(x,0,siz[x]);
    re rta=e[M^1].to,rtb=e[M].to;
    //cout<<rta<<" "<<rtb<<":"<<endl;
    e[M^1].v=e[M].v=1;cnt1=cnt2=0;
    D_3(rta,0,e[M].a,e[M].b);build(t1,cnt1);
    D_4(rtb,0,0,0);build(t2,cnt2);
    merge();
    solve(rta);solve(rtb);
}
int main(){
    //freopen("rain.out","w",stdout);
    read(n);read(m);C(head,-1);tot=-1;cnt=n;
    F(i,1,n)num[i]=i;
    F(i,1,n-1){
        read(X);read(Y);read(A);read(B);
        e[++tot]=(E){Y,head[X],A,B},head[X]=tot;
        e[++tot]=(E){X,head[Y],A,B},head[Y]=tot;
    }
    D_1(1,0);C(head,-1);tot=-1;cnt=0;
    for(auto p:vec)add(p.x,p.y,p.a,p.b),add(p.y,p.x,p.a,p.b);
    solve(1);build(p,cnt);
    n=1;
//  F(i,1,cnt)cout<<p[i].x<<" "<<p[i].y<<endl;
    F(i,0,m-1){
        while(n<cnt&&p[n+1].get(i)>p[n].get(i))n++;
        write(p[n].get(i));putchar(10);
         
    }
    return 0;
}