#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin>>n;
	
	ll a[10]={};
	ll cnt=1;
	for(int i=0;i<10;i++)a[i]=1;
	int k=0;
	while(cnt<n){
		cnt/=a[k];
		a[k]++;
		cnt*=a[k];
		k++;
		if(k==10)k=0;
	}
	string CF="codeforces";
	string ret="";
	for(int i=0;i<10;i++){
		for(int j=0;j<a[i];j++){
			ret+=CF[i];
		}
	}
	cout<<ret<<endl;
}