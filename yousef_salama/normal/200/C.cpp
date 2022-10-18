#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
string team1, team2, score;
int goal1, goal2;
map <string, pair<int, pair <int, int> > > mp;
map <string, int> match;
struct team{
    string name;
    int score, A, B;
    team(string a, int b, int c, int d){
        name = a;
        score = b;
        A = c;
        B = d;
    }
};
vector <team> v;
int main() {
    int itr = 5;
    while(itr--){
        cin >> team1 >> team2 >> score;
        match[team1]++;
        match[team2]++;
        goal1 = score[0] - '0';
        goal2 = score[2] - '0';

        if(goal1 > goal2){
            pair <int, pair <int, int> > cur1, cur2;
            if(!mp.count(team1))
                cur1 = make_pair(0, make_pair(0, 0));
            else
                cur1 = mp[team1];
            if(!mp.count(team2))
                cur2 = make_pair(0, make_pair(0, 0));
            else
                cur2 = mp[team2];

            cur1.first += 3;
            cur1.second.first += goal1;
            cur1.second.second += goal2;

            cur2.second.first += goal2;
            cur2.second.second += goal1;

            mp[team1] = cur1;
            mp[team2] = cur2;
        }else if(goal2 > goal1){
            pair <int, pair <int, int> > cur1, cur2;
            if(!mp.count(team1))
                cur1 = make_pair(0, make_pair(0, 0));
            else
                cur1 = mp[team1];
            if(!mp.count(team2))
                cur2 = make_pair(0, make_pair(0, 0));
            else
                cur2 = mp[team2];

            cur2.first += 3;
            cur2.second.first += goal2;
            cur2.second.second += goal1;

            cur1.second.first += goal1;
            cur1.second.second += goal2;
            mp[team1] = cur1;
            mp[team2] = cur2;
        }else{
            pair <int, pair <int, int> > cur1, cur2;
            if(!mp.count(team1))
                cur1 = make_pair(0, make_pair(0, 0));
            else
                cur1 = mp[team1];
            if(!mp.count(team2))
                cur2 = make_pair(0, make_pair(0, 0));
            else
                cur2 = mp[team2];

            cur1.first += 1;
            cur1.second.first += goal1;
            cur1.second.second += goal2;

            cur2.first += 1;
            cur2.second.first += goal2;
            cur2.second.second += goal1;
            mp[team1] = cur1;
            mp[team2] = cur2;
        }
    }
    for(map <string, pair<int, pair<int, int> > > :: iterator it = mp.begin(); it != mp.end(); it++)
        v.push_back(team(it->first, it->second.first, it->second.second.first, it->second.second.second));

    int x = 0, y = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].name == "BERLAND")x = i;
        else{
            if(match[v[i].name] == 2)y = i;
        }
    }
    int optI = -1, optJ;
    for(int i = 0; i < 100; i++)
    for(int j = i + 1; j < 100; j++){
        int cnt = 0;
        v[y].A += i;
        v[y].B += j;
        
        v[x].score += 3;
        v[x].A += j;
        v[x].B += i;
        for(int k = 0; k < 4; k++)
            if(v[k].name != "BERLAND"){
                if(v[x].score > v[k].score){
                    cnt++;
                    continue;
                }
                if(v[x].score == v[k].score){
                    if(v[x].A - v[x].B > v[k].A - v[k].B){
                        cnt++;
                        continue;
                    }
                    if(v[x].A - v[x].B == v[k].A - v[k].B){
                        if(v[x].A > v[k].A){
                            cnt++;
                            continue;
                        }
                        if(v[x].A == v[k].A){
                            if(v[x].name < v[k].name){
                                cnt++;
                                continue;
                            }
                        }
                    }
                }
            }
        if(cnt >= 2){
            if(optI == -1){
                optI = i;
                optJ = j;
            }else{
                if(j - i < optJ - optI){
                    optI = i;
                    optJ = j;
                }else if(j - i == optJ - optI){
                    if(i < optI){
                        optI = i;
                        optJ = j;
                    }
                }
            }
        }
        v[y].A -= i;
        v[y].B -= j;
        
        v[x].score -= 3;
        v[x].A -= j;
        v[x].B -= i;
    }
    if(optI == -1)cout << "IMPOSSIBLE" << endl;
    else cout << optJ << ':' << optI << endl;
    return 0;
}