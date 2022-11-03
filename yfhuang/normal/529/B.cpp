#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;

struct man{
	int w,h;
}a[1005],c[1005];

bool cmp(man a,man b){
	return a.h + b.w < a.w + b.h;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].w,&a[i].h);
	}
	int ans = 1e9 + 5;
	int w;
	//cout << "!" << endl;
	for(int h = 1000;h > 0;h--){
		w = 0;
		int tot = 0;
		int num = n / 2;
		//cout << h << endl;
		bool flag = true;
		for(int i = 1;i <= n;i++){
			if(a[i].w > h && a[i].h > h) {flag = false;break;}
			else if(a[i].h > h && a[i].w <= h){num--;w += a[i].h;}
			else if(a[i].w > h && a[i].h <= h){w += a[i].w;}
			else{
				if(a[i].h >= a[i].w) w += a[i].w;
				else{
					c[++tot] = a[i];
				}
			}
		}
		//cout << h << endl;
		if(num < 0) flag = false;
		if(!flag) continue;
		if(tot > 0)sort(c + 1,c + tot + 1,cmp);
		for(int i = 1;i <= tot;i++){
			if(num > 0){
				num--;
				w += c[i].h;
			}else{
				w += c[i].w;
			}
		}
		//cout << h << endl;
		ans = min(ans,w * h);
	}
	cout << ans << endl;
	return 0;
}