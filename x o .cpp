#include<iostream>
using namespace std;

char arra[10]={'0','1','2','3','4','5','6','7','8','9'} ;

int wins();
void board();

int main()
{
    int i , c , player = 1 ;
    char m;

    do
    {
        board(); // to show board
        player = player%2?   1:2; //odd & even
        cout<<"PLAYER "<<player<<" , ENTER A NUMBER : "; //enter input
        cin>>c;
        m = (player%2)? 'X':'O'; //odd 'X' % even 'O'

        if      (c == 1 && arra[1] == '1') arra[1] = m;
        else if (c == 2 && arra[2] == '2') arra[2] = m;
        else if (c == 3 && arra[3] == '3') arra[3] = m;
        else if (c == 4 && arra[4] == '4') arra[4] = m;
        else if (c == 5 && arra[5] == '5') arra[5] = m;
        else if (c == 6 && arra[6] == '6') arra[6] = m;
        else if (c == 7 && arra[7] == '7') arra[7] = m;
        else if (c == 8 && arra[8] == '8') arra[8] = m;
        else if (c == 9 && arra[9] == '9') arra[9] = m;

        else
        {
            cout<<"WRONG NUMBER ";
            player -- ;
        }

        i = wins();
        player++ ;
    }while(i== -1 );

    board();
    if(i == 1)
        cout<<">>>> PLAYER "<<--player<<" WIN ";
    else
        cout<<">>>> GAME DRAW ";
    return 0;
}
/*
    function to return
    1   someone is win
    -1  Game not finished
    O   game draw            */

int wins()
{
    // horizontal (1,2,3) (4,5,6) (7,8,9)
    for(int i=1;i<=9;i=i+3){
      if(arra[i]==arra[i+1]&&arra[i+1]==arra[i+2]) return 1;
    }
    // vertical (1,4,7) (2,5,8) (3,6,9)
    for(int i=1;i<=3;i=i+1){
      if(arra[i]==arra[i+3]&&arra[i+3]==arra[i+6]) return 1;
    }
    //diagonal (1,5,9) (3,5,7)
    if(arra[1]==arra[5]&&arra[5]==arra[9]) return 1;
    if(arra[3]==arra[5]&&arra[5]==arra[7]) return 1;
    //checking if we can take further input
    else if (arra[1] != '1' && arra[2] != '2' && arra[3] != '3'
          && arra[4] != '4' && arra[5] != '5' && arra[6] != '6'
          && arra[7] != '7' && arra[8] != '8' && arra[9] != '9' )
          return 0 ;
    //all possible moves are out and no player is winning so the situation is of draw
    else

       return -1;
}
void board()
{


    cout<<"\n\t\t ___________________________________\n"; // border start

    cout<<"\t\t|                                   |\n"; //border

    cout<<"\t\t|                                   |\n"; //border

    cout<<"\t\t|\t   "<<"  (X) (O) GAME           |\n"; //printing title

    cout<<"\t\t|                                   |\n";  //border

    cout<<"\t\t|   Player 1 (X)  -  Player 2 (O)   |\n\t\t|                                   |\n";  //printing simple info about player

    cout<<"\t\t|\t _________________          |\n"; //border

    cout<<"\t\t|\t|     |     |     |         |\n";  //matrix start

    cout<<"\t\t|\t|  "<<arra[1]<<"  |  "<<arra[2]<<"  |  "<<arra[3]<<"  |         |\n";

    cout<<"\t\t|\t|_____|_____|_____|         |\n";

    cout<<"\t\t|\t|     |     |     |         |\n";

    cout<<"\t\t|\t|  "<<arra[4]<<"  |  "<<arra[5]<<"  |  "<<arra[6]<<"  |         |\n";

    cout<<"\t\t|\t|_____|_____|_____|         |\n";

    cout<<"\t\t|\t|     |     |     |         |\n";

    cout<<"\t\t|\t|  "<<arra[7]<<"  |  "<<arra[8]<<"  |  "<<arra[9]<<"  |         |\n";

    cout<<"\t\t|\t|_____|_____|_____|         |\n";  //matrix ends

    cout<<"\t\t|                                   |\n";  //border

    cout<<"\t\t|                                   |\n"; //border

    cout<<"\t\t|___________________________________|\n\n";  //border ending and last output print.
}


