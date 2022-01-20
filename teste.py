f = open("teste.txt", "r")
for line in f:
    x, y = (int(s) for s in line.split())
    print(str(x+1) + " " + str(y+1))