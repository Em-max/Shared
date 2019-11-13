#include "prio.h"

FilePrio creerFilePrio() {
	FilePrio f;
	f = malloc(K*sizeof(File)); // Tableau de K files (K = nbr de prios)
	if (!f)		exit(EXIT_FAILURE);
	
	for (int i = 0; i < K; i++)
		f[i] = creerFile();
	
	return f;
}


int fileVidePrio(FilePrio f) {
	for (int i = 0; i < K; i++) {
		if (!fileVide(f[i])) // si file i pas vide
			return 0;
	}
	return 1;
}

FilePrio enfilePrio(FilePrio f, Paire p){
	f[p.prio] = enfile(f[p.prio], p);
	return f;
}

Paire defilePrio(FilePrio f){ // Plus besoin de passer par adresse pcq FilePrio est un tableau
	Paire p;
	int i;
	if(fileVidePrio(f)) {
		fprintf(stderr, "Erreur : defile dans file de prio vide\n");
		exit(EXIT_FAILURE);
	}
	
	i = K-1;
	while (fileVide(f[i]))
		i--;
	// ici i est l'indice de la file de plus grande priorité non vide
	p = defile(&f[i]);
	
	return p;
}

void afficheFilePrio(FilePrio f){
	int i;
	for (i = 0; i < K; i++) {
		printf("File %d :\n",i);
		afficheFile(f[i]);
	}
	printf("###################\n");
}

FilePrio libereFilePrio(FilePrio f) {
	int i;
	for (i = 0; i < K; i++) {
		f[i] = libereFile(f[i]);
	}
	free(f);
	return NULL;
}
