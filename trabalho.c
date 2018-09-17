/*_____________________________________________________________________________
 |                                                                              |
 |        DATA DE INÃCIO: 12/03/2018                                      |
 |        ÃšLTIMA ATUALIZAÃ‡ÃƒO: 06/08/2018                                     |
 |        PROFESSOR: CARLOS JONES                                               |
 |        CURSO: ENGENHARIA DE CONTROLE E AUTOMAÃ‡ÃƒO        DISCIPLINA:LP      |
 |        SEMESTRE/ANO: 1/2018                                                  |
 |        ALUNOS: CARLOS JONES                                                  |                                                                              |
 |        PROGRAMA EXEMPLO DO USO BÃSICO DE ARQUIVOS.                     |
 | _____________________________________________________________________________|
 */

// NESTE DOCUMENTO VEREMOS ALGUMS CONCEITO BÃSICOS DE ARQUIVOS EM LINGUAGEM C
// VIDE CAPÃTULO 10 DO LIVRO LINGUAGEM C DO LUIS DAMAS

/*

 1 - CRIANDO UM PONTEIRO PARA ARQUIVOS

 FILE *fArq; // onde f indica que o ponteiro Ã© para um arquivo (file);


 2 - MODOS DE ABERTURA

 A sintaxe bÃ¡sica Ã© a seguinte: FILE *fopen(const char *filename, const char *mode)
 - filename: string contendo o nome do arquivo;
 - mode: string contendo o modo de abertura do arquivo.

 MODE:

 - "r": read (abertura para leitura), caso o arquivo nÃ£o exista, serÃ¡ devolvido NULL;
 - "w": write (abertura para escrita), se o arquivo jÃ¡ existir, este serÃ¡ apagado e criado um novo arquivo, se nÃ£o conseguir abertura para escrita serÃ¡ devolvido NULL;
 - "a": append (abertura para inserÃ§Ã£o de novos dados, acrescentar), caso o arquivo nÃ£o exista, ele funcionarÃ¡ exatamente como o "w", caso ele exista, dados serÃ£o acrescentados ao final do arquivo;

 OBS.: olhar na pÃ¡g.231 do livro sobre o uso do caracter "+" nos modos de abertura. Veja tambÃ©m arquivos binÃ¡rios.


 3 - FECHAMENTO DO ARQUIVO

 A sintaxe bÃ¡sica Ã© a seguinte: int fclose(FILE *arq);
 - antes do fechamento todos os arquivos sÃ£o gravados fisicamente;
 - Ã© liberada a memÃ³ria alocada pelo tipo FILE;
 - devolve 0 em caso de sucesso e EOF em caso de erro.

 OBS.: embora todos os arquivos sejam fechados logo apÃ³s o fim da aplicaÃ§Ã£o, Ã© uma boa prÃ¡tica de programaÃ§Ã£o realizar vc msm esta tarefa, evitando assim falhas por desligamento do computador por quaisquer motivos.

 4 - GRAVANDO UM ARQUIVO EM TEMPO DE EXECUÃ‡ÃƒO

 A sintaxe bÃ¡sica Ã© a seguinte: int fflush(FILE *arq);
 - fflush: grava todos os dados em arquivo, porÃ©m, ainda o mantÃ©m aberto;
 - fflush tambÃ©m pode ser usada para limpar o buffer do teclado com o comando fflush(stdin).

 5 - FECHANDO TODOS OS ARQUIVOS ABERTOS

 A sintaxe bÃ¡sica Ã© a seguinte: int fcloseall().
 - fcloseall: fecha todos os arquivos abertos exceto stdin, stdout, stderr, stdprn, stdaux.

 6 - GRAVANDO TODOS OS ARQUIVOS EM TEMPO DE EXECUÃ‡ÃƒO
 A sintaxe bÃ¡sica Ã© a seguinte: int flushall().


 */

//--------------------------INCLUSÃƒO DE BIBLIOTECAS---------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <ctype.h>
#include <time.h> // para usar o time na funÃ§Ã£o gerarAleatÃ³rio
#include <stdio_ext.h> //para  __fpurge(stdin); no linux
//----------------------------------------------------------------------------//


//----------------------------DECLARAÃ‡Ã•ES GLOBAIS-----------------------------//
#define TAM_TEXT 250 // tamanho dos textos a serem escritos, nÃ£o inclui o caractere especial

