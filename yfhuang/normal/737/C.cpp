#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n,s;

const int maxn = 2e5 + 5;

bool vis[maxn];
int a[maxn];

int main(){
	cin >> n >> s;
	int n0 = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
		if(a[i] == 0) n0++;
	}
	if(n0 == n){
		printf("%d\n",n - 1);
	}else{
		int dd = 0;
		if(a[s] != 0) a[s] = 0,dd = 1,n0++;
		if(n0 == n){
			printf("%d\n",n - 1 + dd);
		}
		else{
			memset(vis,false,sizeof(vis));
			sort(a + 1,a + 1 + n);
			vis[0] = 1;
			int m = 1;
			int p1 = 0;
			//int num = n0 - 1;
			for(int i = 1;i <= n;i++){
				if(a[i] != 0){
					p1 = i;
					break;
				}
			}
			int ans = n - 1;
			for(int i = p1;i <= n;i++){
				if(!vis[a[i]]){vis[a[i]] = true;m++;}
				int n2 = (a[i] + 1 - m - (n - i) - (i - m));
				//cout << a[i] + 1 - m << " " << n - i << " " << (i - m) << endl;
				//cout << a[i] << endl;
				//cout << max(a[i] + 1 - m,n - i) << " " << i << endl;
				if(n2 > 0) continue;
				
				else ans = min(ans,max(a[i] + 1 - m,n0 - 1 + n - i));
			}
			cout << ans + dd << endl;
		}
	}
	return 0;
}