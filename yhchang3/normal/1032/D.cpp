#include<bits/stdc++.h>
using namespace std;
double dist(double a,double b,double c,double d){
   return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int a,b,c,d,e,f,g;
   cin>>a>>b>>c>>d>>e>>f>>g;
   double xa,xb,ya,yb,ans,x1,y1,x2,y2;
   x1=d;y1=e;x2=f;y2=g;
   ans=fabs(x1-x2)+fabs(y1-y2);
   if(a==0||b==0){
      cout<<fixed<<setprecision(10)<<ans<<endl;
      return 0;
   }
   xa=(-b*y1-c)/a;
   xb=(-b*y2-c)/a;
   ya=(-a*x1-c)/b;
   yb=(-a*x2-c)/b;
   ans=min(ans,fabs(x1-xa)+dist(xa,y1,xb,y2)+fabs(x2-xb));
   ans=min(ans,fabs(x1-xa)+dist(xa,y1,x2,yb)+fabs(y2-yb));
   ans=min(ans,fabs(y1-ya)+dist(x1,ya,xb,y2)+fabs(x2-xb));
   ans=min(ans,fabs(y1-ya)+dist(x1,ya,x2,yb)+fabs(y2-yb));
   cout<<fixed<<setprecision(10)<<ans<<endl;
}