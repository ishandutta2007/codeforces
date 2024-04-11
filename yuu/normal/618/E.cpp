#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const double radperdeg=pi/180;
class matrix{
public:
	double a[3][3];
	matrix operator *(matrix A){
		matrix res;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				res.a[i][j]=0;
				for(int k=0; k<3; k++) res.a[i][j]+=a[i][k]*A.a[k][j];
			}
		}
		return res;
	}
	void operator *=(matrix A){
		(*this)=(*this)*A;
	}
	void unit(){
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) a[i][j]=(i==j);
	}
	void clear(){
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) a[i][j]=0;
	}
	void start(int i){
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) a[i][j]=0;
		a[0][0]=i;
		a[0][2]=1;
	}
	void output(){
		for(int i=0; i<3; i++) for(int j=0; j<3; j++) cerr<<a[i][j]<<" \n"[j==2];
	}
};
matrix translate(double x, double y, double l){
	matrix res;
	res.unit();
	double len=sqrt(x*x+y*y);
	if(len<1e-9) return res;
	l/=len;
	x*=l;
	y*=l;
	res.a[2][0]=x;
	res.a[2][1]=y;
	return res;
}
matrix rotate(double angle){//clockwise in degree
	matrix res;
	res.unit();
	angle=-angle+360;//ccw
	angle*=radperdeg;
	double s=sin(angle);
	double c=cos(angle);
	res.a[0][0]=res.a[1][1]=c;
	res.a[0][1]=s;
	res.a[1][0]=-s;
	return res;
}
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	matrix value;
	pointer left, right;
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		if(l!=r){
			value.unit();
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
		else{
			value.start(l);
		}
	}
	void down(){
		if(l!=r){
			left->value*=value;
			right->value*=value;
			value.unit();
		}
	}
	void update(int u, int v, matrix A){
		if(l>v||r<u) return;
		if(u<=l&&v>=r) value*=A;
		else{
			down();
			left->update(u, v, A);
			right->update(u, v, A);
		}
	}
	pair <double, double> get(int u){
		if(l==r){
			return {value.a[0][0], value.a[0][1]};
		}
		else{
			down();
			if(m>=u) return left->get(u);
			return right->get(u);
		}
	}
};
segment_tree::pointer tree;
int n, m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cout.precision(16);
	cout<<fixed;
	tree=new segment_tree(0, n);
	for(int i=1, a, x, p; i<=m; i++){
		cin>>a>>x>>p;
		if(a==1){
			auto first=tree->get(x-1);
			auto second=tree->get(x);
			auto mat=translate(second.first-first.first, second.second-first.second, p);
			// cerr<<"translate:\n";
			// mat.output();
			tree->update(x, n, mat);
		}
		else{
			auto root=tree->get(x-1);
			auto mat=translate(root.first, root.second, -sqrt(root.first*root.first+root.second*root.second));
			mat*=rotate(p);
			mat*=translate(root.first, root.second, sqrt(root.first*root.first+root.second*root.second));
			// cerr<<"rotate:\n";
			// mat.output();
			tree->update(x, n, mat);
		}
		auto res=tree->get(n);
		cout<<res.first<<' '<<res.second<<'\n';
	}
}
/*
translation by vector (a, b):
(x, y) -> (x+a, y+b)
[x, y, 1] * [1, 0, 0
						 0, 1, 0
						 a, b, 1]
rotate by angle theta counter clockwise:
(x, y) -> (x*cos(theta)-y*sin(theta), y*cos(theta)+x*sin(theta))
[x, y, 1] * [ cos,  sin, 0
						 -sin,  cos, 0
						    0,    0, 1]
(x+yi)*(cos+sini)
*/