#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

/*----------------------------------------------------------------------------------*/
/*A funcao imprime o estado do tabuleiro jogada a jogada prevenindo erros de espaco ao guardar espaco para 4digitos possiveis(max2048)*/
void mostrar(int grelha[TAM][TAM], int sz){
    for(int i=0; i<sz; i++){
      for(int j=0; j<sz; j++){
        if (grelha[i][j]==0){  /*Troca 0 por - */
          printf("  -  ");
        }else{
          printf("%4d ", grelha[i][j]); /*guarda espaco para 4digitos possiveis(max2048)*/
        }
        printf(" | ");
      }
    printf("\n");
  }
}

/*------------------------------------------------------------------------------------*/

/*A funcao adiciona aleatoriamente na grelha uma casa com um 2 ou um 4 apos uma jogada executada*/
void adiciona(int grelha[TAM][TAM], int sz){
  int i, j, aleatorio = 0;

	for(int k=0; k<sz; k++){
		for(int z=0; z<sz; z++){
  		if(grelha[k][z]==0){
  			do{
	  			i = rand() % sz ;
	  			j = rand() % sz ;
				}while(grelha[i][j]!=0);

				do{
					grelha[i][j] = 2 + (rand() % 3);
  			}while (grelha[i][j] == 3);

  			return;
  		}

  	}
  }

}


/*-------------------------------------------------------------------------------------*/

/*Funcao caso seja escolhido o sentido baixo*/

int baixo(int grelha[TAM][TAM], int sz){
  int combinadas=0;
    for(int i=sz-1; i>=0; i--){ /*corre a matriz sendo a primeira posiçao o canto inferior esquerdo*/
      for(int j=0; j<sz; j++){
     		for(int g=i-1;g>=0;g--){
     			if(grelha[g][j]!=grelha[i][j] && grelha[g][j]!=0){
     				break;
          }
     			if(grelha[g][j]!=0 && grelha[i][j]==grelha[g][j] && grelha[i][j]!=0 && grelha[i][j]!=2048){
     				grelha[i][j] = grelha[i][j] + grelha[g][j];
          	grelha[g][j]=0;
          	combinadas=combinadas+1;
     				break;
     			}
     		}
      }
    }

    for(int i=sz-1; i>0; i--){
      for(int j=0; j<sz; j++){
      	if(grelha[i][j]==0){

      		if(i>0){
      			for(int k=i-1; k>=0; k--){
      				if(grelha[k][j]!=0){
      					if(grelha[i][j]==0){
      						grelha[i][j]=grelha[k][j];
          				grelha[k][j]=0;
      					}
      				}
      			}
					}
        }
      }
		}
  return combinadas;
}


/*-----------------------------------------------------------------------------------------*/
/*Funcao caso seja escolhido o sentido cima*/

int cima(int grelha[TAM][TAM], int sz){
  int combinadas=0;
   for(int i=0; i<sz; i++){ /*corre a matriz sendo a primeira posiçao o canto superior esquerdo*/
     for(int j=0; j<sz; j++){
			for(int g=i+1; g<=sz-1; g++){
     			if(grelha[g][j]!=grelha[i][j] && grelha[g][j]!=0){
     				break;
          }
     			if(grelha[g][j]!=0 && grelha[i][j]==grelha[g][j] && grelha[i][j]!=0 && grelha[i][j]!=2048){
     				grelha[i][j] = grelha[i][j] + grelha[g][j];
          	grelha[g][j]=0;
          	combinadas=combinadas+1;
     				break;
     			}
     		}
     }
   }

   for(int i=0; i<sz; i++){
     for(int j=0; j<sz; j++){
       if(grelha[i][j]==0){

         if(i<sz-1){
           for(int k=i+1; k<=sz-1; k++){
             if(grelha[k][j]!=0){
               if(grelha[i][j]==0){
                 grelha[i][j]=grelha[k][j];
                 grelha[k][j]=0;
               }
             }
           }
         }
       }
     }
   }
 return combinadas;
}


/*---------------------------------------------------------------------------------------*/

/*Funcao caso seja escolhido o sentido direita*/

int direita(int grelha[TAM][TAM], int sz){
int combinadas=0;
 for(int i=sz-1; i>=0; i--){ /*corre a matriz sendo a primeira posiçao o canto inferior direito*/
   for(int j=sz-1; j>=0; j--){
			for(int g=j-1; g>=0; g--){
     			if(grelha[i][g]!=grelha[i][j] && grelha[i][g]!=0){
     				break;
          }
     			if(grelha[i][g]!=0 && grelha[i][j]==grelha[i][g] && grelha[i][j]!=0 && grelha[i][j]!=2048){
     				grelha[i][j] = grelha[i][j] + grelha[i][g];
          	grelha[i][g]=0;
          	combinadas=combinadas+1;
     				break;
     			}
       }
     }
   }

 for(int i=sz-1; i>=0; i--){
   for(int j=sz-1; j>=0; j--){
     if(grelha[i][j]==0){

       if(j>0){
         for(int k=j-1; k>=0; k--){
           if(grelha[i][k]!=0){
             if(grelha[i][j]==0){
              grelha[i][j]=grelha[i][k];
              grelha[i][k]=0;
             }
           }
         }
       }
     }
   }
 }
return combinadas;
}


