							/*			Abdelkader FELLAGUE ==>	a.fellague27@gmail.com			*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct code
{
	char all[12]="";
	char mnm[5] ="";
	char reg[4] ="";
	int  val;
	int  val1;
	int  val2;
	int  CO;
	int  RA;
	int  R0;
	int  R1;
	int  R2;
};
void display(code array[], int, int);
int main()
{
	char chaine[6] = "", ch[4] = "", ai[3] = "", ne[4] = "";
	int R0, nbr, address, nbr_ins, pas;
	code array[15];
	array[0].val = 0;
	printf("In our program, we treat the instructions:\n\nLOAD, ADD, DIV, MUL, INC, DEC, SUB, HALT\n\n\n");
	printf("We use three reg R0, R1 et R2\n\nOperation_Code Destination Source\n\n\n");
	do
	{
		printf("\nEnter the number of instructions: ");
		while(!scanf("%d", &nbr))
		{
			printf("Must be Integer !!!\n");
			rewind(stdin);
			printf("\nEnter the number of instructions: ");
		}
	}while(nbr < 0);
	if(!nbr)
	{
		printf("No Exercice !!!\n");
		return 0;
	}
	do
	{
		printf("\nEnter the first address: ");
		while(!scanf("%d", &address))
		{
			printf("Must be Integer !!!\n");
			rewind(stdin);
			printf("\nEnter the first address: ");
		}
	}while(address < 0);
	do
	{
		printf("\nEnter the step: ");
		while(!scanf("%d", &pas))
		{
			printf("\n Must be integer !!!\n");
			rewind(stdin);
			printf("\nEnter the step: ");
		}
	}while(pas <= 0);
	gets(chaine);
	for(int nbr_ins = 0; nbr_ins < nbr; nbr_ins++)
	{
		char ne[4] = "";
		printf("\nEnter the instruction %d: ", nbr_ins+1);
		gets(chaine);
		int i = 0, j = 0, k = 0, ind = 0;
		while(chaine[ind])
		{
			array[nbr_ins].all[ind] = chaine[ind];
			ind++;
		}
		while(chaine[i] != ' ' && chaine[i] != '\0')
		{
			array[nbr_ins].mnm[i] = chaine[i];
			i++;
		}
		i++;
		while(chaine[i] != ' ' && chaine[i] != '\0')
		{
			array[nbr_ins].reg[j] = chaine[i];
			i++;
			j++;
		}
		i++;
		while(chaine[i] != '\0')
		{
			ne[k] = chaine[i];
			i++;
			k++;
		}
		array[nbr_ins].RA = address + nbr_ins*pas;
		int stc = atoi(ne);
		if(array[nbr_ins].mnm[0] == 'H' || array[nbr_ins].mnm[0] == 'h')
		{
			array[nbr_ins].val = array[nbr_ins-1].val;
			array[nbr_ins].val1 = array[nbr_ins-1].val1;
			array[nbr_ins].val2 = array[nbr_ins-1].val2;
		}
		else if(array[nbr_ins].reg[1] == '0')
			{
				array[nbr_ins].R0 = stc;
				if     (array[nbr_ins].mnm[0] == 'L' || array[nbr_ins].mnm[0] == 'l') array[nbr_ins].val = stc;
				else if(array[nbr_ins].mnm[0] == 'A' || array[nbr_ins].mnm[0] == 'a') array[nbr_ins].val = array[nbr_ins-1].val + stc;
				else if(array[nbr_ins].mnm[0] == 'S' || array[nbr_ins].mnm[0] == 's') array[nbr_ins].val = array[nbr_ins-1].val - stc;
				else if(array[nbr_ins].mnm[0] == 'M' || array[nbr_ins].mnm[0] == 'm') array[nbr_ins].val = array[nbr_ins-1].val * stc;
				else if(array[nbr_ins].mnm[0] == 'I' || array[nbr_ins].mnm[0] == 'i')
				{
					array[nbr_ins].val = array[nbr_ins-1].val + 1;
					array[nbr_ins].R0 = 1;
				}
				else if((array[nbr_ins].mnm[0] == 'd' || array[nbr_ins].mnm[0] == 'D')&&(array[nbr_ins].mnm[1] == 'i' || array[nbr_ins].mnm[1] == 'I'))
				{
					if(stc) array[nbr_ins].val = array[nbr_ins-1].val / stc;
					else
					{
						printf("\nException: Division by zero\n");
						nbr_ins--;
					}
				}
				else if(array[nbr_ins].mnm[0] == 'D' || array[nbr_ins].mnm[0] == 'd')
				{
					array[nbr_ins].val = array[nbr_ins-1].val - 1;
					array[nbr_ins].R0 = 1;
				}
				if(nbr_ins)
				{
					array[nbr_ins].val1 = array[nbr_ins-1].val1;
					array[nbr_ins].val2 = array[nbr_ins-1].val2;
				}
				else
				{
					array[nbr_ins].val1 = 0;
					array[nbr_ins].val2 = 0;
				}
			}
			else if(array[nbr_ins].reg[1] == '1')
				{
					array[nbr_ins].R0 = stc;
					if     (array[nbr_ins].mnm[0] == 'L' || array[nbr_ins].mnm[0] == 'l') array[nbr_ins].val1 = stc;
					else if(array[nbr_ins].mnm[0] == 'A' || array[nbr_ins].mnm[0] == 'a') array[nbr_ins].val1 = array[nbr_ins-1].val1 + stc;
					else if(array[nbr_ins].mnm[0] == 'S' || array[nbr_ins].mnm[0] == 's') array[nbr_ins].val1 = array[nbr_ins-1].val1 - stc;
					else if(array[nbr_ins].mnm[0] == 'M' || array[nbr_ins].mnm[0] == 'm') array[nbr_ins].val1 = array[nbr_ins-1].val1 * stc;
					else if(array[nbr_ins].mnm[0] == 'I' || array[nbr_ins].mnm[0] == 'i')
					{
						array[nbr_ins].val1 = array[nbr_ins-1].val1 + 1;
						array[nbr_ins].R1 = 1;
					}
					else if((array[nbr_ins].mnm[0] == 'd' || array[nbr_ins].mnm[0] == 'D')&&(array[nbr_ins].mnm[1] == 'i' || array[nbr_ins].mnm[1] == 'I'))
					{
						if(stc) array[nbr_ins].val1 = array[nbr_ins-1].val1 / stc;
						else
						{
							printf("\nException: Division by zero\n");
							nbr_ins--;
						}
					}
					else if(array[nbr_ins].mnm[0] == 'D' || array[nbr_ins].mnm[0] == 'd')
					{
						array[nbr_ins].val1 = array[nbr_ins-1].val1 - 1;
						array[nbr_ins].R1 = 1;
					}
					if(nbr_ins)
					{
						array[nbr_ins].val = array[nbr_ins-1].val;
						array[nbr_ins].val2 = array[nbr_ins-1].val2;
					}
					else
					{
						array[nbr_ins].val = 0;
						array[nbr_ins].val2 = 0;
					}
				}
				else if(array[nbr_ins].reg[1] == '2')
				{
					array[nbr_ins].R0 = stc;
					if     (array[nbr_ins].mnm[0] == 'L' || array[nbr_ins].mnm[0] == 'l') array[nbr_ins].val2 = stc;
					else if(array[nbr_ins].mnm[0] == 'A' || array[nbr_ins].mnm[0] == 'a') array[nbr_ins].val2 = array[nbr_ins-1].val2 + stc;
					else if(array[nbr_ins].mnm[0] == 'S' || array[nbr_ins].mnm[0] == 's') array[nbr_ins].val2 = array[nbr_ins-1].val2 - stc;
					else if(array[nbr_ins].mnm[0] == 'M' || array[nbr_ins].mnm[0] == 'm') array[nbr_ins].val2 = array[nbr_ins-1].val2 * stc;
					else if(array[nbr_ins].mnm[0] == 'I' || array[nbr_ins].mnm[0] == 'i')
					{
						array[nbr_ins].val2 = array[nbr_ins-1].val2 + 1;
						array[nbr_ins].R2 = 1;
					}
					else if((array[nbr_ins].mnm[0] == 'd' || array[nbr_ins].mnm[0] == 'D')&&(array[nbr_ins].mnm[1] == 'i' || array[nbr_ins].mnm[1] == 'I'))
					{
						if(stc) array[nbr_ins].val2 = array[nbr_ins-1].val2 / stc;
						else
						{
							printf("\nException: Division by zero\n");
							nbr_ins--;
						}
					}
					else if(array[nbr_ins].mnm[0] == 'D' || array[nbr_ins].mnm[0] == 'd')
					{
						array[nbr_ins].val2 = array[nbr_ins-1].val2 - 1;
						array[nbr_ins].R2 = 1;
					}
					if(nbr_ins)
					{
						array[nbr_ins].val  =  array[nbr_ins-1].val;
						array[nbr_ins].val1 = array[nbr_ins-1].val1;
					}
					else
					{
						array[nbr_ins].val  = 0;
						array[nbr_ins].val1 = 0;
					}
				}
	}
	display(array, nbr, pas);
	printf("\n\n");
	system("pause");
}
void display(code array[], int nbr, int pas)
{
	system("cls");
	system("color A0");
	printf("\n\n\n\t -------------------------------------------------------------------------------");
	printf("\n\t|         |   \t|  \t |      \t|       \t|\t|\t|\t|");
	printf("\n\t|   INS   |  CO\t|   RA\t |      RI\t|      RM\t|  R0\t|  R1\t|  R2\t|");
	printf("\n\t|         |    \t|   \t |      \t|       \t|\t|\t|\t|");
	printf("\n\t|-------------------------------------------------------------------------------|");
	for(int i = 0; i < nbr; i++)
	{
		printf("\n\t|         |    \t|   \t |\t\t|\t\t|\t|\t|\t|");
		if(array[i].mnm[0] == 'H' || array[i].mnm[0] == 'h') printf("\n\t|  DCR %d  | %d\t|  %d\t |  HALT FIN\t|  HALT FIN\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA, array[i].RA, array[i-1].val, array[i-1].val1, array[i-1].val2);
		else if(!i) printf("\n\t|  DCR %d  | %d\t|  %d\t |   %s\t|   %s\t|   /\t|   /\t|   /\t|", i+1, array[i].RA, array[i].RA, array[i].all, array[i].all);
		else   printf("\n\t|  DCR %d  | %d\t|  %d\t |   %s\t|   %s\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA, array[i].RA, array[i].all, array[i].all, array[i-1].val, array[i-1].val1, array[i-1].val2);
		printf("\n\t|         |   \t| \t |\t\t|\t\t|\t|\t|\t|");
		if(!i) printf("\n\t|  FCR %d  | %d\t|  @$%d\t |      //\t|       //\t|   /\t|   /\t|   /\t|", i+1, array[i].RA+pas, array[i].R0);
		else  if(array[i].mnm[0] == 'l' || array[i].mnm[0] == 'L' || array[i].mnm[0] == 'a' || array[i].mnm[0] == 'A' || array[i].mnm[0] == 's' || array[i].mnm[0] == 'S' || array[i].mnm[0] == 'm' || array[i].mnm[0] == 'M' || (( array[i].mnm[0] == 'D' || array[i].mnm[0] == 'd') && ( array[i].mnm[1] == 'I' || array[i].mnm[1] == 'i')))
				 printf("\n\t|  FCR %d  | %d\t|  @$%d\t |      //\t|       //\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].R0, array[i-1].val, array[i-1].val1, array[i-1].val2);
			else printf("\n\t|  FCR %d  | %d\t|  %d\t |      //\t|       //\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].RA, array[i-1].val, array[i-1].val1, array[i-1].val2);
		printf("\n\t|         |   \t| \t |\t\t|\t\t|\t|\t|\t|");
		if(array[i].mnm[0] == 'l' || array[i].mnm[0] == 'L' || array[i].mnm[0] == 'a' || array[i].mnm[0] == 'A' || array[i].mnm[0] == 's' || array[i].mnm[0] == 'S' || array[i].mnm[0] == 'm' || array[i].mnm[0] == 'M' || (( array[i].mnm[0] == 'D' || array[i].mnm[0] == 'd') && ( array[i].mnm[1] == 'I' || array[i].mnm[1] == 'i')))
		{
			if(array[i].mnm[0] == 'L' || array[i].mnm[0] == 'l')
			{
				if(array[i].reg[1] == '1') 		printf("\n\t|  FCE %d  | %d\t|  @$%d\t |      //\t|       %d\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].R0, array[i].val1, array[i].val, array[i].val1, array[i].val2);
				else if(array[i].reg[1] == '0') printf("\n\t|  FCE %d  | %d\t|  @$%d\t |      //\t|       %d\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].R0, array[i].val, array[i].val, array[i].val1, array[i].val2);
				else if(array[i].reg[1] == '2') printf("\n\t|  FCE %d  | %d\t|  @$%d\t |      //\t|       %d\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].R0, array[i].val2, array[i].val, array[i].val1, array[i].val2);
			}
			else printf("\n\t|  FCE %d  | %d\t|  @$%d\t |      //\t|       //\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].R0, array[i].val, array[i].val1, array[i].val2);
		}
		else printf("\n\t|  FCE %d  | %d\t|  %d\t |      //\t|       //\t|   %d\t|   %d\t|   %d\t|", i+1, array[i].RA+pas, array[i].RA, array[i].val, array[i].val1, array[i].val2);
		printf("\n\t|         |   \t| \t |\t\t|\t\t|\t|\t|\t|");
		printf("\n\t -------------------------------------------------------------------------------");
	}
}

