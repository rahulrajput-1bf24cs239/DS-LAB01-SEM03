#include <stdio.h>

#define Size 10

int hashTable[Size];

void initHashTable() {
    for (int i = 0; i < Size; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % Size;
}

void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        while (hashTable[(index + i) % Size] != -1) {
            i++;
        }
        hashTable[(index + i) % Size] = key;
    }
}

void display() {
    printf("\nHASH TABLE\n");
    for (int i = 0; i < Size; i++) {
        if (hashTable[i] == -1) {
            printf("%d -> Empty\n", i);
        } else {
            printf("%d -> %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int n, key;

    initHashTable();

    printf("Enter the number of Employee records: ");
    scanf("%d", &n);

    printf("Enter the %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

