#include<iostream>
#include<string.h>

using namespace std;


struct Livro {
    //variáveis
    int alocado=0;
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
		printf("Titulo: %s\n", titulo);
		printf("Autor: %s\n", autor);
		printf("Paginas: %d\n", paginas);
	}
};

struct Biblioteca {
    Livro livros[10];
    int contador=0;
	
	int vazio(){
		for(int i=0; i<10; i++){
			if(livros[i].alocado==0){
				livros[i].alocado=1;
				return i;
			}
		}
	}
	
    void zerar(){
        for(int i=0; i<10; i++){
            strcpy(livros[i].titulo, "");
            strcpy(livros[i].autor, "");
            livros[i].paginas = 0;
        }
    }

    void acessar(){
    	int quantidade=0;
    	
        for(int i=0; i<10; i++){
			if(livros[i].alocado==1){
				printf("Indice = %d\n", i+1);
	            livros[i].imprimir();
	            printf("\n");
	            quantidade++;
            }
        }
        
        if(quantidade==0){
        	printf("Voce nao tem livros cadastrados!\n");
			printf("\n");
		}
    }

    void cadastrar(){
        if(contador<=10){
            livros[vazio()].ler();
            contador++;
        }else{
            printf("Jean voce ja cadastrou o maximo de livros!\n");
            printf("\n");
        }
    }
	
	void remover(){
		if(contador==0){
			printf("Voce nao tem livros cadastrados!\n");
			printf("\n");
		}else{
			int posicao=0;
			
			printf("Digite o indice do livro que deseja remover: ");
			scanf("%d",&posicao);
			printf("\n");
			posicao--;
			
			if(livros[posicao].alocado==1){
				strcpy(livros[posicao].titulo, "");
		        strcpy(livros[posicao].autor, "");
		        livros[posicao].paginas = 0;
		        livros[posicao].alocado=0;
		        
		        contador--;
		        
		        printf("Livro removido!\n");
		        printf("\n");
            }else{
            	printf("Posicao invalida!\n");
            	printf("\n");
			}
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
            printf("Indice = %d\n", maiorLivroI+1);
            livros[maiorLivroI].imprimir();
            printf("\n");
        }
    }
};

int main(){
    Biblioteca b;
    int escolha=0;

    b.zerar();

    while(escolha!=5){
        printf("Escolha o que voce deseja fazer?\n");
        printf("1 - Acessar estante livros\n");
        printf("2 - Cadastrar um novo livro\n");
        printf("3 - Remover um livro existente\n");
        printf("4 - Maior livro da biblioteca\n");
        printf("5 - Sair\n");
        scanf("%d%*c",&escolha);
        printf("\n");

        if(escolha==1){
            //acessar
            b.acessar();
        }else if(escolha==2){
            //cadastrar
            b.cadastrar();
        }else if(escolha==3){
            //remover
            b.remover();
        }else if(escolha==4){
            //maior livro
            b.maiorLivro();
    	}else if(escolha==5){
			//sair
            printf("Alunos:\n");
            printf("Arthur Xavier\n");
            printf("Joao Augusto Marciano Silva\n");
            printf("\n");

            return 0;
        }else{
            printf("Opcao invalida!\n");
            printf("\n");
        }

        system("pause");
        system("cls");
    }

	return 0;
}
