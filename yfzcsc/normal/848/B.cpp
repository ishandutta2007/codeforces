#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct data{int p,t,bh;}A[maxn],B[maxn];
map<int,queue<int> >st;
int n,w,h,anses[maxn][2],tpa,tpb;
int comp(data& a,data& b){return a.p<b.p;}
int _comp(data& a,data& b){return a.p>b.p;}
int main(){
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1,g,p,t;i<=n;++i){
		scanf("%d%d%d",&g,&p,&t);
		if(g==1)A[++tpa]=data{p,t,i};
		else B[++tpb]=data{p,t,i};
	}
	sort(A+1,A+tpa+1,comp);
	sort(B+1,B+tpb+1,_comp);
	st.clear();
	for(int i=1;i<=tpb;++i)st[B[i].t-B[i].p].push(B[i].bh);
	for(int i=1;i<=tpa;++i){
		if(st[A[i].t-A[i].p].empty())
			anses[A[i].bh][0]=A[i].p,anses[A[i].bh][1]=h;
		else {
//			printf("[ok]");
			int x=st[A[i].t-A[i].p].front();
//			printf("[%d]",x);
			anses[x][0]=A[i].p,anses[x][1]=h;
			st[A[i].t-A[i].p].pop();
			st[A[i].t-A[i].p].push(A[i].bh);
		}
	}
	for(int i=1;i<=tpb;++i){
		
		int x=st[B[i].t-B[i].p].front();
//		printf("[%d]",x);
		st[B[i].t-B[i].p].pop();
		anses[x][0]=w,anses[x][1]=B[i].p;
	}
	for(int i=1;i<=n;++i)printf("%d %d\n",anses[i][0],anses[i][1]);
}