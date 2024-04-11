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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const ll mod=1e9+7,sh=201,inf=1e15;
const int N=1000000+5;
vector<pair<int,int> > v;
multiset<int> s;
int main()
{
    
    GO();
    int T=1,cs=1;
    
   // cin>>T;
    while(T--){
       
       int n;
       cin>>n;
       long double p;
       cin>>p;
      long double arr[1000+5];
      for(int i=0;i<=n;i++) arr[i]=0;


      for(int k=0;k<=n;k++){
        int sty= k;
        int non_sty= n-k; 
        bool ok=1;
       for(int i=0;i<(1<<3);i++){

           int b1= getBit(i,0);
           int b2= getBit(i,1);
           int b3= getBit(i,2);
         //  cout<<(1<<3)<<endl;
           
           long double pp=1.0;
           if(b1==0){
              pp= (non_sty+0.0)/n;
           }
           else{
               pp= (sty+0.0)/n;
           }

           if(b2==0){
              if(b1==0){
                  
                  if(non_sty-1<0){
                      continue;
                  }
                  else{

                      pp*= (non_sty-1+0.0)/(n-1);
                  }
              }
              else{

                  pp*= (non_sty+0.0)/(n-1);
              }

        }
        else{
            if(b1==1){
                  
                  if(sty-1<0){
                      continue;
                  }
                  else{

                      pp*= (sty-1+0.0)/(n-1);
                  }
              }
              else{

                  pp*= (sty+0.0)/(n-1);
              }


        }

        if(b3==0){

            if(b1+b2==0){
                
                if(non_sty-2<0){
                    continue;
                }
                else{
                    pp*= (non_sty-2+0.0)/(n-2);
                }
            }
            else if(b1+b2==1){
                if(non_sty-1<0){
                    continue;
                }
                else{
                    pp*= (non_sty-1+0.0)/(n-2);
                }
            }
            else if(b1+b2==2){
                pp*= (non_sty+0.0)/(n-2);
            }
        }
        else{
            if(b1+b2==2){
                
                if(sty-2<0){
                    continue;
                }
                else{
                    pp*= (sty-2+0.0)/(n-2);
                }
            }
            else if(b1+b2==1){
                if(sty-1<0){
                    continue;
                }
                else{
                    pp*= (sty-1+0.0)/(n-2);
                }
            }
            else if(b1+b2==0){
                pp*= (sty+0.0)/(n-2);
            }

        }
       // if(k==5) cout<<pp<<endl;
       
        
        if(b1+b2+b3==0){
            pp*=0;
        }
        else if(b1+b2+b3==1){
            pp*= 1.0/2;
        }
        else if(b1+b2+b3==2){
            pp*= 1;

        }
        else if(b1+b2+b3==3){
            pp*= 1;
        }

        
        arr[k]+= pp;
       

       }

      }

      for(int i=0;i<=n;i++){
        //  cout<<arr[i]<<endl;
          if(dcmp(arr[i],p)!=-1){
              cout<<i<<"\n";
              break;
              
          }
      }


    }
}