#include "file.h"

File creerFile() {
	File f;
	f.premier = NULL;
	f.dernier = NULL;
	return f;
}

int fileVide(File f) {
	return f.premier == NULL;
}
/* LISTE DOUBLEMENT CHAIN2E OHLALA */
/* Photo sur tel */

File enfile(File f, Paire p) {
	Element *elt = malloc(sizeof(Element));
	if (!elt) exit(EXIT_FAILURE);
	
	elt->p = p;
	elt->pred = NULL;
	elt->suiv = f.premier;
	if (fileVide(f))
		f.premier = f.dernier = elt;
	else {
		f.premier->pred = elt;
		f.premier = elt;
	}
	
	return f;
}
// f est modifiée dans la fonction
Paire defile(File *f) {
	Paire p;
	if (fileVide(*f)) 	exit(EXIT_FAILURE);
	
	p = f->dernier->p;
	if(f->premier == f->dernier) { //si un seul element dans la file
		free(f->dernier);
		*f = creerFile();
	}
	else {
		f->dernier = f->dernier->pred; //ok
		free(f->dernier->suiv);
		f->dernier->suiv = NULL;
	}
	return p;
}

void afficheFile(File f) {
	Element *l = f.premier;
	while(l != NULL) {
		printf("id: %d, prio: %d\n", l->p.id, l->p.prio);
		l = l->suiv;
	}
}

File libereFile(File f) {
	while(!fileVide(f)) { 
		defile(&f);
	}
	return creerFile();
}
