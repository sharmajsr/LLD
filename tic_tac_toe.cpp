/******************************************************************************

Basic TicTacToe Game for 2 players on 3x3 matrix

*******************************************************************************/
/******************************************************************************

#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Board{
    // int board[3][3];
    vector<vector<int>>board;
    public:
    Board(){
        int size =3;
        this->board.resize(size,vector<int>(size,-1));
    }
    
};
class Player{
    string name;
    public:
        Player(string na){
            this->name = na;
        }
};
class Game{
    vector<vector<int>>board;
    vector<Player> players;
    queue<int>currentChance;
    public:
    Game(int size,Player p1, Player p2){
        // this->board =  Board(size);
        int siz =3;
        this->board.resize(siz,vector<int>(siz,-1));
        this->players.push_back(p1);
        this->players.push_back(p2);
        this->currentChance.push(1);
        this->currentChance.push(2);
        cout<<"Board and players loaded \n";
    }
    
    void printBoard(){
        cout<<"Printing Board...\n";
        for(int i=0;i<this->board.size();i++){
            for(int j=0; j <this->board[0].size();j++){
                if(j != 0 ) cout<<" | "<<board[i][j];
                else    cout<<board[i][j];
            }
            cout<<endl;
            if(i!=board.size()-1)
            for(int j=0;j<board[0].size()*4;j++){
                cout<<"-";
            }
            cout<<endl;
        }
    }
    bool putPiece(int player){
        int row = -1,col= -1;
        while(row<0 and row>=this->board.size() and col<0 and col>=this->board[0].size()){
            cout<<"Please tell the row and col\n";
            cin>>row>>col;
            if(row>=0 and row<this->board.size() and col>=0 and col<this->board[0].size()){
                if(this->board[row][col]!=-1){
                    row =-1;
                    col=-1;
                    cout<<"The place is already occupied\n";
                }
            }
        }
        this->board[row][col]=player;
        Game::hasAnyPlayerWon(row,col,player);
        
    }
    bool hasAnyPlayerWon( int row,int col,int player){
        bool rowWon = true, colWon= true ;
        cout<<"Player : "<<player<<" Row : "<<row<<" col : " <<col<<endl;
        for(int i=0;i<this->board.size();i++){    //col
            if(board[i][col] != player ){
                rowWon = false;
            }
        }
        
        for(int i=0;i<this->board[0].size();i++){    //row
            if(board[row][i] != player ){
                colWon =false;
            }
        }
        
        return rowWon || colWon;
    }
    void startGame(){
        while(!currentChance.empty()){
            int player = currentChance.front();
            currentChance.pop();
            currentChance.push(player);
            Game::printBoard();
            // Game::putPiece(top);
            int row = -1,col= -1;
            while(row<0 and row>=this->board.size() and col<0 and col>=this->board[0].size()){
                cout<<"Please tell the row and col\n";
                cin>>row>>col;
                if(row>=0 and row<this->board.size() and col>=0 and col<this->board[0].size()){
                    if(this->board[row][col]!=-1){
                        row =-1;
                        col=-1;
                        cout<<"The place is already occupied\n";
                    }
                }
            }
            this->board[row][col]=player;
            bool hasAnyPlayerWon = Game::hasAnyPlayerWon(row,col,player);
            if(hasAnyPlayerWon){
                cout<<"Player "<<player<<" Won !!\n";
                break;
                
            }
            
        }
        
    }
    
    
};
int main()
{
    Player p1("s1");
    Player p2("s2");
    Game g1(3,p1,p2);
    g1.startGame();
    return 0;
}
