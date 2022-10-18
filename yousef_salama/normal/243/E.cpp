#include <bits/stdc++.h>
using namespace std;

enum node_type {P_NODE, Q_NODE, LEAF};

struct PQ_Tree{
    node_type type;
    int value;
    vector <PQ_Tree*> children;
    bool black, white;

    PQ_Tree(node_type type, int value = -1): type(type), value(value){}
};

void print(PQ_Tree* t, int tabs = 0){
    for(int i = 0; i < tabs; i++)
        cout << '\t';
    
    if(t->type == LEAF)cout << "LEAF " << t->value << endl;
    else{
        if(t->type == P_NODE)cout << "P_NODE" << endl;
        else cout << "Q_NODE" << endl;

        for(auto c : t->children)
            print(c, tabs + 1);
    }
}

void generate_permutation(PQ_Tree* t, vector <int>& perm){
    if(t->type == LEAF){
        perm.push_back(t->value);
        return;
    }

    for(auto c : t->children)
        generate_permutation(c, perm);
}

PQ_Tree* build(int n){
    PQ_Tree* root = new PQ_Tree(P_NODE);
    for(int i = 0; i < n; i++)
        root->children.push_back(new PQ_Tree(LEAF, i));

    return root;
}


PQ_Tree* create_node(node_type type, const vector <PQ_Tree*>& v){
    PQ_Tree* ret = new PQ_Tree(type);
    ret->children = v;
    return ret;
}

void preprocess(PQ_Tree* t, const vector <bool>& black){
    if(t->type == LEAF){
        if(black[t->value]){
            t->black = true;
            t->white = false;
        }else{
            t->black = false;
            t->white = true;
        }
        return;
    }

    t->black = false, t->white = false;
    for(auto c : t->children){
        preprocess(c, black);
        t->black |= c->black;
        t->white |= c->white;
    }
}

optional < vector <PQ_Tree*> > black_then_white(PQ_Tree* t){
    if(t->type == LEAF){
        return vector <PQ_Tree*> ({t});
    }

    if(t->type == P_NODE){
        vector <PQ_Tree*> black_trees, white_trees;
        PQ_Tree* z = NULL;

        for(auto c : t->children){
            if(c->black && c->white){
                if(z == NULL)z = c;
                else{
                    return nullopt;
                }
            }else if(c->black){
                black_trees.push_back(c);
            }else{
                white_trees.push_back(c);
            }
        }

        vector <PQ_Tree*> middle;
        if(z != NULL){
            auto r = black_then_white(z);
            if(!r){
                return nullopt;
            }
            middle = r.value();
        }

        vector <PQ_Tree*> ret;
        
        if(black_trees.size() == 1)ret.push_back(black_trees[0]);
        else if(black_trees.size() > 1)ret.push_back(create_node(P_NODE, black_trees));

        ret.insert(ret.end(), middle.begin(), middle.end());

        if(white_trees.size() == 1)ret.push_back(white_trees[0]);
        else if(white_trees.size() > 1)ret.push_back(create_node(P_NODE, white_trees));

        return ret;
    }else{
        vector <PQ_Tree*> black_trees, white_trees;
        PQ_Tree* z = NULL;
        int dir = 0, prv = -1;

        for(auto c : t->children){
            int cur;
            if(c->black && c->white){
                cur = 1;

                if(z == NULL)z = c;
                else{
                    return nullopt;
                }
            }else if(c->black){
                cur = 0;
                
                black_trees.push_back(c);
            }else{
                cur = 2;

                white_trees.push_back(c);
            }

            if(prv != -1 && prv != cur){
                int cur_dir = (cur > prv ? 1 : -1);
                
                if(dir == 0)dir = cur_dir;
                else if(dir != cur_dir){
                    return nullopt;
                }
            }
            prv = cur;
        }

        vector <PQ_Tree*> middle;
        if(z != NULL){
            auto r = black_then_white(z);
            if(!r){
                return nullopt;
            }
            middle = r.value();
        }

        if(dir == -1){
            reverse(black_trees.begin(), black_trees.end());
            reverse(white_trees.begin(), white_trees.end());
        }

        vector <PQ_Tree*> ret;
        
        ret.insert(ret.end(), black_trees.begin(), black_trees.end());
        ret.insert(ret.end(), middle.begin(), middle.end());
        ret.insert(ret.end(), white_trees.begin(), white_trees.end());

        return ret;
    }
}

