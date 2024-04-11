/*
 * D. Wormhouse.cpp
 *
 *  Created on: 2011-2-26
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

const int MAX_N=100+10;
const int MAX_M=3000;

int ord[MAX_M];

struct Edge{
	int src,dst;
	Edge(int _src,int _dst):
		src(_src),dst(_dst){}
	Edge(){}
};

Edge edges[MAX_M];

struct Graph{
	int n;
	int edge[MAX_N][MAX_N];
	Graph(int _n){
		n=_n;
		memset(edge,0,sizeof edge);
	}
	void addEdge(const Edge&e){
		edge[e.src][e.dst]=1;
		edge[e.dst][e.src]=1;
	}

	void removeEdge(const Edge&e){
		edge[e.src][e.dst]=0;
		edge[e.dst][e.src]=0;
	}

	bool visited[MAX_N];

	int countEdge(int u){
		return count(edge[u],edge[u]+n,1);
	}

	void dfs(int u){
		if(visited[u])
			return;
		visited[u]=true;
		for (int v = 0; v < n; ++v) {
			if(edge[u][v] > 0)
				dfs(v);
		}
	}

	int countCanVisited(int u){
		fill(visited,visited+n,false);
		dfs(u);
		return count(visited,visited+n,true);
	}
};

int n,m;
void inputData(){
	cin>>n>>m;
	for (int i = 0; i <= m; ++i) {
		cin>>ord[i];
		--ord[i];
		if(i >= 1){
			edges[i-1]=Edge(ord[i-1],ord[i]);
		}
	}
}

bool findMinimalEdge(Graph&G,int src,int dst,Edge&result){
	int needToVisited=0;
	for (int i = 0; i < G.n; ++i) {
		if(G.countEdge(i) > 0)
			needToVisited++;
	}
	if(G.countEdge(src) == 1)
		needToVisited--;
	for (int v = dst+1; v < n; ++v) {
		if(G.edge[src][v] > 0){
			Edge e(src,v);
			G.removeEdge(e);
			int cnt=G.countCanVisited(v);
			G.addEdge(e);
			if(cnt==needToVisited){
				result=e;
				return true;
			}
		}
	}

	return false;
}

int main(){
	inputData();
	bool findSol=false;

	Graph graph(n);
	for (int i = m-1; i >= 0; --i) {
		graph.addEdge(edges[i]);
		int src=edges[i].src,dst=edges[i].dst;
		Edge e;
		if(findMinimalEdge(graph,src,dst,e)){
			edges[i]=e;
			graph.removeEdge(e);
			for(++i; i < m; ++i){
				assert(findMinimalEdge(graph,edges[i-1].dst,-1,e));
				edges[i]=e;
				graph.removeEdge(e);
			}
			findSol=true;
			break;
		}
	}

	if(findSol){
		printf("%d ",edges[0].src+1);
		for (int i = 0; i < m; ++i) {
			printf("%d ",edges[i].dst+1);
		}
		printf("\n");
	} else {
		printf("No solution");
	}
}