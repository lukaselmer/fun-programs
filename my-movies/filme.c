#include <stdio.h>			//Standard
#include <math.h>			//Mathematische Ausdrücke
#include <string.h>			//Befehle für Strings
#include <stdlib.h>			//Standard
#include <time.h>			//Zeitbefehle
#include <io.h>				//Input und Output
#include <direct.h>			//Zugriff für Directory


	struct liste_t{

		char name[101];				//Filmnaame
		int brenndatum;				//Brenndatum in Tagen
		int cds;					//anzah CD's
		char typ[51];				//Genre
		int erscheinungsdatum;		//Erscheinungsdatum in Tagen
		int groesse;				//Grösse in MB

	};


	int einlesen(char *filename);
	int menu(int anzahl);
	int anzeigen();
	int berechnen(int anzahl);
	int sortieren(int anzahl);
	enter();
	intro();
	genre_gruppiern(int anzahl);
	suchen(int anzahl);
	kompaktausgabe(int anzahl);

	
	struct liste_t liste[5001];

	int gesamtgroesse;
	int gesamtcds;




int main(int argc, char *argv[])
{
	char filename[31];
	int anzahl;
	int wahl;


//	intro();
	strcpy(filename,"filme_gebrannt.txt");
	anzahl=einlesen(filename);				//anzahl Datensätze




	do{

	wahl=menu(anzahl);
	
	}while(wahl!=4);



//	fflush(stdin);



	return 0;
}



