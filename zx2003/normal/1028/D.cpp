#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int n,p,ans=1;
string o;
set<int>s1,s2,s3;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(;n--;){
		cin>>o>>p;
		if(o=="ADD"){
			if(!s1.empty() && *s1.rbegin()>=p)s1.insert(p);
				else if(!s3.empty() && *s3.begin()<=p)s3.insert(p);
						else s2.insert(p);
		}else{
			if(s2.count(p)){
				ans=2ll*ans%mo;
			}else if(!s1.empty() && *s1.rbegin()==p){
				s1.erase(--s1.end());
			}else if(!s3.empty() && *s3.begin()==p){
				s3.erase(s3.begin());
			}else{ans=0;break;}
			for(int x:s2)if(x<p)s1.insert(x);else if(x>p)s3.insert(x);
			s2.clear();
		}
	}
	ans=1ll*ans*(s2.size()+1)%mo;
	cout<<ans<<endl;
}