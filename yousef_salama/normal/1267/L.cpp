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
const ll N=1000+5,mod=998244353,sh=1000000,inf=(1ll<<62);
string str[N];

int main(){
    // cout<<cbrt(2000000)*2000000<<"\n";
    GO();
    int T=1;
   // cin>>T;
    while(T--){
         string st;
         int n,l,k;
         cin>>n>>l>>k;
         k--;
         cin>>st;
         vector<int> v;

         for(int i=0;i<sz(st);i++){
            v.pb(st[i]-'a');
         }
         sort(all(v));
         int id=0;
         for(int i=0;i<=k;i++){
            str[i]+=(v[id]+'a');
            id++;
         }

         while(sz(str[k])<l){
            int num=k;
            //cout<<sz(str[k])<<endl;
            for(int i=k;i>=0;i--){
                if(i-1>=0&&str[i][sz(str[i])-1]==str[i-1][sz(str[i-1])-1]){
                    num=i-1;
                }
                else{
                    break;
                }
            }

            for(int i=num;i<=k;i++){
                str[i]+= (v[id]+'a');
                id++;
            }


         }
         //cerr<<"in"<<endl;
         for(int i=0;i<n;i++){
            while(sz(str[i])<l){
                str[i]+= (v[id]+'a');
                id++;
            }
         }

         for(int i=0;i<n;i++) cout<<str[i]<<"\n";

    }
}