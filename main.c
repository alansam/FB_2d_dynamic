/*
how to change character in particular string
for example: 
  collection[0][0] = 'A';
  collection[1][1] = 'P';
  
  doing this gives segment error

and how to print this character by character like example 1.0 below
(for char type pointer to pointer)
  example 1.0:
    char *str = "apple";
    char *cpstr = str;
    while (*cpstr != '\0')
      putchar(*cpstr++);
 
*/
//below is the code..

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 5

static
inline
void show(size_t const row, size_t const col, char const ** collection);
static
inline
void sho_arr(size_t const msz, size_t const rows, size_t const cols, char const * arr);
static
void oneway(void);
static
void anotherway(void);

/*
 *  MARK:  main()
 */
int main(int argc, char const * argv[]) {

  puts("----+----|----+----|----+----|----+----|----+----|");
  oneway();
  putchar('\n');

  puts("----+----|----+----|----+----|----+----|----+----|");
  anotherway();
  putchar('\n');

  printf("complete\n");

  return EXIT_SUCCESS;
}

/*
 *  MARK:  oneway()
 */
static
void oneway(void) {
  printf("In function %s()\n", __func__);

  const char * str = "apple";
  size_t const str_sz = strlen(str);
  char ** collection = malloc(ROWS * sizeof(char *));
  if (collection == NULL) {
    fprintf(stderr,
            "malloc of %d rows of char * failed\n", ROWS);
    exit(EXIT_FAILURE);
  }
  else {
    printf("malloc allocated %d rows of char * at %p\n",
           ROWS, collection);
  }
  putchar('\n');

  for (size_t r_ = 0ul; r_ < ROWS; ++r_) {
    collection[r_] = malloc(str_sz * sizeof(char) + 1);
    if (collection[r_] == NULL) {
      fprintf(stderr,
              "malloc of row[%zu] of %zu char failed\n",
              r_, str_sz * sizeof(char) + 1);
      exit(EXIT_FAILURE);
    }
    else {
      printf("allocated %zu chars at %p stowed at %p\n",
             str_sz * sizeof(char) + 1,
             collection[r_], &collection[r_]);
    }
  }
  putchar('\n');

  for (size_t r_ = 0ul; r_ < ROWS; ++ r_) {
    printf("%p\n", &collection[r_]);
  }
  putchar('\n');

  for (size_t r_ = 0ul; r_ < ROWS; ++r_) {
    strcpy(collection[r_], str);
  }

  show(ROWS, str_sz + 1, (char const **) collection);
  putchar('\n');

  // collection[0][0] = 'A';
  // collection[1][1] = 'P';
  // collection[2][2] = 'P';
  // collection[3][3] = 'L';
  // collection[4][4] = 'E';
  collection[0][0] = toupper(collection[0][0]);
  collection[1][1] = toupper(collection[1][1]);
  collection[2][2] = toupper(collection[2][2]);
  collection[3][3] = toupper(collection[3][3]);
  collection[4][4] = toupper(collection[4][4]);

  show(ROWS, str_sz + 1, (char const **) collection);
  putchar('\n');

  printf("\nrelease row memory\n");
  for (size_t r_ = 0ul; r_ < ROWS; ++r_) {
    free(collection[r_]);
  }
  printf("release pointer memory\n");
  free(collection);
  putchar('\n');

  return;
}

/*
 *  MARK:  show()
 */
static
inline
void show(size_t const row, size_t const col, char const ** collection) {
  printf("In function %s(%zu, %zu, %p)\n",
         __func__, row, col, collection);

  for (size_t r_ = 0ul; r_ < row; ++r_) {
    for (size_t c_ = 0ul; c_ < col; ++c_) {
      if (iscntrl(collection[r_][c_])) {
        putchar('\n');
      }
      else {
        putchar(collection[r_][c_]);
      }
    }
  }

  return;
}

/*
 *  MARK:  anotherway()
 */
static
void anotherway(void) {
  printf("In function %s()\n", __func__);

  size_t const rows = 5ul;
  char const * const apple = "apple";
  size_t const cols = strlen(apple) + 1;
  size_t const msz = rows * cols;

  printf("%zu %zu %zu %zu\n",
         rows, cols, msz, cols * rows);
  char * arr = malloc(msz);

  for (size_t i_ = 0ul; i_ < rows; ++i_) {
    printf("%p\n", arr + cols * i_);
    strcpy(arr + cols * i_, apple);
  }
  putchar('\n');

  sho_arr(msz, rows, cols, arr);
  putchar('\n');

  for (size_t p_ = 0ul; p_ < rows; ++p_) {
    printf("%p %c %c\n",
           (arr + cols * p_ + p_),
           *(arr + cols * p_ + p_),
           toupper(*(arr + cols * p_ + p_)));
    *(arr + cols * p_ + p_) = toupper(*(arr + cols * p_ + p_));
  }
  putchar('\n');

  sho_arr(msz, rows, cols, arr);
  putchar('\n');

  free(arr);

  return;
}

/*
 *  MARK:  sho_arr()
 */
static
inline
void sho_arr(size_t const msz, size_t const rows, size_t const cols, char const * arr) {
  printf("In function %s(%zu, %zu, %zu, %p)\n",
         __func__, msz, rows, cols, arr);

  printf("%p: ", arr);
  for (size_t c_ = 0ul; c_ < msz; ++c_) {
    if (iscntrl(*(arr + c_))) {
      putchar('.');
    }
    else {
      putchar(*(arr + c_));
    }
  }
  putchar('\n');
  putchar('\n');

  for (size_t i_ = 0ul; i_ < rows; ++i_) {
    printf("%p: ", arr + cols * i_);
    printf("%s\n", arr + cols * i_);
  }
  putchar('\n');

  return;
}
