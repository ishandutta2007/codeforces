#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool solve(string &ans, const string& num,int rest,vector<int>&used){
	if(rest==0){
		return all_of(used.begin(),used.end(),[](const int a){return a==0;
		});
	}
	if(num==""){
		if(rest>=count(used.begin(),used.end(),true)){
			int k=1;
			for(int i=0;i<10;++i){
				if(used[i]){
					ans[ans.size()-k]='0'+i;
					k++;
				}
			}
			for(;k<=rest;++k){
				ans[ans.size()-k]='9';
			}
			return true;
		}else{
			return false;
		}
	}else{
		char ch(num[num.size()-rest]);
		int t(ch-'0');

		used[t]=!used[t];
		
		bool ok=solve(ans,num,rest-1,used);
		
		used[t]=!used[t];

		if(ok){
			ans[num.size()-rest]='0'+t;
			return true;
		}else{
			if(t!=0){
				string mi;

				for(int tt=t-1;tt>=0;--tt){

					used[tt]=!used[tt];
					bool aok=solve(ans,mi,rest-1,used);
					used[tt]=!used[tt];
				

					if(aok){
						ans[num.size()-rest]='0'+tt;
						return true;
					}
				}
			}
			return false;
		}
	}


}

string minus_one(string a){
	if(a[0]=='1'&&all_of(a.begin()+1,a.end(),[](char ch){return ch=='0';})){
		return string(a.size()-1,'9');
	}else{
		for(int i=a.size()-1;i>=0;--i){
			if(a[i]=='0'){
				a[i]='9';

			}else{
				a[i]--;
				break;
			}
		}
		return a;
	}
}
int main() { 
	int Q;cin>>Q;
	while(Q--){
		string st;cin>>st;
		st=minus_one(st);
		int keta=st.size();
		keta=keta/2*2;
		vector<int>used(10);
		
		string ans(keta,'f');
		if(keta!=st.size()){
			ans=string(st.size()-1,'9');
		}else if(st[0]=='1'&&all_of(st.begin()+1,st.end(),[](const char& ch ){return ch=='0';})){
			ans=string(st.size()-2,'9');
		}else{

			solve(ans,st,keta,used);
		}
		cout<<ans<<endl;
	}
	return 0;

}