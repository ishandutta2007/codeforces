#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n;
int a[200010];

int cnt[200010];
int b[200010];
bool used[200010];
void solve(){
	for(int i=0;i<n;i++){
		cnt[i]=0;
		b[i]=-1;
		used[i]=false;
	}
	for(int i=0;i<n;i++){
		cnt[a[i]]++;
	}
	int ret=0;
	queue<int> X,Y,Z;
	for(int i=0;i<n;i++){
		if(cnt[i]==0){
			if(!used[a[i]]){
				ret++;
				b[i]=a[i];
				used[a[i]]=true;
				Z.push(i);
			}
			else {
				Y.push(i);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(cnt[i]!=0){
			if(!used[a[i]]){
				ret++;
				b[i]=a[i];
				used[a[i]]=true;
			}
			else {
				X.push(i);
			}
		}
	}
	while(!X.empty()){
		int v=X.front(); X.pop();
		if(!Y.empty()){
			int u=Y.front(); Y.pop();
			b[v]=u;
			used[u]=true;
			X.push(u);
		}
		else {
			int u=Z.front(); Z.pop();
			b[v]=u;
			used[u]=true;
		}
	}
	printf("%d\n",ret);
	for(int i=0;i<n;i++){
		printf("%d%c",b[i]+1,(i+1==n)?'\n':' ');
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){ scanf("%d",&a[i]); a[i]--; }
		solve();
	}
}