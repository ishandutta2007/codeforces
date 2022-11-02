#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> d[maxn];

void init(){
	for(int i = 1;i < maxn;i++){
		for(int j = i;j < maxn;j += i){
			d[j].push_back(i);
		}
	}
}
int q;

int root[maxn];
int ch[maxn * 400][2];
int N = 0;
int val[maxn * 400];
void insert(int num,int d){
	int NUM = num;
	int temp[20];
	for(int i = 0;i < 20;i++){
		temp[i] = num % 2;
		num /= 2;
	}
	int u = root[d];
	val[u] = min(val[u],NUM);
	for(int i = 19;i >= 0;i--){
		if(ch[u][temp[i]] == 0){
			memset(ch[N],0,sizeof(ch[N]));
			val[N] = NUM;
			ch[u][temp[i]] = N++;
			u = ch[u][temp[i]];
		}else{
			u = ch[u][temp[i]];
			val[u] = min(val[u],NUM);
		}
	}
}

int dfs(int root,int bound,int v){
	int u = root;
	if(val[u] > bound) return -1;
	int now = 0;
	int temp[20];
	for(int i = 0;i < 20;i++){
		temp[i] = v % 2;
		v /= 2;
	}
	for(int i = 19;i >= 0;i--){
		int to;
		to = ch[u][temp[i] ^ 1];
		if(to && val[to] <= bound){
			now = now * 2 + temp[i] ^ 1;
			u = ch[u][temp[i] ^ 1];
		}else{
			to = ch[u][temp[i]];
			if(to && val[to] <= bound){
				now = now * 2 + temp[i];
				u = to;
			}else{
				return -1;
			}
		}
	}
	return now;
}

int main(){
	init();
	cin >> q;
	for(int i = 1;i <= 100000;i++){
		root[i] = i;
	}
	N = 100000;
	for(int i = 1;i <= q;i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int u;
			scanf("%d",&u);
			for(auto x : d[u]){
				insert(u,x);
			}
		}else{
			int x,k,s;
			scanf("%d%d%d",&x,&k,&s);
			if(x % k){
				printf("-1\n");
				continue;
			}
			printf("%d\n",dfs(root[k],s - x,x));
		}
	}	
	return 0;
}