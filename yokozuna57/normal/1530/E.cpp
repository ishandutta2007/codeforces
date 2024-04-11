#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

string s;
int cnt[26];
void solve(){
	for(int i=0;i<26;i++)cnt[i]=0;
	for(char c: s)cnt[c-'a']++;
	int t=0,a[3];
	for(int i=0;i<26;i++){
		if(cnt[i]==1){
			printf("%c",(char)('a'+i)); cnt[i]--;
			int nex=0;
			while(1){
				while(nex<26&&cnt[nex]==0)nex++;
				if(nex==26)break;
				printf("%c",(char)('a'+nex)); cnt[nex]--;
			}
			puts("");
			return;
		}
		if(cnt[i]>0){
			if(t<3)a[t]=i;
			t++;
		}
	}
	if(t==1){
		cout<<s<<endl;
	}
	else if(cnt[a[0]]<=(s.size()-2)/2+2){
		int nex=a[1];
		for(int i=0;i<s.size();i++){
			if((i==0||(i&1))&&cnt[a[0]]>0){
				printf("%c",(char)('a'+a[0]));
				cnt[a[0]]--;
			}
			else {
				while(cnt[nex]==0)nex++;
				printf("%c",(char)('a'+nex));
				cnt[nex]--;
			}
		}
		puts("");
	}
	else {
		if(t>=3){
			if(cnt[a[0]]==1){
				sort(s.begin(),s.end());
				cout<<s<<endl;
			}
			else {
				printf("%c",(char)('a'+a[0])); cnt[a[0]]--;
				printf("%c",(char)('a'+a[1])); cnt[a[1]]--;
				while(cnt[a[0]]>0){ printf("%c",(char)('a'+a[0])); cnt[a[0]]--; }
				printf("%c",(char)('a'+a[2])); cnt[a[2]]--;
				int nex=a[1];
				while(1){
					while(nex<26&&cnt[nex]==0)nex++;
					if(nex==26)break;
					printf("%c",(char)('a'+nex)); cnt[nex]--;
				}
				puts("");
			}
		}
		else {
			printf("%c",(char)('a'+a[0])); cnt[a[0]]--;
			for(int i=0;i<cnt[a[1]];i++)printf("%c",(char)('a'+a[1]));
			while(cnt[a[0]]>0){ printf("%c",(char)('a'+a[0])); cnt[a[0]]--; }
			puts("");
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		cin>>s;
		solve();
	}
}