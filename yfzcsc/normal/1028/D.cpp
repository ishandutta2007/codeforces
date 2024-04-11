#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
set<int>stmx,stmn,stt;
int ans=1,n,flg=1;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
char s[1000];
int main(){
	scanf("%d",&n);
	for(int i=1,d;i<=n;++i){
		scanf("%s%d",s,&d);
		if(s[1]=='C'){
			if(stmx.count(d)){
				if(d!=*stmx.rbegin())return puts("0"),0;
				else stmx.erase(d);
				
				for(auto c:stt)if(c<d)stmx.insert(c);
				for(auto c:stt)if(c>d)stmn.insert(c);
				stt.clear();
			} else if(stmn.count(d)){
				if(d!=*stmn.begin())return puts("0"),0;
				else stmn.erase(d);
				
				for(auto c:stt)if(c<d)stmx.insert(c);
				for(auto c:stt)if(c>d)stmn.insert(c);
				stt.clear();
			} else if(stt.count(d)){ 
				for(auto c:stt)if(c<d)stmx.insert(c);
				for(auto c:stt)if(c>d)stmn.insert(c);
				int cnt=2;
				if(stmx.size()&&*stmx.rbegin()>d)cnt--;
				if(stmn.size()&&*stmn.begin()<d)cnt--;
				stt.clear();
				ans=1ll*ans*cnt%mod;
			} else return puts("0"),0;
		} else if(s[1]=='D'){
			if(stmx.size()&&d<*stmx.rbegin())stmx.insert(d);
			else if(stmn.size()&&d>*stmn.begin())stmn.insert(d); 
			else stt.insert(d);
		}
	}
	printf("%d",1ll*(stt.size()+1)*ans%mod);
}