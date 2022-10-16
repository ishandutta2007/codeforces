#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll f[200001];
ll r[200001];
string a, b;
int c[2][2];
ll C(int n, int k){
	if(n<k) return 0;
	return ((f[n]*r[k])%base*r[n-k])%base;
}
ll candy(int n, int k){
	if(k==0) return (n==0);
	return C(n+k-1, k-1);
}
int solve(int c[2][2], bool s){//ignore length, start with s
	if(c[0][0]<0) return 0;
	if(c[0][1]<0) return 0;
	if(c[1][0]<0) return 0;
	if(c[1][1]<0) return 0;
	ll ans=0;
	if(s==0){
		//start with 0, b==a or b==a-1
		int a=c[1][0]+1;
		int b=c[0][1];
		if((b<=a)&&(b>=a-1)) ans+=(candy(c[0][0], a)*candy(c[1][1], b))%base;
	}
	else{
		//start with 1, b==a or b==a+1
		int a=c[1][0];
		int b=c[0][1]+1;
		if((a<=b)&&(a>=b-1)) ans+=(candy(c[0][0], a)*candy(c[1][1], b))%base;
	}
	return ans%base;
}
int get(string s){
	if(s=="0") return 0;
	int length=1;
	length+=c[0][0];
	length+=c[0][1];
	length+=c[1][0];
	length+=c[1][1];
	if(length>s.size()) return 0;
	if(length<s.size()){
		return solve(c, 1)%base;
	}
	else{
		int a[2][2];
		a[0][0]=c[0][0];
		a[0][1]=c[0][1];
		a[1][0]=c[1][0];
		a[1][1]=c[1][1];
		ll ans=0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='1') if(i){
				a[s[i-1]-'0'][0]--;
				ans+=solve(a, 0);
				a[s[i-1]-'0'][0]++;
			}
			if(i)	a[s[i-1]-'0'][s[i]-'0']--;
		}
		if((a[0][0]==0)&&(a[0][1]==0)&&(a[1][0]==0)&&(a[1][1]==0)) ans++;
		ans%=base;
		return ans;
	}
}
int main(){
	f[0]=1;
	for(int i=1; i<=200000; i++) f[i]=(f[i-1]*i)%base;
	r[200000]=power(f[200000], base-2);
	for(int i=200000; i>=1; i--) r[i-1]=(r[i]*i)%base;
	cin>>a>>b;
	for(int i=a.size()-1; i>=0; i--) if(a[i]=='0') a[i]='1'; else{
		a[i]='0';
		break;
	}
	for(int i=0; i<=1; i++) for(int j=0; j<=1; j++) cin>>c[i][j];
	int x=get(a);
	int y=get(b);
	y-=x;
	if(y<0) y+=base;
	cout<<y<<'\n';
}
//number in the form of 1010101010
//let a be count 0
//let b be count 1
//if start with 0 -> c[0][1]=b, c[1][0]=a-1
//if start with 1 -> c[0][1]=b-1, c[1][0]=a
//abs(a-b)<=1
//have form, how to place the number: 

//number of 10 is