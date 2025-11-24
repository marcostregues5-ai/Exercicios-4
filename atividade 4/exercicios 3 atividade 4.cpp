#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];
    int i, indice;

    
    printf("=== Cadastro de 5 alunos ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);  
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    
    printf("\n=== Atualizar Nota ===\n");
    printf("Escolha o índice do aluno (0 a 4): ");
    scanf("%d", &indice);

    if (indice < 0 || indice > 4) {
        printf("Índice inválido!\n");
        return 0;
    }

    printf("Digite a nova nota para %s: ", alunos[indice].nome);
    scanf("%f", &alunos[indice].nota);

    
    printf("\n=== Aluno Atualizado ===\n");
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d\n", alunos[indice].idade);
    printf("Nota atualizada: %.2f\n", alunos[indice].nota);

    return 0;
}