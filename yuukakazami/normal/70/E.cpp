/*
 * E. Information Reform.cpp
 *
 *  Created on: 2011-5-16
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N_VERTEXS = 180 + 10;

struct Vertex;
Vertex*vertices;
int dist[MAX_N_VERTEXS][MAX_N_VERTEXS];
int nVertices, buildCost;
int linkCost[MAX_N_VERTEXS];

struct Vertex {
	vector<Vertex*> adj;
	int best[MAX_N_VERTEXS];
	int center;
	void solve(Vertex*fa) {
		center = 0;
		foreach(iter,adj) {
			Vertex*v = *iter;
			if (v == fa)
				continue;
			v->solve(this);
		}
		int me = this - vertices;
		for (int c = 0; c < nVertices; ++c) {
			best[c] = linkCost[dist[me][c]];
			foreach(iter,adj) {
				Vertex*v = *iter;
				if (v == fa)
					continue;
				best[c] += min(v->best[c], v->best[v->center] + buildCost);
			}
			if (best[c] < best[center])
				center = c;
		}
	}

	void build(Vertex*fa) {
		foreach(iter,adj) {
			Vertex*v = *iter;
			if (v == fa)
				continue;
			if (v->best[v->center] + buildCost > v->best[center])
				v->center = center;
			v->build(this);
		}
	}
};

void readInput() {
	scanf("%d%d", &nVertices, &buildCost);
	linkCost[0] = 0;
	vertices = new Vertex[nVertices];
	for (int i = 1; i < nVertices; ++i) {
		scanf("%d", linkCost + i);
	}
	for (int i = 0; i < nVertices; ++i) {
		for (int j = 0; j < nVertices; ++j) {
			dist[i][j] = (i == j ? 0 : INT_MAX / 3);
		}
	}
	for (int i = 0; i < nVertices - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		vertices[--a].adj.push_back(vertices + --b);
		vertices[b].adj.push_back(vertices + a);
		dist[a][b] = dist[b][a] = 1;
	}
}

void work() {
	for (int k = 0; k < nVertices; ++k) {
		for (int i = 0; i < nVertices; ++i) {
			for (int j = 0; j < nVertices; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	Vertex*root = vertices + 0;
	root->solve(0);

	cout << root->best[root->center] + buildCost << endl;
	root->build(0);
	for (int i = 0; i < nVertices; ++i) {
		printf("%d ", vertices[i].center + 1);
	}
	printf("\n");
}

int main() {
	readInput();
	work();
}