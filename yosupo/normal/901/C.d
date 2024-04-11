/+ dub.sdl:
    name "C"
    dependency "dcomp" version=">=0.9.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;

import std.typecons;

// import dcomp.segtree.lazyseg;

int main() {
    Scanner sc = new Scanner(stdin);

    int n, m;
    sc.read(n, m);
    int[][] g = new int[][n];
    foreach (i; 0..m) {
        int a, b;
        sc.read(a, b); a--; b--;
        g[a] ~= b; g[b] ~= a;
    }
    
    int[] par = new int[n];
    int[] dps = new int[n];
    bool[] vis = new bool[n];

    int[] ri = new int[n+1]; ri[] = n;

    void add(int s, int t) {
        int mi = t, ma = t;
        while (s != t) {
            mi = min(mi, s);
            ma = max(ma, s);
            s = par[s];
        }
        ri[mi] = min(ri[mi], ma);
    }

    void dfs(int p, int b = -1, int ndp = 0) {
        par[p] = b;
        dps[p] = ndp;
        vis[p] = true;
        foreach (d; g[p]) {
            if (d == b) continue;
            if (!vis[d]) {
                dfs(d, p, ndp+1);
                continue;
            }
            if (dps[p] < dps[d]) continue;
            add(p, d);
        }
    }
    foreach (i; 0..n) {
        if (vis[i]) continue;
        dfs(i);
    }
    foreach_reverse (i; 0..n-1) {
        ri[i] = min(ri[i], ri[i+1]);
    }
//    writeln(ri);

    int q;
    sc.read(q);
    long[] res = new long[q];

    alias E = Tuple!(int, "left", int, "right", int, "id", bool, "pos");
    E[][] ev = new E[][](n+1);

    foreach (i; 0..q) {
        int a, b;
        sc.read(a, b); a--;
        res[i] = long(b-a) * long(b-a + 1) / 2;
        ev[b] ~= E(a, b, i, false);
        ev[a] ~= E(a, b, i, true);
    }

    alias N = Tuple!(long, int);
    auto seg = LazySeg!(N, long,
        (a, b) => N(a[0]+b[0], a[1]+b[1]),
        (a, b) => N(a[0]+a[1]*b, a[1]),
        "a+b",
        N(0, 0), 0)(N(0, 1).repeat.take(n).array);
    foreach (r; 0..n+1) {
        foreach (e; ev[r]) {
            long u = seg[e.left..e.right].sum[0];
            if (e.pos) {
                res[e.id] += u;
            } else {
                res[e.id] -= u;
            }
        }
        seg[ri[r]..$] += 1;
    }
    writeln(res.map!(to!string).join("\n"));


    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/foundation.d */
 
// module dcomp.foundation;

 
static if (__VERSION__ <= 2070) {
    /*
    Copied by https://github.com/dlang/phobos/blob/master/std/algorithm/iteration.d
    Copyright: Andrei Alexandrescu 2008-.
    License: $(HTTP boost.org/LICENSE_1_0.txt, Boost License 1.0).
    */
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/segtree/lazyseg.d */
// module dcomp.segtree.lazyseg;

// import dcomp.segtree.primitive;

import std.functional : binaryFun;

 
alias LazySeg(T, L, alias opTT, alias opTL, alias opLL, T eT, L eL, alias Engine = LazySegEngine) =
    SegTree!(Engine, T, L , binaryFun!opTT, binaryFun!opTL, binaryFun!opLL, eT, eL);

 
 


struct LazySegEngine(T, L, alias opTT, alias opTL, alias opLL, T eT, L eL) {
    import std.typecons : Tuple;
    alias DataType = T;
    alias LazyType = L;
    alias BinSearch = binSearchLazy;
    alias S = Tuple!(T, "d", L, "lz");
    uint n, sz, lg;
    S[] s;
    this(uint n) {
        import std.conv : to;
        import std.algorithm : each;
        this.n = n;
        uint lg = 0;
        while ((2^^lg) < n) lg++;
        this.lg = lg;
        sz = 2^^lg;
        s = new S[](2*sz);
        s.each!((ref x) => x = S(eT, eL));
    }
    this(T[] first) {
        import std.conv : to;
        import std.algorithm : each;
        n = first.length.to!uint;
        uint lg = 0;
        while ((2^^lg) < n) lg++;
        this.lg = lg;
        sz = 2^^lg;

        s = new S[](2*sz);
        s.each!((ref x) => x = S(eT, eL));
        foreach (i; 0..n) {
            s[sz+i].d = first[i];
        }
        foreach_reverse (i; 1..sz) {
            update(i);
        }
    }
    @property uint length() const { return n; }
    pragma(inline):
    private void lzAdd(uint k, in L x) {
        s[k].lz = opLL(s[k].lz, x);
        s[k].d = opTL(s[k].d, x);
    }
    public void push(uint k) {
        if (s[k].lz == eL) return;
        lzAdd(2*k, s[k].lz);
        lzAdd(2*k+1, s[k].lz);
        s[k].lz = eL;
    }
    private void update(uint k) {
        s[k].d = opTT(s[2*k].d, s[2*k+1].d);
    }
    T single(uint k) {
        k += sz;
        foreach_reverse (uint i; 1..lg+1) {
            push(k>>i);
        }
        return s[k].d;
    }
    void singleSet(uint k, T x) {
        k += sz;
        foreach_reverse (uint i; 1..lg+1) {
            push(k>>i);
        }
        s[k].d = x;
        foreach (uint i; 1..lg+1) {
            update(k>>i);
        }
    }
    T sum(uint a, uint b) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return eT;
        a += sz; b--; b += sz;
        uint tlg = lg;
        while (true) {
            uint k = a >> tlg;
            if (a >> tlg != b >> tlg) {
                tlg++;
                break;
            }
            if (((a-1) >> tlg) + 2 == (b+1) >> tlg) return s[k].d;
            push(k);
            tlg--;
        }
        T sm = eT;
        foreach_reverse (l; 0..tlg) {
            uint k = a >> l;
            if ((a-1)>>l != a>>l) {
                sm = opTT(s[k].d, sm);
                break;
            }
            push(k);
            if (!((a >> (l-1)) & 1)) sm = opTT(s[2*k+1].d, sm);
        }
        foreach_reverse (l; 0..tlg) {
            uint k = b >> l;
            if (b>>l != (b+1)>>l) {
                sm = opTT(sm, s[k].d);
                break;
            }
            push(k);
            if ((b >> (l-1)) & 1) sm = opTT(sm, s[2*k].d);
        }
        return sm;
    }
    void add(uint a, uint b, L x) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return;
        a += sz; b--; b += sz;
        uint tlg = lg;
        while (true) {
            uint k = a >> tlg;
            if (a >> tlg != b >> tlg) {
                tlg++;
                break;
            }
            if (((a-1) >> tlg) + 2 == (b+1) >> tlg) {
                lzAdd(k, x);
                foreach (l; tlg+1..lg+1) {
                    update(a >> l);
                }
                return;
            }
            push(k);
            tlg--;
        }
        foreach_reverse (l; 0..tlg) {
            uint k = a >> l;
            if ((a-1)>>l != a>>l) {
                lzAdd(k, x);
                foreach (h; l+1..tlg) {
                    update(a >> h);
                }
                break;
            }
            push(k);
            if (!((a >> (l-1)) & 1)) lzAdd(2*k+1, x);
        }
        foreach_reverse (l; 0..tlg) {
            uint k = b >> l;
            if (b>>l != (b+1)>>l) {
                lzAdd(k, x);
                foreach (h; l+1..tlg) {
                    update(b >> h);
                }
                break;
            }
            push(k);
            if ((b >> (l-1)) & 1) lzAdd(2*k, x);
        }
        foreach (l; tlg..lg+1) {
            update(a >> l);
        }
    }
}



 


