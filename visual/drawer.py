#!/usr/bin/python
from matplotlib import pyplot as plt

def draw_graph(rooms, links):
	fig = plt.figure(figsize=(15, 10))
	fig.canvas.set_window_title('lem-in mgayduk')
	ax = fig.add_subplot(111)
	ax.grid(True, zorder=0)

	for room in rooms.items():
		a = plt.scatter(room[1][0], room[1][1], s=10000, zorder=3)
		print (type(a))
		plt.annotate(room[0], (room[1][0], room[1][1]),
		xytext=(0, 65), xycoords='data', textcoords='offset points', ha='center', va='center',
		bbox=dict(boxstyle='round,pad=0.5', fc='yellow', alpha=0.9, zorder=1),
		size='large', style='oblique')
		if (room[1][2] == 's'):
				plt.annotate('START', (room[1][0], room[1][1]),
				xytext=(0, -65), xycoords='data', textcoords='offset points', ha='center', va='center',
				bbox=dict(boxstyle='round,pad=0.5', fc='#52db20', alpha=1, zorder=1),
				size='large', style='oblique')
		if (room[1][2] == 'e'):
				plt.annotate('END', (room[1][0], room[1][1]),
				xytext=(0, -65), xycoords='data', textcoords='offset points', ha='center', va='center',
				bbox=dict(boxstyle='round,pad=0.5', fc='red', alpha=1, zorder=1),
				size='large', style='oblique')
	
	for link in links:
		z = zip(rooms[link[0]], rooms[link[1]])
		plt.plot(z[0], z[1], zorder=1, c='b', lw=10)

	plt.show()


if __name__ == "__main__":
	rooms = {'start': [0, 2], 'bathroom': [2, 3], 'end': [4, 2], 'hall': [1, 1], 'kitchen': [3, 1]}
	links = [('zero', 'two'), ('zero', 'three'), ('two', 'three'), ('three', 'one'), ('two', 'one')]
	draw_graph(rooms, links)