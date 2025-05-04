import time

while True:
    try:
        n_cin = int(input("Inserisci numeri di stato: "))
        if n_cin >= 1:
            break
        else:
            print("Inserisci un numero maggiore o uguale a 1.")
    except ValueError:
        print("Inserisci un numero valido.")

pos = []
for i in range(n_cin):
    while True:
        try:
            pos_input = int(input(f"Inserisci i numeri di input per lo stato {i}: "))
            if pos_input >= 1:
                pos.append(pos_input)
                break
            else:
                print("Inserisci un numero maggiore o uguale a 1.")
        except ValueError:
            print("Inserisci un numero valido")

print("\nInserisci comando(stato-lettura-scrittura-posizione):")
comandi = [input() for _ in range(sum(pos))]

print("\nInserisci la stringa fra due #:")
str_input = input().split("#")[1]

print(f"\n{str_input}\n")

while True:
    try:
        cella = int(input(f"Inserisci il numero di cella di inizio (fra 1 e{len(str_input)}): "))
        if 1 <= cella <= len(str_input):
            break
        else:
            print(f"Inserisci un numero (fra 1 e {len(str_input)}.")
    except ValueError:
        print("Inserisci un numero valido.")

print(f"{str_input}")
print(" " * (cella - 1) + "|")

while True:
    tot = sum(pos[:stato + 1])

    for i in range(pos[stato], tot + 1):
        if comandi[tot - i][2] == str_input[cella - 1]:
            str_input = str_input[:cella - 1] + comandi[tot - i][4] + str_input[cella:]
            print("\033c", end="")
            print(f"{str_input}")
            print(" " * (cella - 1) + "|")
            if comandi[tot - i][6] == 'D':
                cella += 1
                stato = int(comandi[tot - i][0])
                break
            elif comandi[tot - i][6] == 'S':
                cella -= 1
                stato = int(comandi[tot - i][0])
                break
            else:
                break

    time.sleep(0.25)
print("\033c", end="")
print(f"{str_input}")
print(" " * (cella - 1) + "|")
print("\n")