int binSearchLazy(bool rev, alias pred, TR)(TR t, int a, int b) {
    import std.traits : TemplateArgsOf;
    alias args = TemplateArgsOf!TR;
    alias opTT = args[2];
    auto x = args[5];
    with (t) {
        static if (!rev) {
             
            if (pred(x)) return a-1;
            int pos = a;
            void f(int a, int b, int l, int r, int k) {
                if (b <= l || r <= a) return;
                if (a <= l && r <= b && !pred(opTT(x, s[k].d))) {
                    x = opTT(x, s[k].d);
                    pos = r;
                    return;
                }
                if (l+1 == r) return;
                push(k);
                int md = (l+r)/2;
                f(a, b, l, md, 2*k);
                if (pos >= md) f(a, b, md, r, 2*k+1);
            }
            f(a, b, 0, sz, 1);
            return pos;
        } else {
             
            if (pred(x)) return b;
            int pos = b-1;
            void f(int a, int b, int l, int r, int k) {
                if (b <= l || r <= a) return;
                if (a <= l && r <= b && !pred(opTT(x, s[k].d))) {
                    x = opTT(s[k].d, x);
                    pos = l-1;
                    return;
                }
                if (l+1 == r) return;
                push(k);
                int md = (l+r)/2;
                f(a, b, md, r, 2*k+1);
                if (pos < md) f(a, b, l, md, 2*k);
            }
            f(a, b, 0, sz, 1);
            return pos;            
        }
    }
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

// import dcomp.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    char[512] lineBuf;
    char[] line;
    private bool succW() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (!line.empty && line.front.isWhite) {
            line.popFront;
        }
        return !line.empty;
    }
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            line = lineBuf[];
            f.readln(line);
            if (!line.length) return false;
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else static if (isStaticArray!T) {
                foreach (i; 0..T.length) {
                    bool f = succW();
                    assert(f);
                    x[i] = line.parse!E;
                }
            } else {
                StackPayload!E buf;
                while (succW()) {
                    buf ~= line.parse!E;
                }
                x = buf.data;
            }
        } else {
            x = line.parse!T;
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}


 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/segtree/primitive.d */
