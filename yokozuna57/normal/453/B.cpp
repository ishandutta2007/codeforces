#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int P[110]={0};

int n,ans=1000000000;
vector<pair<int,int>> A;
vector<int> B;
vector<int> G[62];
vector<int> bb;
int ret=0;

bool used[62];

void solver(int k,int cnt){
	if(cnt>n)return;
	if(k>60){
		//ret++;
		bb.clear();
		for(int i=1;i<=n-cnt;i++)bb.push_back(1);
		for(int i=2;i<=60;i++){
			if(used[i])bb.push_back(i);
		}
		if(bb.size()>n)return;
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=abs(A[i].first-bb[i]);
		}
		if(sum<ans){
			ans=sum;
			B=bb;
		}
		return;
	}

	solver(k+1,cnt);

	bool d=true;
	for(int i=0;i<G[k].size();i++){
		if(used[G[k][i]]){ d=false; break; }
	}

	if(d){
		used[k]=true;
		solver(k+1,cnt+1);
		used[k]=false;
	}
}

int main(){
	for(int i=1;i<=60;i++){
		for(int j=1;j<i;j++){
			if(gcd(i,j)!=1)G[i].push_back(j);
		}
	}

	int a[110],b[110];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	for(int i=1;i<=n;i++){
		A.push_back(pair<int,int>(a[i],i));
	}

	sort(A.begin(),A.end());

	for(int i=0;i<32;i++)used[i]=false;

	solver(2,0);


	for(int i=0;i<n;i++){
		b[A[i].second]=B[i];
	}

	for(int i=1;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("%d\n",b[n]);

	//printf("%d\n",ret);

}