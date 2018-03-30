#!/usr/bin/python

class Room:
    def __init__(self, name, x, y):
        self.name = name
        self.x = x
        self.y = y
    
class Ant(Room):
    pass

class Farm:
    def __init__(self):
        self.ant_num = 0
        self.ants = []
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

    def get_xy_by_name(self, name):
        index = self.room_index[name]
        x = self.rooms[index].x
        y = self.rooms[index].y
        return (x, y)

    def create_ants(self):
        for i in range(1, self.ant_num + 1):
            ant = Ant(str(i), self.rooms[self.start_room].x, \
                        self.rooms[self.start_room].y)
            self.ants.append(ant)
    
    def move_ants(moves):
        moves = moves.split(' ')
        for move in moves:
            move = move.strip('L')
            move = move.split('-')
            i = int(move[0]) - 1
            room_name = move[1]
            self.ants[i].x, self.ants[i].y = get_xy_by_name(room_name) 

