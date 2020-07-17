#include<iostream>
#include<stdlib.h>
using namespace std;
	char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char turn='X';
	bool draw=false;
void display_matrix()
{
    system("cls");
	cout<<"******Alu Cross Game******\n"<<endl;
	cout<<"\tplayer1[X]  \n \tplayer2[O]\n\n\n\n";
	cout<<"\t     |       |     "<<endl;
	cout<<"\t   "<<matrix[0][0] <<" |   "<<matrix[0][1]<< "   | "<<matrix[0][2] <<endl;
	cout<<"\t_____|_______|_____"<<endl;
	cout<<"\t     |       |     "<<endl;
    cout<<"\t   "<<matrix[1][0] <<" |   " <<matrix[1][1]<< "   | "<<matrix[1][2] <<endl;
	cout<<"\t_____|_______|_____"<<endl;
	cout<<"\t     |       |     "<<endl;
    cout<<"\t   "<<matrix[2][0] <<" |   "<<matrix[2][1]<< "   | "<<matrix[2][2] <<endl;
	cout<<"\t     |       |     "<<endl;
}
 void player_turn()
 {
    int choice;
    int row,col;
	if(turn=='X')
    {
		cout<<"player1 [X] turn:";
    }
			else{
                cout<<"player2 [O] turn:";
			}
			cin>>choice;
	switch(choice){
		case 1:row=0;col=0;break;
		case 2:row=0;col=1;break;
		case 3:row=0;col=2;break;
		case 4:row=1;col=0;break;
		case 5:row=1;col=1;break;
		case 6:row=1;col=2;break;
		case 7:row=2;col=0;break;
		case 8:row=2;col=1;break;
		case 9:row=2;col=2;break;
		default:
			cout<<"invalid choice"<<endl;
			break;
	}
			if(turn=='X' && matrix[row][col]!='X' && matrix[row][col]!='O'){
                matrix[row][col]='X';
                turn='O';
			}
			else if(turn=='O' && matrix[row][col]!='X' && matrix[row][col]!='O'){
                matrix[row][col]='O';
                turn='X';
			}
			else{
                cout<<"Already filled!!!!!"<<endl;
                cout<<"please select other";
                player_turn();
			}
}
bool gameover()
{
    //p1 or p2 win
    for(int i=0;i<3;i++)
    {
        if(matrix[i][0]==matrix[i][1] &&matrix[1][0]==matrix[i][2]||matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i] || matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2]||matrix[0][2]==matrix[1][1] && matrix[0][2]==matrix[2][0
           ])
            return false;

    }
    //game draw
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i][j]!='X' && matrix[i][j]!='O')
                return true;
        }
    }
    //draw
    draw=true;
    return false;
}




  int main()
  {
      while(gameover())
      {
            display_matrix();
            player_turn();
            display_matrix();
      }
      if(turn='O' && draw==false)
      {
          cout<<"player1[X] win \n congratulation!!!!"<<endl;
      }
      else if(turn='X'&& draw==false)
      {
          cout<<"player2[O] win \n congratulation!!!!"<<endl;
      }
      else
      {
          cout<<"Game draw"<<endl;
      }
      char opt;
        cout<<"press e exit game and press r to restart game";
        cin>>opt;
        switch(opt)
        {
        case 'r':
            main();
            break;
        case 'e':
            cout<<"default";
            break;
        default:
            cout<<"invalid choice";
        }



}

