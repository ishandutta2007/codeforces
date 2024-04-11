#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   Y            imag()
#define   X            real()
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<long double>
#define     PI                       acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-15);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const ll N=200000+5,mod=998244353,sh=1000000,inf=100000000;
int par[N],rnk[N],a[N],b[N],c[N];
vector< pair<int,int > > ed;
void I(int n){

  for(int i=1;i<=n;i++) par[i]=i,rnk[i]=1;

}
int get_par(int n){

  if(par[n]==n) return n;
  return par[n]=get_par(par[n]);
}
bool lnk(int aa,int bb){

  aa=get_par(aa);
  bb=get_par(bb);
  if(aa==bb) return 0;
  if(rnk[aa]<rnk[bb]) swap(aa,bb);
  rnk[aa]+=rnk[bb];
  par[bb]=aa;
 return 1;
}
int main(){
    GO();
    int T=1;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        I(n);
        ll mi=1e15;
        ed.clear();

        int idx=0;
        for(int i=0;i<m;i++){
            cin>>a[i]>>b[i]>>c[i];
            ll co=abs(k-c[i]);
            if(co<mi){
                mi=co;
                idx=i;
            }
        }

        ll ans=mi,ans2=0;
        //cerr<<idx<<"\n";
        lnk(a[idx],b[idx]);
        for(int i=0;i<m;i++){
            if(i==idx) continue;
           // cout<<ed[i].first<<"\n";
            ll co=max(0,c[i]-k);
            ed.pb(mp(co,i));
        }

        sort(all(ed));
        for(int i=0;i<sz(ed);i++){
            int ni=ed[i].second;
            int A=a[ni];
            int B=b[ni];
            // cout<<ed[i].first<<"\n";
            if(lnk(A,B)){
                ans+=ed[i].first;
            }
        }

        I(n);
        ed.pb(mp(max(0,c[idx]-k),idx));
        sort(all(ed));
        bool ok=0;
        for(int i=0;i<sz(ed);i++){
            int ni=ed[i].second;
            int A=a[ni];
            int B=b[ni];
            // cout<<ed[i].first<<"\n";
            if(lnk(A,B)){
                if(c[ni]>=k) ok=1;
                ans2+=ed[i].first;
            }
        }


        if(ok==1)
        cout<<min(ans,ans2)<<"\n";
        else
        cout<<ans<<"\n";
    }
}