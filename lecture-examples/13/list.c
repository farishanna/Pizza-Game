#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

struct list_elem_t{
  void * elem;
  struct list_elem_t *next; // the next element, NULL if none
};

typedef struct list_elem_t list_elem_t;

list_elem_t * list_init(){
  list_elem_t * l = malloc(sizeof(list_elem_t));
  memset(l, 0, sizeof(list_elem_t)); // initialize with 0
  return l;
}

list_elem_t * list_push(list_elem_t * list, void * elem){
  assert(list != NULL);
  list_elem_t * l = malloc(sizeof(list_elem_t));
  l->elem = elem;
  l->next = list->next;
  list->next = l;
  return l;
}

void * list_pop(list_elem_t * list){
  assert(list != NULL);
  if(list->next == NULL) return NULL;
  list_elem_t * next = list->next;
  list->next = next->next;
  void * elem = next->elem;
  free(next);
  return elem;
}

int main(){
  list_elem_t * list = list_init();
  list_push(list, "this");
  list_push(list, "is");
  list_push(list, "a");
  list_push(list, "test");

  // we can iterate through the list:
  for(list_elem_t * cur = list->next; cur != NULL; cur = cur->next){
    printf("%s ", (char const*) cur->elem);
  }
  printf("\n");

  void * first_elem = list_pop(list);
  printf("First: %s\n", (char const*) first_elem);

  return 0;
}
