time = []
distance = []
ways_to_win = 1

def clean_lines(input):
    for idx, line in enumerate(input):
        line = line.replace('Time:', '')
        line = line.replace('Distance:', '')
        line = line.replace('\n', '')
        line = line.replace(' ', '')
        line = line.split(' ')
        for character in line:
            if character.isdigit():
                if idx == 0:
                    time.append(character)
                if idx == 1:
                    distance.append(character)


with open("input.txt") as input:
    clean_lines(input)
    for idx, i in enumerate(time):
        ways_to_win_game = 0
        for j in range(int(i)+1):
            if (j * (int(i) - j)) > int(distance[idx]):
                ways_to_win_game +=1
        ways_to_win *= ways_to_win_game

print(ways_to_win)