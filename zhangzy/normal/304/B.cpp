#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>\

\
u\
s\
i\
n\
g\
 \
n\
a\
m\
e\
s\
p\
a\
c\
e\
 \
s\
t\
d\
;\

\

\
s\
t\
r\
u\
c\
t\
 \
d\
a\
t\
e\
 \
{\

\
 \
 \
 \
 \
i\
n\
t\
 \
y\
y\
,\
 \
m\
m\
,\
 \
d\
d\
;\

\
}\
;\

\

\
i\
n\
t\
 \
m\
o\
n\
t\
h\
[\
]\
 \
=\
 \
{\
0\
,\
 \
3\
1\
,\
 \
2\
8\
,\
 \
3\
1\
,\
 \
3\
0\
,\
 \
3\
1\
,\
 \
3\
0\
,\
 \
3\
1\
,\
 \
3\
1\
,\
 \
3\
0\
,\
 \
3\
1\
,\
 \
3\
0\
,\
 \
3\
1\
}\
;\

\

\
i\
n\
t\
 \
p\
r\
o\
c\
e\
s\
s\
(\
s\
t\
r\
i\
n\
g\
 \
t\
m\
p\
)\
 \
{\

\
 \
 \
 \
 \
i\
n\
t\
 \
r\
e\
t\
;\

\
 \
 \
 \
 \
s\
t\
r\
i\
n\
g\
s\
t\
r\
e\
a\
m\
 \
s\
s\
;\

\
 \
 \
 \
 \
s\
s\
 \
<\
<\
 \
t\
m\
p\
,\
 \
s\
s\
 \
>\
>\
 \
r\
e\
t\
;\

\
 \
 \
 \
 \
r\
e\
t\
u\
r\
n\
 \
r\
e\
t\
;\

\
}\

\

\
b\
o\
o\
l\
 \
l\
e\
a\
p\
(\
i\
n\
t\
 \
t\
m\
p\
)\
 \
{\

\
 \
 \
 \
 \
i\
f\
 \
(\
t\
m\
p\
 \
%\
 \
4\
0\
0\
 \
=\
=\
 \
0\
 \
|\
|\
 \
(\
t\
m\
p\
 \
%\
 \
4\
 \
=\
=\
 \
0\
 \
&\
&\
 \
t\
m\
p\
 \
%\
 \
1\
0\
0\
 \
!\
=\
 \
0\
)\
)\

\
 \
 \
 \
 \
 \
 \
 \
 \
r\
e\
t\
u\
r\
n\
 \
1\
;\

\
 \
 \
 \
 \
r\
e\
t\
u\
r\
n\
 \
0\
;\

\
}\

\

\
b\
o\
o\
l\
 \
d\
i\
f\
f\
(\
d\
a\
t\
e\
 \
f\
r\
o\
m\
,\
 \
d\
a\
t\
e\
 \
t\
o\
)\
 \
{\

\
 \
 \
 \
 \
r\
e\
t\
u\
r\
n\
 \
(\
f\
r\
o\
m\
.\
y\
y\
 \
=\
=\
 \
t\
o\
.\
y\
y\
 \
&\
&\
 \
f\
r\
o\
m\
.\
d\
d\
 \
=\
=\
 \
t\
o\
.\
d\
d\
 \
&\
&\
 \
f\
r\
o\
m\
.\
m\
m\
 \
=\
=\
 \
t\
o\
.\
m\
m\
)\
;\

\
}\

\

\
i\
n\
t\
 \
m\
a\
i\
n\
(\
)\
 \
{\

\
 \
 \
 \
 \
s\
t\
r\
i\
n\
g\
 \
f\
o\
o\
,\
 \
b\
a\
r\
;\

\
 \
 \
 \
 \
i\
n\
t\
 \
r\
e\
t\
 \
=\
 \
0\
;\

\
 \
 \
 \
 \
c\
i\
n\
 \
>\
>\
 \
f\
o\
o\
 \
>\
>\
 \
b\
a\
r\
;\

\
 \
 \
 \
 \
d\
a\
t\
e\
 \
f\
r\
o\
m\
,\
 \
t\
o\
;\

\
 \
 \
 \
 \
f\
r\
o\
m\
.\
y\
y\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
f\
o\
o\
.\
s\
u\
b\
s\
t\
r\
(\
0\
,\
 \
4\
)\
)\
,\
 \
f\
r\
o\
m\
.\
m\
m\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
f\
o\
o\
.\
s\
u\
b\
s\
t\
r\
(\
5\
,\
 \
2\
)\
)\
,\
 \
f\
r\
o\
m\
.\
d\
d\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
f\
o\
o\
.\
s\
u\
b\
s\
t\
r\
(\
8\
,\
 \
2\
)\
)\
;\

\
 \
 \
 \
 \
t\
o\
.\
y\
y\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
b\
a\
r\
.\
s\
u\
b\
s\
t\
r\
(\
0\
,\
 \
4\
)\
)\
,\
 \
