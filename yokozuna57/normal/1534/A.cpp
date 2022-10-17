#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n,m;
char c[52][52];

void solve(){
	for(int t=0;t<2;t++){
		bool ok=true;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(c[i][j]=='R'&&(i+j)%2==t)ok=false;
			if(c[i][j]=='W'&&(i+j)%2==1-t)ok=false;
		}
		if(ok){
			puts("YES");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if((i+j)%2==t)printf("W");
					else printf("R");
				}
				puts("");
			}
			return;
		}
	}
	puts("NO");
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("\n");
			for(int j=0;j<m;j++)scanf("%c",&c[i][j]);
		}
		solve();
	}
}