// module dcomp.segtree.primitive;

import std.conv : to;

struct SegTree(alias E, Args...) {
    import std.traits : ReturnType;
    alias Engine = E!Args;
    alias T = Engine.DataType;
    alias L = Engine.LazyType;

    Engine eng;

    this(size_t n) { eng = Engine(n.to!uint); }
    this(T[] first) { eng = Engine(first); }

    @property size_t length() const { return eng.length(); }
    @property size_t opDollar() const { return eng.length(); }
    
    struct Range {
        Engine* eng;
        size_t start, end;
        @property const(T) sum() {
            return eng.sum(start.to!uint, end.to!uint);
        }
    }
    const(T) opIndex(size_t k) {
        assert(0 <= k && k < eng.length());
        return eng.single(k.to!uint);
    }
    void opIndexAssign(T x, size_t k) {
        assert(0 <= k && k < eng.length());
        eng.singleSet(k.to!uint, x);
    }
    size_t[2] opSlice(size_t dim : 0)(size_t start, size_t end) {
        assert(0 <= start && start <= end && end <= eng.length());
        return [start, end];
    }
    Range opIndex(size_t[2] rng) {
        return Range(&eng, rng[0].to!uint, rng[1].to!uint);
    }
    static if (!is(L == void)) {
        void opIndexOpAssign(string op : "+")(L x, size_t[2] rng) {
            eng.add(rng[0].to!uint, rng[1].to!uint, x);
        }
    }
}

import std.traits : isInstanceOf;

ptrdiff_t binSearchLeft(alias pred, TR)(TR t, ptrdiff_t a, ptrdiff_t b) 
if (isInstanceOf!(SegTree, TR)) {
    return TR.Engine.BinSearch!(false, pred)(t.eng, a.to!int, b.to!int);
}

ptrdiff_t binSearchRight(alias pred, TR)(TR t, ptrdiff_t a, ptrdiff_t b) 
if (isInstanceOf!(SegTree, TR)) {
    return TR.Engine.BinSearch!(true, pred)(t.eng, a.to!int, b.to!int);
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/container/stackpayload.d */
// module dcomp.container.stackpayload;

 
struct StackPayload(T, size_t MINCAP = 4) if (MINCAP >= 1) {
    import core.exception : RangeError;

    private T* _data;
    private uint len, cap;

    @property bool empty() const { return len == 0; }
    @property size_t length() const { return len; }
    alias opDollar = length;

     
    inout(T)[] data() inout { return (_data) ? _data[0..len] : null; }
    
    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (len <= i) throw new RangeError();
        return _data[i];
    }  
    ref inout(T) front() inout { return this[0]; }  
    ref inout(T) back() inout { return this[$-1]; }  

    void reserve(size_t newCap) {
        import core.memory : GC;
        import core.stdc.string : memcpy;
        import std.conv : to;
        if (newCap <= cap) return;
        void* newData = GC.malloc(newCap * T.sizeof);
        cap = newCap.to!uint;
        if (len) memcpy(newData, _data, len * T.sizeof);
        _data = cast(T*)(newData);
    }  
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }  
     
    void clear() {
        len = 0;
    }

    void insertBack(T item) {
        import std.algorithm : max;
        if (len == cap) reserve(max(cap * 2, MINCAP));
        _data[len++] = item;
    }  
    alias opOpAssign(string op : "~") = insertBack;  
    void removeBack() {
        assert(!empty, "StackPayload.removeBack: Stack is empty");
        len--;
    }  
}

 

/*
This source code generated by dcomp and include dcomp's source code.
dcomp's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dcomp)
dcomp's License: MIT License(https://github.com/yosupo06/dcomp/blob/master/LICENSE.txt)
*/