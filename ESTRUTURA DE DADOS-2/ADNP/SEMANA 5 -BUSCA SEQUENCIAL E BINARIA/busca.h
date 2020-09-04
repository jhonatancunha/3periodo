int busca_seq(int *v, int size, int x);
int busca_bin(int*vetor, int limiteEsquerdo, int limiteDireito, int valor);

int SelectionMinK(int *v, int n, int k);
int encontreMinK(int *v, int i, int tamanho, int indiceMenor);


int partition(int *v, int inicio, int fim);
int QuickMinK(int *v, int e, int d, int k);


int esq(int i);
int dir(int i);
void minHeapify(int *v, int i, int th);
void buildMinHeap(int *v, int n);
void heapSort(int *v, int n);
int HeapMinK(int *v, int n, int k);

// GERAR VETOR ALETAORIO SEM REPETIÇÃO
int* randomVectorUniqueElems(int n, int seed);
void embaralhar(int *v, int inicio, int fim);
void troca(int* v, int pos1, int pos2);
