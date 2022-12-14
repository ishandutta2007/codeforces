#include<bits/stdc++.h>
using namespace std;

bool vis[3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		bool ok=true;
		for(int i=0;i<s.size();i++)
			if(s[i]=='?'){
				memset(vis,false,sizeof vis);
				if(i-1>=0&&s[i-1]!='?')	vis[s[i-1]-'a']=true;
				if(i+1<s.size()&&s[i+1]!='?')	vis[s[i+1]-'a']=true;
				for(int j=0;;j++)
					if(!vis[j]){
						s[i]=char('a'+j);
						break;
					}
			}
		for(int i=0;i<s.size()-1;i++)
			if(s[i]==s[i+1])
				ok=false;
		if(!ok)
			cout<<-1<<'\n';
		else
			cout<<s<<'\n';
	}
}