#include<bits/stdc++.h>
using namespace std;

int T;
map<string,vector<string> >mp;

string ss,s; int n,l1,l2;
void doit(vector<string>&the){
	for (cin>>n;n--;){
		cin>>s; the.push_back(s);
	}
	for (bool fl=1;fl;){
		n=the.size(); if (n<=1) break;
		fl=0;
		for (int i=0;i<n&&!fl;i++)
			for (int j=i+1;j<n&&!fl;j++){
				l1=the[i].length(), l2=the[j].length();
				if (l1>l2){
					if (the[j]==the[i].substr(l1-l2,l2)){
						for (int k=j;k<n-1;k++) the[k]=the[k+1]; the.pop_back();
						fl=1; break;
					}
				}else{
					if (the[i]==the[j].substr(l2-l1,l1)){
						for (int k=i;k<n-1;k++) the[k]=the[k+1]; the.pop_back();
						fl=1; break;
					}
				}
			}
	}
}

#define fi first
#define se second
int main(){
	for (cin>>T;T--;){
		cin>>ss;
		doit(mp[ss]);
	}
	printf("%d\n",mp.size());
	for (auto o:mp){
		cout<<o.fi<<" "<<o.se.size();
		for (auto p:o.se) cout<<" "<<p;
		puts("");
	}
}