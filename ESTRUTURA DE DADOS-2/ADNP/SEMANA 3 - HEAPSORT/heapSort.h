// FILA DE PRIORIDADE
// MAX HEAP
int FP_inicio(int *v, int size);
int FP_remover_maximo(int* fp, int n);
int FP_inserir(int* fp, int n, int x);
int pai(int i);

// FILA DE PRIORIDADE
// MIN HEAP
int FP_MIN_inicio(int *fp, int n);
int FP_MIN_remover(int* fp, int n);
int FP_MIN_inserir(int* fp, int n, int x);

void troca(int *vetor, int pos1, int pos2);
int esq(int i);
int dir(int i);
void maxHeapify(int *v, int i, int sizeOfHeap);
void buildMaxHeap(int *v, int size);
void minHeapify(int* v, int i, int sizeOfHeap);
void buildMinHeap(int* v, int size);
void heapSort(int *v, int size);