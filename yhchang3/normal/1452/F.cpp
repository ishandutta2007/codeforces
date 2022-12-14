#include<bits/stdc++.h>
using namespace std;

int a[30];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
		cin >> a[i];
	while(q--){
		int op, x;
		long long int y;
		cin >> op >> x >> y;
		if(op == 1){
			a[x] = y;
		}
		else{
			long long int res = 0;
			long long int cnt = 0;
			for(int i=0;i<=x;i++)
				y -= a[i], cnt += a[i] * ((1LL << i) - 1);
			for(int i=x+1;i<n&&y>0;i++)
				if(a[i] * (1LL << (i - x)) <= y){
					y -= a[i] * (1LL << (i - x));
					res += a[i] * ((1LL << (i - x)) - 1);
					cnt += a[i] * ((1LL << i) - (1LL << (i - x)));
				}
				else{
					int z = y / (1LL << (i - x));
					y -= z * (1LL << (i - x));
					res += z * ((1LL << (i - x)) - 1);
					cnt += z * ((1LL << i) - (1LL << (i - x)));
					long long int m = 1e18, cur = 0;
					if(y <= cnt)
						m = y;
					cur ++;
					for(int j=i-1;j>x&&y;j--){
						if(y >= 1 << (j - x)){
							y -= (1 << (j - x));
							cur += (1 << (j - x)) - 1;
							cnt += (1 << j) - (1 << (j - x));
						}
						if(y <= cnt)
							m = min(m, cur + y);
						if(y){
							cur++;
						}
					}
					m = min(m, cur);
					y = 0;
					res += m;
					break;
				}
			if(y > 0) {
				if(y <= cnt)
					cout << res + y << '\n';
				else
					cout << -1 << '\n';
			}
			else
				cout << res << '\n';
		}
	}
}