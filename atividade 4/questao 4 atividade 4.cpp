#include <stdio.h>
#include <string.h>

#define MAX 4


typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;


void exibirAluno(Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Nota: %.2f\n", a.nota);
}


void criarAluno(Aluno alunos[], int *qtd) {
    if (*qtd >= MAX) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno novo;

    printf("Nome: ");
    getchar();  // limpar buffer
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &novo.idade);

    printf("Nota: ");
    scanf("%f", &novo.nota);

    alunos[*qtd] = novo;
    (*qtd)++;

    printf("Aluno cadastrado!\n");
}


void removerAluno(Aluno alunos[], int *qtd) {
    if (*qtd == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    int indice;
    printf("Digite o índice do aluno para remover (0 a %d): ", *qtd - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= *qtd) {
        printf("Índice inválido!\n");
        return;
    }

    
    for (int i = indice; i < *qtd - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*qtd)--;

    printf("Aluno removido!\n");
}

int main() {
    Aluno alunos[MAX];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Criar aluno\n");
        printf("2 - Mostrar alunos\n");
        printf("3 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                criarAluno(alunos, &qtd);
                break;

            case 2:
                for (int i = 0; i < qtd; i++) {
                    printf("\nAluno %d:\n", i);
                    exibirAluno(alunos[i]);
                }
                break;

            case 3:
                removerAluno(alunos, &qtd);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}