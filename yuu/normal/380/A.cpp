#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> p;
vector <int> v;
vector <long long> s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1, t, x, y; i<=n; i++){
		cin>>t>>x;
		if(t==1){
			p.push_back(0);
			v.push_back(x);
			s.push_back((s.empty()?0LL:(s.back()))+1);
		}
		else{
			cin>>y;
			while(y){
				if(p.size()>100000) break;
				for(int j=0; j<x; j++){
					p.push_back(0);
					v.push_back(v[j]);
					s.push_back(s.back()+1);
				}
				y--;
			}
			if(y){
				p.push_back(x);
				v.push_back(y);
				s.push_back(s.back()+x*y);
			}
		}
	}
	cin>>n;
	for(int i=1; i<=n; i++){
		long long pos;
		cin>>pos;
		int id=lower_bound(s.begin(), s.end(), pos)-s.begin();
		if(id) pos-=s[id-1];
		long long res;
		if(p[id]==0) res=v[id];
		else{
			pos--;
			pos%=p[id];
			res=v[pos];
		}
		cout<<res<<" \n"[i==n];
	}
}