#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);
void table();
void menu();
void input();
void checkmove();
int WinLose();
int check();

char a[8][8]={0};
int n = 4, N=4, turn=0, st=0;

int main()
{
    system("cls");
    table();
    menu();
    return 0;
}

void table()
{
    int i, j, k, l,m,o;
    printf("\n       A    B    C    D    E    F    G    H\n\n\n");
    for  (o=1;o<9;++o)
            printf("  %d\n\n\n",o);
    for (i=0; i<9; i++){
        for (l=0; l<25; l++){
            gotoxy(i*5+5,l+3);
            printf("|");
        }
        for (j=0; j<9; j++){
            gotoxy(6, j*3+3);
            for (k=0; k<39; k++)
                printf("-");
        }
    }
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void menu()
{
    system("cls");
    int i;
    table();
    gotoxy(50,0);
    printf("MENU");
    gotoxy(50,3);
    printf("1.player1 (play first)");
    gotoxy(50,6);
    printf("2.player2 (play first)");
    gotoxy(50,9);
    printf("3.exit");
    gotoxy(50,12);
    printf("Enter your choice: ");
    scanf("%d",&i);
    switch(i){
    case 1: input(1);
            break;
    case 2: input(2);
            break;
    case 3: printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            exit(1);
    default :   main();
                break;
    }
}

void input(int turn){

    system("cls");
    table();

    int i,j;
    char Pi,X;
    int Y;

    if (st==0){
    a[0][0] = 'r';
    a[1][0] = 'h';
    a[6][0] = 'g';
    a[7][0] = 's';

    a[0][7] = 'R';
    a[1][7] = 'H';
    a[6][7] = 'G';
    a[7][7] = 'S';

        st=1;
    }

    if (turn==1){

        if (WinLose()==0){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
        }

        for (i=0;i<8;i++)
        for (j=0;j<8;j++){
            if(a[i][j]==0){
                gotoxy(i*5+8,j*3+4);
                printf("");
            }else{
                gotoxy(i*5+8,j*3+4);
                printf("%c",a[i][j]);
            }
        }

        gotoxy(50,15);
        printf("You're player1(Big).");
        gotoxy(50,18);
        printf("Enter your piece: ");
        scanf(" %c",&Pi);
            switch(Pi){
                case 'G': case 'H': case 'R': case 'S':
                        gotoxy(50,21);
                        printf("Enter your position: ");
                        scanf(" %c%d",&X,&Y);
                        if (X>64 && X<73 && Y>0 && Y<9){
                            if (check(Pi,X,Y,1)==1)
                                checkmove(Pi,X,Y,1);
                            else
                                printf("Try again");
                        }
                        else
                            input(1);
                default : input(1);
                        break;
            }
    }
    else
    {

        if (WinLose()==0){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
        }

        for (i=0;i<8;i++)
        for (j=0;j<8;j++){
            if(a[i][j]==0){
                gotoxy(i*5+8,j*3+4);
                printf("");
            }else{
                gotoxy(i*5+8,j*3+4);
                printf("%c",a[i][j]);
            }
        }

        gotoxy(50,15);
        printf("You're player2(Small).");
        gotoxy(50,18);
        printf("Enter your piece: ");
        scanf(" %c",&Pi);
            switch(Pi){
                case 'g': case 'h': case 'r': case 's':
                        gotoxy(50,21);
                        printf("Enter your position: ");
                        scanf(" %c%d",&X,&Y);
                        if (X>64 && X<73 && Y>0 && Y<9){
                            if (check(Pi,X,Y,2)==1)
                                checkmove(Pi,X,Y,2);
                            else
                                printf("Try again");
                        }
                        else
                            input(2);
                default : input(2);
                        break;
            }
    }
}

void checkmove(int Pi, int X, int Y, int turn){
    int i,j;
    if (turn==1){
    for (i=0;i<8;i++)
        for (j=0;j<8;j++)
            if(a[i][j] == Pi)
                a[i][j] = 0;

            if(a[X-65][Y-1]==0)
            {
                gotoxy((X-65)*5+8,(Y-1)*3+4);
                printf(" %c",Pi);
                a[X-65][Y-1]=Pi;
                input(2);
            }
            else
            {
                gotoxy((X-65)*5+8,(Y-1)*3+4);
                printf(" %c",Pi);
                a[X-65][Y-1]=Pi;
                n--;
                input(2);
            }
    }
    else
    {
    for (i=0;i<8;i++)
        for (j=0;j<8;j++)
            if(a[i][j] == Pi)
                a[i][j] = 0;

            if(a[X-65][Y-1]==0)
            {
                gotoxy((X-65)*5+8,(Y-1)*3+4);
                printf(" %c",Pi);
                a[X-65][Y-1]=Pi;
                input(1);
            }
            else
            {
                gotoxy((X-65)*5+8,(Y-1)*3+4);
                printf(" %c",Pi);
                a[X-65][Y-1]=Pi;
                N--;
                input(1);
            }
    }
}

int check(int Pi,int X, int Y,int turn){
    int i,j;
    switch(Pi){
    case 71: case 72: case 103: case 104:
        for (i=0;i<8;i++)
            for (j=0;j<8;j++){
                if(a[i][j] == Pi)
                {
                    if(X-65==i+1 || X-65==i-1){
                        if(Y-1==j+2 || Y-1==j-2)
                            return 1;
                    }
                    if (X-65==i+2 || X-65==i-2){
                        if(Y-1==j+1 || Y-1==j-1)
                            return 1;
                    }
                    else
                        return 0;
                }
            }
    case 82: case 83: case 114: case 115:
        return 1;
    }
}

int WinLose(){
    if (n==0){
        gotoxy(50,24);
        printf("Player1 wins.");
        return 0;
    }
    if (N==0){
        gotoxy(50,24);
        printf("Player2 wins.");
        return 0;
    }
}
