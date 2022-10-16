#include <bits/stdc++.h>
using namespace std;
int n, m;
const long long base=1000000007;
class matrix{
public:
	long long x[2][2];
	friend matrix operator* (matrix A, matrix B){
		matrix res;
		res.x[0][0]=(A.x[0][0]*B.x[0][0]+A.x[0][1]*B.x[1][0])%base;
		res.x[0][1]=(A.x[0][0]*B.x[0][1]+A.x[0][1]*B.x[1][1])%base;
		res.x[1][0]=(A.x[1][0]*B.x[0][0]+A.x[1][1]*B.x[1][0])%base;
		res.x[1][1]=(A.x[1][0]*B.x[0][1]+A.x[1][1]*B.x[1][1])%base;
		return res;
	}
	friend matrix operator+ (matrix A, matrix B){
		matrix res;
		res.x[0][0]=(A.x[0][0]+B.x[0][0])%base;
		res.x[0][1]=(A.x[0][1]+B.x[0][1])%base;
		res.x[1][0]=(A.x[1][0]+B.x[1][0])%base;
		res.x[1][1]=(A.x[1][1]+B.x[1][1])%base;
		return res;
	}
	void empty(){
		x[0][0]=x[0][1]=x[1][0]=x[1][1]=0;
	}
	void unit(){
		x[0][0]=x[1][1]=1;
		x[0][1]=x[1][0]=0;
	}
	void start(){
		x[0][0]=0;
		x[0][1]=1;
		x[1][0]=x[1][1]=0;
	}
	void core(){
		x[0][0]=0;
		x[1][0]=x[0][1]=x[1][1]=1;
	}
	void output(){
		cerr<<x[0][0]<<' '<<x[0][1]<<'\n'<<x[1][0]<<' '<<x[1][1]<<'\n'<<'\n';
	}
};
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	matrix a, lazy;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		lazy.unit();
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			a=left->a+right->a;
		}
		else{
			a.start();
		}
		// cerr<<l<<' '<<r<<' '<<a.x[0][0]<<'\n';
	}
	void down(){
		left->a=left->a*lazy;
		left->lazy=left->lazy*lazy;
		right->a=right->a*lazy;
		right->lazy=right->lazy*lazy;
		lazy.unit();
	}
	void update(int u, int v, matrix p){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			a=a*p;
			lazy=lazy*p;
		}
		else{
			down();
			left->update(u, v, p);
			right->update(u, v, p);
			a=left->a+right->a;
		}
	}
	long long get(int u, int v){
		if(l>v||r<u) return 0;
		else if(u<=l&&v>=r) return a.x[0][0];
		else{
			down();
			return (left->get(u, v)+right->get(u, v))%base;
		}
	}
};
segment_tree::pointer tree;
matrix power(matrix a, int k){
	matrix res;
	if(k==0) res.unit();
	else{
		res=a;
		for(int i=__lg(k)-1; i>=0; i--){
			res=res*res;
			if((k>>i)&1) res=res*a;
		}
	}
	return res;
}
matrix core;
int main(){
	cin>>n>>m;
	tree=new segment_tree(1, n);
	core.core();
	for(int i=1, a; i<=n; i++){
		cin>>a;
		// auto res=power(core, a);
		// res.output();
		tree->update(i, i, power(core, a));
	}
	for(int i=1, t, l, r, x; i<=m; i++){
		cin>>t>>l>>r;
		if(t==2){
			cout<<tree->get(l, r)<<'\n';
		}
		else{
			cin>>x;
			tree->update(l, r, power(core, x));
		}
	}
}