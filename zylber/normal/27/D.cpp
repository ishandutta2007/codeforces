#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

int edge[128][128];
int cons[128][2];
int color[128];
int secago;
int n, m;

void pintar(int i, int c)
{
	if(color[i]!=-1)
	{
		if(color[i]!=c) secago=1;
		return;
	}
	/* hola */
	color[i]=c;
	for(int j=0; j<m; j++)
	{
		if(edge[i][j]) pintar(j, c^1);
	}
	return;
}

bool inter(int a, int b, int c, int d)
{
	if(a>b)
	{
		swap(a, b);
		swap(c, d);
	}
	
	if(a==b && c<d) swap(c,d);
	
	if(c<=b) return false;
	if(d<=c) return false;
	return true;
		
}

int main()
{
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		for(int a=0; a<2; a++) cin >> cons[i][a];
		if(cons[i][0]>cons[i][1]) swap(cons[i][0], cons[i][1]);
	}
	
	memset(edge,0,sizeof(edge));
	for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
		if(i!=j)
		{
			if(inter(cons[i][0], cons[j][0], cons[i][1], cons[j][1])) edge[i][j]=1;
		}
	
	memset(color,-1,sizeof(color));
	secago=0;
	for(int i=0; i<m; i++)
	{
		if(color[i]==-1) pintar(i, 0);
	}
	
	/*for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
			cout << edge[i][j] << endl;*/
	
	if(secago) cout << "Impossible" << endl; else{
		for(int i=0; i<m; i++) if(color[i]) cout << 'i'; else cout << 'o';
		cout << endl;
	}
}