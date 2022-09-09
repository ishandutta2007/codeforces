#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define SZ(x) ((int)x.size())
string S,s,ans;
vector<string> a;
map<string,string> MAP;
int main(){
	while(1){
		cin>>s;
		if(s=="\\begin{thebibliography}{99}"){
			ans=ans+s+'\n';
			break;
		}
		S=S+" "+s;
	}
	getline(cin,s);
	int la=-1;
	ref(i,0,SZ(S)-1){
		if(S[i]=='{')la=i;
		if(S[i]=='}'){
			string x="";
			ref(j,la+1,i-1)x=x+S[j];
			a.push_back(x);
		}
	}
	bool err=0;
	ref(i,0,SZ(a)-1){
		getline(cin,s);
		string x="";
		int la=-1;
		ref(I,0,SZ(s)-1){
			if(s[I]=='{')la=I;
			if(s[I]=='}'){
				ref(j,la+1,I-1)x=x+s[j];
				break;
			}
		}
		if(x!=a[i])err=1;
		MAP[x]=s;
	}
	if(err)cout<<"Incorrect"<<endl;else{
		cout<<"Correct"<<endl;
		return 0;
	}
	ref(i,0,SZ(a)-1)ans=ans+MAP[a[i]]+'\n';
	getline(cin,s);ans=ans+s+'\n';
	cout<<ans;
}