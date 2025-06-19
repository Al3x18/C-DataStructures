#define NULLITEM 0
#define MAX_NOME 25
#define MAX_DATA 20

//Nodo esame
typedef struct esame {
    char nomeEsame[MAX_NOME];
    int voto;
    char data[MAX_DATA];
    struct esame *next;  //Puntatore al prossimo nodo esame se c'è altrimenti NULL
} esame;

typedef struct libretto {
    int matricola;
    char cognome[MAX_NOME];
    char nome[MAX_NOME];
    esame *headListaEsami;  //Puntatore al primo nodo della lista concatenata di esami
} libretto;

libretto newLibretto(int matricola, char* cognome, char* nome);
void addEsame(libretto *l, esame e);
void printEsami(libretto l);
esame* cercaEsame(libretto l, char* nomeEsame);