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
        self.ants_copy = []
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
    
    def move_ants(self, steps):
        for step in steps:
            i = step[0]
            x = step[1]
            y = step[2]
            self.ants[i].x = x
            self.ants[i].y = y
    
    def __get_substeps(self, move):
        move = move.strip('L')
        move = move.split('-')
        i = int(move[0]) - 1
        curr_room = (self.ants_copy[i].x, self.ants_copy[i].y)
        next_room = self.get_xy_by_name(move[1])
        temp = []
        s = 10
        dx = (next_room[0] - curr_room[0]) / float(s)
        dy = (next_room[1] - curr_room[1]) / float(s)
        for x in range(s + 1):
            step = []
            step.append(i)
            step.append(curr_room[0] + dx * x)
            step.append(curr_room[1] + dy * x)
            temp.append(step)
        self.ants_copy[i].x, self.ants_copy[i].y = next_room
        return (temp)

    def compute_steps(self, moves):
        steps = []
        moves = moves.split(' ')
        steps = [self.__get_substeps(move) for move in moves]
        res = []
        for i in range(len(steps[0])):
            temp = []
            for step in steps:
                temp.append(step[i])
            res.append(tuple(temp))
        return (res)