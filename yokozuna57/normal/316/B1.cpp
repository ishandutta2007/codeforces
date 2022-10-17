#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,x,a[1005],b[1005]={0},f[1005],s;
vector<int> ans[1005];


int front(int y){
	int c=a[y];
	if(c==0)return 1;
	return front(c)+1;
}

int back(int y){
	int c=0;
	for(int i=1;i<=n;i++){
		if(a[i]==y){c=i; break;}
	}
	if(c==0)return front(y);
	return back(c);
}

int main(){
	ans[0].push_back(0);
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s=front(x);
	for(int i=1;i<=n;i++){b[front(i)]++;}
	for(int i=1;i<1001;i++)b[i]-=b[i+1];
	b[back(x)]--;
	for(int i=1;i<1001;i++){
		int as=ans[i-1].size();
		for(int j=1;j<=b[i];j++){
			for(int k=0;k<as;k++){
				ans[i-1].push_back(ans[i-1][k]+j*i);
			}
		}
		sort(ans[i-1].begin(),ans[i-1].end());
		as=ans[i-1].size();
		ans[i].push_back(ans[i-1][0]);
		for(int j=1;j<as;j++){
			if(ans[i-1][j]!=ans[i-1][j-1])ans[i].push_back(ans[i-1][j]);
		}
	}
	int as=ans[1000].size();
	for(int i=0;i<as;i++){
		printf("%d\n",ans[1000][i]+s);
	}
}