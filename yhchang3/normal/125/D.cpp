#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v){
   for(int i=0;i<v.size();i++)
      cout<<v[i]<<' ';
   cout<<endl;
}
bool check(vector<int> v){
   if(v.size()==0)   return false;
   if(v.size()==1||v.size()==2)  return true;
   int d=v[1]-v[0];
   for(int i=1;i<v.size();i++)
      if(v[i]-v[i-1]!=d)   return false;
   return true;
}
int a[30010];
int b[30010];
int n;
bool visit[30010];
bool solve(int l,int r){
   int d=a[r]-a[l];
   vector<int> va,vb;
   va.clear();vb.clear();
   memset(visit,0,sizeof visit);
   int now=a[l],last;
   for(int i=0;i<n;i++){
      if(a[i]==now){
         va.push_back(a[i]);
         now+=d;
         last=i;
      }
      else
         visit[i]=true;
   }
   for(int i=0;i<n;i++)
      if(visit[i])
         vb.push_back(a[i]);
   if(check(vb)){
      print(va);
      print(vb);
      return true;
   }
   visit[last]=false;
   va.pop_back();
   for(int i=0;i<n;i++)
      if(visit[i])
         vb.push_back(a[i]);
   if(check(vb)){
      print(va);
      print(vb);
      return true;
   }
   return false;
}
bool rsolve(int l,int r){
   int d=b[r]-b[l];
   vector<int> va,vb;
   va.clear();vb.clear();
   memset(visit,0,sizeof visit);
   int now=b[l],last;
   for(int i=0;i<n;i++){
      if(b[i]==now){
         va.push_back(b[i]);
         now+=d;
         last=i;
      }
      else
         visit[i]=true;
   }
   for(int i=0;i<n;i++)
      if(visit[i])
         vb.push_back(b[i]);
   if(check(vb)){
      reverse(va.begin(),va.end());
      reverse(vb.begin(),vb.end());
      print(va);
      print(vb);
      return true;
   }
   visit[last]=false;
   va.pop_back();
   for(int i=0;i<n;i++)
      if(visit[i])
         vb.push_back(b[i]);
   if(check(vb)){
      reverse(va.begin(),va.end());
      reverse(vb.begin(),vb.end());
      print(va);
      print(vb);
      return true;
   }
   return false;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      b[n-i-1]=a[i];
   }
   if(n==2){
      cout<<a[0]<<endl<<a[1]<<endl;
      return 0;
   }
   if(!solve(0,1)&&!solve(0,2)&&!solve(1,2))
      if(!rsolve(0,1)&&!rsolve(0,2)&&!rsolve(1,2))
         cout<<"No solution"<<endl;

}