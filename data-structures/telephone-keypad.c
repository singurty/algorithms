#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
//	printf("added entry %p at %d\n", newEntry, index);
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
	Table.entries = malloc(sizeof(entry) * SIZE);
	memset(Table.entries, '\0', SIZE);
}

void printList(word *l) {
	while (l != NULL) {
		printf("%s\n", l->item);
		l = l->next;
	}
}

void printTable() {
	for (int i = 0; i < SIZE; i++) {
		entry* current = Table.entries[i];
		if (current == NULL) {
//			printf("got a null\n");
			continue;
		}
//		printf("i: %d current entry: %p\n", i, current);
		printf("List for key: %d\n", current->key);
		printList(current->words);
	}
}

int getKey(char letter) {
	if (letter >= 'a' && letter <= 'c') {
		return 2;
	}
	if (letter >= 'd' && letter <= 'f') {
		return 3;
	}
	if (letter >= 'g' && letter <= 'i') {
		return 4;
	}
	if (letter >= 'j' && letter <= 'l') {
		return 5;
	}
	if (letter >= 'm' && letter <= 'o') {
		return 6;
	}
	if (letter >= 'p' && letter <= 's') {
		return 7;
	}
	if (letter >= 't' && letter <= 'v') {
		return 8;
	}
	if (letter >= 'w' && letter <= 'z') {
		return 9;
	}
	// unreachable
	return 0;
}

void addWord(char* word) {
	int key = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		key = key + ((pow(10 ,(strlen(word) - i - 1))) * getKey(word[i]));
	}
	insert(key, word);
}

int main() {
	initTable();

	addWord("any");
	addWord("box");
	addWord("boy");
	addWord("cow");
	addWord("pen");
	addWord("air");
	addWord("ala");
	addWord("ale");
	addWord("all");
	addWord("alt");
	addWord("amp");
	addWord("ana");
	addWord("and");
	addWord("ant");
	addWord("any");
	addWord("ape");
	addWord("app");
	addWord("apt");
	addWord("arc");
	addWord("are");
	addWord("ark");
	addWord("arm");
	addWord("art");
	addWord("ash");
	addWord("ask");
	addWord("asp");
	addWord("ass");
	addWord("ate");
	addWord("ave");
	addWord("awe");
	addWord("axe");
	addWord("aye");
	addWord("BAA");
	addWord("bad");
	addWord("bag");
	addWord("ban");
	addWord("bar");
	addWord("bat");
	addWord("bay");
	addWord("bed");
	addWord("bee");
	addWord("beg");
	addWord("bel");
	addWord("ben");

	addWord("water");
	addWord("after");
	addWord("where");
	addWord("right");
	addWord("think");
	addWord("three");
	addWord("years");
	addWord("place");
	addWord("sound");
	addWord("great");
	addWord("again");
	addWord("still");
	addWord("every");
	addWord("small");
	addWord("found");
	addWord("those");
	addWord("never");
	addWord("under");
	addWord("might");
	addWord("while");
	addWord("house");
	addWord("world");
	addWord("below");
	addWord("asked");
	addWord("going");
	addWord("large");
	addWord("until");
	addWord("along");
	addWord("shall");
	addWord("being");
	addWord("often");
	addWord("earth");

	printTable();
}
