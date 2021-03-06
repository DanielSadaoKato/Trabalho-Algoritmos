#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>

#define bordaY 18
#define bordaX 50


void mgotoxy(int x, int y)
{
 //Define a posição do cursor no buffer da tela do console especificado
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

main()
{
 int x,d=2,cx[300]={15,2},cy[300]={7,7},t=1,mx,my,velo=100,velo2=10;
 char niv;

 char tecla='a';
 int opcao;
 int pontos=0;
 int nivel = 1;
 
 
 
  //219 é o caractere |
  //é necessário usar a funcao mgotoxy para reposicionar o cursor 
  //Esses laços sao para desenhar o quadro com os limites da tela
 for(x=0;x<bordaY;x++)
 { mgotoxy(0,x); //vertical esquerda.//
 printf("%c",219);
 }
 for(x=0;x<bordaX;x++)
 { mgotoxy(x,0); //horizontal ssuperior//
 printf("%c",219);
 }
 for(x=0;x<bordaY;x++)
 { mgotoxy(bordaX,x); //vertical direita//
 printf("%c",219);
 }
 for(x=0;x<bordaX+1;x++)
 { mgotoxy(x,bordaY); //horizontal inferior.//
 printf("%c",219);
 }
 
 
 
 //Geração da comida da cobrinha
 //tamanho deve ser 1 menor do que o do quadro
 srand(time(NULL));
 mx=(rand()%49)+1;
 my=(rand()%17)+1;
 
 //variavel velocidade para a funcao sleep
 velo = 200;
 
 //kbhit espera o usuario pressionar uma tecla
 while(tecla!='p')
 	{ while(tecla!='p'&&!(tecla=kbhit()))
 
 		{ for(x=t;x>0;x--)
 			{ cx[x]=cx[x-1];
			 cy[x]=cy[x-1];
 			}
 			//d recebe um valor modificado de acordo com a tecla pressionada
 			if(d==0)
			 	cx[0]--;
 			if(d==1)
			 	cy[0]--;
 			if(d==2)
			 	cx[0]++;
			if(d==3)
				cy[0]++;
			//rastro	
 			mgotoxy(cx[t],cy[t]);
			printf(" ");
 			
			if(mx==cx[0]&&my==cy[0]){
 				t++;
 				pontos++;
				mx=(rand()%25)+1;
 				my=(rand()%17)+1;
				velo-=5;
 				velo2+=10;
 
 			}
 		
		//criacao da cobrinha com o caractere ||	
 		mgotoxy(cx[0],cy[0]);
 		printf("%c",219);
		
		//primeiro caractere da tabela ASCII e comida da cobrinha
 		mgotoxy(mx,my);
 		printf("%c",1);
 		mgotoxy(55,10);
 		
 		//posicao dos placares e informações
 		printf ("Pontos: %d",pontos);
 		mgotoxy(55,5);
 		printf ("Nivel: %d",nivel);
 		mgotoxy(55,3);
 		printf ("Velocidade: %d",velo2);
 		mgotoxy(3,22);
		
		//Funcao que "pausa" o programa
 		Sleep(velo);
 		for(x=1;x<t;x++){
		 	//verifica se bateu com o corpo 
		 	if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='p';
 			}
 			//verifica se bateu nas bordas
		 	if(cy[0]==0||cy[0]==bordaY||cx[0]==0||cx[0]==bordaX)tecla='p';
 	}
 	
 	//Verifica se o jogo foi parado ou nao
 	//caso nao tenha sido parado, pega o valor com o getch e gracas
 	//ao kbhit(), as setas retornam os valores, 72, 75, 77 e 80 que são 
 	//aos seguintes caracteres da tabela ascii.
	if(tecla!='p')
		tecla=getch();
	if(tecla=='K')//ESQUERDA
		d=0;
	if(tecla=='H')//CIMA
		d=1;
	if(tecla=='M')//DIREITA
		d=2;
	if(tecla=='P')//BAIXO
		d=3;
	if(cy[0]==0||cy[0]==bordaY||cx[0]==0||cx[0]==26)//se bater nas bordas o jogo acaba
		tecla='p';
 }
 
 //limpa a tela	
 system("cls");

 printf ("\n\n\tGAME OVER\n\n");

 printf ("\n\n\tVOCE FEZ %d PONTOS",pontos);
 
getch();

}

/*Referencias: 
 *https://universestudio.wordpress.com/
 *https://www.hardware.com.br/comunidade/include-jogo/1001377/
 *http://linguagemprisma.br4.biz/blog/especial-biblioteca-win-algumas-funcoes-do-windows-h/
 *https://www.tutorialspoint.com/kbhit-in-c-language
*/
