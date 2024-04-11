#include<cstdio>
#include<set>
#include<string>
#include<iostream>
using namespace std;
int n,m,x,y,i,j;
set<int> S[222][222];
string L[222],R[222],s[222];
int main(){
	//freopen("t.in","r",stdin);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		cin>>s[i];
		L[i]=R[i]=s[i];
		for (j=0;j<(int)s[i].size();++j){
			int t=0;
			for (int k=j;k<(int)s[i].size();++k){
				if (k-j+1>=30) break;
				int l=k-j+1;
				if (s[i][k]=='1') t|=(1<<(l-1));
				S[i][l].insert(t);
			}
		}
	}
	scanf("%d",&m);
	for(i=n+1;i<=n+m;++i){
		scanf("%d%d",&x,&y);
		L[i]=R[i]="";
		if (L[x].size()<30){
			string tmp=L[x]+L[y];
			for(j=0;j<30 && j<(int)tmp.size();++j)L[i]+=tmp[j];
		}else L[i]=L[x];
		if (R[y].size()<30){
			string tmp=R[x]+R[y];
			for(j=tmp.size()-1;j>=0 && j>=(int)tmp.size()-30;--j)R[i]=tmp[j]+R[i];
		}else R[i]=R[y];
		string tmp=R[x]+L[y];
		for(j=1;j<=30;++j){
			S[i][j]=S[y][j];
			for (set<int>::iterator it=S[x][j].begin();it!=S[x][j].end();++it)
				S[i][j].insert(*it);
		}
		for (int j=0;j<(int)tmp.size();++j){
			int t=0;
			for (int k=j;k<(int)tmp.size();++k){
				if (k-j+1>=30) break;
				int l=k-j+1;
				if (tmp[k]=='1') t|=(1<<(l-1));
				S[i][l].insert(t);
			}
		}
		int ans=0;
		for(int j=1;j<=30;++j)
			if ((int)S[i][j].size()==(1<<j)) ans=j;
		printf("%d\n",ans);
	}
	return 0;
}