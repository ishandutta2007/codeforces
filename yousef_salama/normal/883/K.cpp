#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define     PI                       acos(-1)
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
const ll N=200000+5,mod=1000000007,sh=201,inf=2000000000;
typedef tree<
pair<ll,ll> , // here the data type stored in set/map_key it can be pair<int,int> or what ever
null_type,  // that's the data type of the mapped value in case i use map if i use set so there won't a mapped value it will null_type.
less<pair<ll,ll> >, // the comparator it can be less or greater < the data type of key >
rb_tree_tag, // the type of the tree used we only use red_black_tree
tree_order_statistics_node_update>
ordered_set;
ll s[N],g[N],ans[N],To[N],F[N];
int main(){
    GO();

    int T=1;
    //cin>>T;

    while(T--){

       int n;
       cin>>n;

       for(int i=1;i<=n;i++){
        cin>>s[i]>>g[i];
       }

       F[1]=s[1];
       To[1]=s[1]+g[1];
       ll res=0;
       for(int i=2;i<=n;i++){
        ll ff=max(F[i-1]-1,s[i]);
        ll tt=min(s[i]+g[i],To[i-1]+1);
        if(ff>tt){
            cout<<"-1\n";
            return 0;
        }

        F[i]=ff;
        To[i]=tt;
       }

       ans[n]=To[n];
       res+= ans[n]-s[n];

       for(int i=n-1;i>=1;i--){
        ans[i]=min(To[i],ans[i+1]+1);
        res+= ans[i]-s[i];

       }
       cout<<res<<"\n";
       for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
       cout<<"\n";



    }
}