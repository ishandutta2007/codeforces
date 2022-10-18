#include <bits/stdc++.h>
using namespace std;

int a, b, best_x, best_y;
vector < pair <int, int> > v;
vector < pair <int, int> > cur;

void rec(int x, int y){
	if(x == 3 || y == 3){
		int Lx = 0, Rx = 0, Ly = 0, Ry = 0, d = 0;
		for(int i = 0; i < (int)cur.size(); i++){
			if(cur[i].first == 0){
				if(cur[i].second == 0){
					if(i != 4){
						Lx += 25;
						Rx += 25;
						Ry += 23;
					}else{
						Lx += 15;
						Rx += 15;
						Ry += 13;
					}
				}else{
					if(i != 4){
						Lx += 26;
						Rx += 26;
						Ly += 24;
						Ry += 24;
						d = 1;
					}else{
						Lx += 16;
						Rx += 16;
						Ly += 14;
						Ry += 14;
						d = 1;
					}
				}
			}else{
				if(cur[i].second == 0){
					if(i != 4){
						Ly += 25;
						Ry += 25;
						Rx += 23;
					}else{
						Ly += 15;
						Ry += 15;
						Rx += 13;
					}
				}else{
					if(i != 4){
						Ly += 26;
						Ry += 26;
						Lx += 24;
						Rx += 24;
						d = 1;
					}else{
						Ly += 16;
						Ry += 16;
						Lx += 14;
						Rx += 14;
						d = 1;
					}
				}
			}
		}
		
		int s = 0;
		if(d == 0){
			if(a < Lx || Rx < a)return;
			if(b < Ly || Ry < b)return;
		}else{
			bool ok = false;
			if((Lx <= a && a <= Rx) && (Ly <= b && b <= Ry))ok = true;
			if(Rx < a){
				if(Ly + (a - Rx) <= b && b <= Ry + (a - Rx)){
					ok = true;
					s = a - Rx;
				}
			}
			if(Ry < b){
				if(Lx + (b - Ry) <= a && a <= Rx + (b - Ry)){
					ok = true;
					s = b - Ry;
				}
			}
			if(!ok)return;
		}
		
		if(v.empty() || x - y > best_x - best_y){
			best_x = x;
			best_y = y;
			v = vector < pair <int, int> > (x + y, make_pair(0, 0));
			
			int rem_x = a - s, rem_y = b - s, rem_s = s;
			
			for(int i = 0; i < (int)v.size(); i++){
				if(cur[i].first == 0){
					if(cur[i].second == 0){
						if(i != 4){
							v[i].first = 25;
							rem_x -= 25;
						}else{
							v[i].first = 15;
							rem_x -= 15;
						}
					}else{
						if(i != 4){
							v[i].first = 26;
							rem_x -= 26;
							v[i].second = 24;
							rem_y -= 24;
						}else{
							v[i].first = 16;
							rem_x -= 16;
							v[i].second = 14;
							rem_y -= 14;
						}
					}
				}else{
					if(cur[i].second == 0){
						if(i != 4){
							v[i].second = 25;
							rem_y -= 25;
						}else{
							v[i].second = 15;
							rem_y -= 15;
						}
					}else{
						if(i != 4){
							v[i].second = 26;
							rem_y -= 26;
							v[i].first = 24;
							rem_x -= 24;
						}else{
							v[i].second = 16;
							rem_y -= 16;
							v[i].first = 14;
							rem_x -= 14;
						}
					}
				}
			}
			
			for(int i = 0; i < (int)v.size(); i++){
				if(cur[i].second == 1){
					v[i].first += rem_s;
					v[i].second += rem_s;
					rem_s = 0;
				}else{
					if(cur[i].first == 0){
						if(i != 4){
							int e = min(rem_y, 23);
							v[i].second += e;
							rem_y -= e;
						}else{
							int e = min(rem_y, 13);
							v[i].second += e;
							rem_y -= e;
						}
					}else{
						if(i != 4){
							int e = min(rem_x, 23);
							v[i].first += e;
							rem_x -= e;
						}else{
							int e = min(rem_x, 13);
							v[i].first += e;
							rem_x -= e;
						}
					}
				}
			}
		}
	}else{
		for(int p = 0; p <= 1; p++)
		for(int q = 0; q <= 1; q++){
			cur.push_back(make_pair(p, q));
			rec(x + (p == 0), y + (p == 1));
			cur.pop_back();
		}
	}
}

int main(){
	int m;
	scanf("%d", &m);
	
	while(m--){
		scanf("%d %d", &a, &b);
		
		v.clear();
		rec(0, 0);
		
		if(v.empty()){
			printf("Impossible\n");
		}else{
			printf("%d:%d\n", best_x, best_y);
			for(int i = 0; i < (int)v.size(); i++){
				if(i > 0)printf(" ");
				printf("%d:%d", v[i].first, v[i].second);
			}
			printf("\n");
		}
	}
	
	return 0;
}