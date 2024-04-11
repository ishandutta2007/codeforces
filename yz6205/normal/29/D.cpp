#include <bits/stdc++.h>
using namespace std;
#define FORMAP(a,b) for(int a=0;a<(int)b.size();a++)

const int N = 305;
vector < int > pe[N];
vector < int > e[N];
bool hs[N][N];
int fa[N];

void dfs(int root,int pre){
    FORMAP(i,pe[root]){
	int v = pe[root][i];
	if (v != pre){
	    fa[v] = root;
	    e[root].push_back(v);
	    dfs(v,root);
	}
    }
}

int solveLeaf(int n){
    int res = 0;
    for (int i=1;i<=n;i++){
	if (e[i].size() == 0){
	    hs[i][i] = 1;
	    res++;
	}
    }
    return res;
}

void solveHs(int root,int n){
    FORMAP(i,e[root]){
	int v = e[root][i];
	solveHs(v,n);
	for (int j=1;j<=n;j++){
	    hs[root][j] += hs[v][j];
	}
    }
}

vector < int > ans;
int go[N];

void goDown(int root,int to){
    //cout << "goDown: " << root << ' ' << to << endl;
   while (root != to){
	FORMAP(i,e[root]){
	    int v = e[root][i];
	    if (hs[v][to]){
		root = v;
		ans.push_back(root);
		break;
	    }
	}
   }
}

int goUp(int leaf,int to){
    while (!hs[leaf][to]){
	leaf = fa[leaf];
	ans.push_back(leaf);
    }
    return leaf;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++){
	int u,v;
	scanf("%d%d",&u,&v);
	pe[u].push_back(v);
	pe[v].push_back(u);
    }
    dfs(1,0);
    int leaf = solveLeaf(n);
    solveHs(1,n);
    for (int i=1;i<=leaf;i++){
	scanf("%d",&go[i]);
    }
    ans.push_back(1);
    int r = 1;
    for (int i=1;i<leaf;i++){
	goDown(r,go[i]);
	r = goUp(go[i],go[i + 1]);
    }
    goDown(r,go[leaf]);
    int tmp = go[leaf];
    while (tmp != 1){
	tmp = fa[tmp];
	ans.push_back(tmp);
    }
    if ((int)ans.size() == 2 * n - 1){
	FORMAP(i,ans){
	    printf("%d ",ans[i]);
	}
	puts("");
    }else{
	puts("-1");
    }
    return 0;
}