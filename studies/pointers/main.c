#include <stdio.h>

void display(int var, int *ptr);
void update(int *p);

int main() 
{
    int var = 15;
    int *ptr;

    ptr = &var;
 
    display(var, ptr);

    update(&var);

    display(var, ptr);

    printf("\n\nEnd.");
    while (1);
    return 0;
}

void display(int var, int *ptr)
{
    printf("conteudo de var = %d\n", var);
    printf("endereco de var = %p\n", &var);

    printf("conteudo apontado por ptr   = %d\n", *ptr);
    printf("endereco apontado de ptr    = %p\n", ptr);
    printf("endereco de ptr             = %p\n", &ptr);

    printf("\n\n");
}

void update(int *p)
{
    (*p)++;
}

//*ptr: o apontado por, conteudo do endereço da variavel que ptr aponta
// ptr: o endereço da variavel
// &ptr: o endereço do ponteiro