PQ_Tree* consecutive_black(PQ_Tree* t){
    if(t->type == LEAF){
        return t;
    }

    if(t->type == P_NODE){
        vector <PQ_Tree*> black_trees, white_trees, mixed_trees;
        for(auto c : t->children){
            if(c->black && c->white){
                mixed_trees.push_back(c);
            }else if(c->black){
                black_trees.push_back(c);
            }else{
                white_trees.push_back(c);
            }
        }

        PQ_Tree* ret = NULL;

        if(mixed_trees.size() > 2){
            return NULL;
        }

        if(mixed_trees.empty()){
            if(black_trees.size() == 1){
                ret = black_trees[0];
            }else if(black_trees.size() > 1){
                ret = create_node(P_NODE, black_trees);
            }
        }else if(mixed_trees.size() == 1 && black_trees.empty()){
            ret = consecutive_black(mixed_trees[0]);
            if(ret == NULL){
                return NULL;
            }
        }else{
            vector <PQ_Tree*> v;

            auto r1 = black_then_white(mixed_trees[0]);
            if(!r1){
                return NULL;
            }
            v.insert(v.end(), r1.value().rbegin(), r1.value().rend());

            if(black_trees.size() == 1){
                v.push_back(black_trees[0]);
            }else if(black_trees.size() > 1){
                v.push_back(create_node(P_NODE, black_trees));
            }

            if(mixed_trees.size() == 2){
                auto r2 = black_then_white(mixed_trees[1]);
                if(!r2){
                    return NULL;
                }
                v.insert(v.end(), r2.value().begin(), r2.value().end());
            }

            ret = create_node(Q_NODE, v);
        }

        if(ret == NULL)return create_node(P_NODE, white_trees);
        else if(white_trees.empty())return ret;
        else{
            white_trees.push_back(ret);
            return create_node(P_NODE, white_trees);
        }
    }else{
        int cnt_black = 0, cnt_white = 0, cnt_mixed = 0;
        int prv = -1, dir = 0;

        for(auto c : t->children){
            int cur;
            if(c->black && c->white){
                cur = 1;
                cnt_mixed++;
            }else if(c->black){
                cur = 2;
                cnt_black++;
            }else{
                cur = 0;
                cnt_white++;
            }

            if(prv != -1 && prv != cur){
                int cur_dir = (cur > prv ? 1 : -1);
                if(dir == 0)dir = cur_dir;
                else{
                    if(dir == -1 && cur_dir == 1){
                        return NULL;
                    }
                    dir = cur_dir;
                }
            }
            prv = cur;
        }

        if(cnt_mixed > 2){
            return NULL;
        }

        vector <PQ_Tree*> v;
        prv = -1;

        for(auto c : t->children){
            int cur;
            if(c->black && c->white){
                cur = 1;

                if(cnt_black == 0 && cnt_mixed == 1){
                    PQ_Tree* cur = consecutive_black(c);
                    if(cur == NULL)return NULL;

                    v.push_back(cur);
                }else{
                    auto r = black_then_white(c);
                    if(!r){
                        return NULL;
                    }

                    if(prv == -1 || prv == 0){
                        v.insert(v.end(), r.value().rbegin(), r.value().rend());
                    }else{
                        v.insert(v.end(), r.value().begin(), r.value().end());
                    }
                }
            }else if(c->black){
                cur = 2;
                v.push_back(c);
            }else{
                cur = 0;
                v.push_back(c);
            }
            prv = cur;
        }

        if(v.size() == 1)return v[0];
        else return create_node(Q_NODE, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    PQ_Tree* tree = build(n);

    for(int i = 0; i < n; i++){
        vector <bool> v(n, false);
        for(int j = 0; j < n; j++)
            v[j] = (s[i][j] - '0');

        preprocess(tree, v);

        tree = consecutive_black(tree);
        if(tree == NULL){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    vector <int> perm;
    generate_permutation(tree, perm);

    for(int i = 0; i < n; i++){
        string q(n, '0');
        for(int j = 0; j < n; j++)
            q[j] = s[i][perm[j]];
        
        cout << q << '\n';
    }

    return 0;
}