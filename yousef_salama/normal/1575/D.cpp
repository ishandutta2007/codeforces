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
int vis[108];
int main()
{
    
    GO();
 
    int T=1,cs=1;
   // cin>>T;
    while(T--){

        string st,tst;
        cin>>st;
        tst= st;
        int n=sz(st);
        int visid=0;
        if(n==1){
            
            if(st[0]=='X'||st[0]=='_'||st[0]=='0') cout<<"1\n";
            else
            cout<<"0\n";
            continue;
        }
        
        if(st[0]=='0'){
            cout<<"0\n";
            continue;
        }

        
        bool mrk=1;
        ll tot=0;
        for(int i=0;i<=9&&mrk==1;i++){
            ll ans=1;
            if(st[0]=='X'&&i==0) continue;
            st=tst;
            mrk=0;
            for(int j=0;j<n-2;j++){
                if(st[j]=='_'){
                    if(j==0)
                    ans*=9;
                    else
                    ans*=10;
                }
                else if(st[j]=='X'){
                    st[j]= (char)(i+'0');
                    mrk=1;
                }
            }
            ll cnt=0;
            visid++;
            for(int j=0;j<=9;j++){
                if(j==0&&n-2==0&&st[n-2]=='_') continue;
                for(int k=0;k<=9;k++){
                    ll num=0;
                    char ch1 = st[n-1];
                    char ch2 = st[n-2];

                    if(st[n-2]=='_') st[n-2]= j+'0';
                    else if(st[n-2]=='X') st[n-2]= i+'0',mrk=1;

                    if(st[n-1]=='_') st[n-1]= k+'0';
                    else if(st[n-1]=='X') st[n-1]= i+'0',mrk=1;

                    num= num*10+ (st[n-2]-'0');
                    num=num*10+ (st[n-1]-'0');
                   //  cout<<st[n-2]<<" "<<st[n-1]<<endl;
                    if(vis[num]!=visid&&num%25==0){
                        cnt++;
                    }
                    vis[num]=visid;
                    st[n-1]=ch1;
                    st[n-2]=ch2;
                }
            }
            
            ans*=cnt;

           tot+= ans;

        }
       
       cout<<tot<<"\n";
    }
}