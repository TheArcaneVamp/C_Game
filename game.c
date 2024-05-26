#include <ncurses.h>
#include <stdlib.h>

typedef struct Player
{
  int xPosition;
  int yPosition;
  int health; 
} Player;

int screenSetUP();

int mapSetUP();

Player *playerSetUp();

int main()
{

  int ch;
  Player *user;
  screenSetUP();

  mapSetUP();

  user = playerSetUp();

  while((ch = getch())!='q')
  {

  }

  getch();

  endwin();

  return 0;
}

int screenSetUP()
{
  initscr();
  //printw("Hello World!");
  noecho();// Prevents from the user typing over the game console
  refresh();

  return 0;
}

int mapSetUP()
{
  mvprintw(13,13,"--------");
  mvprintw(14,13,"|......|");
  mvprintw(15,13,"|......|");
  mvprintw(16,13,"|......|");
  mvprintw(17,13,"|......|");
  mvprintw(18,13,"--------");

  mvprintw(2,40,"--------");
  mvprintw(3,40,"|......|");
  mvprintw(4,40,"|......|");
  mvprintw(5,40,"|......|");
  mvprintw(6,40,"|......|");
  mvprintw(7,40,"--------");
  


}

Player *playerSetUp()
{
  Player *newPlayer;
  newPlayer = malloc(sizeof(Player));
  newPlayer->xPosition = 14;
  newPlayer->yPosition = 14;
  newPlayer->health = 20;

  mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
  move(newPlayer->yPosition, newPlayer->yPosition);

  return newPlayer;
}
