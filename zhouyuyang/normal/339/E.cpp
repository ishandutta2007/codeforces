#include<bits/stdc++.h>
using namespace std;
int d[5][2],a[1005],n;
void work(int dep){
	int fl=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=i) fl=1;
	if (!fl){
		printf("%d\n",dep-1);
		for (int i=dep-1;i>=1;i--)
			printf("%d %d\n",d[i][0],d[i][1]);
		exit(0);
	}
	if (dep==4) return;
	vector<int> ok;
	for (int i=1;i<=n;i++)
		if (a[i]!=i&&(abs(a[i-1]-a[i])!=1||abs(a[i+1]-a[i])!=1))
			ok.push_back(i);
	for (int i=0;i<ok.size();i++)
		for (int j=i+1;j<ok.size();j++){
			d[dep][0]=ok[i];
			d[dep][1]=ok[j];
			reverse(a+ok[i],a+ok[j]+1);
			work(dep+1);
			reverse(a+ok[i],a+ok[j]+1);
		}
}
int main(){
	scanf("%d",&n); a[0]=a[n+1]=-1e9;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	work(1);
}