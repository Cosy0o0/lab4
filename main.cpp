#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

int wczytaj()
{
	int liczba;
	printf("Podaj liczbe: ");
	scanf("%d",&liczba);
	return liczba;
}

void zamiana(int liczba)
{
	int cyfra[8];
	for(int i=0;i<8;i++)
	{
		cyfra[i]=0;
	}
	int ilosc=0;
	if (!liczba) printf("zero ");
	while(liczba)
	{
		ilosc++;
		cyfra[ilosc]=liczba%10;
		liczba=liczba/10;
	}
	if(ilosc==7)
	{
		printf("milion ");
		ilosc=0;
	}
	if(cyfra[4]==1 && ilosc==4) 
	{
		printf ("tysiac ");
		ilosc--;
	}
	while(ilosc)
	{
	bool tysiace=false;
	if(ilosc==6 || ilosc==3)
	{
		switch(cyfra[ilosc])
		{
			case 1: printf("sto "); break;
			case 2: printf("dwiescie "); break;
			case 3: printf("trzysta "); break;
			case 4: printf("czterysta "); break;
			case 5: printf("piecset "); break;
			case 6: printf("szescset "); break;
			case 7: printf("siedemset "); break;
			case 8: printf("osiemset "); break;
			case 9: printf("dziewiecset "); break;
		}
		ilosc--;
	}
	if(ilosc==5 || ilosc==2)
	{
		if(cyfra[ilosc]==1)
		{
			ilosc--;
			switch(cyfra[ilosc])
			{
				case 0: printf("dziesiec "); break;
				case 1: printf("jedenascie "); break;
				case 2: printf("dwanascie "); break;
				case 3: printf("trzynascie "); break;
				case 4: printf("czternascie "); break;
				case 5: printf("pietnascie "); break;
				case 6: printf("szesnascie "); break;
				case 7: printf("siedemnascie "); break;
				case 8: printf("osiemnascie "); break;
				case 9: printf("dziewietnascie "); break;
			}
		}
		else 
		{
			switch(cyfra[ilosc])
			{
				case 2: printf("dwadziescia "); break;
				case 3: printf("trzydziesci "); break;
				case 4: printf("czterdziesci "); break;
				case 5: printf("piecdziesiat "); break;
				case 6: printf("szescdziesiat "); break;
				case 7: printf("siedemdziesiat "); break;
				case 8: printf("osiemdziesiat "); break;
				case 9: printf("dziewiecdziesiat "); break;
			}
			ilosc--;
		}
	}
	if(ilosc==4 || ilosc ==1)
	{
		if (cyfra[ilosc+1]!=1)
		{
			switch(cyfra[ilosc])
			{
				case 1: printf("jeden"); break;
				case 2: printf("dwa "); tysiace=true; break;
				case 3: printf("trzy "); tysiace=true; break;
				case 4: printf("cztery "); tysiace=true; break;
				case 5: printf("piec "); break;
				case 6: printf("szesc "); break;
				case 7: printf("siedem "); break;
				case 8: printf("osiem "); break;
				case 9: printf("dziewiec "); break;
			}
		}
		ilosc--;
	}
	if (ilosc) 
	{
		if(tysiace) printf("tysiace ");
		else printf("tysiecy ");
	}
	}
	printf("\n");

}

int binarna(int liczba)
{
	int k=1;
	for(bool koniec=false;!koniec;k++)
	{
		for(int i=liczba*k;i;)
		{
			if(i%10!=0 && i%10!=1) break;
			i/=10;
			if(!i) 
			{
				koniec=true;
				k--;
			}
		}
	}
	return k;
}

int main(int argc, char *argv[])
{
	int liczba=atoi(argv[1]);
	int k=binarna(liczba);
	zamiana(k);
	zamiana(k*liczba);
}