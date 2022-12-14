#include<bits/stdc++.h>
using namespace std;

int a[100000][3];
int cnt[100001];
vector<int> v[100001];
bool visit[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-2;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			cnt[a[i][j]]++;
			v[a[i][j]].emplace_back(i);
		}
	}
	int head,tail,f1,f2;
	for(head=1;;head++)
		if(cnt[head]==1)
			break;
	for(tail=n;;tail--)
		if(cnt[tail]==1)
			break;
	for(f2=n;;f2--)
		if(cnt[f2]==2)
			break;
	for(f1=1;;f1++)
		if(cnt[f1]==2)
			break;
	for(int i=0;i<n-4;i++){
		cout<<head<<' ';
		int nxt;
		for(int it:v[head])
			if(!visit[it]){
				visit[it]=true;
				for(int j=0;j<3;j++){
					if(--cnt[a[it][j]]==1)
						nxt=a[it][j];
				}
			}
		head=nxt;
	}
	cout<<head<<' ';
	for(int it:v[head])
		if(!visit[it])
			for(int j=0;j<3;j++)
				if(a[it][j]!=f1&&a[it][j]!=f2&&a[it][j]!=head)
					cout<<a[it][j]<<' ';
	if(cnt[f1]==2)
		cout<<f1<<' ';
	else
		cout<<f2<<' ';
	cout<<tail<<endl;
}