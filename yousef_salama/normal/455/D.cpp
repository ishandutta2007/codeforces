#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int number, prior, cnt;
    node *left, *right, *parent, *all;

    node(){}
    node(int number): number(number), prior(rand()), cnt(1), left(nullptr), right(nullptr), parent(nullptr), all(nullptr){}
};

void refresh(node *t){
    t->cnt = 1;
    if(t->left != nullptr){
        t->cnt += t->left->cnt;
        t->left->parent = t;
    }
    if(t->right != nullptr){
        t->cnt += t->right->cnt;
        t->right->parent = t;
    }
}

void merge(node *t1, node *t2, node *&t){
    if(t1 == nullptr){
        t = t2;
        return;
    }
    if(t2 == nullptr){
        t = t1;
        return;
    }

    if(t1->prior >= t2->prior){
        merge(t1->right, t2, t1->right);
        t = t1;

        refresh(t);
    }else{
        merge(t1, t2->left, t2->left);
        t = t2;

        refresh(t);
    }
}

void split(node *t, int index, node *&t1, node *&t2){
    if(t == nullptr){
        t1 = nullptr;
        t2 = nullptr;

        return;
    }

    t->parent = nullptr;

    int t_index = t->left == nullptr ? 0 : t->left->cnt;
    if(index < t_index){
        split(t->left, index, t1, t->left);
        t2 = t;

        refresh(t2);
    }else{
        split(t->right, index - t_index - 1, t->right, t2);
        t1 = t;

        refresh(t1);
    }
}

int search(node *t, int index){
    int t_index = t->left == nullptr ? 0 : t->left->cnt;
    if(index == t_index)return t->number;

    if(index < t_index)return search(t->left, index);
    else return search(t->right, index - t_index - 1);
}

int calc_index(node *t){
    if(t->parent == nullptr){
        return (t->left == nullptr ? 0 : t->left->cnt);
    }

    if(t->parent->left == t){
        int ret = calc_index(t->parent);
        ret -= 1 + (t->right == nullptr ? 0 : t->right->cnt);
        return ret;
    }else{
        int ret = calc_index(t->parent);
        ret += 1 + (t->left == nullptr ? 0 : t->left->cnt);
        return ret;
    }
}

void split_secondary(node *t, int index, node *&t1, node *&t2){
    if(t == nullptr){
        t1 = nullptr;
        t2 = nullptr;

        return;
    }

    t->parent = nullptr;

    int t_index = calc_index(t->all);
    if(index < t_index){
        split_secondary(t->left, index, t1, t->left);
        t2 = t;

        refresh(t2);
    }else{
        split_secondary(t->right, index, t->right, t2);
        t1 = t;

        refresh(t1);
    }
}

void print(node *t, int tab = 0){
    if(t == nullptr)return;

    print(t->left, tab + 1);

    for(int i = 0; i < tab; i++)printf("\t");
    printf("%d, %d, %d, %d\n", t->number, t->prior, t->cnt, calc_index(t->all));

    print(t->right, tab + 1);
}

int main(){
    srand(time(NULL));

    int n;
    scanf("%d", &n);

    vector <node*> treaps(n + 1, nullptr);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        
        node* main_treap_node = new node(a);
        node* secondary_treap_node = new node(a);
        main_treap_node->all = main_treap_node;
        secondary_treap_node->all = main_treap_node;

        merge(treaps[0], main_treap_node, treaps[0]);
        merge(treaps[a], secondary_treap_node, treaps[a]);
    }

    int q;
    scanf("%d", &q);

    int lastans = 0;

    while(q--){
        int opt;
        scanf("%d", &opt);

        if(opt == 1){
            int l, r;
            scanf("%d %d", &l, &r);
            
            l = (l + lastans - 1) % n;
            r = (r + lastans - 1) % n;
            if(l == r)continue;
            if(l > r)swap(l, r);

            int number = search(treaps[0], r);
            node *t1, *t2, *t3, *t4;

            split_secondary(treaps[number], l - 1, t1, t2);
            split_secondary(t2, r - 1, t2, t3);
            split_secondary(t3, r, t3, t4);

            merge(t1, t3, t1);
            merge(t1, t2, t1);
            merge(t1, t4, t1);
            treaps[number] = t1;
            
            split(treaps[0], l - 1, t1, t2);
            split(t2, r - l - 1, t2, t3);
            split(t3, 0, t3, t4);

            merge(t1, t3, t1);
            merge(t1, t2, t1);
            merge(t1, t4, t1);
            treaps[0] = t1;
        }else{
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            
            l = (l + lastans - 1) % n;
            r = (r + lastans - 1) % n;
            k = (k + lastans - 1) % n + 1;
            if(l > r)swap(l, r);

            node *t1, *t2, *t3;
            split_secondary(treaps[k], l - 1, t1, t2);
            split_secondary(t2, r, t2, t3);

            lastans = t2 == nullptr ? 0 : t2->cnt;

            merge(t1, t2, t1);
            merge(t1, t3, t1);
            treaps[k] = t1;

            printf("%d\n", lastans);
        }
    }


    return 0;
}