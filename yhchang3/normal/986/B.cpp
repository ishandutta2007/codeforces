#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[1000000];
int n;
int BIT[1000001];
void add(int pos){
   for(;pos<=n;pos+=pos&-pos)
      BIT[pos]++;
}
int sum(int pos){
   int ans=0;
   for(;pos>0;pos-=pos&-pos)
      ans+=BIT[pos];
   return ans;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>p[i].first;
      p[i].second=i+1;
   }
   sort(p,p+n);
   int tmp=0;
   for(int i=n-1;i>=0;i--){
      tmp+=sum(p[i].second);
      add(p[i].second);
   }
   tmp+=n;
   if(tmp&1)
      cout<<"Um_nik"<<endl;
   else
      cout<<"Petr"<<endl;

}