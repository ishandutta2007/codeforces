#include<iostream>
using namespace std;

int par[52];

void init(int n){ for(int i=1;i<=n;i++)par[i]=i; }
int find(int x){ if(x==par[x])return x; return par[x]=find(par[x]); }
bool same(int x,int y){ return find(x)==find(y); }
void unit(int x,int y){ if(same(x,y))return; x=find(x); y=find(y); par[x]=y; }

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	int cnt=0;
	init(n);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);

		if(!same(x,y)){
			unit(x,y);
			cnt++;
		}
	}

	long long ret=1;
	for(int i=0;i<cnt;i++){
		ret*=2;
	}

	printf("%I64d\n",ret);
}