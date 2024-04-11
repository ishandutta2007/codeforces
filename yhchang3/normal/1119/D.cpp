#include<bits/stdc++.h>
using namespace std;
long long int s[100000];
long long int a[100000];
long long int q[100001];
vector<long long int> v;
map<long long int,long long int> m;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int n,l,r,Q,pre=0;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>s[i];
   sort(s,s+n);
   for(int i=0;i<n-1;i++){
      a[i]=s[i+1]-s[i]-((long long int)1e18)-1;
   }
   sort(a,a+n-1);
   cin>>Q;
   for(int i=0;i<Q;i++){
      cin>>l>>r;
      q[i]=(long long int)1e18-r+l;
      v.push_back(q[i]);
   }
   sort(v.begin(),v.end());
   int now=n-2;
   long long int tmp=0;
   for(int i=0;i<v.size();i++){
      tmp+=(v[i]-pre)*(n-2-now);
      while(now>=0&&v[i]+a[now]>0){
         tmp+=v[i]+a[now];
         now--;
      }
      pre=v[i];
      m[v[i]]=tmp;
   }
   for(int i=0;i<Q;i++){
      cout<<s[n-1]-s[0]+1+(long long int)1e18-q[i]-m[q[i]]<<' ';
   }
   cout<<endl;
}