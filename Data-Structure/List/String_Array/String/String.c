/**
 * 顺序
 */
#define MAXLEN 255;
typedef struct {
  char ch[MAXLEN + 1];
  int length;
} SString;

/**
 * 块链
 */
#define CHUNKSIZE 80
typedef struct Chunk {
  char ch[CHUNKSIZE];
  struct Chunk *next;
} Chunk;

typedef struct {
  Chunk *head, *tail;
  int curlen;
} LString;

