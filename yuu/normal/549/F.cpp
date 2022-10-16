#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[300002];
int s[300002];
int t[300002];
int x[300002];
int y[300002];
int f[1000000];
int g[1000000];
int donef[1000000];
int doneg[1000000];
int now;
long long ans=0;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m, b;
	pointer left, right;
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		if(l==r) b=l;
		else{
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			if(a[left->b]>a[right->b]) b=left->b;
			else b=right->b;
		}
	}
	int get(int u, int v){
		if(l>v||r<u) return 0;
		if(u<=l&&v>=r){
			return b; 
		}
		else{
			int bl=left->get(u, v);
			int br=right->get(u, v);
			if(a[bl]>a[br]) return bl;
			else return br;
		}
	}
};
segment_tree::pointer tree;
void solve(int l, int r){
	if(l>=r) return;
	else{
		int m=tree->get(l, r);
		if(m-l>r-m){
			for(int i=m+1; i<=r; i++)	f[x[i]]--;
			for(int i=m; i<=r; i++)	g[y[i]]--;
			for(int i=r; i>=m; i--){
				if(i==m) f[x[m]]--;
				int key=s[i]-s[m]+s[m-1];
				key%=k;
				if(key<0) key+=k;
				if(donef[key]==now)	
					ans+=f[key];
			}
			solve(l, m-1);
			now++;
			for(int i=m+1; i<=r; i++){
				f[x[i]]=0;
				donef[x[i]]=now;
			}
			for(int i=m+1; i<=r; i++) f[x[i]]++;
			for(int i=m+1; i<=r; i++){
				g[y[i]]=0;
				doneg[y[i]]=now;
			}
			for(int i=m+1; i<=r; i++) g[y[i]]++;
			solve(m+1, r);
		}
		else{
			for(int i=m-1; i>=l; i--)	g[y[i]]--;
			for(int i=m; i>=l; i--)	f[x[i]]--;
			for(int i=l; i<=m; i++){
				if(i==m) g[y[m]]--;
				int key=t[i]-t[m]+t[m+1];
				key%=k;
				if(key<0) key+=k;
				if(doneg[key]==now)	
					ans+=g[key];
			}
			solve(m+1, r);
			now++;
			for(int i=m-1; i>=l; i--){
				f[x[i]]=0;
				donef[x[i]]=now;
			}
			for(int i=m-1; i>=l; i--) f[x[i]]++;
			for(int i=m-1; i>=l; i--){
				g[y[i]]=0;
				doneg[y[i]]=now;
			}
			for(int i=m-1; i>=l; i--) g[y[i]]++;
			solve(l, m-1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
		s[i]%=k;
	}
	for(int i=n; i>=1; i--) t[i]=(t[i+1]+a[i])%k;
	for(int i=1; i<=n; i++) x[i]=(s[i-1])%k;
	for(int i=1; i<=n; i++) y[i]=(t[i+1])%k;
	for(int i=1; i<=n; i++) f[x[i]]++;
	for(int i=1; i<=n; i++) g[y[i]]++;
	tree=new segment_tree(1, n);
	solve(1, n);
	cout<<ans<<'\n';
}