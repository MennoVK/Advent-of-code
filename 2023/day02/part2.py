sum_of_power = 0
min_red = 0
min_green = 0
min_blue = 0
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
            if 'red' in color:
                if min_red < int(color[0] + color[1]):
                    min_red = int(color[0] + color[1])
            if 'green' in color:
                if min_green < int(color[0] + color[1]):
                    min_green = int(color[0] + color[1])
            if 'blue' in color:
                if min_blue < int(color[0] + color[1]):
                    min_blue = int(color[0] + color[1])
    sum_of_power += min_red * min_green * min_blue
    min_red = 0
    min_green = 0
    min_blue = 0


print(sum_of_power)
