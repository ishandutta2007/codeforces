#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define     PI                       acos(-1)
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define     point                    complex<double>
#define    dp(a,b)          (((conj(a))*(b)).real())
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-9);
using namespace std;
using namespace __gnu_pbds;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const ll N=300000+5,mod=1000000007,sh=201,inf=20000000;
typedef tree<
pair<ll,ll> ,
null_type,
less<pair<ll,ll> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int arr[10009];
vector<int> p,tp;
int n;
void apply(int fl){
  fl++;
  if(fl==1){
    for(int i=1;i<=n*2;i+=2){
        swap(tp[i],tp[i+1]);
    }
  }
  else{

    for(int i=1;i<=n;i++){
        swap(tp[i],tp[i+n]);
    }
  }


}
bool check(){

  for(int i=1;i<=n+n;i++){
    if(tp[i]!=i) return 0;
   }
   return 1;

}
int solve(int str){
   tp=p;
   if(check()) return 0;
 //  cerr<<sz(v)<<endl;
   for(int i=1,j=str;i<=n+n;i++){
      apply(j);
      j=!j;
      if(check()) return i;
   }

   return inf;

}

int main(){
     GO();

     cin>>n;
     int id=-1;
     p.resize(n+n+1);
     for(int i=1;i<=n+n;i++){
        cin>>p[i];
        if(p[i]!=i){
            id=i;
        }
     }

     if(id==-1){
        cout<<"0\n";
        return 0;
     }

     int ans=inf;
     ans=solve(0);
     ans=min(ans,solve(1));


     if(ans==inf)
     cout<<"-1\n";
     else
      cout<<ans<<"\n";


}