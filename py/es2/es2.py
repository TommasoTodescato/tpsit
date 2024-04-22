'''
creare un file CSV costituito da NOME, COGNOME, TELEFONO
ordinato in base a nome, cognome se sono uguali, e telefono se sono uguali
'''

nome = input("Inserisci il nome: ")
cognome = input("Inserisci il cognome: ")
tel = input("Inserisci il numero di telefono: ")

try:
    with open("rubrica.txt", "r") as f:
        p = list(f.read().strip().split("\n"))
        p.append(f"{nome};{cognome};{tel}")
        p.sort()

    with open("rubrica.txt", "w") as f:
        for i in p:
            f.write(f"{i}\n")
    
except:
    with open("rubrica.txt", "w") as f:
        print("file creato, riesegui")