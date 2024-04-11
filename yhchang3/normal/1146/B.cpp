#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]!='a')
			s1+=s[i];
	if(s1.size()&1){
		cout<<":("<<endl;
		return 0;
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[i+(int)s1.size()/2]){
			cout<<":("<<endl;
			return 0;
		}
	}
	int tmp=(int) s1.size()/2;
	for(int i=0;i<tmp;i++){
		if(s1.back()!=s.back()){
			cout<<":("<<endl;
			return 0;
		}
		s1.pop_back();
		s.pop_back();
	}
	cout<<s<<endl;
}