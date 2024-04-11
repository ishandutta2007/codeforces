/+ dub.sdl:
    name "B"
    dependency "dunkelheit" version="1.0.1"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dkh.foundation, dkh.scanner, dkh.datastructure.segtree;

int main() {
    Scanner sc = new Scanner(stdin);
    scope(exit) assert(!sc.hasNext);

    int n;
    sc.read(n);
    int[] a;
    sc.read(a);

    auto seg = LazySeg!(int, int,
        "a+b",
        (a, b) => max(a, b),
        (a, b) => max(a, b),
        -1,
        -1)(a);

    int q;
    sc.read(q);

    foreach (i; 0..q) {
        int ty;
        sc.read(ty);
        if (ty == 1) {
            int p, x;
            sc.read(p, x); p--;
            seg[p] = x;
        } else {
            int x;
            sc.read(x);
            seg[0..n] += x;
        }
    }

    iota(n).map!(i => seg[i]).map!(to!string).join(" ").writeln;
    return 0;
}
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/datastructure/segtree.d */
// module dkh.datastructure.segtree;

import std.conv : to;
import std.functional : binaryFun;
import std.traits : isInstanceOf;

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

ptrdiff_t binSearchLeft(alias pred, TR)(TR t, ptrdiff_t a, ptrdiff_t b) 
if (isInstanceOf!(SegTree, TR)) {
    return TR.Engine.BinSearch!(false, pred)(t.eng, a.to!int, b.to!int);
}

ptrdiff_t binSearchRight(alias pred, TR)(TR t, ptrdiff_t a, ptrdiff_t b) 
if (isInstanceOf!(SegTree, TR)) {
    return TR.Engine.BinSearch!(true, pred)(t.eng, a.to!int, b.to!int);
}

 
alias SimpleSeg(T, alias opTT, T eT, alias Engine = SimpleSegEngine) =
    SegTree!(Engine, T, binaryFun!opTT, eT);

 
 

struct SimpleSegEngine(T, alias opTT, T eT) {
    alias DataType = T;
    alias LazyType = void;
    alias BinSearch = binSearchSimple;
    uint n, sz, lg;
    T[] d;
    @property uint length() const {return n;}
    this(uint n) {
        import std.algorithm : each;
        this.n = n;
        if (n == 0) return;
        while ((2^^lg) < n) lg++;
        sz = 2^^lg;
        d = new T[](2*sz);
        d.each!((ref x) => x = eT);
    }
    this(T[] first) {
        import std.conv : to;
        import std.algorithm : each;
        n = first.length.to!uint;
        if (n == 0) return;
        while ((2^^lg) < n) lg++;
        sz = 2^^lg;
        d = new T[](2*sz);
        d.each!((ref x) => x = eT);
        foreach (i; 0..n) {
            d[sz+i] = first[i];
        }
        foreach_reverse (i; 1..sz) {
            update(i);
        }
    }
    pragma(inline):
    void update(uint k) {
        d[k] = opTT(d[2*k], d[2*k+1]);
    }
    T single(uint k) {
        return d[k+sz];
    }
    void singleSet(uint k, T x) {
        k += sz;
        d[k] = x;
        foreach (uint i; 1..lg+1) {
            update(k>>i);
        }
    }
    T sum(uint a, uint b) {
        assert(0 <= a && a <= b && b <= n);
        T sml = eT, smr = eT;
        a += sz; b += sz;
        while (a < b) {
            if (a & 1) sml = opTT(sml, d[a++]);
            if (b & 1) smr = opTT(d[--b], smr);
            a >>= 1; b >>= 1;
        }
        return opTT(sml, smr);
    }
}

int binSearchSimple(bool rev, alias pred, TR)(TR t, int a, int b) {
    import std.traits : TemplateArgsOf;
    alias args = TemplateArgsOf!TR;
    alias opTT = args[1];
    auto x = args[2];
    with (t) {
        static if (!rev) {
             
            if (pred(x)) return a-1;
            int pos = a;
            void f(int a, int b, int l, int r, int k) {
                if (b <= l || r <= a) return;
                if (a <= l && r <= b && !pred(opTT(x, d[k]))) {
                    x = opTT(x, d[k]);
                    pos = r;
                    return;
                }
                if (l+1 == r) return;
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
                if (a <= l && r <= b && !pred(opTT(x, d[k]))) {
                    x = opTT(d[k], x);
                    pos = l-1;
                    return;
                }
                if (l+1 == r) return;
                int md = (l+r)/2;
                f(a, b, md, r, 2*k+1);
                if (pos < md) f(a, b, l, md, 2*k);
            }
            f(a, b, 0, sz, 1);
            return pos;            
        }
    }
}

 
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
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/foundation.d */
 
// module dkh.foundation;

 
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
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/container/stackpayload.d */
// module dkh.container.stackpayload;

 
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

 
/* IMPORT /home/yosupo/Programs/dunkelheit/source/dkh/scanner.d */
// module dkh.scanner;

// import dkh.container.stackpayload;

 
class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    private File f;
     
    this(File f) {
        this.f = f;
    }
    private char[512] lineBuf;
    private char[] line;
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
                    assert(succW());
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

     
    int unsafeRead(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
     
    void read(Args...)(auto ref Args args) {
        import std.exception : enforce;
        static if (args.length != 0) {
            enforce(readSingle(args[0]));
            read(args[1..$]);
        }
    }
     
    bool hasNext() {
        return succ();
    }
}


 
 

 

/*
This source code generated by dunkelheit and include dunkelheit's source code.
dunkelheit's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dunkelheit)
dunkelheit's License: MIT License(https://github.com/yosupo06/dunkelheit/blob/master/LICENSE.txt)
*/