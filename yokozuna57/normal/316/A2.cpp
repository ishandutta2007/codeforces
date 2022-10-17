#include<iostream>
#include<string>
using namespace std;

int main(){
	bool AJ[12],first=false;
	for(int i=0;i<12;i++)AJ[i]=false;
	long long int ans=1,h=0,k=0;
	string s;
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if('A'<=s[i]&&s[i]<='J')AJ[s[i]-'A']=true;
		if(s[i]=='?')h++;
	}
	for(int i=0;i<10;i++)if(AJ[i])k++;
	int j=10;
	for(int i=0;i<k;i++){
		ans*=j;
		j--;
	}
	if('A'<=s[0]&&s[0]<='J'){ans/=10; ans*=9;}
	if(s[0]=='?'){ans*=9; h--;}
	cout<<ans;
	for(int i=0;i<h;i++)cout<<"0";
}