with open("input.txt", "r") as f:
    lines = f.readline()

def loopTroughString():
    letters = []
    for idx,i in enumerate(lines):
        if len(letters) == len(set(letters)):
            if len(letters) > 3:
                print(idx)
                break
        letters.append(lines[idx])
        if len(letters) > 4:
            letters.pop(0)

loopTroughString()