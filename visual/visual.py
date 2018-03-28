#!/usr/bin/python
import sys
import re
import drawer as dr

def read_data():
	rooms = {}
	links = []
	for line in sys.stdin:
		if (re.match('\w+ \d+ \d+', line)):
			temp = line[:-1].split(' ')
			rooms[temp[0]] = [int(temp[1]), int(temp[2])]
		elif (re.match('^(?!L)(\w|\d)+-(\w|\d)+$', line)):
			temp = line[:-1].split('-')
			links.append((temp[0], temp[1]))
	return(rooms, links)

def main():
	rooms, links = read_data()
	if (len(rooms) == 0):
		print ("Error")
		exit (1)
	dr.draw_graph(rooms, links)

if __name__ == "__main__":
	main()