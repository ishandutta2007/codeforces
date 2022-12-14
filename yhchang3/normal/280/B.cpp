#include<bits/stdc++.h>
using namespace std;
int a[100000];
stack<int> st;
int main(){
   ios_base::sync_with_stdio(0);;
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>a[i];
   st.push(a[0]);
   int ans=0;
   for(int i=1;i<n;i++){
      while(!st.empty()&&a[i]>st.top()){
         ans=max(ans,a[i]^st.top());
         st.pop();
      }
      if(!st.empty()){
         ans=max(ans,a[i]^st.top());
      }
      st.push(a[i]);
   }
   cout<<ans<<endl;
}