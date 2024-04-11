#include<bits/stdc++.h>
using namespace std;
int a[300000];
stack<int> st;
vector<int> v;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>a[i];
   int ans=0;
   st.push(0);
   int pos=0,posval=a[0];
   v.push_back(0);
   for(int i=1;i<n;i++){
      while(!st.empty()&&a[st.top()]%a[i]==0)
         st.pop();
      if(st.empty()){
         ans=i;
         v.clear();
         v.push_back(i);
         pos=0;posval=a[i];
      }
      else{
         if(a[i]%posval==0){
            if(i-pos>ans){
               ans=i-pos;
               v.clear();
               v.push_back(i);
            }
            else if(i-pos==ans)
               v.push_back(i);
         }
         else{
            pos=st.top()+1;
            posval=a[i];
            if(i-st.top()-1>ans){
               ans=i-st.top()-1;
               v.clear();
               v.push_back(i);
            }
            else if(i-st.top()-1==ans)
               v.push_back(i);
         }
      }
      st.push(i);
   }
   cout<<v.size()<<' '<<ans<<endl;
   for(int i=0;i<v.size();i++)
      cout<<v[i]-ans+1<<' ';
   cout<<endl;
}