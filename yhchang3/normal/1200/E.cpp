#include<bits/stdc++.h>
using namespace std;

string ans;
const int MAXN=1e6+5;
int z[MAXN];
void Zvalue(string& s){
   z[0]=s.size();
   int l=0,r=0,x;
   for(int i=1;i<s.size();i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<s.size()&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;};
      }
      else
         z[i]=z[i-l];
   }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(i==1){
			ans=s;
			continue;
		}
		string zs=s+"$"+ans.substr(max((int)ans.size()-(int)s.size(),0));
		Zvalue(zs);
		int sub=0;
		for(int j=s.size()+1;j<zs.size();j++)
			if(z[j]+j==zs.size()){
				sub=z[j];
				break;
			}
		for(int j=sub;j<s.size();j++)
			ans+=s[j];
	}
	cout<<ans<<endl;
}