int einlesen(char *filename)
{
	
	int index=0;
	int brenntag;
	int brennmonat;
	int brennjahr;
	int brenntemp;
	int erschtemp;
	int erschtag;
	int erschmonat;
	int erschjahr;
	char shit[500];


	FILE * myfile;
	myfile=fopen(filename,"r");
	
	if(!myfile)
	{
		fclose(myfile);
		printf("\nTextfile nicht gefunden\n");
		return 0;
	}



	index=0;
	
	fscanf(myfile,"%[^\n]\n",shit);
	
	
	gesamtgroesse=0;
	gesamtcds=0;

	do
	{
		fscanf(myfile,"%[^\t]\t%d.%d.%d\t%d\t%[^\t]\t%d.%d.%d\t%d\n",liste[index].name,&brenntag,&brennmonat,&brennjahr,&liste[index].cds,liste[index].typ,&erschtag,&erschmonat,&erschjahr,&liste[index].groesse);
		//printf("%s\t%d.%d.%d\t%d\t%s\t%d.%d.%d\t%d\n",liste[index].name,brenntag,brennmonat,brennjahr,liste[index].cds,liste[index].typ,erschtag,erschmonat,erschjahr,liste[index].groesse);
		brenntemp=360*brennjahr;
		brenntemp+=30*brennmonat;
		liste[index].brenndatum=brenntemp+brenntag;

		erschtemp=360*erschjahr;
		erschtemp+=30*erschmonat;
		liste[index].erscheinungsdatum=erschtemp+erschtag;

		gesamtgroesse+=liste[index].groesse;
		gesamtcds+=liste[index].cds;

		index++;


	}while(!feof(myfile));

	fclose(myfile);

	index--;

	return index;


}

	menu(int anzahl)
	{
		int wahl1=0;
		int wahl2=0;
		char bug[999];
			

			system("cls");
		
			printf("\n\n\n\t**********************\n");
			printf("\t** Was wollen Sie ? **\n");
			printf("\t**********************\n\n");

			printf("\t1  Sortieren\n");
			printf("\t2  Berechnen\n");
			printf("\t3  Kompaktanzeige\n");
			printf("\t4  Programm verlassen\n\n\n");

			printf("\tIhre Wahl: ");
			scanf("%d",&wahl1);
			fflush(stdin);
			printf("\n\n");
				
			switch (wahl1)
				{
				case 1:

					do{
					wahl2=sortieren(anzahl);
					}while(wahl2!=7);

												
				break;

				case 2:

					do{
					wahl2=berechnen(anzahl);
					}while(wahl2!=8);
					
					
				break;

				case 3:

					kompaktausgabe(anzahl);
					
				break;
	
				case 4:

					system("cls");
					printf("\n\n\n\n\tCopyright Lukas Elmer, 2004\n\n");
					scanf("^[\n]",bug);

				break;


				default:
				printf("\n\nDiese Eingabe ist ungültig\n");
				printf("Bitte wiederholen Sie die Eingabe\n\n\n");
					
				}

	
	
		return wahl1;
	}

	sortieren(int anzahl)
	{
		int wahl2=0;

		system("cls");
		printf("\n\n\n\t***************\n");
		printf("\t** Sortieren **\n");
		printf("\t***************\n\n");

		printf("\t1  Nach Name\n");
		printf("\t2  Nach Anzahl CD's\n");
		printf("\t3  Nach Typ\n");
		printf("\t4  Nach Erschenungsdatum\n");
		printf("\t5  Nach Brenndatum\n");
		printf("\t6  Suchen\n");
		printf("\t7  Sortieren abbrechen");

		printf("\n\n\tIhre Wahl: ");
		scanf("%d",&wahl2);
		fflush(stdin);
		printf("\n\n");

		switch(wahl2)
		{
			case 1:
				
				enter();

			break;
		
			case 2:

				enter();

			break;

			case 3:
		
				enter();

			break;

			case 4:

				enter();
			break;

			case 5:

				enter();
			break;

			case 6:
				suchen(anzahl);
				enter();
			break;

			case 7:
				enter();
			break;
			
			default:
		
				printf("\n\nDiese Eingabe ist ungültig\n");
				printf("Bitte wiederholen Sie die Eingabe\n\n\n");
		}
	
		return wahl2;
	}


	berechnen(int anzahl)
	{
		int wahl2=0;
		int x=0;
		int y=0;
		int z=0;
		
		
		system("cls");
		printf("\n\n\n\t***************\n");
		printf("\t** Berechnen **\n");
		printf("\t***************\n\n");
		printf("\t1  Gesamt gebrannte MegaBytes\n");
		printf("\t2  Gesamt gebrannte CD's\n");
		printf("\t3  Aeltester Film\n");
		printf("\t4  Neuster Film\n");
		printf("\t5  Vor wie vielen Tagen der Letzte Film gebrannt wurde\n");
		printf("\t6  Vor wie vielen Tagen der Erste Film gebrannt wurde\n");
		printf("\t7  Nach Genre gruppieren\n");
		printf("\t8  Abbrechen\n");

		printf("\n\n\tIhre Wahl: ");
		scanf("%d",&wahl2);
		fflush(stdin);
		printf("\n\n");


		switch(wahl2)
		{
			case 1:
				
				printf("\tGesamtgroesse der Gebrannten Filme in MB:\t%d\n",gesamtgroesse);
				printf("\tGesamtgroesse der Gebrannten Filme in GB:\t%d\n\n",gesamtgroesse/1000);

				enter();

			break;
		
			case 2:

				printf("\tGesamt Gebrannte CDs:\t%d\n",gesamtcds);
				enter();

			break;

			case 3:
				
				x=0;
				z=0;
				y=liste[x].erscheinungsdatum;
				do{
					if(liste[x].erscheinungsdatum<y)
					{
						y=liste[x].erscheinungsdatum;
						z=x;
					}
					x++;
				}while(anzahl>=x);
				printf("\tDer Aelteste Film ist : %s\n\n",liste[z].name);
				enter();

			break;

			case 4:
				x=0;
				z=0;
				y=liste[x].erscheinungsdatum;
				do{
					if(liste[x].erscheinungsdatum>y)
					{
						y=liste[x].erscheinungsdatum;
						z=x;
					}
					x++;
				}while(anzahl>=x);
				printf("\tDer Neuste Film ist : %s\n\n",liste[z].name);
				enter();
			break;

			case 5:
				x=0;
				z=0;
				y=liste[x].brenndatum;
				do{
					if(liste[x].brenndatum<y)
					{
						y=liste[x].brenndatum;
						z=x;
					}
					x++;
				}while(anzahl>=x);
				printf("\tDer erstgebrannte Film ist : %s\n\n",liste[z].name);
				enter();
			break;

			case 6:
				x=0;
				z=0;
				y=liste[x].brenndatum;
				do{
					if(liste[x].brenndatum>y)
					{
						y=liste[x].brenndatum;
						z=x;
					}
					x++;
				}while(anzahl>=x);
				printf("\tDes zuletzt gebrannte Film ist : %s\n\n",liste[z].name);
				enter();
			break;

			case 7:
				genre_gruppiern(anzahl);	
				enter();
			break;
			
			default:
		
				printf("\n\nDiese Eingabe ist ungültig\n");
				printf("Bitte wiederholen Sie die Eingabe\n\n\n");
		}
		return wahl2;

		
		




	}


