#include <bits/stdc++.h>
using namespace std;
int n;
string temp;
long long k;
vector <int> b, s;
void make(vector <pair <long long, int>> d){
	long long sum=0;
	for(auto x: d) sum+=x.first;
	int c=0;
	vector <int> a;
	while(sum>0){
		c+=sum%10;
		a.push_back(sum%10);
		sum/=10;
	}
	reverse(a.begin(), a.end());
	if(c<10){
		cout<<temp<<'\n';
		cout<<setw(d[0].second)<<setfill('0')<<d[0].first;
		for(int i=1; i<d.size(); i++) cout<<"+"<<setw(d[i].second)<<setfill('0')<<d[i].first;
		cout<<'\n';
		cout<<a[0];
		for(int i=1; i<a.size(); i++) cout<<"+"<<a[i];
		exit(0);
	}
}
vector <pair <long long, int>> d;
void backtrack(int u, long long n, int len=1){
	if(u==s.size()){
		d.push_back({n, len});
		make(d);
		d.pop_back();
	}
	else{
		backtrack(u+1, n*10+s[u], len+1);
		d.push_back({n, len});
		backtrack(u+1, s[u]);
		d.pop_back();
	}
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int lim=2;
void try_first(){
	temp="";
	int i=0;
	long long sum=0;
	for(int i=0; i<b.size(); i++){
		int diff=rng()%lim;
		while(diff+i>=b.size()) diff=rng()%lim;
		long long val=0;
		if(!temp.empty()) temp+='+';
		for(int j=0; j<=diff; j++){
			temp+=char(b[i+j]+48);
			(val*=10)+=b[i+j];
		}
		sum+=val;
		i+=diff;
	}
	s.clear();
	k=sum;
	while(sum){
		s.push_back(sum%10);
		sum/=10;
	}
	reverse(s.begin(), s.end());
	backtrack(1, s[0]);
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		char c;
		cin>>c;
		b.push_back(c-48);
	}
	if(b.size()==1){
		cout<<b[0]<<'\n';
		cout<<b[0]<<'\n';
		cout<<b[0]<<'\n';
		return 0;
	}
	while(true) try_first();
}