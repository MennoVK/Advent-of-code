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
        score += (lose + scissorsC)
    elif i == "A Y":
        score += (tie + rockA)
    elif i == "A Z":
        score += (win + paperB)
    elif i == "B X":
        score += (lose + rockA)
    elif i == "B Y":
        score += (tie + paperB)
    elif i == "B Z":
        score += (win + scissorsC)
    elif i == "C X":
        score += (lose + paperB)
    elif i == "C Y":
        score += (tie + scissorsC)
    elif i == "C Z":
        score += (win + rockA)
print(score)