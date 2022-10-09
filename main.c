/*
  Program 2: wumpus, version 2
  Course: CS 211, Fall 2022.
  System: Windows on Replit & CLion
  Author: Moe Abuseini
---------------------------------------------
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // for srand
//--------------------------------------------------------------------------------
void setRoomLayout(int **roomLayout) {
  roomLayout[0][0] = 0;
  roomLayout[0][1] = 0;
  roomLayout[0][2] = 0;
  roomLayout[1][0] = 2;
  roomLayout[1][1] = 5;
  roomLayout[1][2] = 8;
  roomLayout[2][0] = 1;
  roomLayout[2][1] = 3;
  roomLayout[2][2] = 10;
  roomLayout[3][0] = 2;
  roomLayout[3][1] = 4;
  roomLayout[3][2] = 12;
  roomLayout[4][0] = 3;
  roomLayout[4][1] = 5;
  roomLayout[4][2] = 14;
  roomLayout[5][0] = 1;
  roomLayout[5][1] = 4;
  roomLayout[5][2] = 6;
  roomLayout[6][0] = 5;
  roomLayout[6][1] = 7;
  roomLayout[6][2] = 15;
  roomLayout[7][0] = 6;
  roomLayout[7][1] = 8;
  roomLayout[7][2] = 17;
  roomLayout[8][0] = 1;
  roomLayout[8][1] = 7;
  roomLayout[8][2] = 9;
  roomLayout[9][0] = 8;
  roomLayout[9][1] = 10;
  roomLayout[9][2] = 18;
  roomLayout[10][0] = 2;
  roomLayout[10][1] = 9;
  roomLayout[10][2] = 11;
  roomLayout[11][0] = 10;
  roomLayout[11][1] = 12;
  roomLayout[11][2] = 19;
  roomLayout[12][0] = 3;
  roomLayout[12][1] = 11;
  roomLayout[12][2] = 13;
  roomLayout[13][0] = 12;
  roomLayout[13][1] = 14;
  roomLayout[13][2] = 20;
  roomLayout[14][0] = 4;
  roomLayout[14][1] = 13;
  roomLayout[14][2] = 15;
  roomLayout[15][0] = 6;
  roomLayout[15][1] = 14;
  roomLayout[15][2] = 16;
  roomLayout[16][0] = 15;
  roomLayout[16][1] = 17;
  roomLayout[16][2] = 20;
  roomLayout[17][0] = 7;
  roomLayout[17][1] = 16;
  roomLayout[17][2] = 18;
  roomLayout[18][0] = 9;
  roomLayout[18][1] = 17;
  roomLayout[18][2] = 19;
  roomLayout[19][0] = 11;
  roomLayout[19][1] = 18;
  roomLayout[19][2] = 20;
  roomLayout[20][0] = 13;
  roomLayout[20][1] = 16;
  roomLayout[20][2] = 19;
}  // end of setRoomLayout()

//--------------------------------------------------------------------------------
void displayCave() {
  printf(
      "       ______18______             \n"
      "      /      |       \\           \n"
      "     /      _9__      \\          \n"
      "    /      /    \\      \\        \n"
      "   /      /      \\      \\       \n"
      "  17     8        10     19       \n"
      "  | \\   / \\      /  \\   / |    \n"
      "  |  \\ /   \\    /    \\ /  |    \n"
      "  |   7     1---2     11  |       \n"
      "  |   |    /     \\    |   |      \n"
      "  |   6----5     3---12   |       \n"
      "  |   |     \\   /     |   |      \n"
      "  |   \\       4      /    |      \n"
      "  |    \\      |     /     |      \n"
      "  \\     15---14---13     /       \n"
      "   \\   /            \\   /       \n"
      "    \\ /              \\ /        \n"
      "    16---------------20           \n"
      "\n");
}  // end displayCave()
//--------------------------------------------------------------------------------
void displayInstructions() {
  printf(
      "Hunt the Wumpus:                                             \n"
      "The Wumpus lives in a completely dark cave of 20 roomLayout. Each \n"
      "room has 3 tunnels leading to other roomLayout.                   \n"
      "                                                             \n"
      "Hazards:                                                     \n"
      "1. Two roomLayout have bottomless pits in them.  If you go there you fall and die.   \n"
      "2. Two other roomLayout have super-bats.  If you go there, the bats grab you and     \n"
      "   fly you to some random room, which could be troublesome.  Then those bats go \n"
      "   to a new room different from where they came from and from the other bats.   \n"
      "3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and    \n"
      "   is too heavy for bats to lift.  Usually he is asleep.  Two things wake       \n"
      "    him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus   \n"
      "    will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n"
      "    When you move into the Wumpus' room, then he wakes and moves if he is in an \n"
      "    odd-numbered room, but stays still otherwise.  After that, if he is in your \n"
      "    room, he snaps your neck and you die!                                       \n"
      "                                                                                \n"
      "Moves:                                                                          \n"
      "On each move you can do the following, where input can be upper or lower-case:  \n"
      "1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
      "   then a room number.                                                          \n"
      "2. Shoot your guided arrow through a list of up to three adjacent roomLayout, which  \n"
      "   you specify.  Your arrow ends up in the final room.                          \n"
      "   To shoot enter 'S' followed by the number of roomLayout (1..3), and then the      \n"
      "   list of the desired number (up to 3) of adjacent room numbers, separated     \n"
      "   by spaces. If an arrow can't go a direction because there is no connecting   \n"
      "   tunnel, it ricochets and moves to the lowest-numbered adjacent room and      \n"
      "   continues doing this until it has traveled the designated number of roomLayout.   \n"
      "   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You  \n"
      "   automatically pick up the arrow if you go through a room with the arrow in   \n"
      "   it.                                                                          \n"
      "3. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
      "4. Enter 'C' to cheat and display current board positions.                      \n"
      "5. Enter 'D' to display this set of instructions.                               \n"
      "6. Enter 'P' to print the maze room layout.                                     \n"
      "7. Enter 'X' to exit the game.                                                  \n"
      "                                                                                \n"
      "Good luck!                                                                      \n"
      " \n\n");
}  // end displayInstructions()
//--------------------------------------------------------------------------------

// For easier implementation of vars
struct gameVars {
  int moveNumber;
  int player;
  int wumpus;
  int pit1;
  int pit2;
  int bats1;
  int bats2;
  int arrow;
};
void adjacentRoomCheck(struct gameVars *gameInfo, bool *playerIsAlive, int **roomLayout);
//--------------------------------------------------------------------------------
int validMoveCheck(int currentRoom[3], int futureRoom) { return (currentRoom[0] == futureRoom || currentRoom[1] == futureRoom || currentRoom[2] == futureRoom); }  // end validMoveCheck()
//--------------------------------------------------------------------------------
int checkTakenVal(int numRand, int *currentValue, int limit) {
  int found = false;

  for (int i = 0; i < limit; i++) {
    if (numRand == currentValue[i]) {
      found = true;
      break;
    }
  }
  return found;
}  // end checkTakenVal()
//--------------------------------------------------------------------------------
void randomizeVals(int *numRand, int randSize) {
  int currentValue = -1;

  for (int i = 0; i < randSize; i++) {
    do {
      currentValue = rand() % 20 + 1;
    } while (checkTakenVal(currentValue, numRand, i));
    numRand[i] = currentValue;
  }
}

//--------------------------------------------------------------------------------
void assignRandVals(struct gameVars *gameInfo) {
  int *numRand;
  numRand = malloc(sizeof(int) * 7);

  randomizeVals(numRand, 7);
  gameInfo->player = numRand[0];
  gameInfo->wumpus = numRand[1];
  gameInfo->pit1 = numRand[2];
  gameInfo->pit2 = numRand[3];
  gameInfo->bats1 = numRand[4];
  gameInfo->bats2 = numRand[5];
  gameInfo->arrow = numRand[6];

  gameInfo->moveNumber = 1;

  free(numRand);

}  // end assignRandVals()
//--------------------------------------------------------------------------------
void printRoomDetails(struct gameVars gameInfo, int **roomLayout) {
  int currentRoom = gameInfo.player;
  printf("You are in room %d. ", currentRoom);

  int room1 = roomLayout[currentRoom][0];
  int room2 = roomLayout[currentRoom][1];
  int room3 = roomLayout[currentRoom][2];

  int wumpus = gameInfo.wumpus;
  if (room1 == wumpus || room2 == wumpus || room3 == wumpus) {
    printf("You smell a stench. ");
  }

  int pit1Room = gameInfo.pit1;
  int pit2Room = gameInfo.pit2;
  if (room1 == pit1Room || room1 == pit2Room || room2 == pit1Room || room2 == pit2Room || room3 == pit1Room || room3 == pit2Room) {
    printf("You feel a draft. ");
  }

  int bats1 = gameInfo.bats1;
  int bats2 = gameInfo.bats2;
  if (room1 == bats1 || room1 == bats2 || room2 == bats1 || room2 == bats2 || room3 == bats1 || room3 == bats2) {
    printf("You hear rustling of bat wings. ");
  }

  printf("\n\n");
}  // end printRoomDetails()

//--------------------------------------------------------------------------------

void roomPlayerAndBats(struct gameVars *gameInfo, bool *playerIsAlive, int **roomLayout)

{
  int assignNewRooms = -1;

  do {
    assignNewRooms = rand() % 20 + 1;
  } while (assignNewRooms == gameInfo->player);

  int playerOldRoom = gameInfo->player;
  gameInfo->player = assignNewRooms;
  printf("Woah... you're flying! \n");
  printf("You've just been transported by bats to room %d.\n", gameInfo->player);

  do {
    assignNewRooms = rand() % 20 + 1;
  } while (assignNewRooms == gameInfo->player || assignNewRooms == gameInfo->bats1 || assignNewRooms == gameInfo->bats2);

  if (playerOldRoom == gameInfo->bats1) {
    gameInfo->bats1 = assignNewRooms;
  } else {
    gameInfo->bats2 = assignNewRooms;
  }

  int player = gameInfo->player;
  if (player == gameInfo->bats1 || player == gameInfo->bats2 || player == gameInfo->pit1 || player == gameInfo->pit2 || player == gameInfo->wumpus) {
    adjacentRoomCheck(gameInfo, playerIsAlive, roomLayout);
  }
}  // end roomPlayerAndBats()

//--------------------------------------------------------------------------------

void adjacentRoomCheck(struct gameVars *gameInfo, bool *playerIsAlive,

                       int **roomLayout) {
  int player = gameInfo->player;

  if (player == gameInfo->wumpus) {
    if (gameInfo->wumpus % 2 == 1) {
      printf(
          "You hear a slithering sound, as the Wumpus slips away. \n"
          "Whew, that was close! \n");

      gameInfo->wumpus = roomLayout[player][0];

    } else {
      printf(
          "You briefly feel a slimy tentacled arm as your neck is snapped. \n"
          "It is over.\n");
      *playerIsAlive = false;
      return;
    }
  }

  if (player == gameInfo->pit1 || player == gameInfo->pit2) {
    printf("Aaaaaaaaahhhhhh....   \n");
    printf("    You fall into a pit and die. \n");
    *playerIsAlive = false;
    return;
  }

  if (gameInfo->player == gameInfo->bats1 || gameInfo->player == gameInfo->bats2) {
    roomPlayerAndBats(gameInfo, playerIsAlive, roomLayout);
  }
}  // end adjacentRoomCheck()
//--------------------------------------------------------------------------------

void arrowHandling(struct gameVars *gameInfo, bool *playerIsAlive, bool *wumpusIsAlive, int **roomLayout) {
  int *roomForArrow;
  int numRoomArrow = 0;

  printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
  scanf("%d", &numRoomArrow);
  if (numRoomArrow > 3) {
    printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");
    numRoomArrow = 3;
  }

  roomForArrow = malloc(sizeof(int) * numRoomArrow);

  for (int i = 0; i < numRoomArrow; i++) {
    scanf("%d", &roomForArrow[i]);
  }

  gameInfo->arrow = gameInfo->player;
  for (int i = 0; i < numRoomArrow; i++) {
    if (validMoveCheck(roomLayout[gameInfo->arrow], roomForArrow[i])) {
      gameInfo->arrow = roomForArrow[i];

      if (gameInfo->arrow == gameInfo->wumpus) {
        *wumpusIsAlive = false;
        printf(
            "Wumpus has just been pierced by your deadly arrow! \n"
            "Congratulations on your victory, you awesome hunter you.\n");
        return;
      }

      if (gameInfo->arrow == gameInfo->player) {
        *playerIsAlive = false;
        printf(
            "You just shot yourself.  \n"
            "Maybe Darwin was right.  You're dead.\n");
        return;
      }
    } else {
      printf("Room %d is not adjacent.  Arrow ricochets...\n", roomForArrow[i]);

      gameInfo->arrow = roomLayout[gameInfo->arrow][0];

      if (gameInfo->arrow == gameInfo->player) {
        *playerIsAlive = false;
        printf(
            "You just shot yourself, and are dying.\n"
            "It didn't take long, you're dead.\n");
        return;
      }

      if (gameInfo->arrow == gameInfo->wumpus) {
        *wumpusIsAlive = false;
        printf(
            "Your arrow ricochet killed the Wumpus, you lucky dog!\n"
            "Accidental victory, but still you win!\n");
        return;
      }
    }
  }

  gameInfo->wumpus = roomLayout[gameInfo->wumpus][0];

  free(roomForArrow);
}  // end arrowHandling()

//--------------------------------------------------------------------------------

void menuChoiceR(struct gameVars *gameInfo) {
  printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: \n");

  scanf(" %d %d %d %d %d %d %d", &gameInfo->player, &gameInfo->wumpus, &gameInfo->pit1, &gameInfo->pit2, &gameInfo->bats1, &gameInfo->bats2, &gameInfo->arrow);
  printf("\n");
}

//--------------------------------------------------------------------------------
void menuChoiceC(struct gameVars gameInfo) {
  printf(
      "Cheating! Game elements are in the following rooms: \n"
      "Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
      "%4d %5d %6d %5d %5d %5d %5d \n\n",
      gameInfo.player, gameInfo.wumpus, gameInfo.pit1, gameInfo.pit2, gameInfo.bats1, gameInfo.bats2, gameInfo.arrow);
}
//--------------------------------------------------------------------------------
// void newPlayerAndBatsRoom(int *player, int *pit1, int *pit2, int *wumpus, int *bats1, int *bats2) {
//   *bats1 = rand() % 20 + 1;
//   if (*bats1 == *pit1 || *bats1 == *pit2 || *bats1 == *wumpus || *bats1 == *player) {
//     *bats1 = rand() % 20 + 1;
//   }
//   *bats2 = rand() % 20 + 1;
//   if (*bats2 == *pit1 || *bats2 == *pit2 || *bats2 == *wumpus || *bats2 == *player || *bats2 == *bats1) {
//     *bats2 = rand() % 20 + 1;
//   }
//   *player = rand() % 20 + 1;
//   if (*player == *pit1 || *player == *pit2 || *player == *wumpus || *player == *bats1 || *player == bats2) {
//     *player = rand() % 20 + 1;
//   }
// } // end newPlayerAndBatsRoom()
//--------------------------------------------------------------------------------
int main(void) {
  struct gameVars gameInfo;
  int moveNum = 1;
  int futureRoom;
  char menuOption;
  bool playerIsAlive = true;
  bool wumpusIsAlive = true;

  srand(1);  // srand(time(0));

  int **roomLayout = malloc(21 * sizeof(int *));

  for (int i = 0; i < 21; i++) {
    roomLayout[i] = (int *)malloc(sizeof(int) * 3);
    for (int j = 0; j < 3; j++) {
      roomLayout[i][j] = 0;
    }
  }

  setRoomLayout(roomLayout);
  assignRandVals(&gameInfo);
  while (playerIsAlive && wumpusIsAlive) {
    printRoomDetails(gameInfo, roomLayout);

    printf("%d. Enter your move (or 'D' for directions): ", gameInfo.moveNumber);

    scanf(" %c", &menuOption);
    if (menuOption == 'D' || menuOption == 'd') {
      displayCave();
      displayInstructions();
      continue;

    } else if (menuOption == 'P' || menuOption == 'p') {
      displayCave();
      continue;
    } else if (menuOption == 'M' || menuOption == 'm') {
      scanf(" %d", &futureRoom);

      if (validMoveCheck(roomLayout[gameInfo.player], futureRoom)) {
        gameInfo.player = futureRoom;

        adjacentRoomCheck(&gameInfo, &playerIsAlive, roomLayout);

        if (gameInfo.arrow == gameInfo.player) {
          printf("Congratulations, you found the arrow and can once again shoot.\n");
          gameInfo.arrow = -1;
        }
      } else {
        printf("Invalid move.  Please retry. \n");
        continue;
      }
    } else if (menuOption == 'S' || menuOption == 's') {
      if (gameInfo.arrow == -1) {
        arrowHandling(&gameInfo, &playerIsAlive, &wumpusIsAlive, roomLayout);
      } else {
        printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
      }
    } else if (menuOption == 'C' || menuOption == 'c') {
      menuChoiceC(gameInfo);
      continue;
    } else if (menuOption == 'R' || menuOption == 'r') {
      menuChoiceR(&gameInfo);
      continue;
    } else if (menuOption == 'X' || menuOption == 'x') {
      playerIsAlive = false;
      break;
    }
    gameInfo.moveNumber = gameInfo.moveNumber + 1;
  }

  for (int i = 0; i < 21; i++) {
    free(roomLayout[i]);
    }
  free(roomLayout);

  printf("\nExiting Program ...\n");
  return 0;
}
