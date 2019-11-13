#include <stdio.h>
#include <stdlib.h>
#include "file.h"

#define K 10 // nombre de priorités 

typedef File* FilePrio;
// FilePrio est un tableau de files, donc un pointeur sur type File

FilePrio creerFilePrio();
int fileVidePrio(FilePrio);
FilePrio enfilePrio(FilePrio, Paire);
Paire defilePrio(FilePrio);
void afficheFilePrio(FilePrio);
FilePrio libereFilePrio(FilePrio); 

