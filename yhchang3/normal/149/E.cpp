#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1010,INF=1e9;
string text,rtext,pattern;
int z[MAXN],pos[1010];
void Zvalue(string s){
   z[0]=s.size();
   int l=0,r=0,x;
   for(int i=1;i<s.size();i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<s.size()&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;}
      }
      else
         z[i]=z[i-l];
      if(i>pattern.size()&&z[i])
         pos[z[i]]=min(pos[z[i]],i-(int) pattern.size()+z[i]-2);
   }
}
bool check(string s){
   z[0]=s.size();
   int l=0,r=0,x;
   for(int i=1;i<s.size();i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<s.size()&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;}
      }
      else
         z[i]=z[i-l];
      if(i>pattern.size()&&pos[pattern.size()-z[i]]<=(int) s.size()-1-i-z[i]){
         return true;
      }

   }
   return false;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin>>text;
   rtext=text;
   reverse(rtext.begin(),rtext.end());
   int t,ans=0;
   cin>>t;
   pos[0]=-1;
   while(t--){
      for(int i=1;i<=1005;i++)
         pos[i]=INF;
      cin>>pattern;
      if(pattern.size()==1)   continue;
      s=pattern+"$"+text;
      Zvalue(s);
      reverse(pattern.begin(),pattern.end());
      s=pattern+"$"+rtext;
      for(int i=(int)pattern.size()-1;i>=1;i--)
         pos[i]=min(pos[i],pos[i+1]-1);
      /*for(int i=1;i<=pattern.size();i++)
         cout<<i<<' '<<pos[i]<<endl;*/
      if(check(s)){
         ans++;
         //cout<<t+1<<endl;
      }
      /*for(int i=25;i<s.size();i++){
         cout<<i-25<<' '<<z[i]<<endl;
      }
      cout<<s<<endl;*/
   }
   cout<<ans<<endl;
}