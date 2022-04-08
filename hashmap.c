#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
  long pos=hash(key,map->capacity);
  if (map->buckets[pos]==NULL){
    map->buckets[pos]=createPair(key,value);
    map->current=pos;
    map->size++;
  }
  else
  {
    while(map->buckets[pos] != NULL){
      pos=pos+1;
      if(map->buckets[pos]==NULL){
        map->buckets[pos]=createPair(key,value);
        map->current=pos;
        map->size++;
        break;
      }
    }
    
    
  }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
  long Ncap=capacity;
  HashMap * aux=(HashMap *)malloc(sizeof(HashMap));
  aux->buckets=(Pair**)calloc(Ncap,sizeof(Pair*));
  aux->capacity=Ncap;
  aux->size=0;
  aux->current=-1;
  return aux;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {
  Pair * aux=createPair(map->buckets[0]->key,map->buckets[0]->value);
  map->current=0;
  return aux;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
