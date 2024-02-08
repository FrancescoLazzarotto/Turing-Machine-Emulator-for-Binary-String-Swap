import time

while True:
    try:
        n_cin = int(input("Enter the number of states: "))
        if n_cin >= 1:
            break
        else:
            print("Enter a number greater than or equal to 1.")
    except ValueError:
        print("Enter a valid number.")

pos = []
for i in range(n_cin):
    while True:
        try:
            pos_input = int(input(f"Enter the number of inputs for state {i}: "))
            if pos_input >= 1:
                pos.append(pos_input)
                break
            else:
                print("Enter a number greater than or equal to 1.")
        except ValueError:
            print("Enter a valid number.")

print("\nEnter commands (state-read-write-position):")
comandi = [input() for _ in range(sum(pos))]

print("\nEnter the string between two #:")
str_input = input().split("#")[1]

print(f"\n{str_input}\n")

while True:
    try:
        cella = int(input(f"Enter the starting cell number (between 1 and {len(str_input)}): "))
        if 1 <= cella <= len(str_input):
            break
        else:
            print(f"Enter a number between 1 and {len(str_input)}.")
    except ValueError:
        print("Enter a valid number.")

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
