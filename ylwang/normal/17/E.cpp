#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(register int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=2e6+5,P=51123987;
typedef int arr[N];
typedef long long ll;
int n,sum,ans;arr suf,dep;char s[N];
struct eg{int nx,to,w;};
struct node{int fail,len,cnt;};
inline int pls(int a,int b){return a+=b,a>=P?a-P:a;}
inline int sub(int a,int b){return a-=b,a<0?a+P:a;}
struct PAM{
    int n,tot,las,ce;arr fi,s;node a[N];eg e[N];
    inline void add(int u,int v,int w){e[++ce]={fi[u],v,w},fi[u]=ce;}
    inline void init(){s[0]=-1,tot=1,ce=n=las=0;a[0].fail=1,a[1].len=-1;}
    inline int gf(int x){while(s[n-a[x].len-1]^s[n])x=a[x].fail;return x;}
    inline int get(int u,int w){go(u)if(e[i].w==w)return v;return 0;}
    inline int ins(int v){
        int&u=tot;s[++n]=v;las=gf(las);
        if(!get(las,v)){
            a[++u]={get(gf(a[las].fail),v),a[las].len+2,0};
			add(las,u,v);dep[u]=dep[a[u].fail]+1;
        }++a[las=get(las,v)].cnt;return dep[las];
    }
    inline int calc(){
        int tp=0;
        fd(i,tot,2)tp=pls(tp,a[i].cnt),
        	a[a[i].fail].cnt+=a[i].cnt;
        return tp;
    }
}p;
int main(){
    #ifndef ONLINE_JUDGE
        file("s");
    #endif
    scanf("%d%s",&n,s+1);
    p.init();fd(i,n,1)suf[i]=pls(suf[i+1],p.ins(s[i]-'a'));
    memset(p.fi,0,4*(p.tot+1));
    p.init();fp(i,1,n)ans=pls(ans,1ll*p.ins(s[i]-'a')*suf[i+1]%P);
    sum=p.calc();sum=1ll*sum*(sum-1)/2%P;printf("%d",sub(sum,ans));
return 0;
}