#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;
vector<int> vec[N];
int n,m,x,y,cnt,fl,a[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		a[i]=i;
	for (int i=1;i<=10000;i++){
		random_shuffle(a+1,a+n+1);
		a[0]=a[n];
		cnt=0;
		for (int j=0;j<n;j++){
			fl=1;
			for (int k=0;k<vec[a[j]].size();k++)
				if (vec[a[j]][k]==a[j+1]) fl=0;
				cnt+=fl;
		}
		if (cnt>=m){
			for (int j=0;j<n;j++){
				fl=1;
				for (int k=0;k<vec[a[j]].size();k++)
					if (vec[a[j]][k]==a[j+1]) fl=0;
				if (fl&&m){
					m--;
					printf("%d %d\n",a[j],a[j+1]);
				}
			}
			return 0;
		}
	}
	puts("-1");
}