#include<bits/stdc++.h>
using namespace std;

string s[60];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		int cA=0,cP=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				cA+=s[i][j]=='A';
				cP+=s[i][j]=='P';
			}
		if(cP==0){
			cout<<0<<'\n';
		}
		else if(cA==0){
			cout<<"MORTAL"<<'\n';
		}
		else{
			bool ok=false,ok1=true,ok2=true,ok3=true,ok4=true;
			for(int i=0;i<n;i++){
				if(s[i][0]=='P')
					ok1=false;
				if(s[i][m-1]=='P')
					ok2=false;
			}
			for(int j=0;j<m;j++){
				if(s[0][j]=='P')
					ok3=false;
				if(s[n-1][j]=='P')
					ok4=false;
			}
			ok=ok1|ok2|ok3|ok4;
			if(ok){
				cout<<1<<'\n';
				continue;
			}
			ok=false;
			for(int i=0;i<n;i++){
				bool okok=true;
				for(int j=0;j<m;j++)
					if(s[i][j]=='P'){
						okok=false;
						break;
					}
				ok|=okok;
			}
			for(int j=0;j<m;j++){
				bool okok=true;
				for(int i=0;i<n;i++)
					if(s[i][j]=='P'){
						okok=false;
						break;
					}
				ok|=okok;
			}
			if(ok||s[0][0]=='A'||s[n-1][0]=='A'||s[0][m-1]=='A'||s[n-1][m-1]=='A'){
				cout<<2<<'\n';
				continue;
			}
			ok=false;
			for(int i=0;i<n;i++)
				if(s[i][0]=='A'||s[i][m-1]=='A')
					ok=true;
			for(int j=0;j<m;j++)
				if(s[0][j]=='A'||s[n-1][j]=='A')
					ok=true;
			if(ok)
				cout<<3<<'\n';
			else
				cout<<4<<'\n';
		}
	}
}