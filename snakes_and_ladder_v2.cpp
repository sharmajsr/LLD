/******************************************************************************

SNAKES & LADDERS Game

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int getRandomNumberInARange(int min,int max){
    return min + rand()%(max-min+1);
}
class Player{
  int id;
  int pos ;
  public: 
      Player(int id,int pos):id(id),pos(pos){}
      int getId(){
          return id;
      }
      int getCurrentPosition(){
          return pos;
      }
      void setPosition(int newPos){
          pos = newPos;
      }
  
};
class Dice{
  int min = 0 ;
  int max = 6;
//   Dice()
    public:
    int rollDie(){
        
        //return a rolled die;
        return  getRandomNumberInARange(1,6);
    }

};
class Board{
    vector<int>board;
    unordered_map<int,int>snakeLocation;
    unordered_map<int,int>ladderLocation;
    vector<int>snakes;
    vector<int>ladders;
    public:
        Board(){
            int n = 5;
          for(int i=0;i<n ;i++){
              int snakeHead = getRandomNumberInARange(1,100);
              while(snakeLocation.find(snakeHead) != snakeLocation.end() or ladderLocation.find(snakeHead) != ladderLocation.end()){
                  snakeHead = getRandomNumberInARange(1,100);
              }
              int snakeTail = getRandomNumberInARange(1,snakeHead);
              snakeLocation[snakeHead]=snakeTail;
              
              int ladderHead = getRandomNumberInARange(1,99);
              while(snakeLocation.find(ladderHead) != snakeLocation.end() or ladderLocation.find(snakeHead) != ladderLocation.end()){
                //   cout<<"\ngoing to find ladder tail with ladder head. : "<<ladderHead<<endl;
                  ladderHead = getRandomNumberInARange(1,99);
              }
              int ladderTail = getRandomNumberInARange(ladderHead,100);
            //   cout<<"ladder tail found :" <<ladderTail<<endl;
              ladderLocation[ladderHead]=ladderTail;
          }
          for(auto i : snakeLocation){
              cout<<"Snake Head : "<<i.first<<" Snake Tail : "<<snakeLocation[i.first]<<endl;
          }
          for(auto i : ladderLocation){
              cout<<"Ladder Head : "<<i.first<<" Ladder Tail : "<<ladderLocation[i.first]<<endl;
          }
        }
        int isSnakePresentInPosition(int pos){
            if(snakeLocation.find(pos) != snakeLocation.end()){
                return snakeLocation[pos];
            }
            return -1;
        }
        int isLadderPresentInPosition(int pos){
            if(ladderLocation.find(pos) != ladderLocation.end()){
                return ladderLocation[pos];
            }
            return -1;
        }
};
class Game{
  Board* board;
  Dice dice;
  vector<Player*> playerList;
  public: 
   Game(vector<Player*>players){
       this->board = new Board();
       this->playerList = players;
   }
   void startGame(){
       queue<Player*>q;
       for(auto player : playerList){
           q.push(player);
       }
       while(!q.empty()){
           Player* currentPlayer = q.front();
           q.pop();
           q.push(currentPlayer);
           int dieRoll = dice.rollDie();
           while(dieRoll + currentPlayer->getCurrentPosition() > 100 ){
               dieRoll = dice.rollDie();
           }
           
           int newPos = currentPlayer->getCurrentPosition() + dieRoll;
           if(newPos == 100){
               cout<<"Player "<<currentPlayer->getId()<<" Won !!" ;
               break;
           }
           
           int isSnakePresentAtNewPostion = board->isSnakePresentInPosition(newPos);
           int isLadderPresentAtNewPostion = board->isLadderPresentInPosition(newPos);
           if(isSnakePresentAtNewPostion != -1){
               cout<<"Player : "<<currentPlayer->getId()<<" bitten by snake at pos : "<<newPos<<" , new pos : "<<isSnakePresentAtNewPostion<<endl;
               newPos = isSnakePresentAtNewPostion;
           }
           else if(isLadderPresentAtNewPostion != -1){
               cout<<"Player : "<<currentPlayer->getId()<<" found a ladder at : "<<newPos<<" , new pos : "<<isLadderPresentAtNewPostion<<endl;
               
               newPos = isLadderPresentAtNewPostion;
           }
          cout<<"Player "<<currentPlayer->getId()<<" old pos : "<<currentPlayer->getCurrentPosition()<<" new pos : "<<newPos<<endl;
           currentPlayer->setPosition(newPos);
       }
       
   }
};
int main()
{
    srand(time(0));
    printf("snakes & ladders");
    vector<Player*>playerList;
    Player* p1 = new Player(1,0);
    Player* p2 = new Player(2,0);
    playerList.push_back(p1);
    playerList.push_back(p2);
    // Board* board = new Board();
    Game g1(playerList);
    g1.startGame();
    return 0;
}
