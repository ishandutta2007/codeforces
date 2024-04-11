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
priority_queue< pair<int,int> > pq;
int vis[30];
ll n,m,k,tot,mem[26][N];
ll solve(int id,int ex,int sum){

    if(id==26){
        ll rem= min(m,tot-sum);
        if(n-sum+m-rem<=vis[ex]){
            return 1ll*(n-sum)*(m-rem);
        }
        else{
            return n*m;
        }
    }

    ll &ret=mem[id][sum];
    ll ans=n*m;


    if(ret!=-1) return ret;
    if(id==ex){
        ans=min(ans,solve(id+1,ex,sum));

    }
    else{
    if(vis[id]>0&&sum+vis[id]<=n){
        ans=min(ans,solve(id+1,ex,sum+vis[id]));
    }

    ans=min(ans,solve(id+1,ex,sum));

    }

    return ret=ans;


}
bool solve2(int id,int sum){

   if(id==26){
    ll rem= tot-sum;
    if(rem>=m&&sum>=n) return 1;
    return 0;
   }

   ll &ret=mem[id][sum];

   if(ret!=-1) return ret;

   int ans=0;
   ans|= solve2(id+1,sum);
   ans|= solve2(id+1,sum+vis[id]);

   return ret=ans;

}
int main(){
     GO();
     int T=1;
     cin>>T;

     while(T--){


        string st;
        cin>>n>>m>>k;
        cin>>st;
        for(int i=0;i<26;i++) vis[i]=0;
        tot=0;
        for(int i=0;i<k;i++){
            vis[st[i]-'A']++;
        }
        for(int i=0;i<26;i++) tot+=vis[i];

        for(int i=0;i<26;i++){
            for(int j=0;j<=k;j++){
                mem[i][j]=-1;
            }
        }

        if(solve2(0,0)==1){
            cout<<"0\n";
            continue;
        }

        ll ans=n*m;

        for(int i=0;i<26;i++){
            if(vis[i]==0) continue;

           for(int l=0;l<26;l++){
              for(int j=0;j<=k;j++){
                mem[l][j]=-1;
              }
            }
            tot-=vis[i];
            ans=min(ans,solve(0,i,0));
            tot+=vis[i];
        }
        cout<<ans<<"\n";

     }

}