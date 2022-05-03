#pragma once
#include "canvas.h"
#include "monster.h"
#include <windows.h>
#define DIM 40
#define MAXMONS 20

class Monsterworld {
	int map[DIM][DIM];
	int xmax, ymax, nmon, nmove;
	monster mon[MAXMONS];
	canvas canvas;
	int& Map(int x, int y) { return map[y][x]; }
	bool isDone() { return countItems() == 0; }
	int countItems() {
		int nitems = 0;
		for (int y = 0; y < ymax; y++)
			for (int x = 0; x < xmax; x++)
				if (Map(x, y) > 0) nitems++;
		return nitems;
	}
	void print() {
		canvas.clear();
		for (int y = 0; y < ymax; y++)
			for (int x = 0; x < xmax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nmon; i++)
			mon[i].draw(canvas);
		canvas.print("[Monster World (Basic)]");

		cerr << "전체 이동 횟수=" << nmove << endl;
		cerr << "남은 아이템 수=" << countItems() << endl;
		for (int i = 0; i < nmon; i++)
			mon[i].print();
	}
public:
	Monsterworld(int w, int h) : canvas(w, h), xmax(w), ymax(h) {
		nmon = 0;
		nmove = 0;
		for (int y = 0; y < ymax; y++)
			for (int x = 0; x < xmax; x++) Map(x, y) = 1;
	}
	~Monsterworld() { }
	void add(monster& m) {
		if (nmon < MAXMONS) mon[nmon++] = m;
	}
	void add(monster&& m) {
		if (nmon < MAXMONS) mon[nmon++] = m;
	}
	void play(int maxwalk, int wait) {
		print();
		cerr << "엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nmon; k++)
				mon[k].move(map, xmax, ymax);
			nmove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};