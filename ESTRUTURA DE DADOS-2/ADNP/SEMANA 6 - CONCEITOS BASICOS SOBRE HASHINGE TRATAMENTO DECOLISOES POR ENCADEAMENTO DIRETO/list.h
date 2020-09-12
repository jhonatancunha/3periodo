typdef struct No{
  int chave;
  int valor;
  int ocupado;
} No;

typedef struct Lista{
  No *nos;
  int max;
  int tam;
  int alloc;
  int alloc_step;
} Lista;


Lista* criarLista(int alloc_step);
int inserirLista(Lista *L, int chave, int valor);
int removerLista(Lista *L, int chave);
void imprimirLista(Lista *L, int debug);
Lista* enderecoLista(Lista *L, int pos);
int buscarLista(Lista *L, int chave);