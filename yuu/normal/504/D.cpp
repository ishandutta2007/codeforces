#include <bits/stdc++.h>
using namespace std;
const int SZ=2048;
int done[SZ];
vector <pair <bitset <SZ>, bitset<SZ>>> basis; 
int n;
const long long base=1LL<<32;

bitset <SZ> input_reader(){
	vector <long long> v;
	v.push_back(0);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i+=8){
		int p10=1;
		int val=0;
		for(int j=0; j<8; j++){
			if(i+j>=s.size()) break;
			val=val*10+s[i+j]-'0';
			p10*=10;
		}
		for(auto &x: v) x*=p10;
		v[0]+=val;
		for(int i=0; i<v.size(); i++){
			if(v[i]>=base){
				if(i+1==v.size()) v.push_back(0);
				v[i+1]+=v[i]>>32;
				v[i]&=base-1;
			}
		}
	}
	bitset <SZ> res=0;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<32; j++){
			if(i*32+j>=SZ) break;
			res[i*32+j]=v[i]%2;
			v[i]/=2;
		}
	}
	return res;
}
int main(){
	for(int i=0; i<SZ; i++) done[i]=-1;
	cin>>n;
	for(int z=0; z<n; z++){
		auto x=input_reader();
		bitset <SZ> rep;
		for(int i=0; i<SZ; i++) if(x[i]){
			if(done[i]!=-1){
				x^=basis[done[i]].first;
				rep^=basis[done[i]].second;
			}
		}
		for(int i=0; i<SZ; i++) if(x[i]){
			done[i]=basis.size();
			rep[z]=1;
			for(int j=0; j<basis.size(); j++) if(basis[j].first[i]){
				basis[j].first^=x;
				basis[j].second^=rep;
			}
			basis.push_back(make_pair(x, rep));
			rep=0;
			break;
		}
		int cnt=0;
		for(int i=0; i<SZ; i++) cnt+=rep[i];
		cout<<cnt;
		if(cnt)	for(int i=0; i<SZ; i++) if(rep[i]) cout<<' '<<i;
		cout<<'\n';
	}
}