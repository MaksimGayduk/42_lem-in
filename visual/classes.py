#!/usr/bin/python

class Room:
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y

class Farm:
    def __init__(self):
        self.ants = 0
        self.rooms = []
        self.start_room = None
        self.end_room = None
        self.i = 0
        self.room_index = {}
        self.links = []
    
    def add_room(self, line, status):
        name, x, y = line.split(' ')
        self.rooms.append(Room(name, int(x), int(y)))
        self.room_index[name] = self.i
        if (status == "start"):
            self.start_room = self.i
        if (status == "end"):
            self.end_room = self.i
        self.i += 1

    def add_link(self, line):
        temp = line.split('-')
        self.links.append((temp[0], temp[1]))
