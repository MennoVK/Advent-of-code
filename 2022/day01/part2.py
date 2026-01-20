variabele = 0;
listPartTotal = [];
top3List = []

f = open("input.txt", "r")

for x in f:
    if x in ['\n', '\r\n']:
          listPartTotal.append(variabele)
          variabele = 0;
          continue
    variabele += int(x)

top3List.append(max(listPartTotal))
listPartTotal.remove(max(listPartTotal))
top3List.append(max(listPartTotal))
listPartTotal.remove(max(listPartTotal))
top3List.append(max(listPartTotal))

print(sum(top3List))