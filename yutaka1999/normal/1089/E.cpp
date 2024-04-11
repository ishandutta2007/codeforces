#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> P;
int main(){
	int n;
	scanf("%d",&n);
	
	vector<P> vec;
	if(n <= 49){
		int x = 0, y = 0;
		vec.push_back(P(x,y));
		for(int i = 0 ; i < n-2 ; i ++){
			if(y%2 == 0){
				if(x == 7){
					y ++;
				}
				else x ++;
			}
			else {
				if(x == 0){
					y ++;
				}
				else x --;
			}
			vec.push_back(P(x,y));
		}
		if(x == 7){
			y = 6;
			vec.push_back(P(x,y));
			y = 7;
			vec.push_back(P(x,y));
		}
		else {
			y = 7;
			vec.push_back(P(x,y));
			x = 7;
			vec.push_back(P(x,y));
		}
	}
	else if(n <= 62){
		int x = 0, y = 0;
		vec.push_back(P(x,y));
		for(int i = 0 ; i < 47 ; i ++){
			if(y%2 == 0){
				if(x == 7){
					y ++;
				}
				else x ++;
			}
			else {
				if(x == 0){
					y ++;
				}
				else x --;
			}
			vec.push_back(P(x,y));
		}
		for(int i = 47 ; i < n-2 ; i ++){
			if(x%2 == 0){
				if(y == 7){
					x ++;
				}
				else y ++;
			}
			else {
				if(y == 6){
					x ++;
				}
				else y --;
			}
			vec.push_back(P(x,y));
		}
		if(y == 7){
			x = 6;
			vec.push_back(P(x,y));
			x = 7;
			vec.push_back(P(x,y));
		}
		else {
			x = 7;
			vec.push_back(P(x,y));
			y = 7;
			vec.push_back(P(x,y));
		}
	}
	else {
		int x = 0, y = 0;
		vec.push_back(P(x,y));
		for(int i = 0 ; i < 47 ; i ++){
			if(y%2 == 0){
				if(x == 7){
					y ++;
				}
				else x ++;
			}
			else {
				if(x == 0){
					y ++;
				}
				else x --;
			}
			vec.push_back(P(x,y));
		}
		for(int i = 47 ; i < 59 ; i ++){
			if(x%2 == 0){
				if(y == 7){
					x ++;
				}
				else y ++;
			}
			else {
				if(y == 6){
					x ++;
				}
				else y --;
			}
			vec.push_back(P(x,y));
		}
		vec.push_back(P(7,6));
		vec.push_back(P(6,6));
		vec.push_back(P(6,7));
		vec.push_back(P(7,7));
	}
	
	for(int i = 0 ; i < vec.size() ; i ++){
		printf("%c%d",'a'+vec[i].first,vec[i].second+1);
		if(i+1 != vec.size())printf(" ");
	}
	printf("\n");
}