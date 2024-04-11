#include <bits/stdc++.h>
using namespace std;
int rub[2000001];
int pi[2000001];
bool is_palin(int i){
	stringstream ss;
	ss<<i;
	string s;
	ss>>s;
	i=0;
	int j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
int main(){
	///pi(n)~n/lg(n)
	///rub(n)~sqrt(n)
	///A>=pi(n)/rub(n)~sqrt(n)/ln(n)
	///sqrt(n)/ln(n)<=40+eps
	///1 mil should work//2
	for(int i=2; i<=2000000; i++) pi[i]=1;
	for(int i=2; i<=2000000; i++) if(pi[i]){
		for(int j=i+i; j<=2000000; j+=i) pi[j]=0;
	}
	for(int i=2; i<=2000000; i++) pi[i]+=pi[i-1];
	for(int i=1; i<=2000000; i++) rub[i]=rub[i-1]+is_palin(i);
	int ans=0;
	long long	x, y;
	cin>>x>>y;
	for(int i=1; i<=2000000; i++) if(y*pi[i]<=x*rub[i]) ans=i;
	cout<<ans<<'\n';
}