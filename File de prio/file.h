#include <stdlib.h>
#include <stdio.h>

#ifndef KA
#define KA // Pour qu'il vérifie si les structures ont pas déja été créée
// Pcq si on reprend file.h dans file prio faut pas qu'il réinitialise 
//Pour inclure qu'une seule fois un fichier

struct paire {
	int id;
	int prio;
};
typedef struct paire Paire;

struct element {
	Paire p;
	struct element *suiv, *pred;
};
typedef struct element Element;

struct file {
	struct element *premier, *dernier;
};
typedef struct file File;

#endif

File creerFile();
int fileVide(File);
File enfile(File, Paire);
Paire defile(File*);
void afficheFile(File);
File libereFile(File); 
