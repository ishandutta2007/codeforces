#include<bits/stdc++.h>
#define se second
using namespace std;

int n,m,fl;
struct Node{
	int id,door,mx[10],mn[10],sz;
}the,tmp;
map<int,Node>mp;
map<int,Node>::iterator it;

void onion(Node &x,Node y){
	for (int i=0;i<m;i++){
		x.mx[i]=max(x.mx[i],y.mx[i]);
		x.mn[i]=min(x.mn[i],y.mn[i]);
	}
	x.sz+=y.sz;
}

void doit(){
	for (fl=1;fl;){
		it=mp.lower_bound(the.door); if (it==mp.begin()) break;
		tmp=(--it)->se;
		fl=0;
		for (int i=0;i<m;i++)
			if (tmp.mx[i]>the.mn[i]){
				fl=1;
				break;
			}
		if (fl){
			mp.erase(it);
			onion(the,tmp);
		}
	}
	
	for (fl=1;fl;){
		it=mp.lower_bound(the.door); if (it==mp.end()) break;
		tmp=it->se;
		fl=0;
		for (int i=0;i<m;i++)
			if (tmp.mn[i]<the.mx[i]){
				fl=1;
				break;
			}
		if (fl){
			mp.erase(it);
			onion(the,tmp);
		}
	}
	
	mp[the.door]=the;
}

int main(){
	cin>>n>>m;
	mp.clear();
	for (int i=1;i<=n;i++){
		for (int j=0;j<m;j++){
			scanf("%d",&the.mn[j]);
			the.mx[j]=the.mn[j];
		}
		the.id=i; the.door=the.mx[0]; the.sz=1;
		doit();
		it=mp.end(); it--;
		printf("%d\n",it->se.sz);
	}
}