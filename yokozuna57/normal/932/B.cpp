#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

int f(int x){
	vector<int> vec;
	while(x > 0){
		vec.pb(x%10);
		x /= 10;
	}
	int ret = 1;
	for(int i = 0 ; i < vec.size() ; i ++){
		if(vec[i] != 0)ret *= vec[i];
	}
	return ret;
}
int G[1000010];
int g(int x){
	if(G[x] != -1)return G[x];
	if(x < 10)return G[x] = x;
	return G[x] = g(f(x));
}

int main(){
	for(int i = 0 ; i < 1000010 ; i ++)G[i] = -1;
	for(int i = 1 ; i <= 1000000 ; i ++){
		g(i);
	}
	
	static int cnt[10][1000010] = {};
	for(int i = 1 ; i <= 1000000 ; i ++){
		cnt[G[i]][i] ++;
	}
	for(int i = 1 ; i <= 1000000 ; i ++){
		for(int j = 0 ; j < 10 ; j ++){
			cnt[j][i+1] += cnt[j][i];
		}
	}
	
	int Q;
	scanf("%d",&Q);
	for(int i = 0 ; i < Q ; i ++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",cnt[k][r]-cnt[k][l-1]);
	}
}