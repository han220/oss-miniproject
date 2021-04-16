typedef struct {
  char name[20];
  int weight, price, stars, star_count;
} Product;

int createProduct(Product *p[], int count);
int readProduct(Product p);
int updateProduct(Product *p[]);
int deleteProduct(Product *p[]);

int openFile(Product *p[]);
int saveFile(Product *p[], int count);

void listProduct(Product *p[], int count);
Product *searchProductByName(Product *p[], int count, char *niddle);
int searchProductsByPrice(Product *p[], int count, int price);
int searchProductsByWeight(Product *p[], int count, int weight);

void showMenu();
int selectMenu();
void printProduct(Product *p);
