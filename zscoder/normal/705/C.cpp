#include "stdio.h"
#include "set"
#include "queue"

int n,q,t,xi,ty,co;
std::set<int> noti;
std::queue<int> app[300005];

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 0; i < q; i++){
		scanf("%d%d",&ty,&xi);
		if(ty==1){
			app[xi].push(t);
			noti.insert(t++);
			co++;
		}else if(ty==2){
			while(!app[xi].empty()){
				if(noti.count(app[xi].front())==1){
					noti.erase(app[xi].front());
					co--;
				}
				app[xi].pop();
			}
		}else{
			for(auto it = noti.begin(); it != noti.end();){
				if(*it < xi){
					it = noti.erase(it);
					co--;
				}else break;
			}
		}
		printf("%d\n",co);
	}

}