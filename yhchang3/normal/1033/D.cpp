#include<bits/stdc++.h>
using namespace std;
long long int a[501];
bool visit[501];
map<long long int,int> m,mm;
vector<long long int> v;
long long int MOD=998244353;
long long int GCD(long long int a,long long int b){
   if(a<b)  swap(a,b);
   while((a%=b)&&(b%=a));
   return max(a,b);
}
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      long long int x=round(sqrt(a[i]));
      long long int z=round(cbrt(a[i]));
      if(x*x==a[i]){
         long long int y=round(sqrt(x));
         if(y*y==x){
            m[y]+=4;
         }
         else{
            m[x]+=2;
         }
      }
      else if(z*z*z==a[i]){
         m[z]+=3;
      }
      else{
         v.push_back(a[i]);
      }
   }
   for(int i=0;i<v.size();i++){
      if(visit[i])   continue;
      for(map<long long int,int>::iterator it=m.begin();it!=m.end();it++){
         if(v[i]%(it->first)==0){
            m[it->first]++;
            m[v[i]/(it->first)]++;
            visit[i]=true;
            break;
         }
      }
      if(visit[i])   continue;
      for(int j=i+1;j<v.size();j++){
         long long int tmp=GCD(v[i],v[j]);
         if(tmp==v[i])  continue;
         if(tmp!=1){
            m[tmp]+=2;
            m[v[i]/tmp]++;
            m[v[j]/tmp]++;
            visit[i]=visit[j]=true;
         }
         if(visit[i])   break;
      }
   }
   for(int i=0;i<v.size();i++){
      if(!visit[i])
         mm[v[i]]++;
   }
   long long int ans=1;
   for(map<long long int,int>::iterator it=m.begin();it!=m.end();it++){
      ans=ans*(it->second+1)%MOD;
   }
   for(map<long long int,int>::iterator it=mm.begin();it!=mm.end();it++){
      ans=ans*(it->second+1)*(it->second+1)%MOD;
   }
   cout<<ans<<endl;
   cout.flush();
}