/*	anzeigen()
	{
		int wahl2=0;

		system("cls");
		printf("\n\n\n\t**************\n");
		printf("\t** Anzeigen **\n");
		printf("\t**************\n\n");
		printf("\t1  Alle Datens%ctze anzeigen\n",142);
		printf("\t2  Abbrechen\n");

		printf("\n\n\tIhre Wahl: ");
		scanf("%d",&wahl2);
		fflush(stdin);
		printf("\n\n");

		switch(wahl2)
		{
			case 1:
				
				printf("\n\nGesamtgroesse:\t%d MB\n",gesamtgroesse);
				printf("Gesamtgroesse:\t%d GB\n\n",gesamtgroesse/1000);

			break;
		
			case 2:

				printf("Gesamtcds:\t%d\n",gesamtcds);
				enter();

			break;

			case 3:
		
				enter();

			break;

			case 4:

				enter();
			break;

			case 5:

				enter();
			break;

			case 6:

				enter();
			break;

			case 7:
				enter();
			break;
			
			default:
		
				printf("\n\nDiese Eingabe ist ungültig\n");
				printf("Bitte wiederholen Sie die Eingabe\n\n\n");
		}
	
		return wahl2;
	}
*/		

	enter()
	{
		char bug[9999];
		
		printf("\n\tDr%ccken Sie Enter",129);
		scanf("^[\n]",bug);


	}


	
	
	intro()

	{

		int index;
		int index2;
		char x[400];
//		int wahl;
		char name[31];
		FILE * myfile;

/*		do
		{
			
		printf("\n\nSind Sie ueber 18?\n1\t\tJa\n2\t\tNein\n\nIhre Wahl:\t");
		
		scanf("%d",&wahl);
		fflush(stdin);

		if(wahl==1)
		{*/
			strcpy(name,"cool.txt");
/*		}
		else
		{
			strcpy(name,"cool2.txt");
		}


*/
			myfile=fopen(name,"r");
			
			if(! myfile)
			{
				printf("\nFile nicht gefunden !");
				fclose(myfile);
				return 0;
			}

			index=0;

			do
			{
				fscanf(myfile,"%[^\n]\n",&x);
				printf("%s\n",x);
				index2=-20000;
				index=0;
				do
				{
					do
					{
			
						index2++;
			
					}while(index2!=5000);
					index2=-2000;
					index++;
		
				}while(index!=2000);

			}while(!feof(myfile));

			fclose(myfile);

			printf("\n\n Laden... bitte warten\n\n");
			index=-10000;
			index2=-10000;
			do
			{
				do
				{
				
				index2++;
			
				}while(index2!=20000);
				index2=-5000;
				index++;
			
			}while(index!=20000);

//			printf("\n\n\nNochmal!\n\n\n");

//		}while(index=1);

		return 0;
	}



	genre_gruppiern(int anzahl)
	{
	
		int x=0;
		int y=0;		//Anzahl verschiedene Genre
		int z=0;
		int w=0;
		int vorhanden=0;	
		struct genre_t{	
			char genre[51];
			int anz;
		};

		struct genre_t genre[5001];
		


		x=0;
		y=0;
		z=0;
		w=0;

		do
		{
			
			vorhanden=0;
			do
			{
				w= strcmp(liste[x].typ,genre[z].genre);

				if(w==0)
				{
					genre[z].anz++;
					vorhanden=1;
					//printf("vorhanden\t%d\t%d\n",x+1,z+1);
					//printf("%s\n",liste[x].typ);
				}
				//printf("vorhanden%d\t%d\n",z,x);
				z++;
				
			}while(z<=anzahl);
			z=0;
			if(vorhanden==0)
			{
				strcpy(genre[y].genre,liste[x].typ);
				genre[y].anz=1;
//				printf("%d\t%s\t%s\n",x+1,genre[y].genre,liste[x].typ);
				y++;
				
				
			}
			
			x++;

		}while(x<=anzahl);

		y--;
		x=0;

		do{
	
		printf("\t%s\t%d\n",genre[x].genre,genre[x].anz);
//		printf("%s\n",liste[3].typ);
		x++;
		}while(x<=y);

		enter();
	}

	suchen(int anzahl)
	{
/*		char filmname[101]="";

		struct name_t{	
			char filmtitel[101];
		};

		struct name_t name[5001];

		
		int index=0;
	

		printf("\n\n\tGeben Sie mindestens ein Teil des gesuchten Films ein\n");
		scanf("%s",filmname);
		
		do{
			strcpy(name[index].filmtitel,strstr(liste[index].name,filmname));
			printf("\n\t%s",name[index].filmtitel);
		}while(anzahl>=index);
*/

	}


kompaktausgabe(int anzahl)
{
	system("cls");
	printf("\n\n\n\t********************\n");
	printf("\t** Kompaktanzeige **\n");
	printf("\t********************\n\n");

	printf("\tGebrannte Filme in MB:\t%d\n",gesamtgroesse*1,014);
	printf("\tGebrannte Filme in GB:\t   %d\n\n",gesamtgroesse/1000);
	printf("\tGesamt Gebrannte CDs:\t   %d\n",gesamtcds);
	enter();



}