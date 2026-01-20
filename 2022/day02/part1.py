rockA = 1
paperB = 2
scissorsC = 3

lose = 0
tie = 3
win = 6

# RockX
# PaperY
# ScissorsZ

score = 0

f = open("input.txt", "r")

for i in f:
    i = i.strip()
    if i == "A X":
        score += (tie + rockA)
    elif i == "A Y":
        score += (win + paperB)
    elif i == "A Z":
        score += (lose + scissorsC)
    elif i == "B X":
        score += (lose + rockA)
    elif i == "B Y":
        score += (tie + paperB)
    elif i == "B Z":
        score += (win + scissorsC)
    elif i == "C X":
        score += (win + rockA)
    elif i == "C Y":
        score += (lose + paperB)
    elif i == "C Z":
        score += (tie + scissorsC)
print(score)