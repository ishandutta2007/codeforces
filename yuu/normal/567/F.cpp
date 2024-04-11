#include <bits/stdc++.h>
using namespace std;
int n, k;
vector <int> re[71];
int x[100];
string sign[100];
int y[100];
int s[100];
using ll=long long;
bool check(int id, int vx, int vy){
	if(sign[id]=="=") return vx==vy;
	else if(sign[id]=="<") return vx<vy;
	else if(sign[id]==">") return vx>vy;
	else if(sign[id]=="<=") return vx<=vy;
	else if(sign[id]==">=") return vx>=vy;
	else assert(0);
}
bool done[71][71];
ll f[71][71];
int get_left(int pos, int u, int v){
	if((pos==u)||(pos==u+1)) return 0;
	else if((pos<u)||(pos>v)) return -1;
	else return 1;
}
int get_right(int pos, int u, int v){
	if((pos==v)||(pos==v-1)) return 0;
	else if((pos<u)||(pos>v)) return -1;
	else return 1;
}
int get_both(int pos, int u, int v){
	if((pos==u)||(pos==v)) return 0;
	else if((pos<u)||(pos>v)) return -1;
	else return 1;
}
ll F(int u, int v){
	if(u>v) return 1;
	if(done[u][v]) return f[u][v];
	done[u][v]=1;
	int i=((u-1)+(n-v))/2+1;
	///put 2 i at begining
	{
		bool good=1;
		for(int id: re[u]){
			if(!check(id, get_left(x[id], u, v), get_left(y[id], u, v))){
				good=0;
				break;
			}
		}
		if(good){
			for(int id: re[u+1]){
				if(!check(id, get_left(x[id], u, v), get_left(y[id], u, v))){
					good=0;
					break;
				}
			}
		}
		if(good) f[u][v]+=F(u+2, v);
	}
	if(u+1!=v){
		{
			bool good=1;
			for(int id: re[v]){
				if(!check(id, get_right(x[id], u, v), get_right(y[id], u, v))){
					good=0;
					break;
				}
			}
			if(good){
				for(int id: re[v-1]){
					if(!check(id, get_right(x[id], u, v), get_right(y[id], u, v))){
						good=0;
						break;
					}
				}
			}
			if(good) f[u][v]+=F(u, v-2);
		}
		{
			bool good=1;
			for(int id: re[u]){
				if(!check(id, get_both(x[id], u, v), get_both(y[id], u, v))){
					good=0;
					break;
				}
			}
			if(good){
				for(int id: re[v]){
					if(!check(id, get_both(x[id], u, v), get_both(y[id], u, v))){
						good=0;
						break;
					}
				}
			}
			if(good) f[u][v]+=F(u+1, v-1);
		}
	}
	return f[u][v];
}
int main(){
	cin>>n>>k;
	for(int i=0; i<k; i++){
		cin>>x[i]>>sign[i]>>y[i];
		s[i]=x[i]^y[i];
		re[x[i]].push_back(i);
		re[y[i]].push_back(i);
	}
	// cerr<<get_left(1, 1, 6)<<'\n';
	// cerr<<get_left(2, 1, 6)<<'\n';
	// cerr<<get_left(3, 1, 6)<<'\n';
	// cerr<<F(1, 4)<<'\n';
	cout<<F(1, n*2)<<'\n';;
}