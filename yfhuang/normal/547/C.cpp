#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 500000 + 5;

int vis[maxn],mu[maxn],prime[maxn];
int cnt;

int n,q;

void init(){
	memset(vis,0,sizeof(vis));
	mu[1] = 1;
	cnt = 0;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0;j < cnt && i * prime[j] < maxn; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else{
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

const int N = 2e5 + 5;

int a[N];
bool used[N];

int num[maxn];

vector<int> divi[N];


int main(){
	cin >> n >> q;
	init();
	for(int i = 1;i <= n;i++) used[i] = false;
	memset(num,0,sizeof(num));
	int x[10];
	int m = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		int tmp = a[i];
		m = 0;
		for(int j = 0;j < cnt && prime[j] * prime[j] <= a[i];j++){
			if(tmp % prime[j] == 0){
				x[m++] = prime[j];
				while(tmp % prime[j] == 0){
					tmp /= prime[j];
				}
			}
		}
		if(tmp > 1) x[m++] = tmp;
		for(int j = 0;j < (1 << m);j++){
			tmp = 1;
			for(int l = 0;l < m;l++){
				if((j >> l) & 1) tmp *= x[l];
			}
			divi[i].push_back(tmp);
			//num[tmp]++;
		}
	}
	long long ans = 0;
	/*for(int i = 1;i <= 500000;i++){
		ans += mu[i] * num[i];
	}*/
	for(int i = 1;i <= q;i++){
		int id;
		scanf("%d",&id);
		if(used[id]){
			used[id] = false;
			for(int j = 0;j < divi[id].size();j++){
				int tmp = divi[id][j];
				num[tmp]--;
			}
			//for(int j = 1;j <= 10;j++){
			//	cout << num[j] << " ";
			//}
			//cout << endl;
			long long now = 0;
			for(int j = 0;j < divi[id].size();j++){
				int tmp = divi[id][j];
				now += mu[tmp] * num[tmp];
			}
			ans -= now;
		}else{
			used[id] = true;
			long long now = 0;
			for(int j = 0;j < divi[id].size();j++){
				int tmp = divi[id][j];
				now += mu[tmp] * num[tmp];
			}
			ans += now;
			for(int j = 0;j < divi[id].size();j++){
				int tmp = divi[id][j];
				num[tmp]++;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}