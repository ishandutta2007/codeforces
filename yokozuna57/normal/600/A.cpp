#include <bits/stdc++.h>
using namespace std;

void out(vector<string> vec){
	if(vec.size()==0){
		puts("-");
		return;
	}
	string ret="\"";
	for(int i=0;i<vec.size();i++){
		ret+=vec[i];
		if(i+1<vec.size())ret+=",";
		else ret+="\"";
	}
	cout<<ret<<endl;
}

int main(){
	string s;
	cin >> s; s+=",";
	vector<string> A,B;
	
	string t="";
	for(int i=0;i<s.size();i++){
		if(s[i]==','||s[i]==';'){
			bool a=true;
			if(t.size()==0||!('1'<=t[0]&&t[0]<='9'))a=false;
			if(t.size()==1&&t[0]=='0')a=true;
			for(int i=1;i<t.size();i++){
				a&=('0'<=t[i]&&t[i]<='9');
			}
			if(a)A.push_back(t);
			else B.push_back(t);
			t="";
		}
		else t+=s[i];
	}
	out(A);
	out(B);
}