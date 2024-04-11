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

vector< pair<ll,ll> > v,b;
ll p[N],a[N];
bool check(int mid){

   multiset< pair<ll,ll> > S,v3;
   ll mx=v[0].first;

   for(int i=0;i<sz(b);i++){
    if(b[i].first>mx) break;
    ll id=b[i].second;
    S.insert(mp(p[id],-b[i].first));

   }
 //cout<<sz(S)<<endl;
   if(sz(S)<mid){
    return 0;
   }

   auto it=(S.begin());
   for(int i=0;i<mid;i++){
     v3.insert(mp((*it).second,(*it).first));
     it=S.erase(it);
   }



   ll pre=0,cnt=0;
   for(int i=0;i<sz(v);i++){
    ll mo=v[i].second+v[i].first+pre;
    ll mx=v[i].first;






  // cout<<mo<<" "<<mx<<" "<<pre<<endl;
    auto it=v3.begin();

    while(it!=v3.end()&&-(*it).first>mx){
        v3.erase(it);

        auto it2=S.begin();
        while(it2!=S.end()&&-(*it2).second>mx){
          it2=S.erase(it2);
        }

        if(it2!=S.end()){
            v3.insert(mp((*it2).second,(*it2).first));
            S.erase(it2);
        }

        it=v3.begin();
    }

    vector<pair<ll,ll> > vv;
    while(it!=v3.end()&&(i+1>=sz(v)||-(*it).first>v[i+1].first)){
        vv.pb(mp((*it).second,(*it).first));
        it++;
    }
    sort(all(vv));

    for(int j=0;j<sz(vv)&&mo>=vv[j].first;j++){
        mo-=vv[j].first;
        cnt++;
        v3.erase(v3.find(mp(vv[j].second,vv[j].first)));
    }


   //cout<<mo<<endl;
    pre=mo;

   }

   return (cnt>=mid);

}
int BS(int l,int r){

   int ans=l;

   while(l<=r){
    int mid=(l+r)/2;
    if(check(mid)){
        l=mid+1;
        ans=mid;
    }
    else{
        r=mid-1;
    }
   }
   return ans;

}
int main(){
    GO();

    int T=1;
    //cin>>T;

    while(T--){

        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2||y1==y2){
            cout<<(llabs(x2-x1)+llabs(y2-y1)+3)*2<<"\n";
        }
        else
        cout<<(llabs(x2-x1)+llabs(y2-y1)+2)*2<<"\n";

    }
}