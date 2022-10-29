#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 106;

int ans[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];
string mp[MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		mp[0].resize(n+2);
		for (int i=1;n>=i;i++) {
			string s;
			cin >> s;
			mp[i] = " "+s+" ";
		}
		mp[n+1].resize(n+2);
		if (n==1) {
			cout<<"YES"<<endl;
			cout<<"o"<<endl;
			continue;
		}
		memset(ans,0,sizeof(ans));
		memset(used,0,sizeof(used));
		for (int dx=-(n-1);(n-1)>=dx;dx++) {
			for (int dy=-(n-1);(n-1)>=dy;dy++) {
				//now we have vector = (dx,dy)
				bool can=true;
				int cnt=0;
				for (int i=1;n>=i;i++) {
					for (int j=1;n>=j;j++) {
						if (mp[i][j] == 'o') {
							if (1<=i-dy && i-dy<=n && 1<=j+dx && j+dx<=n) {
								if (mp[i-dy][j+dx] == '.') {
									can=false;
								}
								else {
									cnt++;
								}
							}
						}
					}
				}
//				cout<<"dx = "<<dx<<" , dy = "<<dy<<" , can = "<<can<<endl;
				if (can) {
//					cout<<"dx = "<<dy<<" , dy = "<<dx<<" , can!!!"<<endl;
					ans[dy+(n-1)][dx+(n-1)]=1;
					for (int j=1;n>=j;j++) {
						for (int i=1;n>=i;i++) {
							if (mp[i][j] == 'o') {
								if (1<=i-dy && i-dy<=n && 1<=j+dx && j+dx<=n) {
									used[i-dy][j+dx]=1;
								}
							}
						}
					}
				}
			}
		}
		bool can=true;
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (mp[i][j] =='x' && used[i][j] == false) {
					can=false;
				}
			}
		}
		if (!can) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			for (int i=2*n-2;i>=0;i--) {
				for (int j=0;2*n-2>=j;j++) {
//					cout<<"now we are looking at vertex ("<<(j-(n-1))<<","<<(i-(n-1))<<")"<<endl;
//					cout<<"j = "<<j<<" , i = "<<i<<" ans = "<<ans[j][i]<<endl;
					if (i==n-1 && j==n-1) cout<<'o';
					else if (ans[i][j]) cout<<'x';
					else cout<<'.';
				}
				cout<<endl;
			}
		}
	}
}