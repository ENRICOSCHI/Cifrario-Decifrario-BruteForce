#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 



IT ACTUALLY WORK ON A C COMPILER ONLINE



*/
void encrypt(char *message, char *key) {
  int messageLen = strlen(message), keyLen = strlen(key), i, j;
  char newKey[messageLen], encryptedMessage[messageLen], decryptedMessage[messageLen];

  // Crea una nuova chiave con la lunghezza uguale a quella del messaggio
  for(i = 0, j = 0; i < messageLen; ++i, ++j) {
    if(j == keyLen) {
      j = 0;
    }

    newKey[i] = key[j];
  }

  newKey[i] = '\0';

  // Cifra il messaggio utilizzando la nuova chiave
  for(i = 0; i < messageLen; ++i) {
    encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'A';
  }

  encryptedMessage[i] = '\0';

  // Decifra il messaggio cifrato utilizzando la nuova chiave
  for(i = 0; i < messageLen; ++i) {
    decryptedMessage[i] = (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'A';
  }

  decryptedMessage[i] = '\0';

  printf("Messaggio originale: %s\n", message);
  printf("Chiave: %s\n", key);
  printf("Nuova chiave: %s\n", newKey);
  printf("Messaggio cifrato: %s\n", encryptedMessage);
  printf("Messaggio decifrato: %s\n", decryptedMessage);
}

void bruteForce(char *encryptedMessage, int messageLen) {
  char message[messageLen];
  int i, j, key = 0;

  // Prova ogni possibile chiave
  for(key = 1; key <= 26; ++key) {
    for(i = 0; i < messageLen; ++i) {
      message[i] = (((encryptedMessage[i] - key) + 26) % 26) + 'A';
    }

    printf("Chiave: %d - Messaggio decifrato: %s\n", key, message);
  }
}

int main() {
  char message[] = "HELLO";
  char key[] = "WORLD";

  encrypt(message, key);
  printf("\n");

  char encryptedMessage[] = "URYYB";
  int messageLen = strlen(encryptedMessage);

  bruteForce(encryptedMessage, messageLen);

  return 0;
}
