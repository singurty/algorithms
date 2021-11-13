#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

// list of words matching a sequence
typedef struct word {
	char* item;
	struct word* next;
} word;

typedef struct {
	int key;
	word* words;
} entry;

typedef struct {
	entry** entries;
} table;

table Table;

void insertToList(word** headPtr, char* item) {
	word *p;
	p = malloc(sizeof(word));
	p->item = item;
	p->next = *headPtr;
	*headPtr = p;
}

void addNewEntry(int index, int key, char* value) {
	entry* newEntry = malloc(sizeof(entry));
	newEntry->key = key;
	insertToList(&newEntry->words, value);
	Table.entries[index] = newEntry;
}

void insert(int key, char* value) {
	// no collision and new entry
	if (Table.entries[key % SIZE] == NULL) {
		addNewEntry(key % SIZE, key, value);
		return;
	}
	// no collision and old entry
	if (Table.entries[key % SIZE]->key == key) {
		insertToList(&Table.entries[key % SIZE]->words, value);
		return;
	}
	// handle collision by sequential probing open addressing
	for (int i = key % SIZE; i < SIZE; i++) {
		if (Table.entries[i] != NULL) {
			continue;
		}
		addNewEntry(i, key, value);
		return;
	}
	// the other direction
	for (int i = 0; i < key % SIZE; i++) {
		if (Table.entries[i] != NULL) {
			continue;
		}
		addNewEntry(i, key, value);
		return;
	}
}

void initTable() {
	Table.entries = malloc(SIZE);
	memset(Table.entries, '\0', SIZE);
}

int main() {
	initTable();
}
