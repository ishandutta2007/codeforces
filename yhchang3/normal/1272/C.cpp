#include<bits/stdc++.h>
using namespace std;

bool ok[200000];
bool c[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<k;i++){
		char cc;
		cin>>cc;
		c[cc-'a']=true;
	}
	for(int i=0;i<n;i++)
		if(c[s[i]-'a'])
			ok[i]=true;
	long long int ans=0;
	for(int i=0;i<n;i++){
		if(!ok[i])	continue;
		int j=i;
		while(j+1<n&&ok[j+1])	j++;
		ans+=(j-i+1LL)*(j-i+2LL);
		i=j;
	}
	cout<<ans/2<<endl;
}