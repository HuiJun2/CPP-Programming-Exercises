#include "Monsterworld.h"
#include <time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	Monsterworld game(w, h);
	monster m("몬스터", "※", rand() % w, rand() % h);
	game.add(m);
	game.add(monster("도깨비", "§", rand() % w, rand() % h));
	game.add(monster("별그대", "★", rand() % w, rand() % h));
	game.add(monster("고스트", "♥", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------게임 종료------------------\n");
}