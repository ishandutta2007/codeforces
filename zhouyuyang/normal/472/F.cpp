#include<bits/stdc++.h>
#define pa pair<int,int>
using namespace std;
const int N=10005;
int n,a[N],b[N];
vector<pa> qa,qb;
void add(int *a,int i,int j,vector<pa> &q){
	a[i]^=a[j];
	q.push_back(pa(i,j));
}
void work(int *a,vector<pa> &q){
	for (int i=30,j=1,k;i>=0;i--){
		for (k=j;k<=n&&!(a[k]&(1<<i));k++);
		if (k>n) continue;
		if (k^j) add(a,j,k,q),add(a,k,j,q),add(a,j,k,q);
		for (int k=1;k<=n;k++)
			if ((a[k]&(1<<i))&&k!=j) add(a,k,j,q);
		j++;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	work(a,qa); work(b,qb);
	for (int i=1,k;i<=n&&a[i];i++){
		for (k=30;k+1&&!((1<<k)&a[i]);k--);
		for (int j=1;j<=30&&j<=n;j++)
			if ((a[j]^b[j])&(1<<k)) add(a,j,i,qa);
	}
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i])
			return puts("-1"),0;
	printf("%d\n",qa.size()+qb.size());
	for (int i=0;i<qa.size();i++)
		printf("%d %d\n",qa[i].first,qa[i].second);
	for (int i=qb.size()-1;i>=0;i--)
		printf("%d %d\n",qb[i].first,qb[i].second);
}