#!/usr/bin/python
import sys
import re
import drawer as dr
from classes import Room



def read_data():
	rooms = {}
	links = []
	moves = []
	Rooms = []

	for line in sys.stdin:
		line = line.rstrip('\n')

		if (re.match('^\d+$', line)):
			ants = int(line)
		#Execute ##start instruction
		elif (line == "##start"):
			line = sys.stdin.next().strip('\n')
			name, x, y = line.split(' ')
			rooms[name] = [int(x), int(y), 's']
			continue
		
		#Execute ##end instruction
		elif (line == "##end"):
			line = sys.stdin.next().strip('\n')
			name, x, y = line.split(' ')
			rooms[name] = [int(x), int(y), 'e']
			continue

		#Room parameter (smth like A 2 3)
		elif (re.match('\w+ \d+ \d+', line)):
			name, x, y = line.split(' ')
			rooms[name] = [int(x), int(y), 'c']
			Rooms.append(Room(name, int(x), int(y), 'c'))
		
		#Link between rooms (smth like A-B)
		elif (re.match('^(?!L)(\w|\d)+-(\w|\d)+$', line)):
			temp = line.split('-')
			links.append((temp[0], temp[1]))

		elif (re.match('^L+', line)):
			moves.append(line)
		print (line)

	for room in Rooms:
		print (room.name)
	return(ants, rooms, links, moves)

def main():
	ants, rooms, links, moves = read_data()
	# if (len(rooms) == 0):
	# 	print ("Error")
	# 	exit (1)
	#dr.draw_graph(rooms, links)
	print (ants)
	print (rooms)
	print (links)
	print (moves)

if __name__ == "__main__":
	main()