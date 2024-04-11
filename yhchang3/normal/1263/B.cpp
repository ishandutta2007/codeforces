#include<bits/stdc++.h>
using namespace std;
string s[10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i];
		int cnt=0;
		for(int i=0;i<n;i++){
			bool ok=true;
			for(int j=0;j<n;j++)
				if(s[i]==s[j]&&i!=j)
					ok=false;
			if(ok)	continue;
			cnt++;
			string t=s[i];
			for(char c='0';c<='9';c++){
				bool ok=true;
				t[0]=c;
				for(int j=0;j<n;j++)
					if(t==s[j])
						ok=false;
				if(ok){
					s[i]=t;
					break;
				}
			}

		}
		cout<<cnt<<'\n';
		for(int i=0;i<n;i++)
			cout<<s[i]<<'\n';
	}
}