#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

struct IO{
	int n;
	int x[1002],y[1002];
	void read(){
		scanf("%d",&n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
	}
	int query(int u,int v){
		cout<<"? "<<u<<" "<<v<<endl;
		fflush(stdout);
		cin>>u;
		return u;
	}
	int cnt[1002];
	bool used[1002];
	void run(){
		read();
		for(int i=1;i<=n;i++){
			used[i]=false;
		}
		for(int i=0;i<n-1;i++){
			cnt[x[i]]++;
			cnt[y[i]]++;
		}
		while(1){
			int u=-1,v=-1;
			for(int i=1;i<=n;i++){
				if(cnt[i]==1){
					v=i;
					swap(u,v);
				}
			}
			if(v==-1){
				for(int i=1;i<=n;i++){
					if(!used[i]){
						cout<<"! "<<i<<endl;
						fflush(stdout);
						return;
					}
				}
			}
			for(int i=0;i<n-1;i++){
				if(x[i]==u||x[i]==v)cnt[y[i]]--;
				if(y[i]==u||y[i]==v)cnt[x[i]]--;
			}
			cnt[u]=cnt[v]=0;
			used[u]=used[v]=true;
			int r=query(u,v);
			if(r==u||r==v){
				cout<<"! "<<r<<endl;
				fflush(stdout);
				return;
			}
		}
	}
}io;

int main(){
	io.run();
}