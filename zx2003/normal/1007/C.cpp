#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
ll n,x,y,lx,ly;int z;
double tot,zz,nzz;
int main(){
	scanf("%lld",&n);mp[n]=n;
	lx=ly=1;
	for(;;){
		tot=1.0*(mp.begin()->first-lx+1)*(mp.begin()->second-ly+1);
		for(auto it1=mp.begin(),it2=it1;++it2!=mp.end();++it1)
			tot+=1.0*(it2->second-ly+1)*(it2->first-it1->first);
		if(1.0*(mp.begin()->first-lx+1)*(mp.begin()->second-ly+1)>=tot/3){
			x=ll(tot/3/(mp.begin()->second-ly+1))+lx;
		}else{
			zz=1.0*(mp.begin()->first-lx+1)*(mp.begin()->second-ly+1);
			for(auto it1=mp.begin(),it2=it1;++it2!=mp.end();++it1){
				nzz=zz+1.0*(it2->second-ly+1)*(it2->first-it1->first);
				if(nzz>=tot/3){x=ll((tot/3-zz)/(it2->second-ly+1))+it1->first;break;}zz=nzz;
			}
		}
		x=max(x,lx);x=min(x,mp.rbegin()->first);
		if(1.0*(mp.rbegin()->first-lx+1)*(mp.rbegin()->second-ly+1)>=tot/3){
			y=ll(tot/3/(mp.rbegin()->first-lx+1))+ly;
		}else{
			zz=1.0*(mp.rbegin()->first-lx+1)*(mp.rbegin()->second-ly+1);
			for(auto it1=mp.rbegin(),it2=it1;++it2!=mp.rend();++it1){
				nzz=zz+1.0*(it2->second-it1->second)*(it2->first-lx+1);
				if(nzz>=tot/3){y=ll((tot/3-zz)/(it2->first-lx+1))+it1->second;break;}zz=nzz;
			}
		}
		y=max(y,ly);y=min(y,mp.begin()->second);
		printf("%lld %lld\n",x,y);fflush(stdout);
		scanf("%d",&z);
		if(z==0)break;
		if(z==1){
			lx=x+1;
			for(;mp.begin()->first<lx;mp.erase(mp.begin()));
		}
		if(z==2){
			ly=y+1;
			for(;mp.rbegin()->second<ly;mp.erase(--mp.end()));
		}
		if(z==3){
			ll v1,v2;
			v1=mp.lower_bound(x-1)->second;
			for(auto it=mp.rbegin();;++it)if(it->second>=y-1){v2=it->first;break;}
			for(auto it=mp.begin();it!=mp.end();)if(it->first>=x && it->second>=y)mp.erase(it++);else ++it;
			if(x-1>=lx)mp[x-1]=v1;if(y-1>=ly)mp[v2]=y-1;
		}
	}
	return 0;
}