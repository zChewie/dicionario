int main()
{ 
  int ok=1;
  char opcao;

  zerar(); // zera o vetor que serÃ¡ impresso

  while(ok)
  {   
    system("clear");
    printf("Estudo de arquivos:\n");
    printf("1. Visualizar\n");
    printf("2. Buscar\n"); 
    printf("3. Inserir\n"); 
    printf("4. Retirar\n"); 
    printf("5. Corrigir\n");  
    printf("6. Ordenar\n");
    printf("7. Estudar\n"); 
    printf("0. Sair do Programa\n");
    printf("Opcao :\n");
    //fflush(stdin);
    opcao=getchar();
    system("clear");

    switch (opcao)
    {
    case '1':
      {
        zerar();
        carregar();
        imprimir();
        //getchar();
        break;  
      } 
    case '2':
      {
        buscar();
        break;
      } 
    case '3':
      {
        inserir();
        break;
      }
    case '4':
      {
        apagar();
        zerar();
        carregar();
        break;  
      }
    case '5':
      {   
        zerar();
        carregar();
        corrigir();
        break;  
      }
    case '6':
      {
        zerar();
        carregar();
        ordenar();
        break;  
      }
      case '7':
      {
        zerar();
        carregar();
        play();
        break;
      }
    case '0':
      {
        system("clear");  
        exit(1);
        break;  
      }
    default :
      {
        break;  
      }

    }

  }

  //fclose(fArq); // sempre fechar o arquivo apÃ³s finalizar o programa
  return 0;
}