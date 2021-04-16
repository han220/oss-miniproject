#include "manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define DPRINT(f) f
#else
#define DPRINT
#endif

void showMenu() {
  printf("======================\n");
  printf("Select Menu\n");
  printf("1) List Items\n");
  printf("2) Add Item\n");
  printf("3) Update Item\n");
  printf("4) Delete Item\n");
  printf("5) Search Item\n");
  printf("6) Save\n");
  printf("7) Quit\n");
}

int selectMenu() {
  int temp;
  printf("Menu (1-5): ");
  scanf("%d", &temp);
  return temp;
}