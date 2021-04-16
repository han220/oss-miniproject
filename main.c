#include <stdio.h>

#include "manager.h"

int main(void) {
  Product *p[100];
  int count = openFile(p);
  int selectOption = 0;

  int search;
  int price, weight;
  char name[20];

  while (1) {
    showMenu();
    selectOption = selectMenu();
    switch (selectOption) {
      case 1:
        listProduct(p, count);
        break;
      case 2:
        count = createProduct(p, count);
        break;
      case 3:
        updateProduct(p);
        break;
      case 4:
        deleteProduct(p);
        break;
      case 5:
        printf("Search Method. 1 - Name, 2 - Price, 3 - Weight: ");
        scanf("%d", &search);
        switch (search) {
          case 1:
            printf("Insert Name: ");
            scanf("%s", name);
            Product *found = searchProductByName(p, count, name);
            if (found == NULL)
              printf("Nothing Found\n");
            else
              printProduct(found);
            break;
          case 2:
            printf("Search Price: ");
            scanf("%d", &price);
            searchProductsByPrice(p, count, price);
            break;
          case 3:
            printf("Search Price: ");
            scanf("%d", &weight);
            searchProductsByWeight(p, count, weight);
            break;
        }
        break;
      case 6:
        saveFile(p, count);
        break;
      case 7:
        printf("BYe Bye\n");
        return 0;
    }
  }
}