FILE *fArq; //declaraÃ§Ã£o do ponteiro do tipo arquivo para manipulaÃ§Ã£o de streams
char aux[1000][TAM_TEXT+1];
char aux2[1000][TAM_TEXT+1];
char ap[1000][TAM_TEXT+1];
char ap2[1000][TAM_TEXT+1]; // 1000 palavras de 250 caracteres mais o \0
int linhas;

// insere palavras/frases no dicionÃ¡rio
void inserir(void)
{
    char palavra[TAM_TEXT+1]; // considerar o '\0'

    fArq=fopen("palavras.txt","ab"); // abre o dicionÃ¡rio somente para leitura

    // erro caso nÃ£o encontre o arquivo de bd do dicionÃ¡rio
    if(fArq == NULL)
    {
        printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
    }
    else
    {
        printf("Digite a palavra:\n");
        //fflush(stdin); // usado no win para limpar o buffer do teclado
        __fpurge(stdin); // usado no linux para limpar o buffer do teclado
        fgets(palavra, TAM_TEXT, stdin); //stdin Ã© o teclado

        //fArq=fopen("palavras.txt","ab"); // abre o dicionÃ¡rio em modo de adiÃ§Ã£o/acrescentar mais palavras
        fprintf(fArq,"%s",palavra); // salva a palavra o BD e quebra a linha

    }
    fclose(fArq); // fecha o dicionario
    palavra[0]=' ';
    fArq=fopen("significados.txt","ab"); // abre o dicionÃ¡rio somente para leitura

    // erro caso nÃ£o encontre o arquivo de bd do dicionÃ¡rio
    if(fArq == NULL)
    {
        printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
    }
    else
    {
        printf("Digite o significado:\n");
        //fflush(stdin); // usado no win para limpar o buffer do teclado
        __fpurge(stdin); // usado no linux para limpar o buffer do teclado
        fgets(palavra, TAM_TEXT, stdin); //stdin Ã© o teclado

        //fArq=fopen("significados.txt","ab"); // abre o dicionÃ¡rio em modo de adiÃ§Ã£o/acrescentar mais palavras
        fprintf(fArq,"%s",palavra); // salva a palavra o BD e quebra a linha

    }
    fclose(fArq); // fecha o dicionario
}

void ordenar()
{
    printf("para ordernar de forma correta verifique no menu visualizar se nao ha espaco antes do inicio da palavra/frase. ");
    __fpurge(stdin); // usado no linux para limpar o buffer do teclado
    fflush(stdin);
    getchar();

    char temp[TAM_TEXT+1], temp1[TAM_TEXT+1], c=' ';
    int i = 0;
    int j;
    int linhas=0;
    fArq=fopen("palavras.txt","r");
    while ((c = fgetc(fArq)) != EOF)
    {
        if (c == '\n')
        {
            linhas++;
        }
    }
    fclose(fArq);
    for(j=1; j<linhas; j++)
    {
        strcpy(temp,aux[j]);
        strcpy(temp1,aux2[j]);
        i = j-1;
        while(i >= 0 && strcmp(aux[i], temp) > 0)
        {
            strcpy(aux[i+1],aux[i]);
            strcpy(aux2[i+1],aux2[i]);
            i--;
        }
        strcpy(aux[i+1],temp);
        strcpy(aux2[i+1],temp1);
    }

    fArq=fopen("significados.txt","wb"); // abre o dicionÃ¡rio somente para leitura

    if(fArq == NULL)
    {
        printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
    }
    else
    {
        for (int i = 0; i < linhas; ++i)
        {
            fprintf(fArq,"%s",aux2[i]); // salva a palavra o BD e quebra a linha
        }

        fclose(fArq); // fecha o dicionario
    }
    fArq=fopen("palavras.txt","wb"); // abre o dicionÃ¡rio somente para leitura

    if(fArq == NULL)
    {
        printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
    }
    else
    {
        for (int i = 0; i < linhas; ++i)
        {
            fprintf(fArq,"%s",aux[i]); // salva a palavra o BD e quebra a linha
        }
    }

    fclose(fArq); // fecha o dicionario
    system("clear");
    printf("Ordenarcao concluida.\nDigite qualquer tecla para continuar.");
    __fpurge(stdin); // usado no linux para limpar o buffer do teclado
    fflush(stdin);
    getchar();
}











