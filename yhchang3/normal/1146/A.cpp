#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='a')
			cnt++;
	cout<<min(cnt*2-1,(int) s.size())<<endl;
}