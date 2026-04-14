#include <stdio.h>

#define init "Iniciando Sistema...\n"
#define end "Saindo do Sistema...\n"

int main() {

    char nome[100];
    float salario;
    int idade;
    char sexo;

    printf(init);

    printf("Informe o nome de usuário: \n");
    scanf("%99s", nome);

    printf("Informe o salário do usuário: \n");
    scanf("%f", &salario);

    printf("Informe a idade do usuário: \n");
    scanf("%i", &idade);

    printf("Informe o sexo do usuário (F/M): \n");
    scanf(" %c", &sexo);

    printf(
        "-Nome: %s \n-Salario: %f \n-Idade: %i \n-Sexo: %c\n", 
        nome,
        salario,
        idade,
        sexo
    );

    printf(end);
}