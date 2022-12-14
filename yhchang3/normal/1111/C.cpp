#include<bits/stdc++.h>
using namespace std;
long long int n,k,A,B,tmp;
vector<long long int> a;
long long int destroy(int x,int y){
   int p=upper_bound(a.begin(),a.end(),y)-lower_bound(a.begin(),a.end(),x);
   //cout<<x<<' '<<y<<' '<<p<<endl;
   if(p==0)
         return A;
   else
      if(x==y)
         return p*B;
      else
         return min(p*B*(y-x+1),destroy(x,(x+y)/2)+destroy((x+y)/2+1,y));
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k>>A>>B;
   for(int i=0;i<k;i++){
      cin>>tmp;
      a.push_back(tmp);
   }
   sort(a.begin(),a.end());
   cout<<destroy(1,1<<n)<<endl;

}