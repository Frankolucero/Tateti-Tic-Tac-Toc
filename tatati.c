#include <stdio.h>
#include <time.h>

void loop(char c[3][3]);
void intro_Primera(char c[3][3]);
void Tablero(char c[3][3]);
void intro_Yo(char c[3][3]);
void intro_Ia(char c[3][3]);
int Ganador(char c[3][3]);

int main() {
  char c[3][3];
  loop(c);
  return 0;
}

void loop(char c[3][3]) {
  int i, j;

  i = 0;

  intro_Primera(c);

  do {
    system("cls");
    Tablero(c);

    if (i % 2 == 0) {
      intro_Yo(c);
    } else {
      intro_Ia(c);
    }

    j = Ganador(c);
    i++;
  } while (i <= 9 && j == 2);

  system("cls");
  Tablero(c);

  if (j == 0) {
    printf("ganaste\n");

  } else if (j == 1) {
    printf("perdiste\n");
  } else {
    printf("Empate\n");
  }
}

void intro_Primera(char c[3][3]) {
  int i, j;
  char aux;

  aux = '1';
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = aux++;
    }
  }
}

void intro_Yo(char c[3][3]) {
  char aux;
  int i, j, k;
  do {
    do {
      printf("\n");
      printf("Ingrese un numero:");
      fflush(stdin);
      scanf(" %c", &aux);

    } while (aux < '1' || aux > '9');

    k = 0;
    switch (aux) {
    case '1':
      i = 0;
      j = 0;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '2':
      i = 0;
      j = 1;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '3':
      i = 0;
      j = 2;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '4':
      i = 1;
      j = 0;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '5':
      i = 1;
      j = 1;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '6':
      i = 1;
      j = 2;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '7':
      i = 2;
      j = 0;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '8':
      i = 2;
      j = 1;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    case '9':
      i = 2;
      j = 2;
      if (c[i][j] == 'X' || c[i][j] == 'O') {
        k = 1;
        printf("La casilla esta ocupada");
      }
      break;
    }

  } while (k == 1);
  c[i][j] = 'X';
}

void intro_Ia(char c[3][3]) {
  int i, j, k;
  srand(time(NULL));
  do {
    i = rand() % 3;
    j = rand() % 3;
    k = 0;

    if (c[i][j] == 'X' || c[i][j] == 'O') {
      k = 1;
    }
  } while (k == 1);
  c[i][j] = 'O';
}

void Tablero(char c[3][3]) {

  int i, j;
  printf("\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (j < 2) {
        printf(" %c |", c[i][j]);
      } else {
        printf(" %c ", c[i][j]);
      }
    }
    if (i < 2) {
      printf("\n-----------\n");
    }
  }
}

int Ganador(char c[3][3]) {
  if (c[0][0] == 'X' || c[0][0] == 'O') {
    if (c[0][0] == c[0][1] && c[0][0] == c[0][2]) {
      if (c[0][0] == 'X') {
        return 1; // ganaste
      } else {
        return 0; // perdiste
      }
    }
    if (c[0][0] == c[1][0] && c[2][0]) {
      if (c[0][0] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }
  }

  if (c[1][1] == 'X' || c[1][1] == 'O') {

    if (c[1][1] == c[0][0] && c[1][1] == c[2][2]) {
      if (c[1][1] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }

    if (c[1][1] == c[1][0] && c[1][1] == c[1][2]) {
      if (c[1][1] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }

    if (c[1][1] == c[2][0] && c[1][1] == c[0][2]) {
      if (c[1][1] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }

    if (c[1][1] == c[0][1] && c[1][1] == c[2][1]) {
      if (c[1][1] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }
  }

  if (c[2][2] == 'X' || c[2][2] == 'O') {

    if (c[2][2] == c[2][0] && c[2][2] == c[2][1]) {

      if (c[2][2] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }

    if (c[2][2] == c[0][2] && c[2][2] == c[1][2]) {

      if (c[2][2] == 'X') {
        return 0; // ganaste
      } else {
        return 1; // perdiste
      }
    }
  }

  return 2;

} 