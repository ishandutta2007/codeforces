#include<iostream>
#include<set>
using namespace std;
#define ll long long
int a[200010];
int pre[200010];
int main(){
   int t;cin>>t;
   while(t--){
       int n;cin>>n;
       for(int i=1;i<=n;i++){
           cin>>a[i];
       }
       for(int i=1;i<=n;i++)pre[i]=0;
       int ans=1e9;
       for(int i=1;i<=n;i++){
           if(pre[a[i]]==0){
               pre[a[i]]=i;
           }
           else{
               ans=min(ans,i-pre[a[i]]+1);
               pre[a[i]]=i;
           }
       }
       cout<<(ans==1e9?-1:ans)<<endl;
   }
}