/*---------------------------------------------------------------------------------------*/

/*Funcao caso seja escolhido o sentido esquerda*/

int esquerda(int grelha[TAM][TAM], int sz){
  	int combinadas=0;
    for(int i=sz-1; i>=0; i--){ /*corre a matriz sendo a primeira posiçao o canto inferior esquerdo*/
      for(int j=0; j<sz; j++){
      	for(int g=j+1; g <= sz-1; g++){
     			if(grelha[i][g] != grelha[i][j] && grelha[i][g] != 0){
     				break;
          }
     			if(grelha[i][g]!=0 && grelha[i][j]==grelha[i][g] && grelha[i][j]!=0 && grelha[i][j]!=2048){
     				grelha[i][j] = grelha[i][j] + grelha[i][g];
          	grelha[i][g]=0;
          	combinadas=combinadas+1;
     				break;
     			}
     		}
      }
    }

    for(int i=sz-1; i>=0; i--){
      for(int j=0; j<sz; j++){
        if(grelha[i][j]==0){

          if(j<sz-1){
            for(int k=j+1; k<=sz-1; k++){
              if(grelha[i][k]!=0){
                if(grelha[i][j]==0){
                  grelha[i][j]=grelha[i][k];
                  grelha[i][k]=0;
                }
              }
            }
          }
        }
      }
    }
 return combinadas;
}


/*-------------------------------------------------------------------------------------------*/
/*funcao que verifica se existem ainda jogadas possiveis para utilizador poder continuar a jogar*/

