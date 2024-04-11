#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second
template <int N = 100010>
struct UF{
	int par[N],r[N];
	UF(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	void init(){
		for(int i = 0 ; i < N ; i ++){
			par[i] = i;
			r[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(x<y){
			par[y]=x;
		}
		else {
			par[x]=y;
		}
		/*if(r[x] < r[y]){
			par[x] = y;
		}
		else {
			par[y] = x;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}*/
	}
};

UF<400010> uf;

int n;
int a[200010],b[200010];
int c[200010];
int cnt[200010][2];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<b[i])c[i]=0;
		else {
			swap(a[i],b[i]);
			c[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]<=n||n<a[i]){
			puts("-1");
			return 0;
		}
	}
	vector<pair<pair<int,int>,int>> vec;
	for(int i=0;i<n;i++){
		vec.push_back(mp(mp(a[i],b[i]),i));
	}
	sort(vec.begin(),vec.end());
	deque<pair<int,int>> deq;
	int MAX=1000000;
	for(auto p: vec){
		if(p.fr.sc>MAX){
			puts("-1");
			return 0;
		}
		if(deq.size()==0||deq.back().fr>p.fr.sc){
			deq.push_back(mp(p.fr.sc,p.sc));
		}
		else {
			while(deq.size()>0&&deq.front().fr>p.fr.sc){
				deq.pop_front();
			}
			while(deq.size()>0){
				int i=deq.front().sc;
				int j=p.sc;
				uf.unit(2*i,2*j+1);
				uf.unit(2*j,2*i+1);
				if(deq.size()>1)deq.pop_front();
				else break;
			}
			MAX=min(MAX,p.fr.sc);
		}
	}
	for(int i=0;i<n;i++){
		if(uf.same(2*i,2*i+1)){
			puts("-1");
			return 0;
		}
	}
	int ret=0;
	for(int i=0;i<n;i++){
		int j=uf.find(2*i);
		int fl=c[i]+c[j/2]+(j&1); fl&=1;
		cnt[j/2][fl]++;
	}
	for(int i=0;i<n;i++)ret+=min(cnt[i][0],cnt[i][1]);
	cout<<ret<<endl;
}