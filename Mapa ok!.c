#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int i = 0;
int j = 0;
int k = 0;
char buscarCPF [11];

struct vacinados{
  int codigo;
  char nome [50];
  char cpf [12];
  char vacina [15];
  char data [11];
  int numLote;
};
struct vacinados cadastro[100];

void cadastrarVacina (){
    cadastro[i].codigo = (i+1);
    printf ("Digite o nome do paciente: \n");
    fflush (stdin);
    gets (cadastro[i].nome);
    printf ("Digite o CPF do paciente: \n");
    scanf ("%s", &cadastro[i].cpf);
    printf ("Digite o nome da vacina: \n");
    scanf ("%s", &cadastro[i].vacina);
    printf ("Digite a data da vacina: \n");
    scanf ("%s", &cadastro[i].data);
    printf ("Digite o número do lote impresso no verso da ampola: \n");
    scanf ("%d", &cadastro[i].numLote);
    i++;
}

void listarAplicacoes (){
	printf ("\nPacientes vacinados:\n");
	for (j = 0; j < i; j++){
		printf("Código: %d\n", cadastro[j].codigo);
		printf("%s\n", cadastro[j].nome);
		printf("%s \n", cadastro[j].cpf);
		printf("%s\n", cadastro[j].vacina);
		printf("%s\n", cadastro[j].data);
		printf("%d\n\n", cadastro[j].numLote);
		printf("================================================== \n \n");
		}
	}

void consultarPorCPF(){
	printf("Digite o CPF para consulta: \n");
	scanf("%s", &buscarCPF);
	for(k = 0; k < i; k++){
		if(strcmp(buscarCPF, cadastro[k].cpf) == 0){
			printf("CPF encontrado. Imprimindo dados...\n");
			printf("Código: %d\n", cadastro[k].codigo);
			printf("%s\n", cadastro[k].nome);
			printf("%s \n", cadastro[k].cpf);
			printf("%s\n", cadastro[k].vacina);
			printf("%s\n", cadastro[k].data);
			printf("%d\n", cadastro[k].numLote);
		}
		else{
			printf("CPF não encontrado!");
		}
	}
}		
int main(void) {
  setlocale (LC_ALL, "Portuguese");
  int opcao;
  do{
    printf ("Selecione a opção desejada:\n1) Cadastrar vacina. \n2) Listar aplicações. \n3) Consultar por CPF. \n4) Sair.\n");
    scanf ("%d", &opcao);
    switch (opcao){
      case 1:{
        cadastrarVacina ();
        system ("cls");
        break;
      }
      case 2:{
      	listarAplicacoes ();
		break;
	  }
	  case 3:{
	  	consultarPorCPF();
		break;
	  }
	  case 4: {
	  	printf("Até logo!");
		break;
	  }
	  default:{
	  	printf("Opção inválida!\n");
		break;
	  }
    }
  }
  while (opcao != 4);
 
  return 0;
}
