#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 506;

LL a[MAX_N],b[MAX_N];
pii p[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
		}
		int k;
		scanf("%d",&k);
		for (int i=1;k>=i;i++) {
			scanf("%I64d",&b[i]);
		}
		bool flag=true;
		int j=1;
		for (int i=1;k>=i;i++) {
			LL sum=a[j];
			int l=j;
			LL mx=a[j];
			j++;
			while (sum<b[i] && j<=n) {
				sum += a[j];
				mx = max(mx,a[j]);
				j++;
			}
			if (sum != b[i]) {
				flag=false;
				break;
			}
			int r=j-1;
			p[i] = make_pair(l,r);
			if ((r-l+1)*mx == b[i] && r!=l) {
//				cout<<"i = "<<i<<endl;
				flag=false;
				break;
			}
		}
		if (!flag || j!=n+1) {
			puts("NO");
		}
		else {
			puts("YES");
			for (int i=1;k>=i;i++) {
				int l=p[i].first,r=p[i].second;
				if (l==r) continue;
				LL mx=a[l];
				for (int j=l+1;r>=j;j++) {
					mx = max(mx,a[j]);
				}
				int can=-1;
				int dir=0;
				for (int j=l;r>=j;j++) {
					if (a[j] == mx) {
						int right=j+1;
						int left=j-1;
						if (left>=l && a[left] < a[j]) {
							can=j;
							dir=-1;
							break;
						}
						if (right <= r && a[right] < a[j]) {
							can=j;
							dir=1;
							break;
						}
					}
				}
				if (dir == 1) {
					int nowid = (i-1) + (can-l+1);
					for (int j=can+1;r>=j;j++) {
						printf("%d R\n",nowid);
					}
					for (int j=l;can>j;j++) {
						printf("%d L\n",nowid);
						nowid--;
					}
				}
				else if (dir==-1) {
					int nowid = (i-1) + (can-l+1);
					for (int j=l;can>j;j++) {
						printf("%d L\n",nowid);
						nowid--;
					}
					for (int j=can+1;r>=j;j++) {
						printf("%d R\n",nowid);
					}
				}
			}
		}
	}
}