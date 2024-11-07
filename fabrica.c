#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as características de um monstro
typedef struct {
    char nome[50];
    char formatoCabeca[50];
    char caracteristicas[50];
    char caracteristicasFace[50];
} Monstro;

// Função para exibir o catálogo de monstros com suas características
void exibirCatalogo(Monstro catalogo[], int numMonstros) {
    printf("Catálogo de Monstros:\n");
    for (int i = 0; i < numMonstros; i++) {
        printf("Nome: %s\n", catalogo[i].nome);
        printf("Formato da Cabeça: %s\n", catalogo[i].formatoCabeca);
        printf("Características: %s\n", catalogo[i].caracteristicas);
        printf("Características Faciais: %s\n\n", catalogo[i].caracteristicasFace);
    }
}

// Função para identificar um monstro no catálogo com base nas descrições
Monstro* identificarMonstro(char* descricaoFormatoCabeca, char* descricaoCaracteristicas, char* descricaoCaracteristicasFace, Monstro catalogo[], int numMonstros) {
    for (int i = 0; i < numMonstros; i++) {
        // Usa strcasecmp para comparar as strings sem diferenciar maiúsculas de minúsculas
        if (strcasecmp(descricaoFormatoCabeca, catalogo[i].formatoCabeca) == 0 && 
            strcasecmp(descricaoCaracteristicas, catalogo[i].caracteristicas) == 0 && 
            strcasecmp(descricaoCaracteristicasFace, catalogo[i].caracteristicasFace) == 0) {
            return &catalogo[i];  // Retorna um ponteiro para o monstro identificado
        }
    }
    return NULL; // Retorna NULL se nenhum monstro coincidir
}

// Função para criar um novo monstro
Monstro criarMonstro(char* nome, char* formatoCabeca, char* caracteristicas, char* caracteristicasFace) {
    Monstro novoMonstro;
    strcpy(novoMonstro.nome, nome);
    strcpy(novoMonstro.formatoCabeca, formatoCabeca);
    strcpy(novoMonstro.caracteristicas, caracteristicas);
    strcpy(novoMonstro.caracteristicasFace, caracteristicasFace);
    return novoMonstro;
}

// Função principal
int main() {
    // Definição inicial do catálogo de monstros
    Monstro catalogo[3] = {
        {"Franken Wackus", "Franken", "Wackus", "N/A"},
        {"Zombos Vegitas", "Zombos", "Vegitas", "N/A"},
        {"Happy", "Happy", "N/A", "Spritem"}
    };

    int numMonstros = 3;

    // Exibir o catálogo para o usuário
    exibirCatalogo(catalogo, numMonstros);

    // Obter as características do monstro descrito pelo usuário
    char formatoCabeca[50];
    char caracteristicas[50];
    char caracteristicasFace[50];

    printf("Descreva o monstro para identificá-lo:\n");
    printf("Formato da Cabeça: ");
    scanf("%49s", formatoCabeca);

    printf("Características: ");
    scanf("%49s", caracteristicas);

    printf("Características Faciais: ");
    scanf("%49s", caracteristicasFace);

    // Tentar identificar o monstro no catálogo
    Monstro* monstroIdentificado = identificarMonstro(formatoCabeca, caracteristicas, caracteristicasFace, catalogo, numMonstros);

    if (monstroIdentificado != NULL) {
        // Monstro já existe no catálogo
        printf("Monstro identificado: %s\n", monstroIdentificado->nome);
    } else {
        // Monstro não identificado, criar um novo
        printf("Monstro não identificado no catálogo.\n");

        // Permitir que o usuário crie um novo monstro
        char nomeNovoMonstro[50];
        printf("\nDigite o nome do novo monstro: ");
        getchar(); // Limpar o buffer antes de usar fgets
        fgets(nomeNovoMonstro, sizeof(nomeNovoMonstro), stdin);
        nomeNovoMonstro[strcspn(nomeNovoMonstro, "\n")] = '\0';  // Remove o caractere de nova linha

        Monstro novoMonstro = criarMonstro(nomeNovoMonstro, formatoCabeca, caracteristicas, caracteristicasFace);

        // Adicionar o novo monstro ao catálogo e aumentar o contador
        if (numMonstros < 10) {  // Limite de segurança para o tamanho do catálogo
            catalogo[numMonstros] = novoMonstro;
            numMonstros++;
            printf("Monstro criado e adicionado ao catálogo com sucesso.\n");
        } else {
            printf("O catálogo está cheio, não é possível adicionar mais monstros.\n");
        }

        // Exibir catálogo atualizado após a adição do novo monstro
        printf("\nCatálogo atualizado:\n");
        exibirCatalogo(catalogo, numMonstros);
    }

    return 0;
}