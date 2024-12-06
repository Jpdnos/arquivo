#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

void exportarDados();
void importarDados();
void limparBuffer();
int abrirArquivo(const char* nomeArquivo, const char* modo, FILE** arquivo);

#endif
