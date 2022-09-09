#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int N=105;
string s[N];
int i,n,j;
int main(){
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s[i];
		for(j=1;j<i && s[j]!=s[i];++j);
		puts(j<i?"YES":"NO");
	}
	return 0;
}