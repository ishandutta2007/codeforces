#!/usr/bin/env python3

import sys
sys.setrecursionlimit(65536)

vars, reserved = {}, set()
rules, irules, R = [], {}, 0



def wwj():
	n__ = 0
	def dak():
		nonlocal n__
		while 'a' + str(n__) in reserved:
			n__ += 1
		n__ += 1
		return 'a' + str(n__ - 1)
	return dak

next_var = wwj()

L = int(input())
for i in range(L):
	k, v = input().split('=')
	if v.isidentifier():
		if v in vars:
			vars[k] = vars[v]
		else:
			vars[k] = v
			reserved.add(v)
	else:
		j = [i for i in range(len(v)) if not v[i].isalnum()][0]
		v1, op, v2 = vars.get(v[:j], v[:j]), v[j], vars.get(v[j + 1:], v[j + 1:])
		r = (op, v1, v2)
		if r not in irules:
			rules.append(r)
			irules[r] = R
			R += 1
		vars[k] = irules[r]

if vars.get('res', 'res') == 'res':
	print(0)
	exit()

resolve = {}
output = []

def interprete(v, name = None):
	if isinstance(v, str):
		return v
	if v in resolve:
		return resolve[v]
	op, v1, v2 = rules[v]
	u1, u2 = interprete(v1), interprete(v2)
	if name is None:
		name = next_var()
	resolve[v] = name
	output.append('{}={}{}{}'.format(name, u1, op, u2))
	return name

R = interprete(vars['res'], 'res')
if R != 'res':
	output.append('res={}'.format(R))

print(len(output), '\n'.join(output), sep = '\n')