void corrigir()
{
    int i=0, ok=0,linhas=0;
    char d=' ',c=' ';
    char palavra[TAM_TEXT+1],palavra1[TAM_TEXT+1]; // considerar o '\0'


    printf("MENU\nEscolha as seguintes opcoes:\n1-Corrigir uma palavra.\n2-Corrigir o significado.\nQualquer outra tecla para cancelar.");
    __fpurge(stdin); // usado no linux para limpar o buffer do teclado
    fflush(stdin);
    d=getchar();
    system("clear");
    if(d=='1')
    {
        printf("Digite a palavra que deseja corrigir:");
        __fpurge(stdin); // usado no linux para limpar o buffer do teclado
        fgets(palavra, TAM_TEXT, stdin);
        for(i=0; i<1000; i++)
        {
            if((strcmp(aux[i], palavra)==0))
            {

                ok=1;
                printf("Digite a forma correta:");
                __fpurge(stdin); // usado no linux para limpar o buffer do teclado
                fgets(palavra1, TAM_TEXT, stdin);
                strcpy(aux[i], palavra1);
                __fpurge(stdin);
                fflush(stdin);
                d=getchar();
                system("clear");
                fArq=fopen("palavras.txt","r");
                while ((c = fgetc(fArq)) != EOF)
                {
                    if (c == '\n')
                    {
                        linhas++;
                    }
                }
                fclose(fArq);
                fArq=fopen("palavras.txt","wb"); // abre o dicionÃ¡rio somente para leitura

                if(fArq == NULL)
                {
                    printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
                }
                else
                {
                    for (int i = 0; i < linhas; ++i)
                    {
                        fprintf(fArq,"%s",aux[i]); // salva a palavra o BD e quebra a linha
                    }
                }

                fclose(fArq); // fecha o diciona
            }

        }
        if (ok==0)
        {
            printf("Palavra/Frase nao encontrada\n");
            __fpurge(stdin);
            fflush(stdin);
            d=getchar();
            system("clear");
        }

    }

    else if(d=='2')
    {
        printf("Digite a palavra que deseja corrigir a tradução:");
        __fpurge(stdin); // usado no linux para limpar o buffer do teclado
        fgets(palavra, TAM_TEXT, stdin);
        for(i=0; i<1000; i++)
        {
            if((strcmp(aux[i], palavra)==0))
            {

                ok=1;
                printf("Digite a forma correta:");
                __fpurge(stdin); // usado no linux para limpar o buffer do teclado
                fgets(palavra1, TAM_TEXT, stdin);
                strcpy(aux2[i], palavra1);
                __fpurge(stdin);
                fflush(stdin);
                d=getchar();
                system("clear");
                fArq=fopen("significados.txt","r");
                while ((c = fgetc(fArq)) != EOF)
                {
                    if (c == '\n')
                    {
                        linhas++;
                    }
                }
                fclose(fArq);
                fArq=fopen("significados.txt","wb"); // abre o dicionÃ¡rio somente para leitura

                if(fArq == NULL)
                {
                    printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
                }
                else
                {
                    for (int i = 0; i < linhas; ++i)
                    {
                        fprintf(fArq,"%s",aux2[i]); // salva a palavra o BD e quebra a linha
                    }
                }

                fclose(fArq); // fecha o diciona
            }

        }
        if (ok==0)
        {
            printf("Palavra/Frase nao encontrada\n");
            __fpurge(stdin);
            fflush(stdin);
            d=getchar();
            system("clear");
        }

    }
    else
    {
        printf("Opcao invalida...\n");
        __fpurge(stdin);
        fflush(stdin);
        d=getchar();
    }

}










