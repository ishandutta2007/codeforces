#include <bits/stdc++.h>
using namespace std;
string ss, tt;
class compressed_string: public deque <pair <char, int>>{
public:
	compressed_string(string s=""){
		clear();
		for(char c: s){
			if(empty()||back().first!=c) push_back({c, 1});
			else back().second++;
		}
	}
	void insert_front(compressed_string c){
		while(!c.empty()){
			if(empty()||(c.back().first!=front().first)) push_front(c.back());
			else front().second+=c.back().second;
			c.pop_back();
		}		
	}
};
compressed_string s, t;
vector <pair <int, int>> ans;
int main(){
	cin>>ss>>tt;
	s=compressed_string(ss);
	t=compressed_string(tt);
	while(s.size()+t.size()>3){
		if(s.empty()){
			int sz=0;
			while(s.size()<t.size()){
				sz+=t.front().second;
				s.push_back(t.front());
				t.pop_front();
			}
			ans.push_back({0, sz});
		}
		else if(t.empty()){
			int sz=0;
			while(t.size()<s.size()){
				sz+=s.front().second;
				t.push_back(s.front());
				s.pop_front();
			}
			ans.push_back({sz, 0});
		}
		else if(t.size()==1){
			int x=s.size()/2;
			if(s.size()%2==0) x--;
			if(s[x].first==t[0].first){
				compressed_string pfs, pft;
				int szs=0, szt=0;
				for(int i=0; i<=x; i++){
					pft.push_back(s.front());
					szs+=s.front().second;
					s.pop_front();
				}
				s.insert_front(pfs);
				t.insert_front(pft);
				ans.push_back({szs, szt});
			}
			else{
				compressed_string pfs, pft;
				int szs=0, szt=0;
				for(int i=0; i<=x; i++){
					pft.push_back(s.front());
					szs+=s.front().second;
					s.pop_front();
				}
				pfs.push_back(t.front());
				szt+=t.front().second;
				t.pop_front();
				s.insert_front(pfs);
				t.insert_front(pft);
				ans.push_back({szs, szt});
			}
		}
		else if(s.size()==1){
			int x=t.size()/2;
			if(t.size()%2==0) x--;
			if(t[x].first==s[0].first){
				compressed_string pfs, pft;
				int szs=0, szt=0;
				for(int i=0; i<=x; i++){
					pfs.push_back(t.front());
					szt+=t.front().second;
					t.pop_front();
				}
				t.insert_front(pft);
				s.insert_front(pfs);
				ans.push_back({szs, szt});
			}
			else{
				compressed_string pfs, pft;
				int szs=0, szt=0;
				for(int i=0; i<=x; i++){
					pfs.push_back(t.front());
					szt+=t.front().second;
					t.pop_front();
				}
				pft.push_back(s.front());
				szs+=s.front().second;
				s.pop_front();
				s.insert_front(pfs);
				t.insert_front(pft);
				ans.push_back({szs, szt});
			}
			
		}
		else{
			if(s[0].first==t[0].first){
				if(s.size()>t.size()){
					int x=(s.size()+2-t.size())/2;
					if(x%2) x++;
					if(x==s.size()) x-=2;
					compressed_string pfs, pft;
					int szs=0, szt=0;
					for(int i=0; i<x; i++){
						pft.push_back(s.front());
						szs+=s.front().second;
						s.pop_front();
					}
					pfs.push_back(t.front());
					szt+=t.front().second;
					t.pop_front();
					s.insert_front(pfs);
					t.insert_front(pft);
					ans.push_back({szs, szt});
				}
				else{
					int x=(t.size()+2-s.size())/2;
					if(x%2) x++;
					if(x==t.size()) x-=2;
					compressed_string pfs, pft;
					int szs=0, szt=0;
					for(int i=0; i<x; i++){
						pfs.push_back(t.front());
						szt+=t.front().second;
						t.pop_front();
					}
					pft.push_back(s.front());
					szs+=s.front().second;
					s.pop_front();
					s.insert_front(pfs);
					t.insert_front(pft);
					ans.push_back({szs, szt});
				}
			}
			else{
				if(s.size()>t.size()){
					int x=(s.size()+2-t.size())/2;
					if(x%2==0) x++;
					if(x==s.size()) x-=2;
					compressed_string pfs, pft;
					int szs=0, szt=0;
					for(int i=0; i<x; i++){
						pft.push_back(s.front());
						szs+=s.front().second;
						s.pop_front();
					}
					pfs.push_back(t.front());
					szt+=t.front().second;
					t.pop_front();
					s.insert_front(pfs);
					t.insert_front(pft);
					ans.push_back({szs, szt});
				}
				else{
					int x=(t.size()+2-s.size())/2;
					if(x%2==0) x++;
					if(x==t.size()) x-=2;
					compressed_string pfs, pft;
					int szs=0, szt=0;
					for(int i=0; i<x; i++){
						pfs.push_back(t.front());
						szt+=t.front().second;
						t.pop_front();
					}
					pft.push_back(s.front());
					szs+=s.front().second;
					s.pop_front();
					s.insert_front(pfs);
					t.insert_front(pft);
					ans.push_back({szs, szt});
				}
			}
		}
	}
	// cerr<<"OK\n";
	// cerr<<ans.size()<<"\n";
	// cerr<<s.size()<<' '<<t.size()<<' '<<'\n';
	if(s.size()+t.size()==3){
		if(s.size()==3){
			ans.push_back({s[0].second+s[1].second, 0});
			ans.push_back({0, s[0].second});
		}
		else if(s.size()==2){
			if(s.front().first!=t.front().first){
				ans.push_back({s[0].second, t[0].second});
			}
			else{
				ans.push_back({s[0].second, 0});
			}
		}
		else if(s.size()==1){
			if(s.front().first!=t.front().first){
				ans.push_back({s[0].second, t[0].second});
			}
			else{
				ans.push_back({0, t[0].second});
			}
		}
		else{
			ans.push_back({0, t[0].second+t[1].second});
			ans.push_back({t[0].second, 0});
		}
	}
	if(s.empty())	ans.push_back({0, t[0].second});
	else if(t.empty()) ans.push_back({s[0].second, 0});
	cout<<ans.size()<<'\n';
	for(auto x: ans) cout<<x.first<<' '<<x.second<<'\n';
}