#include<iostream>
#include<string.h>

using namespace std;


struct Livro {
    //variáveis
    char titulo[100];
    char autor[100];
    int paginas;

    //funções
    void ler(){
        printf("Digite o titulo: ");
		scanf("%[^\n]%*c", titulo);
		printf("Digite o autor: ");
		scanf("%[^\n]%*c", autor);
		printf("Digite a quantidade de paginas: ");
		scanf("%d%*c", &paginas);
		printf("\n");
	}

	void imprimir(){
	    printf("\n");
		printf("Titulo: %s \t", titulo);
		printf("Autor: %s \t", autor);
		printf("Paginas: %d\n", paginas);
	}
};

struct Biblioteca {
    Livro livros[10];
    int contador=0;

    void zerar(){
        for(int i=0; i<10; i++){
            strcpy(livros[i].titulo, "");
            strcpy(livros[i].autor, "");
            livros[i].paginas = 0;
        }
    }

    void acessar(){
        for(int i=0; i<10; i++){
            printf("Indice = %d \n", i+1);
            printf("Titulo: %s \n", livros[i].titulo);
            printf("Autor: %s \n", livros[i].autor);
            printf("Paginas: %d\n", livros[i].paginas);
            printf("\n");
        }
    }

    void cadastrar(){
        if(contador<=9){
            livros[contador].ler();
            contador++;
        }else{
            printf("Jean voce ja cadastrou o maximo de livros!\n");
        }
    }

    void maiorLivro(){
        int maior=0, maiorLivroI=0;

        for(int i=0; i<10; i++){
            if(livros[i].paginas>maior){
                maior=livros[i].paginas;
                maiorLivroI=i;
            }
        }

        if(maior==0){
            printf("Voce nao tem livros cadastrados!\n");
            printf("\n");
        }else{
            printf("Indice = %d \n", maiorLivroI+1);
            printf("Titulo: %s \n", livros[maiorLivroI].titulo);
            printf("Autor: %s \n", livros[maiorLivroI].autor);
            printf("Paginas: %d\n", livros[maiorLivroI].paginas);
            printf("\n");
        }
    }
};

int main(){
    Biblioteca b;
    int escolha=0;

    b.zerar();

    while(escolha!=4){
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Acessar os livros\n");
        printf("2 - Cadastrar um novo livro\n");
        printf("3 - Maior livro da biblioteca\n");
        printf("4 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //acessar
            b.acessar();

        }else if(escolha==2){
            //cadastrar
            b.cadastrar();
        }else if(escolha==3){
            //maior livro
            b.maiorLivro();
        }else if(escolha==4){
            //sair

            printf("Alunos:\n");
            printf("Arthur Xavier\n");
            printf("Joao Augusto Marciano Silva:\n");
            printf("\n");

            return 0;
        }else{
            printf("\n");
            printf("Opcao invalida!\n");
            printf("\n");
        }

        system("pause");
        system("cls");
    }

	return 0;
}
