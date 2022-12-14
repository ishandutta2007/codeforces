#include<bits/stdc++.h>
using namespace std;
int a[101];
vector<pair<int,pair<int,int> > > v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
   int n,tmp;
   cin>>n;
   int sum=0;
   for(int i=1;i<=100;i++)
      for(int j=i+1;j<=100;j++){
         tmp=0;
         for(int k=i;k<=j;k++){

            if(j%k==0&&k+i*j/k-i-j<tmp)
               tmp=k+i*j/k-i-j;
         }
         v.push_back({tmp,{i,j}});
         // tmp=i*j;
         // tmp2=ceil(sqrt(tmp));
         // while(true){
         //    if(tmp%tmp2==0){
         //       v.push_back({tmp2+tmp/tmp2-i-j,{i,j}});
         //       break;
         //    }
         //    tmp2--;
         // }
      }
   sort(v.begin(),v.end());
   for(int i=1;i<=n;i++){
      cin>>tmp;
      a[tmp]++;
      sum+=tmp;
   }
   for(int i=0;i<v.size();i++){
      if(a[v[i].second.first]&&a[v[i].second.second]){
         //cout<<v[i].second.first<<' '<<v[i].second.second<<endl;
         sum+=v[i].first;
         break;
      }
   }
   cout<<sum<<endl;

}