void apagar()
{
    carregar();
    int i=0, a=0,linhas =0, ok=0, indice=0;
    char d,c;
    char palavra[TAM_TEXT+1];
    printf("Digite a palavra/frase para apagar:");
    __fpurge(stdin); // usado no linux para limpar o buffer do teclado
    fgets(palavra, TAM_TEXT, stdin);
    for(i=0; i<1000; i++)
    {
        if((strcmp(aux[i], palavra)==0))
        {
            indice=i;
            ok=1;
            printf("Palavra que deseja apagar:%s",aux[indice] );
            printf("Traducao/Significado:");
            printf("%s\n", aux2[indice]);
            printf("Digite 1 para confirmar e qualquer outra tecla para cancelar\n");
            __fpurge(stdin);
            fflush(stdin);
            d=getchar();
            if(d=='1')
            {
                i=1000;
            }
            system("clear");

        }

    }

    if (ok==0)
    {
        printf("Palavra/Frase nao encontrada\n");
        __fpurge(stdin);
        fflush(stdin);
        d=getchar();
        system("clear");
    }
    else
    {
        fArq=fopen("palavras.txt","r");

        if (fArq == NULL)
        {
            printf("Erro na leitura do Arquivo!!! Entre em contato com o suporte tÃ©cnico!\n");
        }
        else
        {
            while ((c = fgetc(fArq)) != EOF)
            {
                if (c == '\n')
                {
                    linhas++;
                }
            }
            //linhas++;
            for (int i = 0; i < linhas; ++i,a++)
            {
                if(i==indice)
                {
                    i++;

                }

                strcpy(ap2[a], aux2[i]);
                strcpy(ap[a], aux[i]);


            }
        }
        fclose(fArq);
        fArq=fopen("significados.txt","wb"); // abre o dicionÃ¡rio somente para leitura

        if(fArq == NULL)
        {
            printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
        }
        else
        {
            for (int i = 0; i < linhas; ++i)
            {
                fprintf(fArq,"%s",ap2[i]); // salva a palavra o BD e quebra a linha
            }

            fclose(fArq); // fecha o dicionario
        }
        fArq=fopen("palavras.txt","wb"); // abre o dicionÃ¡rio somente para leitura

        if(fArq == NULL)
        {
            printf("Erro, nao foi possivel abrir o banco de dados do dicionario.\n");
        }
        else
        {
            for (int i = 0; i < linhas; ++i)
            {
                fprintf(fArq,"%s",ap[i]); // salva a palavra o BD e quebra a linha
            }
        }
    }
    fclose(fArq); // fecha o dicionario

}










void carregar()
{
    int i=0;


    fArq=fopen("palavras.txt","r");

    if (fArq == NULL)
    {
        printf("Erro na leitura do Arquivo!!! Entre em contato com o suporte tÃ©cnico!\n");
    }
    else
    {
        while(fgets(aux[i], TAM_TEXT+1, fArq)!=NULL) i++; // copia palavra para um vetor

    }
    fclose(fArq);
    fArq=fopen("significados.txt","r");
    i=0;
    if (fArq == NULL)
    {
        printf("Erro na leitura do Arquivo!!! Entre em contato com o supo{rte tÃ©cnico!\n");
    }

    else
    {
        while(fgets(aux2[i], TAM_TEXT+1, fArq)!=NULL)// copia palavra para um vetor
        {
            i++;
        }
    }
    fclose(fArq);
}







void buscar()
{
    zerar();
    int i=0, ok=0;
    char d;
    char palavra[TAM_TEXT+1]; // considerar o '\0'
    carregar();

    printf("Digite a palavra/frase para procurar seu significado:");
    __fpurge(stdin); // usado no linux para limpar o buffer do teclado
    fgets(palavra, TAM_TEXT, stdin);
    for(i=0; i<1000; i++)
    {
        if((strcmp(aux[i], palavra)==0))
        {

            ok=1;
            printf("Traducao/Significado:");
            printf("%s\n", aux2[i]);
            __fpurge(stdin);
            fflush(stdin);
            d=getchar();
            system("clear");

        }

    }
    if (ok==0)
    {
        printf("Palavra/Frase nao encontrada\n");
        __fpurge(stdin);
        fflush(stdin);
        d=getchar();
        system("clear");
    }


}








void imprimir()
{
    int i=0, a=0;
    char d;

    for(i=0; i<1000; i++)
    {
        if((strcmp(aux[i], " ")!=0)&&(strcmp(aux2[i], " ")!=0))
        {

            printf("Palavra/Frase:");
            printf("%s", aux[i]);
            printf("Traducao/Significado:");
            printf("%s\n", aux2[i]);
            a++;
            if(a==5)
            {
                a=0;
                printf("Digite qualquer tecla para continuar...\n" );
                __fpurge(stdin);
                fflush(stdin);
                d=getchar();
                //system("read -p \"Pressione enter para sair\" saindo");
                system("clear");
            }
        }
        else
        {
            //printf("vazio\n");
            break;
        }
    }
    __fpurge(stdin);
    fflush(stdin);
    d=getchar();
}



