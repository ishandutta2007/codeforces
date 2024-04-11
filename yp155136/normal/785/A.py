# -*- coding: utf-8 -*-
"""
Created on Wed Mar 15 23:22:04 2017

@author: Anan
"""

n = int(input())
#"Tetrahedron" (without quotes), if the i-th polyhedron in Anton's collection is a tetrahedron.
#"Cube" (without quotes), if the i-th polyhedron in Anton's collection is a cube.
#"Octahedron" (without quotes), if the i-th polyhedron in Anton's collection is an octahedron.
#"Dodecahedron" (without quotes), if the i-th polyhedron in Anton's collection is a dodecahedron.
#"Icosahedron" (without quotes), if the i-th polyhedron in Anton's collection is an icosahedron.

d={"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}
ans = 0
for i in range(0,n) :
    s=input()
    ans += d[s];
    
print(ans)