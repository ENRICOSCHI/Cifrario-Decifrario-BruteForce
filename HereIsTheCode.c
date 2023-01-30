#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,chiave,lungh,i,keyFalsa=1;
char input[50];
char p_iniziale[50];
//CIFRARIO
void Cifrare(){
	printf("inserire la parola da cifrare\n");
	scanf("%s",&input);
	
	printf("Inserire la chiave\n");
	scanf("%d",&chiave);

	lungh=strlen(input);//lenght di input
	
	for(i=0;i<lungh;i++){
		if (input[i]+chiave>122)
		 input[i]=input[i]+chiave-26;
		else
		 input[i]=input[i]+chiave;
	}	
	printf("%s\n",input);
}
//DECIFRARIO
void Decifrare(){
	printf("inserire la parola da decifrare\n");
	scanf("%s",&input);
	
	printf("Inserire la chiave\n");
	scanf("%d",&chiave);

	lungh=strlen(input);//lenght di input
	
	for(i=0;i<lungh;i++){
		if (input[i]-chiave<97)
		 input[i]=input[i]-chiave+26;
		else
		 input[i]=input[i]-chiave;
	}	
	printf("%s\n",input);
}
//BRUTE FORCE
void BruteForce(){
	printf("inserire la parola con cui fare il brute force\n");
	scanf("%s",&input);
	for(i=0;i<strlen(input);i++)
		p_iniziale[i]=input[i];//per reimpostare l'input alla parola iniziale
	do{//la chiave inizia da 0 e finisce a 26
		for(i=0;i<strlen(input);i++){
			input[i] = p_iniziale[i];//reimposto la lettera iniziale dell'input
			if (input[i]-chiave<97)
		 		input[i]=input[i]-chiave+26;
			else
		 		input[i]=input[i]-chiave;
	}
		printf("la parola %s con la chiave %d e' uguale a: %s \n",p_iniziale,chiave,input);
		chiave++;//aggiorno la chiave
	}while(chiave<=26);
}

//MAIN
int main(int argc, char *argv[]) {
	do{
		printf("Scegliere tra i 3 tipi di opzione\n1) Cifrare la parola data\n2) Decifrare la parola data\n3) Brute Force\n4) Esci dal programma\n");
		scanf("%d",&n);
		if(n==1)
			Cifrare();	
		if(n==2)
			Decifrare();
		if(n==3)
			BruteForce();
	}while(n!=4);
	return 0;
}