void play()
{
//     srand(time(NULL)); //inicializa a semente aleatÃ³ria
    int x[1000], i=0, j=0, linhas=0, f=0, dif=0, ok=1, aleatorio_ant=0, linhas1=0,sair=0, trava=0;
    char d, c, a, k='\0';
    /*fArq=fopen("palavras.txt","r"); //Abre o arquivo para contar a quantidade de linhas
    while ((c = fgetc(fArq)) != EOF)
      {
        if (c == '\n') //Quando acahar o '\n' no arquivo ele soma mais um
        {
            linhas++; //assim tem a quantidades de linhas do arquivo todo
        }
      }
      fclose(fArq);*/ //fecha o arquivo

        fArq=fopen("palavras.txt","r");

        if (fArq == NULL)
        {
            printf("Erro na leitura do Arquivo!!! Entre em contato com o suporte tÃ©cnico!\n");
        }
        else
        {
            while ((c = fgetc(fArq)) != EOF)
            {
                if (c == '\n')
                {
                    linhas1++;
                }
            }
        }
 fclose(fArq);
    while(ok)
    {
        /*
          fArq=fopen("palavras.txt","r"); //Abre o arquivo para contar a quantidade de linhas
          while ((c = fgetc(fArq)) != EOF)
            {
              if (c == '\n') //Quando acahar o '\n' no arquivo ele soma mais um
              {
                linhas++; //assim tem a quantidades de linhas do arquivo todo
              }
            }
        fclose(fArq); //fecha o arquivo
        */

        while(i<1000)
        {
            if((strcmp(aux[i], " ")==0))
            {
                linhas--;
            }

            linhas++;
            i++;
        }
        i=0;


        if(linhas>0)
        {
        	 f=geraAleatorio(linhas1);
        	 while(f==aleatorio_ant)
        	 {
        	 	f=geraAleatorio(linhas1);
        	 }
        }
sair=0;
trava=0;
        //if((strcmp(aux[f], " ")!=0)&&(strcmp(aux2[f], " "))!=0)
		while(sair==0)
        {
       		 if(linhas!=0)
        	{
        	
	        	aleatorio_ant=f;
	            system("clear");
	            printf("A palavra e: %s\n", aux[f]);
	            printf("pressione ENTER para continuar...\n" );
	           if(trava==0)
	           {
	           	__fpurge(stdin);
	            d=getchar();
	            trava=1;
	           }
	           else
	           {
	           	printf("\n");
	           }
	            
	            printf("Significado: %s\n\n", aux2[f]);
	            printf("Digite:\n");
	           printf("0- voltar ao menu principal\n");
	            printf("1- Fácil\n");
	            printf("2- Tive dificuldade ou errei\n");
	            
	           

	           	 __fpurge(stdin);
	            a=getchar();
	            if(a=='1')
	            {
	                strcpy(aux[f]," ");
	                strcpy(aux2[f]," ");
	                sair=15;

	            }

            	else if(a=='2')
           		 {
                ok=1;
                sair=15;
           		 }
           		 else if(a=='0')
           		 {
                printf("pressione ENTER para voltar ao menu\n");
                ok=0;
                sair=15;
            	}
          	 }
        

        	else if(linhas==0)
        	{
            system("clear");
            printf("Não há nenhuma palavra\n");
            __fpurge(stdin);
            d=getchar();
            sair=15;
            ok=0;
        	}
		}
        linhas=0;
        
    }
}


void zerar()
{
    int i;

    for(i=0; i<1000; i++)
    {
        strcpy(aux[i]," ");
        strcpy(aux2[i]," ");
        strcpy(ap[i]," ");
        strcpy(ap2[i]," ");
    }
}


// gera um numero aleatÃ³rio para a geraÃ§Ã£o de Ã­ndices do vetor
int geraAleatorio(int tam)
{
    srand(time(NULL));

    int ale=rand()%(tam);

    while(strcmp(aux[ale], " ")==0)
    {
        ale=rand()%(tam);
    }
    return(ale);
}
