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

int openFile(Product *p[]) {
  DPRINT(printf("File Open\n"));
  FILE *fp = fopen("products.txt", "rt");
  printf("Loading File\n");
  if (fp == NULL) return 0;
  int i = 0;
  for (i = 0; !feof(fp) && i < 100; i++) {
    p[i] = malloc(sizeof(Product));
    fscanf(fp, "%s %d %d %d %d\n", p[i]->name, &p[i]->weight, &p[i]->price,
           &p[i]->stars, &p[i]->star_count);
  }
  fclose(fp);
  printf("Loaded: %d\n", i);
  return i;
}

int saveFile(Product *p[], int count) {
  DPRINT(printf("Save File\n"));
  FILE *fp = fopen("products.txt", "wt");
  int i = 0;
  for (i = 0; i < count; i++) {
    if (p[i] == NULL) continue;
    fprintf(fp, "%s %d %d %d %d\n", p[i]->name, p[i]->weight, p[i]->price,
            p[i]->stars, p[i]->star_count);
  }
  fclose(fp);
  return i;
}