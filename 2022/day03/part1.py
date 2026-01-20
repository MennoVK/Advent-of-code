f = open("input.txt", "r")

def checkRucksack():
    total_amount = 0
    for i in f:
        i = i.strip()
        x = slice(0, (int(len(i)/2)))
        y = slice((int(len(i) / 2)), (int(len(i))))
        double = None
        first_part = i[x]
        second_part = i[y]
        for i in first_part:
            for j in second_part:
                if i == j:
                    double = i
        incoming_amount = getPriority(double)
        total_amount += incoming_amount
    print(total_amount)

def getPriority(letter):
    alfa = "abcdefghijklmnopqrstuvwxyz"
    for idx, i in enumerate(alfa):
        if letter.lower() == i:
            if letter.islower():
                amount_lower = (idx+1)
                return(amount_lower)
            else:
                amount_upper = (idx + 1 + 26)
                return(amount_upper)

checkRucksack()