int verifica (int grelha[TAM][TAM], int sz){
  int jogo=0;

  for(int k=0; k<sz; k++){
    for(int z=0; z<sz; z++){
    	if(grelha[k][z]==0){
				return jogo;
    	}
    }
  }

  for(int i=0; i<sz; i++){
    for(int j=0; j<sz; j++){
    	if(i==0 && j==0){
    		if((grelha[i][j]==grelha[i][j+1] || grelha[i][j]==grelha[i+1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
			else if(i==0 && j==sz-1){
    		if((grelha[i][j]==grelha[i][j-1] || grelha[i][j]==grelha[i+1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
      else if(i==sz-1 && j==0){
    		if((grelha[i][j]==grelha[i][j+1] || grelha[i][j]==grelha[i-1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else if(i==sz-1 && j==sz-1){
    		if((grelha[i][j]==grelha[i][j-1] || grelha[i][j]==grelha[i-1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else if(i==0 && j!=0 && j!=sz-1){
    		if((grelha[i][j]==grelha[i][j+1] || grelha[i][j]==grelha[i+1][j] || grelha[i][j]==grelha[i][j-1]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else if(j==0 && i!=sz-1 && i!=0){
    		if((grelha[i][j]==grelha[i][j+1] || grelha[i][j]==grelha[i-1][j] || grelha[i][j]==grelha[i+1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else if(j==sz-1 && i!=0 && i!=sz-1){
    		if((grelha[i][j]==grelha[i][j-1] || grelha[i][j]==grelha[i+1][j] || grelha[i][j]==grelha[i-1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else if(i==sz-1 && j!=sz-1 && j!=0){
    		if((grelha[i][j]==grelha[i][j-1] || grelha[i][j]==grelha[i-1][j] || grelha[i][j]==grelha[i][j+1]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    	else{
    		if((grelha[i][j]==grelha[i][j-1] || grelha[i][j]==grelha[i-1][j] || grelha[i][j]==grelha[i][j+1] || grelha[i][j]==grelha[i+1][j]) && grelha[i][j]!=2048){
    			return jogo;
    		}
    	}
    }
  }

  jogo=1;

  return jogo;
}




/*-----------------------------------------------------------------------------------------*/

/*A funcao faz a jogada do utilizador conforme o sentido que seja escolhido utilizando as funcoes anteriormente feitas e adiciona as pecas combinadas*/

int jogada(int grelha[TAM][TAM], int sz, char sentido, int jogo){

		int combinadas=0;

		if(sentido == 'C' || sentido == 'c'){

      combinadas = combinadas + cima(grelha, sz);
      adiciona(grelha, sz);
      mostrar(grelha, sz);
      printf("\n");

    }else if(sentido == 'B' || sentido == 'b'){

      combinadas = combinadas + baixo(grelha, sz);
      adiciona(grelha, sz);
      mostrar(grelha, sz);
      printf("\n");

    }else if(sentido == 'E' || sentido == 'e'){

      combinadas = combinadas + esquerda(grelha, sz);
      adiciona(grelha, sz);
      mostrar(grelha, sz);
      printf("\n");

    }else if(sentido == 'D' || sentido == 'd'){

      combinadas = combinadas + direita(grelha, sz);
      adiciona(grelha, sz);
      mostrar(grelha, sz);
      printf("\n");


    }else if(sentido == 'F' || sentido == 'f'){


    }else{

      printf("JOGADA INVALIDA - REVEJA AS ALTERNATIVAS POSSIVEIS DE JOGADA\n");
      printf("\n");
    }

    return combinadas;

}


/*--------------------------------------------------------------------------------------------------*/
/*A funcao gera o tabuleiro inicial apresentando apenas duas casas aleatorias com 2 ou 4*/

void tabuleiro(int grelha[TAM][TAM], int sz){
    int i, j, aleatorias = 0;
    while(aleatorias < 2){
      i = rand() % sz ;
      j = rand() % sz ;
      if(grelha[i][j]==0){
        do{
          grelha[i][j] = 2 + (rand() % 3);
        }while (grelha[i][j] == 3);
        aleatorias++;
      }
    }
  }




/*--------------------------------------------------------------------------------------------*/

/*A funcao conta e imprime o vetor onde foram postos os numeros contados das casas de cada numero que restam ou estao no tabuleiro*/

void imprime_contagem(int grelha [TAM][TAM], int sz){
  int contagem2, contagem4, contagem8, contagem16, contagem32, contagem64, contagem128, contagem256, contagem512, contagem1024, contagem2048;
  contagem2 = 0;
  contagem4 = 0;
  contagem8 = 0;
  contagem16 = 0;
  contagem32 = 0;
  contagem64 = 0;
  contagem128 = 0;
  contagem256 = 0;
  contagem512 = 0;
  contagem1024 = 0;
  contagem2048 = 0;
  int vetor[12];
  for(int i=0; i<sz; i++){
    for(int j=0; j<sz; j++){
      if(grelha[i][j]==2){
        contagem2 ++;
      }
      if(grelha[i][j]==4){
        contagem4 ++;
      }
      if(grelha[i][j]==8){
        contagem8 ++;
      }
      if(grelha[i][j]==16){
        contagem16 ++;
      }
      if(grelha[i][j]==32){
        contagem32 ++;
      }
      if(grelha[i][j]==64){
        contagem64 ++;
      }
      if(grelha[i][j]==128){
        contagem128 ++;
      }
      if(grelha[i][j]==256){
        contagem256 ++;
      }
      if(grelha[i][j]==512){
        contagem512 ++;
      }
      if(grelha[i][j]==1024){
        contagem1024 ++;
      }
      if(grelha[i][j]==2048){
        contagem2048 ++;
      }
    }
  }

      vetor[0] = contagem2;
      vetor[1] = contagem4;
      vetor[2] = contagem8;
      vetor[3] = contagem16;
      vetor[4] = contagem32;
      vetor[5] = contagem64;
      vetor[6] = contagem128;
      vetor[7] = contagem256;
      vetor[8] = contagem512;
      vetor[9] = contagem1024;
      vetor[10] = contagem2048;

 for(int g = 0; g < 11; g++){
    printf("%4d  ",vetor[g]);
 }
}


/*-----------------------------------------------------------------------------------------*/


int main(){
  int sz, jogo, grelha[TAM][TAM] = {0}; /*gera tabuleiro inicial apenas com zeros*/
  int combinadas_geral=0;
  char sentido;
  printf("Qual o tamanho (NxN) desejado do jogo? (TAMANHO MAXIMO = 10)\n");
  scanf("%d", &sz);
  while(sz > 10){ /*corrige erro caso seja introduzido um numero para o tamanho maior que 10*/
    printf("\n");
    printf("TAMANHO DESEJADO INVALIDO\n" );
    printf("\n");
    printf("Qual o tamanho (NxN) desejado do jogo? (TAMANHO MAXIMO = 10)\n");
    scanf("%d", &sz);
  }
  printf("\n");
  srand(time(NULL));
  tabuleiro(grelha, sz); /*gera tabuleiro inicial do jogo*/
  mostrar(grelha,sz); /*imprime o tabuleiro gerado no ecra*/
  jogo=0; /*enquanto o jogo mantiver valor 0 havera jogadas possiveis*/

  while(jogo!=1 && sentido != 'F' && sentido != 'f'){  /*Le cada jogada do utilizador ate haver jogadas possiveis ou ser introduzido 'f'*/

    printf("\n");
    printf("Sabendo das opcoes de jogada ( C --> CIMA | B --> BAIXO | D --> DIREITA | E --> ESQUERDA )\n");
    printf("Qual a sua jogada\n");
    printf("\n");
    scanf("%c\n", &sentido);
    sentido = getchar();
    printf("\n");

		combinadas_geral = combinadas_geral + jogada(grelha, sz, sentido, jogo); /*Adiciona as casas combinadas correspondentes a cada jogada do utilizador*/
		jogo = verifica(grelha, sz);

  }

  mostrar(grelha, sz); /*mostra grelha final*/
  printf("\n");
  jogo = verifica(grelha, sz);
  printf("\n");
  printf("O JOGO CHEGOU AO FIM\n");
  printf("\n");
  printf("Pecas combinadas = %d", combinadas_geral); /*Imprime o total de casas combinadas*/
  printf("\n");
  printf("Contagem: ");
  imprime_contagem(grelha,sz); /*imprime o vetor que contem contagem das casas restantes do tabuleiro por ordem*/

}
