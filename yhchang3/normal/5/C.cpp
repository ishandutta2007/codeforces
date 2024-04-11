#include<bits/stdc++.h>
using namespace std;
string s;
stack<pair<int,int> > st;
int pos=-1;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   int ans=0,cnt=1;
   for(int i=0;i<s.size();i++){
      if(s[i]=='('){
         if(st.empty())
            st.push({i,pos+1});
         else
            st.push({i,st.top().first+1});
      }

      else{
         if(st.empty()){
            pos=i;
         }
         else{
            if(!st.empty()){
               if(i-st.top().second+1>ans){
                  ans=i-st.top().second+1;
                  cnt=1;
               }
               else if(i-st.top().second+1==ans)
                  cnt++;
               st.pop();
            }
         }
      }
   }
   cout<<ans<<' '<<cnt<<endl;
}