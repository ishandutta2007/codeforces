#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll MOD=998244353;

string s;
int a[2000010];
void manachar(){
	int i=0,j=0;
	while(i<s.size()){
		while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])j++;
		a[i]=j;
		int k=1;
		while(i-k>=0&&i+k<s.size()&&k+a[i-k]<j){
			a[i+k]=a[i-k];
			k++;
		}
		i+=k; j-=k;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		string t;
		cin>>t;
		int x=0;
		while(x<t.size()-1-x&&t[x]==t[t.size()-1-x])x++;
		s="";
		for(int i=x;i<t.size()-x;i++){
			s+=t[i];
			if(i+1<t.size()-x)s+="$";
		}
		manachar();
		int y=0,z=0;
		for(int i=0;i<s.size();i++){
			if(a[i]>=i+1)y=a[i];
			if(a[i]>=s.size()-i)chmax(z,a[i]);
		}
		if(y>=z)cout<<t.substr(0,x+y)<<t.substr(t.size()-x,x)<<"\n";
		else cout<<t.substr(0,x)<<t.substr(t.size()-x-z,x+z)<<"\n";
	}
}