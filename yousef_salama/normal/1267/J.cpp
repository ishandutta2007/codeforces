#include <bits/stdc++.h>
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
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const ll N=2000000+5,mod=998244353,sh=1000000,inf=(1ll<<62);
int cnt[N],a[N];
vector<int> v1;
int main(){
    // cout<<cbrt(2000000)*2000000<<"\n";
    GO();
    int T=1;
    cin>>T;
    while(T--){
         int n;
         cin>>n;
         v1.clear();
         for(int i=1;i<=n;i++) cnt[i]=0;
         for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
         }
         int mi=n;
         for(int i=1;i<=n;i++){
            if(cnt[i]==0) continue;
            v1.pb(cnt[i]);
            mi=min(mi,cnt[i]);
         }
         int ans=n;
         for(int i=1;i<=mi+1;i++){
            int siz=i;
            bool ok=1;
            int op=0;
            for(int j=0;j<sz(v1)&&ok;j++){
                int num=v1[j];
                int mo=num%siz;
                int rem= siz-1-mo;
                if(mo==0||rem<=num/siz){
                    op+= num/siz+ (num%siz!=0);
                }
                else{
                    ok=0;
                }
            }


            if(ok){
                ans=min(ans,op);
            }

         }
         cout<<ans<<"\n";

    }
}