int busca_seq(int *v, int size, int x);
int busca_bin(int*vetor, int limiteEsquerdo, int limiteDireito, int valor);

int SelectionMinK(int *v, int n, int k);
int encontreMinK(int *v, int i, int tamanho, int indiceMenor);


// GERAR VETOR ALETAORIO SEM REPETIÇÃO
int* randomVectorUniqueElems(int n, int seed);
void embaralhar(int *v, int inicio, int fim);
void troca(int* v, int pos1, int pos2);