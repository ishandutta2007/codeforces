/*
Rustyyyy
*/
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
const double EPS = 1e-6;
using namespace std;
//using namespace __gnu_pbds;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const ll mod=1e6,sh=201,inf=1e15;
const int N=1000000+5;
vector< pair<string,int> > v1;
bool cmp(pair<string,int> a, pair<string,int> b){

    for(int i=0;i<sz(a.first);i++){
       char ch1= a.first[i];
       char ch2 = b.first[i];

       if(i%2==0){
           if(ch1!=ch2){
               return (ch1<ch2);
           }
       }
       else{
           if(ch1!=ch2){
               return (ch1>ch2);
           }
       }
    }

    return (a.second<b.second);

}
int main()
{
    
    GO();
 
    int T=1,cs=1;
   // cin>>T;
    while(T--){

        int n,m;
        cin>>n>>m;

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v1.pb(mp(s,i+1));
           
        }

        sort(all(v1),cmp);

        for(int i=0;i<n;i++) cout<<v1[i].second<<" ";
        cout<<"\n";
        
        cout<<"\n";
    }
}