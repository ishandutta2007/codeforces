#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		string t;
		for(int i=0;i<2*(k-1);i++)
			if(i&1)
				t+=')';
			else
				t+='(';
		int r=(n-2*(k-1))/2;
		for(int i=0;i<r;i++)
			t+='(';
		for(int i=0;i<r;i++)
			t+=')';
		cout<<n<<'\n';
		for(int i=0;i<n;i++){
			if(s[i]==t[i])
				cout<<i+1<<' '<<i+1<<'\n';
			else{
				int j;
				for(j=i+1;;j++)
					if(s[j]!=s[i])
						break;
				cout<<i+1<<' '<<j+1<<'\n';
				for(int a=i,b=j;a<b;a++,b--)
					swap(s[a],s[b]);
			}
		}
		assert(s==t);
	}
}