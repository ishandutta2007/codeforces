#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,x,y,fi,dif;
int ask(vector<int> a){
	printf("? %d",a.size());
	for (int i=0;i<a.size();i++)
		printf(" %d",a[i]);
	puts("");
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
int work(vector<int> a){
	int l=0,r=a.size()-1;
	while (l!=r){
		vector<int> b;
		int mid=(l+r)/2;
		for (int i=l;i<=mid;i++)
			b.push_back(a[i]);
		int tmp=ask(b);
		if ((tmp==y||tmp==(x^y)))
			r=mid;
		else l=mid+1;
	}
	return a[l];
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for (int i=0;(1<<i)<=n;i++){
		vector<int> a;
		for (int j=1;j<=n;j++)
			if (j&(1<<i)) a.push_back(j);
		int jb=ask(a);
		if ((jb==y)||(jb==(x^y))){
			if (!fi) fi=i;
			dif|=(1<<i);
		}
	}
	vector<int> a,b;
	for (int i=1;i<=n;i++)
		if (i&(1<<fi)) a.push_back(i);
		else b.push_back(i);
	if (a.size()>b.size()) swap(a,b);
	int ans1=work(a),ans2=ans1^dif;
	if (ans1>ans2) swap(ans1,ans2);
	printf("! %d %d",ans1,ans2);
}