'''
gestione file:

    a) creare una lista di 100 numeri casuali da 1 a 1000
    b) scrivere la lista in un file CSV (;) chiamato "numeri.txt"
    c) leggere il file "numeri.txt" e creare altri due file "pari.txt" e "dispari.txt"

'''
import random

sep = ";"

a = list(range(100))
for i in range(len(a)):
    a[i] = random.randint(1, 1000)

with open("numeri.txt", "w") as f:
    for i in a:
        f.write(str(i))
        f.write(sep)

with open("pari.txt", "w") as c:
    pass
with open("dispari.txt", "w") as c:
    pass

with open("numeri.txt", "r") as f:
    l = f.read().split(sep)
    for i in l:
        if i == '': break
        if int(i) % 2 == 0:
            with open("pari.txt", "a") as p:
                p.write(i)
                p.write(sep)
        else:
            with open("dispari.txt", "a") as d:
                d.write(i)
                d.write(sep)