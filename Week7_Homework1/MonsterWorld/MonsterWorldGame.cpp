#include "Monsterworld.h"
#include <time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	Monsterworld game(w, h);
	monster m("����", "��", rand() % w, rand() % h);
	game.add(m);
	game.add(monster("������", "��", rand() % w, rand() % h));
	game.add(monster("���״�", "��", rand() % w, rand() % h));
	game.add(monster("��Ʈ", "��", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------���� ����------------------\n");
}