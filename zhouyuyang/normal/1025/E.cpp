#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y,id;
}S[55],T[55];
int tar[55],a[55],n,m;
vector<pair<P,P> > SS,MM,TT;
bool cmp(P a,P b){
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
void move(P &S,P T,vector<pair<P,P> > &res){
	for (;S.x<T.x;){
		P U=S; S.x++;
		res.push_back(make_pair(U,S));
	}
	for (;S.x>T.x;){
		P U=S; S.x--;
		res.push_back(make_pair(U,S));
	}
	
	for (;S.y<T.y;){
		P U=S; S.y++;
		res.push_back(make_pair(U,S));
	}
	for (;S.y>T.y;){
		P U=S; S.y--;
		res.push_back(make_pair(U,S));
	}
}
void solve(P *S,vector<pair<P,P> > &res){
	sort(S+1,S+m+1,cmp);
	for (int i=1,j;i<=m;i=j+1){
		for (j=i;j<m&&S[j+1].x==S[i].x;j++);
		for (;;){
			int fl=0;
			for (int p=i;p<=j;p++){
				for (;p<S[p].y&&(p==i||S[p-1].y!=S[p].y-1);)
					move(S[p],(P){S[p].x,S[p].y-1,S[i].id},res),fl=1;
				for (;p>S[p].y&&(p==j||S[p+1].y!=S[p].y+1);)
					move(S[p],(P){S[p].x,S[p].y+1,S[i].id},res),fl=1;
			}
			if (!fl) break;
		}
	}
	for (int i=1;i<=m;i++)
		move(S[i],(P){i,i,S[i].id},res);
}
void Swap(int j,vector<pair<P,P> > &res){
	swap(a[j],a[j-1]);
	res.push_back(make_pair((P){j-1,j-1,0},(P){j-1,j,0}));
	res.push_back(make_pair((P){j,j,0},(P){j,j-1,0}));
	res.push_back(make_pair((P){j-1,j,0},(P){j,j,0}));
	res.push_back(make_pair((P){j,j-1,0},(P){j-1,j-1,0}));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&S[i].x,&S[i].y),S[i].id=i;
	for (int i=1;i<=m;i++)
		scanf("%d%d",&T[i].x,&T[i].y),T[i].id=i;
	solve(S,SS); solve(T,TT);
	for (int i=1;i<=m;i++) tar[T[i].id]=T[i].x;
	for (int i=1;i<=m;i++) a[S[i].x]=tar[S[i].id];
	for (int i=1;i<=m;i++)
		for (int j=i;j>1;j--){
			if (a[j]>a[j-1]) break;
			Swap(j,MM);
		}
	printf("%d\n",SS.size()+TT.size()+MM.size());
	for (int i=0;i<SS.size();i++)
		printf("%d %d %d %d\n",SS[i].first.x,SS[i].first.y,SS[i].second.x,SS[i].second.y);
	for (int i=0;i<MM.size();i++)
		printf("%d %d %d %d\n",MM[i].first.x,MM[i].first.y,MM[i].second.x,MM[i].second.y);
	for (int i=TT.size()-1;i>=0;i--)
		printf("%d %d %d %d\n",TT[i].second.x,TT[i].second.y,TT[i].first.x,TT[i].first.y);
}