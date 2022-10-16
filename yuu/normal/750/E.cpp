#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int f[5][5];
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		for(int i=0; i<=4; i++) for(int j=i; j<=4; j++) f[i][j]=1e9*(j!=i);
		if(l==r){
			if(s[l]=='2'){
				f[0][0]=1;
				f[0][1]=0;
			}
			else if(s[l]=='0'){
				f[1][1]=1;
				f[1][2]=0;
			}
			else if(s[l]=='1'){
				f[2][2]=1;
				f[2][3]=0;
			}
			else if(s[l]=='7') f[3][4]=0;
			else if(s[l]=='6') f[3][3]=f[4][4]=1;
		}
		else{
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			for(int i=0; i<=4; i++) for(int j=i; j<=4; j++) f[i][j]=1e9;
			for(int i=0; i<=4; i++) for(int k=i; k<=4; k++) for(int j=k; j<=4; j++) f[i][j]=min(f[i][j], left->f[i][k]+right->f[k][j]);
		}
	}
	void get(int u, int v, int *now){
		if(l>v||r<u) return;
		else if(u<=l&&v>=r){
			int temp[5];
			for(int i=0; i<=4; i++) temp[i]=1e9;
			for(int i=0; i<=4; i++) for(int j=i; j<=4; j++) temp[j]=min(temp[j], now[i]+f[i][j]);		
			for(int i=0; i<=4; i++) now[i]=temp[i];
		}
		else{
			left->get(u, v, now);
			right->get(u, v, now);
		}
	}
};
segment_tree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	cin>>n>>q>>s;
	s='0'+s;
	tree=new segment_tree(1, n);
	{
		int a, b;
		int f[5];
		for(int i=1; i<=q; i++){
			cin>>a>>b;
			for(int j=1; j<=4; j++) f[j]=1e9;
			f[0]=0;
			tree->get(a, b, f);
			if(f[4]!=1e9) cout<<f[4]<<'\n';
			else cout<<-1<<'\n';
		}
	}
}