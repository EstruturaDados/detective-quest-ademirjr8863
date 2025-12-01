#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------
// Estrutura da BST
// ------------------------------------
typedef struct No {
    char pista[50];
    struct No* esquerda;
    struct No* direita;
} No;

// ------------------------------------
// Função para inserir na BST
// ------------------------------------
No* inserir(No* raiz, char* pista) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }

    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserir(raiz->esquerda, pista);
    else if (strcmp(pista, raiz->pista) > 0)
        raiz->direita = inserir(raiz->direita, pista);

    return raiz;
}

// ------------------------------------
// Função de busca na BST
// ------------------------------------
int buscar(No* raiz, char* pista) {
    if (raiz == NULL)
        return 0;

    int cmp = strcmp(pista, raiz->pista);

    if (cmp == 0)
        return 1;
    else if (cmp < 0)
        return buscar(raiz->esquerda, pista);
    else
        return buscar(raiz->direita, pista);
}

// ------------------------------------
// Impressão em ordem alfabética
// ------------------------------------
void emOrdem(No* raiz) {
    if (raiz == NULL) return;

    emOrdem(raiz->esquerda);
    printf("- %s\n", raiz->pista);
    emOrdem(raiz->direita);
}

// ------------------------------------
// Salas que adicionam pistas
// ------------------------------------
void visitarSala(char* nomeSala, No** arvore) {

    if (strcmp(nomeSala, "biblioteca") == 0) {
        printf("Você encontrou uma pista na biblioteca!\n");
        *arvore = inserir(*arvore, "chave_antiga");
    }
    else if (strcmp(nomeSala, "cozinha") == 0) {
        printf("Você encontrou uma pista na cozinha!\n");
        *arvore = inserir(*arvore, "luva_queimada");
    }
    else if (strcmp(nomeSala, "porão") == 0) {
        printf("Você encontrou uma pista no porão!\n");
        *arvore = inserir(*arvore, "mapa_rasgado");
    }
    else if (strcmp(nomeSala, "quarto") == 0) {
        printf("Você encontrou uma pista no quarto!\n");
        *arvore = inserir(*arvore, "bilhete_sombrio");
    }
    else {
        printf("Esta sala não possui pistas.\n");
    }
}

// ------------------------------------
// Menu principal
// ------------------------------------
int main() {
    No* pistas = NULL;
    int opcao;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1 - Visitar sala\n");
        printf("2 - Ver todas as pistas\n");
        printf("3 - Procurar pista\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char sala[30];
            printf("Digite o nome da sala (biblioteca / cozinha / porão / quarto): ");
            scanf("%s", sala);
            visitarSala(sala, &pistas);
        }

        else if (opcao == 2) {
            if (pistas == NULL) {
                printf("Nenhuma pista encontrada ainda.\n");
            } else {
                printf("\nPistas encontradas (em ordem alfabética):\n");
                emOrdem(pistas);
            }
        }

        else if (opcao == 3) {
            char busca[50];
            printf("Digite a pista a procurar: ");
            scanf("%s", busca);

            if (buscar(pistas, busca))
                printf("Pista encontrada!\n");
            else
                printf("Pista não encontrada.\n");
        }

        else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        }

        else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
