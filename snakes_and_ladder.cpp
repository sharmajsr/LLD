/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int getRandomInARange(int min,int max){
    return min+rand()%(max-min+1);
}
class Jump{
    
    int start,end;
    public: 
    Jump(){
        int start = -1;
        int end = -1;
    }
    Jump(int Start,int End){
        this->start = Start;
        this->end = End;
    }
    // bool isNotValid(){
    //     return (this->start == -1 or this->end == -1);
    // }
    int getJumpStart(){
        return this->start;
    }
    int getJumpEnd(){
        return this->end;
    }
};
class Cell{
    Jump jump;
    public:
    Cell(){
        // Jump();
    }
    void setJump(Jump jumpobj){
        this->jump = jumpobj;
    }
    Jump getJump(){
        return this->jump;
    }
    int getCellJumpStart(){
        return this->jump.getJumpStart();
    }
    int getCellJumpEnd(){
        return this->jump.getJumpEnd();
    }
    bool checkIfCellHasValidJump(){
        return (this->jump.getJumpStart() == -1 or this->jump.getJumpEnd() == -1 or this->jump.getJumpStart() >10 or this->jump.getJumpEnd()<10 ) ;
    }
};
class Board{
    int snakes = 5;
    int ladders = 4;
    vector<vector<Cell>>board;
    int boardSize;
    public: 
    Board(){}
    Board(int boardSize,int snakes,int ladders){
        initialiseCells(boardSize);
        addSnakesAndLadders();
        this->boardSize = boardSize;
        this->board.resize(boardSize, vector<Cell>(boardSize));
    }
    void initialiseCells(int boardSize){
        this->board.resize(boardSize, vector<Cell>(boardSize));
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                Cell cellObj ;
                board[i][j]=cellObj;
            }
        }
    }
    void addSnakesAndLadders(){
        int snakes = this->snakes;
        int ladders = this->ladders;
        
        while(snakes>0){
            int snakeHead = getRandomInARange(1,(this->board.size()*this->board.size()));
            int snakeTail = getRandomInARange(1,(this->board.size()*this->board.size()));
            if(snakeTail >= snakeHead){
                continue;
            }
            --snakes;
            Jump snakeObj(snakeHead,snakeTail);
            cout<<"Snake : "<<snakeObj.getJumpStart()<<" "<<snakeObj.getJumpEnd()<<endl;
            Cell cell = getCell(snakeHead);
            cell.setJump(snakeObj);
            
        }
        while(ladders>0){
            int ladderHead = getRandomInARange(1,(this->board.size()*this->board.size()));
            int ladderTail = getRandomInARange(1,(this->board.size()*this->board.size()));
            if(ladderTail >= ladderHead){
                continue;
            }
            --ladders;
            
            Jump ladderObj(ladderTail,ladderHead);
            cout<<"Ladder : "<<ladderObj.getJumpStart()<<" "<<ladderObj.getJumpEnd()<<endl;
            Cell cell = getCell(ladderTail);
            cell.setJump(ladderObj);
            
        }
    }
    Cell getCell(int id){
        int boardSize = this->board.size();
        int row = id%boardSize;
        int col = id/boardSize;
        return this->board[row][col];
    }
    int getSize(){
        return this->boardSize;
    }
};


class Dice{
    int diceCount = 1;
    int minValue = 1 ;
    int maxValue = 6; 
    public: 
    Dice(int noOfDices){
        this->diceCount = noOfDices;
        srand(time(0));
    }
    int rollDice(){
        int randomNumber = getRandomInARange(this->minValue,this->maxValue);
        return randomNumber;
    }
};
class Players{
    int id;
    int curPos;
    string name;
    public:
    Players(int id,int curPos,string name){
        this->id =id;
        this->curPos = curPos;
        this->name= name;
    }
    int getCurPos(){
        return curPos;
    }
    string getName(){
        return this->name;
    }
    void setNewPos(int newPos){
        this->curPos = newPos;
    }
};
int findNextPos(int curPos){
    int a =2;
    return 2;
}
class Game{
    Board *board;
    queue<Players*>playersList;
    Dice *dice;
    bool winner = false;
    public: 
    Game(){}
    
    
    void initialiseGame(int BoardSize,int noOfSnakesAndLadders,int diceCount){
        cout<<"Inside Game Init\n";
        this->board = new Board(BoardSize,noOfSnakesAndLadders,noOfSnakesAndLadders);
        cout<<"Board Initialised\n";
        this->dice = new Dice(diceCount);
        cout<<"Dice Initialised\n";
    }
    void addPlayers(){
        Players *player1 = new Players(1,0,"shubham");
        Players *player2 = new Players(2,0,"surya");
        playersList.push(player1);
        playersList.push(player2);
    }
    void startGame(){
        cout<<"Game Started\n";
        while(!winner){
            Players *player = playersList.front();
            int curPosOfPlayer = player->getCurPos();
            int findNextPos = checkJump(curPosOfPlayer);
            player->setNewPos(findNextPos);
            cout<<player->getName()<<" is now at position "<<findNextPos<<endl;
            cout<<curPosOfPlayer<<" "<<findNextPos<<endl;
            if(findNextPos == 100){
                cout<<player->getName()<<" wins the game.\n";
                winner =true;
            }
            playersList.pop();
            playersList.push(player);
        }
    }
    
    int checkJump(int curPos){
        int boardSize = this->board->getSize();
        int rollDice = this->dice->rollDice(); 
        while((curPos + rollDice) > boardSize * boardSize ){
            rollDice = this->dice->rollDice(); 
            continue;
        }
        int newPos = curPos + rollDice;
        cout<<"NewPos with just roll dice : "<<newPos<<endl;
        Cell cell = this->board->getCell(newPos);
        bool checkIfCellHasValidJump = cell.checkIfCellHasValidJump();
        // Jump newCellJump = cell.checkIfCellHasValidJump();
        if( checkIfCellHasValidJump ){
            // Jump newCellJump = cell.getCell(newPos);
            int cellJumpStart = cell.getCellJumpStart() ;
            int cellJumpEnd = cell.getCellJumpEnd();
            cout<<"cellJumpStart : "<<cellJumpStart<<" cellJumpEnd : "<<cellJumpEnd<<endl;
            if(cellJumpStart > cellJumpEnd){    //snake
                cout<<"Caught by Snake at pos "<<cellJumpStart<<" going to "<< cellJumpEnd<<endl;
            }
            else{  //ladder
                cout<<"Found ladder at pos "<<cellJumpStart<<" going to "<< cellJumpEnd<<endl;
            }
            cout<<"cellJumpEnd setting to new pos "<<cellJumpEnd<<endl;
            newPos = cellJumpEnd;
        }
        
        return newPos;
    } 
};
int main()
{
    srand(time(0));
    Game game;
    game.initialiseGame(10,3,1);
    game.addPlayers();
    game.startGame();
    return 0;
}
