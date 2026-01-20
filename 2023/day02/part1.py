id_sum = 0
max_red = 12
max_green = 13
max_blue = 14
possible = True

input = open('input.txt', 'r')

for idx, line in enumerate(input):
    line = line.replace(f'Game {idx + 1}: ', '')
    line = line.replace(', ', ',')
    line = line.replace('; ', ';')
    games = line.split(';')
    for game in games:
        colors = game.split(',')
        for color in colors:
            if possible and 'red' in color:
                if int(color[0] + color[1]) > max_red:
                    possible = False
            if possible and 'green' in color:
                if int(color[0] + color[1]) > max_green:
                    possible = False
            if possible and 'blue' in color:
                if int(color[0] + color[1]) > max_blue:
                    possible = False
    if(possible):
        id_sum += (idx + 1)
    possible = True

print(id_sum)