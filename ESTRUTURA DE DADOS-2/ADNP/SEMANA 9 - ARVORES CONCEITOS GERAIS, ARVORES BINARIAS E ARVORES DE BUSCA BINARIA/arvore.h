typedef struct AB{
  struct AB *esq;
  struct AB *dir;
  int chave;
} AB;

void imprime_pre_ordem(AB *A);
void imprime_em_ordem(AB *A);
void imprime_pos_ordem(AB *A);