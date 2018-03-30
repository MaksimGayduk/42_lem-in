#!/usr/bin/python
from matplotlib import pyplot as plt
from matplotlib import animation
from classes import Room, Farm

def draw_annotation(name, x, y, vpos=65, bcolor='yellow', al=0.9, z=5):
	plt.annotate(
		name, (x, y),
		xytext=(0, vpos), textcoords='offset points', ha='center', va='center',
		bbox=dict(boxstyle='round,pad=0.5', fc=bcolor, alpha=al, zorder=z),
		size='large', style='oblique'
	)

def draw_rooms(farm):
	for room in farm.rooms:
		plt.scatter(room.x, room.y, s=10000, zorder=3)
		draw_annotation(room.name, room.x, room.y)
		if (farm.rooms.index(room) == farm.start_room):
			draw_annotation("START", room.x, room.y, -65, '#52db20')
		if (farm.rooms.index(room) == farm.end_room):
			draw_annotation("END", room.x, room.y, -65, 'red')

def draw_links(farm):
	for link in farm.links:
		start = farm.get_xy_by_name(link[0])
		end = farm.get_xy_by_name(link[1])
		data = zip(start, end)
		plt.plot(data[0], data[1], zorder=1, c='b', lw=10)


def draw_ants(farm):
	colors = ['#8fce6b', '#e529e2', '#e7ed36', '#eaa52e', '#ea472e', '#29b0e5', '#962eea']
	i = 0
	l = len(colors)
	for ant in farm.ants:
		plt.scatter(ant.x, ant.y, s=5000, zorder=3, c=colors[i % l])
		draw_annotation(ant.name, ant.x, ant.y, vpos=0, bcolor='white', al=1, z=10)
		i += 1

def init():
	draw_rooms(gfarm)
	draw_links(gfarm)
	draw_ants(gfarm)

def animate(steps):
	gfarm.move_ants(steps)
	plt.clf()
	plt.grid(True, zorder=0)
	f = plt.gcf()
	draw_rooms(gfarm)
	draw_links(gfarm)
	draw_ants(gfarm)

def draw_graph(farm, steps, interval):
	global gfarm
	gfarm = farm
	fig, ax = plt.subplots(figsize=(15, 10))
	fig.canvas.set_window_title('lem-in mgayduk')
	ax.grid(True, zorder=0)
	init()

	anim = animation.FuncAnimation(fig, animate, frames=steps, init_func=init,
									blit=False, repeat=False, interval=interval)

	plt.show()
