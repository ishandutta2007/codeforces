#include<bits/stdc++.h>
using namespace std;
int x[305],y[305];
const double eps=1e-12;
double ansp,ansn,tmp,ans;
double cross(int a,int b,int c){
   double x1=x[b]-x[a],y1=y[b]-y[a],x2=x[c]-x[a],y2=y[c]-y[a];
   return x1*y2-x2*y1;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>x[i]>>y[i];
   for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         ansp=ansn=0;
         for(int k=0;k<n;k++){
            if(k==i||k==j) continue;
            tmp=cross(i,j,k);
            if(tmp>0)
               ansp=max(tmp,ansp);
            else
               ansn=max(ansn,-tmp);
         }
         if(fabs(ansp)>eps&&fabs(ansn)>eps)
            ans=max(ans,ansp+ansn);
      }
   cout<<fixed<<setprecision(9)<<ans/2<<endl;
}