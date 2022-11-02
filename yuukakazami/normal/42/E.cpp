/*
 * E. Baldman and the military_Other.cpp
 *
 *  Created on: 2011-1-15
 *      Author: wjmzbmr
 *
 * An interesting method to solve path max querying
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin() ;e!=x.end();e++)
using namespace std;
//#define DEBUG
#ifdef DEBUG
	#define LLFMT "%lld"
#else
	#define LLFMT "%I64d"
#endif
struct Edge{
	int s,t,c;
	void input(){
		scanf("%d%d%d",&s,&t,&c);
		--s;--t;
	}
	bool operator<(const Edge&e)const{
		return c<e.c;
	}
};

const int MAX_VERTEX=100000+100;
const int MAX_EDGE=200000+100;

Edge edges[MAX_EDGE];
struct UF{
	int rank[MAX_VERTEX];
	int father[MAX_VERTEX];

	void makeUse(int n){
		for(int i=0;i<n;i++){
			father[i]=i;
			rank[i]=0;
		}
	}

	int find(int x){
		if(x==father[x])
			return x;
		return father[x]=find(father[x]);
	}

	int unite(int a,int b){
		a=find(a);b=find(b);
		if(rank[a]<rank[b]){
			father[a]=b;
		} else {
			father[b]=a;
		}
		if(rank[a]==rank[b])
			rank[a]++;
		return find(a);
	}

	bool link(int a,int b){
		return find(a)==find(b);
	}
};

int nVets,nEdges;
void inputGraph(){
	scanf("%d%d",&nVets,&nEdges);
	for(int i=0;i<nEdges;i++){
		edges[i].input();
	}
}

typedef long long int64;

int treeCnt;
int64 treeCost;
UF U;

bool inMST[MAX_EDGE];
void calcMST(){
	U.makeUse(nVets);
	sort(edges,edges+nEdges);

	treeCnt=nVets;treeCost=0;
	for(int edgeId=0;edgeId<nEdges;edgeId++){
		Edge&e=edges[edgeId];
		if(!U.link(e.s,e.t)){
			U.unite(e.s,e.t);
			treeCnt--;
			treeCost+=e.c;
			inMST[edgeId]=true;
		} else {
			inMST[edgeId]=false;
		}
	}
}

const int MAX_QUERYS=100000+100;
int maxEdge[MAX_QUERYS];
struct Query{
	int a,b;
};
Query querys[MAX_QUERYS];

struct Node{
	Node*l,*r;
	int id;
	int len;
	vector<int> qs;

	Node(Node*_l,Node*_r,int _id,int _len):
		l(_l),r(_r),id(_id),len(_len){}

	int dfs();
};
Node* nodes[MAX_VERTEX];
Node* root[MAX_VERTEX];
int Node::dfs(){
	if(id!=-1){
		foreach(qIt,qs){
			int qId=*qIt;
			int other=querys[qId].a+querys[qId].b-id;
			if(root[U.find(other)]!=0){
				maxEdge[qId]=root[U.find(other)]->len;
			}
		}
		return id;
	}
	int x=l->dfs();
	root[U.find(x)]=this;
	return U.unite(x,r->dfs());
}
int nQuerys;
void solve(){
	calcMST();
	scanf("%d",&nQuerys);
	if(treeCnt>2){
		for(int i=0;i<nQuerys;i++)
			puts("-1");
		return;
	} else if(treeCnt==2){
		for(int i=0;i<nQuerys;i++){
			int a,b;scanf("%d%d",&a,&b);
			--a;--b;
			if(U.link(a,b))
				puts("-1");
			else
				printf(LLFMT"\n",treeCost);
		}
	} else {
		U.makeUse(nVets);
		for(int i=0;i<nVets;i++){
			nodes[i]=new Node(0,0,i,-1);
		}
		memset(maxEdge,-1,sizeof(int)*nQuerys);
		for(int i=0;i<nQuerys;i++){
			Query&query=querys[i];
			scanf("%d%d",&query.a,&query.b);
			query.a--;query.b--;
			nodes[query.a]->qs.push_back(i);
			nodes[query.b]->qs.push_back(i);
		}
		for(int eId=0;eId<nEdges;eId++)
			if(inMST[eId]){
				Edge&e=edges[eId];
				Node*t=new Node(nodes[U.find(e.s)],nodes[U.find(e.t)],-1,e.c);
				nodes[U.unite(e.s,e.t)]=t;
			}
		memset(root,0,sizeof(Node*)*nVets);
		int vs=U.find(0);
		U.makeUse(nVets);
		nodes[vs]->dfs();
		for(int i=0;i<nQuerys;i++){
			printf(LLFMT"\n",treeCost-maxEdge[i]);
		}
	}
}
int main(){
	inputGraph();
	solve();
}