#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
vector<pair<pair<int,int>,int>> ret;

void add(int a,int b,int c){
	ret.push_back(mp(mp(a,b),c));
}

void solve(int l,int r){
	if(l!=1){
		solve(1,r-l+1);
		for(auto &ed: ret){
			if(ed.fr.fr==0)ed.sc+=l-1;
		}
		return;
	}
	if(r==1){
		n=2;
		add(0,1,1);
	}
	else if(r==2){
		n=3;
		add(0,1,1);
		add(0,2,1);
		add(1,2,1);
	}
	else if(r==3){
		n=4;
		add(0,1,1);
		add(0,3,1);
		add(1,2,1);
		add(1,3,1);
		add(2,3,1);
	}
	else if(r==4){
		n=4;
		add(0,1,1);
		add(0,2,2);
		add(0,3,1);
		add(1,2,2);
		add(1,3,1);
		add(2,3,1);
	}
	else {
		int k=(r-1)/4;
		solve(1,k);
		if(k<=4){
			for(auto &ed: ret){
				if(ed.fr.sc==n-1)ed.fr.sc++;
			}
			add(n-1,n,1);
			n++;
		}
		n+=3;
		for(auto &ed: ret){
			ed.fr.fr+=3;
			ed.fr.sc+=3;
		}
		add(0,n-1,1);
		add(0,1,1);
		add(0,2,k+1);
		add(0,3,1);
		add(1,2,2*k);
		add(1,3,k);
		add(2,3,k);
		if(r>=4*k+2)add(1,n-1,4*k+1);
		if(r>=4*k+3)add(1,n-2,4*k+1);
		if(r>=4*k+4)add(0,n-2,4*k+3);
	}
}
int main(){
	int l,r;
	cin>>l>>r;
	solve(l,r);
	
	puts("YES");
	printf("%d %d\n",n,(int)ret.size());
	for(auto ed: ret){
		printf("%d %d %d\n",ed.fr.fr+1,ed.fr.sc+1,ed.sc);
	}
}