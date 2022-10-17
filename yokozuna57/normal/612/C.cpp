#include <bits/stdc++.h>
using namespace std;

char c[4][2]={{'<','>'},{'{','}'},{'[',']'},{'(',')'}};

void NG(){
	puts("Impossible");
	exit(0);
}

int main(){
	static string s;
	cin>>s;
	
	int ret=0;
	static stack<char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='['||s[i]=='('||s[i]=='{'||s[i]=='<'){
			st.push(s[i]);
		}
		else {
			if(st.size()==0)NG();
			char t=st.top(); st.pop();
			bool ok=false;
			for(int k=0;k<4;k++){
				ok|=(t==c[k][0]&&s[i]==c[k][1]);
			}
			if(!ok)ret++;
		}
	}
	if(st.size()>0)NG();
	cout<<ret<<endl;
}