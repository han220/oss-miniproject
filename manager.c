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

int createProduct(Product *p[], int count) {
  DPRINT(printf("Create Product\n"));
  p[count] = malloc(sizeof(Product));
  printf("이름 입력");
  scanf("%s", p[count]->name);
  printf("무게 입력");
  scanf("%d", &p[count]->weight);
  printf("가격 입력");
  scanf("%d", &p[count]->price);
  printf("별점 입력");
  scanf("%d", &p[count]->stars);
  printf("리뷰 인원 입력");
  scanf("%d", &p[count]->star_count);
  return ++count;
}

int updateProduct(Product *p[]) {
  int selected;
  printf("번호 선택");
  scanf("%d", &selected);
  selected--;

  DPRINT(printf("Updating Product %d\n", selected));
  printf("이름 입력");
  scanf("%s", p[selected]->name);
  printf("무게 입력");
  scanf("%d", &p[selected]->weight);
  printf("가격 입력");
  scanf("%d", &p[selected]->price);
  printf("별점 입력");
  scanf("%d", &p[selected]->stars);
  printf("리뷰 인원 입력");
  scanf("%d", &p[selected]->star_count);
  return selected;
}

void printProduct(Product *p) {
  printf("%s %d %d %d(%d)\n", p->name, p->weight, p->price, p->stars,
         p->star_count);
}

void listProduct(Product *p[], int count) {
  printf("이름   무게   가격   별점(인원)\n");

  for (int i = 0; i < count; i++) {
    if (p[i] == NULL) continue;
    printf("%d ", i + 1);
    printProduct(p[i]);
  }
}

int deleteProduct(Product *p[]) {
  printf("삭제할 ID 입력");
  int no;
  scanf("%d", &no);
  no--;  // to index.
  DPRINT(printf("Deleting index: %d", no));

  free(p[no]);
  p[no] = NULL;
  return 1;
}

Product *searchProductByName(Product *p[], int count, char *niddle) {
  for (int i = 0; i < count; i++) {
    if (p[i] == NULL) continue;
    DPRINT(printf("Comparing %s with %s", p[i]->name, niddle));
    if (strcmp(p[i]->name, niddle) == 0) return p[i];
  }
  return NULL;
}

int searchProductsByPrice(Product *p[], int count, int price) {
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (p[i] == NULL) continue;
    DPRINT(printf("Comparing %d with %d price", p[i]->price, price));
    if (p[i]->price == price) {
      printProduct(p[i]);
      found++;
    };
  }
  return found;
}

int searchProductsByWeight(Product *p[], int count, int weight) {
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (p[i] == NULL) continue;
    if (p[i]->weight == weight) {
      printProduct(p[i]);
      found++;
    };
  }
  return found;
}
