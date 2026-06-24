#include "rna_transcription.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

char *to_rna(const char *dna) {

  size_t len = strlen(dna);
  // we can't return a pointer to a stack mut_rna becauase
  // it gets dropped in this scope - so wee need to
  // allocate it on the heap

  if (len == 0) {
    char *empty = malloc(1 * sizeof(char));
    empty[0] = '\0';
    return empty;
  }

  // allocate 12 slots for each char and one for the terminator '\0'
  char *heap_rna = malloc((12 + 1) * sizeof(char));
  for (size_t i = 0; i < len; i++) {
    //- `G` -> `C` - `C` -> `G` - `T` -> `A` - `A` -> `U`
    // always adding a terminator char at the end
    switch (dna[i]) {
    case 'G':
      heap_rna[i] = 'C';
      heap_rna[i + 1] = '\0';
      break;
    case 'C':
      heap_rna[i] = 'G';
      heap_rna[i + 1] = '\0';
      break;
    case 'T':
      heap_rna[i] = 'A';
      heap_rna[i + 1] = '\0';
      break;
    case 'A':
      heap_rna[i] = 'U';
      heap_rna[i + 1] = '\0';
      break;
    default:
      break;
    }
  }

  return heap_rna;
}
