/*
===============================================================================
   Filename.c
   (c) 2023 Author:

   Description:

===============================================================================
*/


/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* END Includes --------------------------------------------------------------*/


/* typedef -------------------------------------------------------------------*/

/* END typedef ---------------------------------------------------------------*/


/* define --------------------------------------------------------------------*/
    #define ESC        27
    #define MMIN      109
    #define MMAY      77
    #define NMAY      78
    #define NMIN      110
    #define F1       1059
    #define F2       1060
    #define F3       1061
    #define F4       1062
    #define F5       1063
/* END define ----------------------------------------------------------------*/


/* Function prototypes -------------------------------------------------------*/

/* END Function prototypes ---------------------------------------------------*/


/* Global variables ----------------------------------------------------------*/

/* END Global variables ------------------------------------------------------*/


/* Function prototypes user code ----------------------------------------------*/

/* END Function prototypes user code ------------------------------------------*/

int main()
{
/* Local variables -----------------------------------------------------------*/
    int x,y ,i,k,l,array[10][10], row, col, elementoActual, mayor, rowAux, colAux,ubicacionRow,ubicacionCol;
    short opt;
    char menu[][80] = { {"[N]   para agregar filas"}, // Hecho
                        {"[M]   para agregar columnas"}, //Hecho
                        {"Carga de matriz aleatoria NxM [300,600]"}, //hecho
                        {"[F1]  sin repetir"}, //hecho
                        {"[F2]  con valores repetidos"},
                        {"[F3]  Muestra cuantos elementos son mayores que el ultimo"},
                        {"[F4]  Cargar un valor en una posicion especifica"},
                        {"[F5]  Columna Mayor | Fila Menor"},
                        {"[ESC] para salir."},
                        {""}};
    int contador = 0;
/* END Local variables -------------------------------------------------------*/


/* User code -----------------------------------------------------------------*/

    randomize();
    row=8;
    col=8;
// Para obtener matriz sin valores repetidos
    for(x=0;x<row;x++){
        for(y=0;y<col;y++){
            array[x][y] = random(301)+300;
            for(k=0;k<=x;k++){
                if(k==x)
                    colAux=y;
                else
                    colAux = col;

                for(l=0;l<colAux;l++){
                    if(array[x][y]==array[k][l]){
                        y--;
                        l=colAux; // como l es igual a colAux ya sale
                        k=x; //k ya es igual a x sale del otro for
                    }
                }
            }
        }
    }

// Metodo para ordenar una matriz de menor a mayor
    for(x=0;x<row;x++){ // pone el pivot en 0
        for(i=0;i<row;i++){
            for(k=0;k<col;k++){
                for(l=0;l<col;l++){
                    if(array[x][i]<array[k][l]){
                        elementoActual = array[k][l];
                        array[k][l]= array[x][i];
                        array[x][i] = elementoActual;
                    }
                }
            }
        }
    }

    for(x=0;x<row-1;x++){
        for(i=x+1;i<col;i++){

        }
    }

    gotoxy(1,8);
    for(x=0;x<row;x++){
        for(i=0;i<col;i++){
            printf("%5d",array[x][i]);
        }
        printf("\n");
    }

    while(1){
        clrscr();
        _setcursortype(_NOCURSOR);
        textcolor (LIGHTGREEN);

        for(x=0;x<row;x++){
            gotoxy(1,x+8);
            for(i=0;i<col;i++){
                if(opt==F3){
                    if(array[x][i]>array[row-1][col-1]){
                        textcolor ( LIGHTMAGENTA );
                        cprintf("%4d",array[x][i]);
                        textcolor (LIGHTGREEN);
                    }
                    else
                        printf("%4d",array[x][i]);
                }
                else
                    printf("%4d",array[x][i]);
            }
        }


        for(int x=3; x<17;x++){
            gotoxy(53,x+1);
            cprintf("|");
        }
        for(int x=3; x<17;x++){
            gotoxy(113,x+1);
            cprintf("|");
        }
        for(int x=53; x<112;x++){
            gotoxy(x+1,17);
            cprintf("_");
        }
        for(int x=53; x<112;x++){
            gotoxy(x+1,3);
            cprintf("_");
        }
        gotoxy(75,6);
        cprintf("Juego de Array");
        for(int x=0;menu[x][0]!='\0';x++){ // funciona filas ver menu 150920232006
            gotoxy(55,x+7);
            cprintf("%s",menu[x]);
        }

        if((opt=getch())==0)
            opt=getch() + 1000;
        if(opt==ESC)
            break;

        switch(opt){
            case NMAY:
            case NMIN:
                while(1){
                    gotoxy(55,7);
                    cprintf("                            ");
                    gotoxy(55,7);
                    textcolor( LIGHTRED );
                    _setcursortype(_NORMALCURSOR);
                    cprintf("Ingrese Numero de filas: ");
                    scanf("%d",&row);
                    if(row >3 && row <11){
                            clrscr();
                        break;
                    }
                }
                break;
            case MMAY:
            case MMIN:
                while(1){
                    gotoxy(55,8);
                    cprintf("                            ");
                    gotoxy(55,8);
                    textcolor( LIGHTRED );
                    _setcursortype(_NORMALCURSOR);
                    cprintf("Ingrese Numero de columnas: ");
                    scanf("%d",&col);
                    if(col >3 && col <11){
                            clrscr();
                        break;
                    }
                }
                break;
            case F1:
                for(x=0;x<row;x++){
                    for(y=0;y<col;y++){
                        array[x][y] = random(301)+300;
                    for(k=0;k<=x;k++){
                        if(k==x)
                            colAux=y;
                        else
                            colAux = col;

                        for(l=0;l<colAux;l++){
                            if(array[x][y]==array[k][l]){
                                y--;
                                l=colAux; // como l es igual a colAux ya sale
                                k=x; //k ya es igual a x sale del otro for
                                }
                            }
                        }
                    }
                }
                break;
            case F3:
            case F2:
                for(x=0;x<row;x++)
                    for(i=0;i<col;i++)
                        array[x][i] = random(301)+300;
                break;
            case F4:
                gotoxy(55,13);
                cprintf("                                                     ");
                gotoxy(55,13);
                textcolor( LIGHTRED );
                _setcursortype(_NORMALCURSOR);
                cprintf("Ingrese Numero de filas, Columuna: ");
                scanf("%d,%d",&ubicacionRow,&ubicacionCol);


        } //FIn SWITCH

        if(opt==NMAY || opt==NMIN || opt==MMAY || opt==MMIN){
            for(x=0;x<row;x++){
                    for(y=0;y<col;y++){
                        array[x][y] = random(301)+300;
                    for(k=0;k<=x;k++){
                        if(k==x)
                            colAux=y;
                        else
                            colAux = col;

                        for(l=0;l<colAux;l++){
                            if(array[x][y]==array[k][l]){
                                y--;
                                l=colAux; // como l es igual a colAux ya sale
                                k=x; //k ya es igual a x sale del otro for
                                }
                            }
                        }
                    }
                }
        }

    }

/* END User code -------------------------------------------------------------*/

   return 0;
}

