#!/usr/bin/python
import sys
import re
import drawer
from classes import Ant, Room, Farm

def read_data():
	
	farm = Farm()
	moves = []
	for line in sys.stdin:
		line = line.rstrip('\n')
		#Read number of ants
		if (re.match('^\d+$', line)):
			farm.ant_num = int(line)
		#Execute ##start/##end instruction
		elif (line == "##start" or line == "##end"):
			temp = line.strip('#')
			line = sys.stdin.next().strip('\n')
			farm.add_room(line, temp)
			continue
		#Room parameter (smth like 'A 2 3')
		elif (re.match('\w+ \d+ \d+', line)):
			farm.add_room(line, "common")
		#Link between rooms (smth like 'A-B')
		elif (re.match('^(?!L)(\w|\d)+-(\w|\d)+$', line)):
			farm.add_link(line)
		#Moves of ants (smth like 'L3-B')
		elif (re.match('^L+', line)):
			moves.append(line.strip())
	return(farm, moves)

def check_interval(interval):
	try:
		interval = int(interval)
	except:
		print ("Error: invalid interval value")
		exit (1)
	if (interval <= 0):
		print ("Error: invalid interval value")
		exit (1)

def main():
	farm, moves = read_data()
	interval = sys.argv[1]
	check_interval(interval)
	farm.create_ants()
	drawer.draw_graph(farm, moves, int(sys.argv[1]))
if __name__ == "__main__":
	main()