t\
o\
.\
m\
m\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
b\
a\
r\
.\
s\
u\
b\
s\
t\
r\
(\
5\
,\
 \
2\
)\
)\
,\
 \
t\
o\
.\
d\
d\
 \
=\
 \
p\
r\
o\
c\
e\
s\
s\
(\
b\
a\
r\
.\
s\
u\
b\
s\
t\
r\
(\
8\
,\
 \
2\
)\
)\
;\

\
 \
 \
 \
 \
i\
f\
 \
(\
f\
r\
o\
m\
.\
y\
y\
 \
>\
 \
t\
o\
.\
y\
y\
)\

\
 \
 \
 \
 \
 \
 \
 \
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
y\
y\
,\
 \
t\
o\
.\
y\
y\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
m\
m\
,\
 \
t\
o\
.\
m\
m\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
d\
d\
,\
 \
t\
o\
.\
d\
d\
)\
;\

\
 \
 \
 \
 \
e\
l\
s\
e\
 \
i\
f\
 \
(\
f\
r\
o\
m\
.\
y\
y\
 \
=\
=\
 \
t\
o\
.\
y\
y\
 \
&\
&\
 \
f\
r\
o\
m\
.\
m\
m\
 \
>\
 \
t\
o\
.\
m\
m\
)\

\
 \
 \
 \
 \
 \
 \
 \
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
y\
y\
,\
 \
t\
o\
.\
y\
y\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
m\
m\
,\
 \
t\
o\
.\
m\
m\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
d\
d\
,\
 \
t\
o\
.\
d\
d\
)\
;\

\
 \
 \
 \
 \
e\
l\
s\
e\
 \
i\
f\
 \
(\
f\
r\
o\
m\
.\
y\
y\
 \
=\
=\
 \
t\
o\
.\
y\
y\
 \
&\
&\
 \
f\
r\
o\
m\
.\
m\
m\
 \
=\
=\
 \
t\
o\
.\
m\
m\
 \
&\
&\
 \
f\
r\
o\
m\
.\
d\
d\
 \
>\
 \
t\
o\
.\
d\
d\
)\

\
 \
 \
 \
 \
 \
 \
 \
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
y\
y\
,\
 \
t\
o\
.\
y\
y\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
m\
m\
,\
 \
t\
o\
.\
m\
m\
)\
,\
 \
s\
w\
a\
p\
(\
f\
r\
o\
m\
.\
d\
d\
,\
 \
t\
o\
.\
d\
d\
)\
;\

\
 \
 \
 \
 \
w\
h\
i\
l\
e\
 \
(\
!\
d\
i\
f\
f\
(\
f\
r\
o\
m\
,\
 \
t\
o\
)\
)\
 \
{\

\
 \
 \
 \
 \
 \
 \
 \
 \
r\
e\
t\
+\
+\
,\
 \
f\
r\
o\
m\
.\
d\
d\
+\
+\
;\

\
 \
 \
 \
 \
 \
 \
 \
 \
i\
f\
 \
(\
f\
r\
o\
m\
.\
d\
d\
 \
>\
=\
 \
m\
o\
n\
t\
h\
[\
f\
r\
o\
m\
.\
m\
m\
]\
 \
+\
 \
1\
 \
+\
 \
(\
f\
r\
o\
m\
.\
m\
m\
 \
=\
=\
 \
2\
 \
&\
&\
 \
l\
e\
a\
p\
(\
f\
r\
o\
m\
.\
y\
y\
)\
)\
)\
 \
{\

\
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
f\
r\
o\
m\
.\
d\
d\
 \
=\
 \
1\
,\
 \
f\
r\
o\
m\
.\
m\
m\
+\
+\
;\

\
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
i\
f\
 \
(\
f\
r\
o\
m\
.\
m\
m\
 \
>\
 \
1\
2\
)\

\
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
 \
f\
r\
o\
m\
.\
m\
m\
 \
=\
 \
1\
,\
 \
f\
r\
o\
m\
.\
y\
y\
+\
+\
;\

\
 \
 \
 \
 \
 \
 \
 \
 \
}\

\
 \
 \
 \
 \
 \
 \
 \
/\
/\
 \
c\
o\
u\
t\
 \
<\
<\
 \
f\
r\
o\
m\
.\
d\
d\
 \
<\
<\
 \
"\
 \
"\
 \
<\
<\
 \
f\
r\
o\
m\
.\
m\
m\
 \
<\
<\
 \
"\
 \
"\
 \
<\
<\
 \
f\
r\
o\
m\
.\
y\
y\
 \
<\
<\
 \
e\
n\
d\
l\
;\

\
 \
 \
 \
 \
}\

\
 \
 \
 \
 \
c\
o\
u\
t\
 \
<\
<\
 \
r\
e\
t\
 \
<\
<\
 \
e\
n\
d\
l\
;\

\
}