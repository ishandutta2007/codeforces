#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int we[1005];
int b[1005];

long long f[2][1005];


const int maxn = 1005;
int fa[maxn];
int sum[maxn];
long long be[maxn];

vector<pair<int,long long> > lian[maxn];

int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

bool vis[maxn];

int d[maxn];
int cnt;


int main(){
	int n,m,w;
	cin >> n >> m >> w;
	for(int i = 1;i <= n;i++){
		cin >> we[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> b[i];
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		sum[i] = we[i];
		be[i] = b[i];
	}
	for(int i = 1;i <= m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int fx = Find(x);
		int fy = Find(y);
		if(fx != fy){
			fa[fx] = fy;
			sum[fy] += sum[fx];
			be[fy] += be[fx];
		}
	}
	//cout << "!" << endl;
	cnt = 0;
	memset(vis,false,sizeof(vis));
	for(int i = 1;i <= n;i++){
		int fx = Find(i);
		if(vis[fx]){
			lian[fx].push_back(make_pair(we[i],b[i]));
		}else{
			vis[fx] = true;
			d[++cnt] = fx;
			lian[fx].push_back(make_pair(we[i],b[i]));
			lian[fx].push_back(make_pair(sum[fx],be[fx]));
		}
	}
	//cout << "!" << endl;
	//cout << cnt << endl;
	memset(f,0,sizeof(f));
	for(int i = 1;i <= cnt;i++){
		//cout << d[i] << endl;
		for(int j = 0;j < lian[d[i]].size();j++){
			int wei = lian[d[i]][j].first;
			long long beu = lian[d[i]][j].second;
			//cout << wei << " " << beu << endl;
			for(int mm = wei;mm <= w;mm++){
				f[1][mm] = max(f[1][mm],f[0][mm - wei] + beu);
			}
		}
		swap(f[1],f[0]);
		for(int j = 0;j <= w;j++){
			f[1][j] = f[0][j];
		}
	}
	long long ans = 0;
	for(int i = 0;i <= w;i++){
		ans = max(ans,f[0][i]);
	}
	cout << ans << endl;
	return 0;
}