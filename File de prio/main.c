#include "file.h"
#include "prio.h"

int main() {
	File f = creerFile();
	Paire p = {5, 0};
	f = enfile(f, p);
	p.id = 6; p.prio = 2; f = enfile(f, p);
	p.id = 3; p.prio = 0; f = enfile(f, p);
	p.id = 7; p.prio = 0; f = enfile(f, p);
	
	afficheFile(f);
	defile(&f);
	printf("Defile:\n");
	afficheFile(f);
	
	f = libereFile(f);
	return 0;
}
