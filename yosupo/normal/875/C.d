/+ dub.sdl:
    name "C"
    dependency "dcomp" version=">=0.7.3"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;
// import dcomp.twosat;

int main() {
    Scanner sc = new Scanner(stdin);
    int n, m;
    sc.read(n, m);
    auto sat = TwoSat(m);
    int[][] g = new int[][n];
    foreach (i; 0..n) {
        int k;
        sc.read(k);
        g[i] = new int[k];
        foreach (j; 0..k) {
            sc.read(g[i][j]);
        }
        g[i][] -= 1;
    }

    foreach (i; 0..n-1) {
        //g[i], g[i+1]
        int mi = min(g[i].length, g[i+1].length).to!int;
        bool dif = false;
        foreach (j; 0..mi) {
            int x = g[i][j];
            int y = g[i+1][j];
            if (x != y) {
                dif = true;
                if (x > y) {
                    //only true, false
                    sat.addCond(x, true, y, false);
                    sat.addCond(x, false, y, false);
                    sat.addCond(x, true, y, true);
                } else {
                    //only ~(false, true)
                    sat.addCond(x, true, y, false);
                }
                break;
            }
        }
        if (!dif) {
            if (g[i].length > g[i+1].length) {
                writeln("No");
                return 0;
            }
        }
    }
    if (!sat.exec()) {
        writeln("No");
        return 0;
    }
    auto res = sat.res.enumerate.filter!"a[1]==true".array;
    writeln("Yes");
    writeln(res.length);
    writeln(res.map!"a[0]+1".map!(to!string).join(" "));
    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/twosat.d */
 
// module dcomp.twosat;

// import dcomp.graph.scc;
// import dcomp.array;

 
struct TwoSat {
     
    bool[] res;

    struct Edge {int to;}
    FastAppender!(Edge[])[] g;

     
    void addCond(int a, bool aExp, int b, bool bExp) {
        g[2*a+(aExp?0:1)] ~= Edge(2*b+(bExp?1:0));
        g[2*b+(bExp?0:1)] ~= Edge(2*a+(aExp?1:0));
    }

     
    bool exec() {
        import std.array : array;
        import std.algorithm : map;
        import std.conv : to;
        int n = res.length.to!int;
        auto sccInfo = scc(g.map!(v => v.data).array);
        for (int i = 0; i < n; i++) {
            if (sccInfo.id[2*i] == sccInfo.id[2*i+1]) return false;
            res[i] = sccInfo.id[2*i] < sccInfo.id[2*i+1];
        }
        return true;
    }
     
    this(int n) {
        res = new bool[n];
        g = new FastAppender!(Edge[])[](2*n);
    }
}

 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/graph/scc.d */
// module dcomp.graph.scc;

// import dcomp.array;
// import dcomp.graph.primitive;
// import dcomp.container.deque;

 
struct SCCInfo {
    int[] id;  
    int[][] groups;  
     
    int[] group(int i) {
        return groups[id[i]];
    }    
    this(int n) {
        id = new int[n];
    }
}

 
SCCInfo scc(T)(T g) {
    import std.range;
    import std.algorithm : each, map, min, reverse;
    import std.conv : to;
    int n = g.length.to!int;
    auto sccInfo = SCCInfo(n);
    with (sccInfo) {
        bool[] inS = new bool[n];
        int[] low = new int[n], ord = new int[n]; ord[] = -1;
        int time = 0;
        Deque!int st;
        int bufC = 0;
        FastAppender!(int[]) buf; buf.reserve(n);
        FastAppender!(int[][]) gBuf;
        void dfs(int v) {
            low[v] = ord[v] = time++;
            st.insertBack(v);
            inS[v] = true;
            foreach (e; g[v]) {
                if (ord[e.to] == -1) {
                    dfs(e.to);
                    low[v] = min(low[v], low[e.to]);
                } else if (inS[e.to]) {
                    low[v] = min(low[v], ord[e.to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = st.back; st.removeBack;
                    buf ~= u;
                    if (u == v) break;
                }
                auto gr = buf.data[bufC..$];
                bufC = buf.length.to!int;
                gr.each!(x => inS[x] = false);
                gBuf ~= gr;
            }
        }
        foreach (i; 0..n) {
            if (ord[i] == -1) dfs(i);
        }
        groups = gBuf.data;
        reverse(groups);
        groups.each!((i, v) => v.each!(x => id[x] = i.to!int));
    }
    return sccInfo;
}

 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/container/deque.d */
// module dcomp.container.deque;

struct DequePayload(T) {
    import core.exception : RangeError;
    import core.memory : GC;
    import std.range : ElementType, isInputRange;
    import std.traits : isImplicitlyConvertible;
    T *d;
    size_t st, length, cap;
    @property bool empty() const { return length == 0; }
    alias opDollar = length;
    ref inout(T) opIndex(size_t i) inout {
        version(assert) if (length <= i) throw new RangeError();
        return d[(st+i >= cap) ? (st+i-cap) : st+i];
    }
    private void expand() {
        import std.algorithm : max;
        assert(length == cap);
        auto nc = max(size_t(4), 2*cap);
        T* nd = cast(T*)GC.malloc(nc * T.sizeof);
        foreach (i; 0..length) {
            nd[i] = this[i];
        }
        d = nd; st = 0; cap = nc;
    }
    void clear() {
        st = length = 0;
    }
    void insertFront(T v) {
        if (length == cap) expand();
        if (st == 0) st += cap;
        st--; length++;
        this[0] = v; 
    }
    void insertBack(T v) {
        if (length == cap) expand();
        length++;
        this[length-1] = v; 
    }
    void removeFront() {
        assert(!empty, "Deque.removeFront: Deque is empty");        
        st++; length--;
        if (st == cap) st = 0;
    }
    void removeBack() {
        assert(!empty, "Deque.removeBack: Deque is empty");        
        length--;
    }
    
    ref inout(T) front() inout { return this[0]; }
    ref inout(T) back() inout { return this[$-1]; }
    Range opSlice() {return Range(&this, 0, length); }
    
    alias Range = RangeT!(DequePayload!T);
    alias ConstRange = RangeT!(const DequePayload!T);
    alias ImmutableRange = RangeT!(immutable DequePayload!T);

    static struct RangeT(A) {
        import std.traits : CopyTypeQualifiers;
        alias E = CopyTypeQualifiers!(A, T);
        A *p;
        size_t a, b;
        @property bool empty() const { return b <= a; }
        @property size_t length() const { return b-a; }
        @property RangeT save() { return RangeT(p, a, b); }
        @property RangeT!(const A) save() const {
            return typeof(return)(p, a, b);
        }
        alias opDollar = length;
        @property ref inout(E) front() inout { return (*p)[a]; }
        @property ref inout(E) back() inout { return (*p)[b-1]; }
        void popFront() {
            version(assert) if (empty) throw new RangeError();
            a++;
        }
        void popBack() {
            version(assert) if (empty) throw new RangeError();
            b--;
        }
        ref inout(E) opIndex(size_t i) inout { return (*p)[i]; }
        RangeT opSlice() { return this.save; }
        RangeT opSlice(size_t i, size_t j) {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
        RangeT!(const A) opSlice() const { return this.save; }
        RangeT!(const A) opSlice(size_t i, size_t j) const {
            version(assert) if (i > j || a + j > b) throw new RangeError();
            return typeof(return)(p, a+i, a+j);
        }
    }
}


 
struct Deque(T, bool mayNull = true) {
    import core.exception : RangeError;
    import core.memory : GC;
    import std.range : ElementType, isInputRange;
    import std.traits : isImplicitlyConvertible;

    alias Payload = DequePayload!T;
    alias Range = Payload.Range;
    alias ConstRange = Payload.ConstRange;
    alias ImmutableRange = Payload.ImmutableRange;
    
    Payload* p;
    private void I() { if (mayNull && !p) p = new Payload(); }
    private void C() const {
        version(assert) if (mayNull && !p) throw new RangeError();
    }
    static if (!mayNull) {
        @disable this();
    }
     
    private this(Payload* p) {
        this.p = p;
    }
    this(U)(U[] values...) if (isImplicitlyConvertible!(U, T)) {
        p = new Payload();
        foreach (v; values) {
            insertBack(v);
        }
    }
     
    this(Range)(Range r)
    if (isInputRange!Range &&
    isImplicitlyConvertible!(ElementType!Range, T) &&
    !is(Range == T[])) {
        p = new Payload();
        foreach (v; r) {
            insertBack(v);
        }
    }
    static Deque make() { return Deque(new Payload()); }
    @property bool havePayload() const { return (!mayNull || p); }
     
    @property bool empty() const { return (!havePayload || p.empty); }
     
    @property size_t length() const { return (havePayload ? p.length : 0); }
     
    alias opDollar = length;
    ref inout(T) opIndex(size_t i) inout {C; return (*p)[i]; }
     
    ref inout(T) front() inout {C; return (*p)[0]; }
     
    ref inout(T) back() inout {C; return (*p)[$-1]; }
    void clear() { if (p) p.clear(); }
     
    void insertFront(T v) {I; p.insertFront(v); }
     
    void insertBack(T v) {I; p.insertBack(v); }
     
    alias stableInsertBack = insertBack;
     
    void removeFront() {C; p.removeFront(); }
     
    void removeBack() {C; p.removeBack(); }
     
    Range opSlice() {I; return Range(p, 0, length); }
}

 
 

 

 

 

 

 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

// import dcomp.array;

 
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
                FastAppender!(E[]) buf;
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


 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/graph/primitive.d */
// module dcomp.graph.primitive;

 

import std.range : ElementType;
alias EdgeType(R) = ElementType!(ElementType!R);
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
version (X86) static if (__VERSION__ < 2071) {
    import core.bitop : bsf, bsr, popcnt;
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/array.d */
// module dcomp.array;

 
T[N] fixed(T, size_t N)(T[N] a) {return a;}

 
 

 
struct FastAppender(A, size_t MIN = 4) {
    import std.algorithm : max;
    import std.conv;
    import std.range.primitives : ElementEncodingType;
    import core.stdc.string : memcpy;

    private alias T = ElementEncodingType!A;
    private T* _data;
    private uint len, cap;
     
    @property size_t length() const {return len;}
    bool empty() const { return len == 0; }
     
    void reserve(size_t nlen) {
        import core.memory : GC;
        if (nlen <= cap) return;
        
        void* nx = GC.malloc(nlen * T.sizeof);

        cap = nlen.to!uint;
        if (len) memcpy(nx, _data, len * T.sizeof);
        _data = cast(T*)(nx);
    }
    void free() {
        import core.memory : GC;
        GC.free(_data);
    }
     
    void opOpAssign(string op : "~")(T item) {
        if (len == cap) {
            reserve(max(MIN, cap*2));
        }
        _data[len++] = item;
    }
     
    void insertBack(T item) {
        this ~= item;
    }
     
    void removeBack() {
        len--;
    }
     
    void clear() {
        len = 0;
    }
    ref inout(T) back() inout { assert(len); return _data[len-1]; }
    ref inout(T) opIndex(size_t i) inout { return _data[i]; }
     
    T[] data() {
        return (_data) ? _data[0..len] : null;
    }
}

 
 

/*
This source code generated by dcomp and include dcomp's source code.
dcomp's Copyright: Copyright (c) 2016- Kohei Morita. (https://github.com/yosupo06/dcomp)
dcomp's License: MIT License(https://github.com/yosupo06/dcomp/blob/master/LICENSE.txt)
*/