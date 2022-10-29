#include<bits/stdc++.h>
using namespace std;
int n,x;
map<int,int>st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&x),st[x]^=1;
	for(auto s:st)if(s.second)return puts("Conan"),0;
	puts("Agasa");
}