text = []
startttt = "\\begin{thebibliography}{99}"
endddddd = "\\end{thebibliography}"
while True:
    s = input()
    if s == startttt:
        break
    text.append(s)
items = []
while True:
    s = input()
    if s == endddddd:
        break
    items.append(s)

text = ' '.join(text)
cites = [i.split('}')[0] for i in text.split('{')[1:]]

ordered_items = [i.split('}')[0][9:] for i in items]

if ordered_items == cites:
    print('Correct')
    exit()
print('Incorrect')
print(startttt)
for i in cites:
    print(items[ordered_items.index(i)])
print(endddddd)