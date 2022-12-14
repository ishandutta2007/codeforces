#include<bits/stdc++.h>
using namespace std;

int a[50];

bool choose[50];

vector<pair<int,int>> v[2][25];
int which;

void dfs(int idx,int to,int mask,int val,int cnt){
	if(idx>to){
		v[which][cnt].emplace_back(make_pair(val,mask));
		return;
	}
	dfs(idx+1,to,mask,val,cnt);
	dfs(idx+1,to,mask|1<<(to-idx),val+a[idx],cnt+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	sort(a,a+n+n);
	int sum = 0;
	for(int i=2;i<2*n;i++)
		sum+=a[i];
	choose[0]=true;
	dfs(2,n,0,0,0);
	which=1;
	dfs(n+1,2*n-1,0,0,0);
	for(int i=0;i<=n-1;i++){
		sort(v[0][i].begin(),v[0][i].end());
		sort(v[1][i].begin(),v[1][i].end(),greater<pair<int,int> > () );
	}
	int ans=-1,ans1,ans2;
	for(int i=0;i<=n-1;i++){
		int j=n-1-i;
		int inow=0,jnow=0;
		while(inow<v[0][i].size()&&jnow<v[1][j].size()){
			int cur=(v[0][i][inow].first+v[1][j][jnow].first)*2;
			if(cur>=sum){
				if(ans==-1||cur-sum<ans){
					ans=cur-sum;
					ans1=v[0][i][inow].second;
					ans2=v[1][j][jnow].second;
				}
				jnow++;
			}
			else
				inow++;
		}
	}
	for(int i=0;i<n-1;i++)
		if(ans1&(1<<i))
			choose[n-i]=true;
	for(int i=0;i<n-1;i++)
		if(ans2&(1<<i))
			choose[2*n-1-i]=true;
	for(int i=0;i<2*n;i++)
		if(choose[i])
			cout<<a[i]<<' ';
	cout<<endl;
	for(int i=2*n-1;i>=0;i--)
		if(!choose[i])
			cout<<a[i]<<' ';
	cout<<endl;
}