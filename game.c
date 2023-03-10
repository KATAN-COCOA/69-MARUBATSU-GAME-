#include <stdio.h>
#define ROW 3
#define COLUMN 3

void now();
void enter(int player);
int judge_victory();
int judge_place(int row, int column);

int map[ROW][COLUMN];

int main(){

  int flag;

  //仕様説明
  printf("\n\nplayer1 -> 6\n");
  printf("player2 -> 9\n\n");


  //配列を初期化
  for(int i = 0; i < ROW; i++){
      for(int j = 0; j < COLUMN; j++){
        map[i][j] = 0;
      }
    }

  //スタート演出
  printf("=====START=====\n\n");
  //本体
  while(1){
    flag = 0;
    now();
    printf("\nplayer1's turn\n");
    enter(1);
    flag = judge_victory();
    printf("%d\n", flag);
    if(flag != 0){
      break;
    }
    now();
    printf("\nplayer2's turn \n");
    enter(2);
    flag = judge_victory();
    printf("%d\n", flag);
    if(flag != 0){
      break;
    }
  }

  //勝利演出
  now();
  printf("\n\n*****WINNER*****\n");
  if(flag == 1){
    printf("PLAYER1!!!");
  }else if(flag == 2){
    printf("PLAYER2!!!");
  }
  printf("\n");


  return 0;
}

//現在の盤面を表示
void now(){
  printf("====NOW====\n");
  for(int i = 0; i < ROW; i++){
    for(int j = 0; j < COLUMN; j++){
      printf("%d", map[i][j]);
    }
    printf("\n");
  }
  printf("===========\n");
}

//入力
void enter(int player){
  int p1_r = 0, p1_c = 0;
  int p2_r = 0, p2_c = 0;

  int flag = 0;

  if(player == 1){
    while(1){
      printf("Where?\n");
      printf("row>>>");
      scanf("%d", &p1_r);
      printf("column>>>");
      scanf("%d", &p1_c);
      flag = judge_place(p1_r, p1_c);
      if(flag != 0){
        break;
      }
    }
    map[p1_r][p1_c] = 6;
  }else if(player == 2){
    while(1){
      printf("Where?\n");
      printf("row>>>");
      scanf("%d", &p2_r);
      printf("column>>>");
      scanf("%d", &p2_c);
      flag = judge_place(p2_r, p2_c);
      if(flag != 0){
        break;
      }
    }
    map[p2_r][p2_c] = 9;
  }
}

int judge_place(int row, int column){

  if(map[row][column] != 0){
    printf("\n#####CAUTION#####\n");
    printf("This place is already used!\n\n");
    return 0;
  }

  return 1;
}

//勝利判定
int judge_victory(){

  //横判定
  if(map[0][0] == 6 && map[0][1] == 6 && map[0][2] == 6){
    return 1;
  }else if(map[0][0] == 9 && map[0][1] == 9 && map[0][2] == 9){
    return 2;
  }else if(map[1][0] == 6 && map[1][1] == 6 && map[1][2] == 6){
    return 1;
  }else if(map[1][0] == 9 && map[1][1] == 9 && map[1][2] == 9){
    return 2;
  }else if(map[2][0] == 6 && map[2][1] == 6 && map[2][2] == 6){
    return 1;
  }else if(map[2][0] == 9 && map[2][1] == 9 && map[2][2] == 9){
    return 2;
  }

  //縦判定
  if(map[0][0] == 6 && map[1][0] == 6 && map[2][0] == 6){
    return 1;
  }else if(map[0][0] == 9 && map[1][0] == 9 && map[2][0] == 9){
    return 2;
  }else if(map[0][1] == 6 && map[1][1] == 6 && map[2][1] == 6){
    return 1;
  }else if(map[0][1] == 9 && map[1][1] == 9 && map[2][1] == 9){
    return 2;
  }else if(map[0][2] == 6 && map[1][2] == 6 && map[2][2] == 6){
    return 1;
  }else if(map[0][2] == 9 && map[1][2] == 9 && map[2][2] == 9){
    return 2;
  }

  //斜め判定
  if(map[0][0] == 6 && map[1][1] == 6 && map[2][2] == 6){
    return 1;
  }else if(map[0][0] == 9 && map[1][1] == 9 && map[2][2] == 9){
    return 2;
  }

  return 0;
}
