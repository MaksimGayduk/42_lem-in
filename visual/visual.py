#!/usr/bin/python
import sys
import re
import drawer as dr

def read_data():
	rooms = {}
	links = []
	for line in sys.stdin:
		line = line.rstrip('\n')
		if (line == "##start\n"):
			line = sys.stdin.next()
			continue

		#Room parameter (smth like A 2 3)
		if (re.match('\w+ \d+ \d+', line)):
			temp = line.split(' ')
			rooms[temp[0]] = [int(temp[1]), int(temp[2])]
		
		#Link between rooms (smth like A-B)
		elif (re.match('^(?!L)(\w|\d)+-(\w|\d)+$', line)):
			temp = line.split('-')
			links.append((temp[0], temp[1]))
		print (line)
	return(rooms, links)

def main():
	rooms, links = read_data()
	if (len(rooms) == 0):
		print ("Error")
		exit (1)
	dr.draw_graph(rooms, links)

if __name__ == "__main__":
	main()