#define MAXSIZE 20
typedef int KeyType;

typedef struct {
  KeyType key;
  InfoType otherinfo;
} RedType;

typedef struct {
  RedType r[MAXSZIE + 1];
  int length;
} SqList;
