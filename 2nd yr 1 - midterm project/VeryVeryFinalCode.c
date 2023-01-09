/*
Developed by: BUGGY TEAM

MEMBERS:
	Rezelle June G. Udtohan
	Jonavia J. Mahumas

	CCS 104 B | Set B

*/


//*****Header files included******
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for toupper
#include <time.h>


//**constant values**
#define rSize 8
#define cSize 10


//*******Global variables*********

// Initialized some elements of every row
int array[rSize][cSize] = {
	{101, 102, 103, 104, 105},
	{201, 202, 203, 204, 205, 206, 207, 208, 209},
	{301, 302, 303, 304, 305, 306, 307, 308, 309},
	{401, 402, 403, 404, 405, 406, 407, 408, 409},
	{501, 502, 503, 504, 505, 506, 507, 508, 509},
	{601, 602, 603, 604, 605, 606, 607, 608, 609},
	{701, 702, 703, 704, 705, 706, 707, 708, 709},
	{801, 802, 803, 804, 805, 806, 807, 808, 809}};

// int variable which stores the number of real elements in every rows
int n[rSize] = {5, 9, 9, 9, 9, 9, 9, 9};

// name of each rows of the arena seats or each rows of the 2d array
char section[rSize][15] = {"PREMIUM-BOX", "PATRON-A", "PATRON-B", "PATRON-C", "LBOX-VIP", "LBOX-REGULAR", "UPPER-BOX", "GEN-ADM"};

// a 3d character array that stores the names of the ticket buyers
char allNames[rSize][cSize][20] = {
	{"Sana Bading", "Seyoung", "God Jihyo", "Minari", "Jeongyoonie"},
	{"Chewy", "Momoring", "Tofu", "Nabong", "Zaki Taji", "Kathryn Bernardo", "Calum Scott", "Brent Manalo", "Daniel Padilla"},
	{"Saitama", "Inosuke Hashibira", "Nezuko Kamado", "Denji", "Uzumaki Naruto", "Zayn Malik", "Lady Gaga", "Harry Styles", "Louis Thompson"},
	{"Rem", "Saitama", "Yama", "Yoasobi", "Itachi Uchiha", "Niall Horan", "Ed Sheraan", "Olivia Rodrigo", "Bebe Rexha"},
	{"Zenitsu Agatsuma", "Zoro", "Luffy", "Nanami Kento", "Yuuta Okkotsu", "Hinata", "Taylor Swift", "Lebron James", "Kobe"},
	{"Eren Yeager", "Sasha Braus", "Yumeko Jabami", "Sano Manjirou", "Izumi Miyamura", "Junjun", "July falla", "Hackdog", "Jack n Jill"},
	{"Kaneki Ken", "Tanjiro Kamado", "Inumaki Toge", "Gojou Satoru", "Mai Sakurajima", "Paluma Rodrigez", "Matthew Cordelle", "Remi Gio", "Tiquera"},
	{"Violet Evergarden", "Sakuta Azusagawa", "Itadori Yuuji", "Yor Forger", "Nobra Kugisaki", "Raphtalia", "Maki Zenin", "Konan", "Mikasa Ackerman"}}; // Initialized some elements of every row

//initialized the income since I initialized the ticket codes and names
float income=21490;


//*********functions************

// function that displays a line in the console using a for loop
void lineLoop()
{
	int ctr;

	printf("\n");
	for (ctr = 0; ctr < 120; ctr++)
	{
		printf(".");
	}
	printf("\n");
}


// function that displays an intro design, it displays the name of the app
void introDesign()
{

	printf("\n\n\n   \t\t\t\t\t\t##### #### #### ####\n   \t\t\t\t\t    ####### ###### ###### ######\n   \t\t\t\t        ######### ######## ######## ########\n   \t\t\t\t      ######### ########## ########## ########\n   \t\t\t\t     ######### ########### ########### ########\n   \t\t\t\t    ######### ############ ############ ########\n   \t\t\t\t   ########## ############ ############ #########\n   \t\t\t\t   ########## ############ ############ #########\n   \t\t\t\t   ========== ============ ============ =========\n   \t\t\t\t   ########## ############ ############ #########\n   \t\t\t\t   ########## ############ ############ #########\n   \t\t\t\t    ########## ########### ########### #########\n   \t\t\t\t     ########## ########## ########## #########\n   \t\t\t\t      ########## ######### ######### #########\n   \t\t\t\t        ######### ######## ######## ########\n   \t\t\t\t            ####### ###### ###### ######\n   \t\t\t\t               ###### #### #### #####");
	printf("\n\n\t\t\t\t\t       P  B  A      G  A  M  E\n\n\t\t\t\t\t  T I C K E T I N G    S Y S T E M");
}


// function that displays the menu options
void menuOptions()
{

	printf("\n\n\t\t\t\t\t   [ - - M E N U    O P T I O N S - - ]");
	lineLoop();

	printf("\t\t\t\t\t   [a] - Buy a ticket to reserve a seat\n\t\t\t\t\t   [b] - Search a reserved seat\n\t\t\t\t\t   [c] - Cancel a ticket/reserved seat\n\t\t\t\t\t   [d] - Display all occupied and not occupied seats\n\t\t\t\t\t   [e] - Exit");
	lineLoop();
}


// function that displays the price levels / ticket prices
void priceLevels()
{
	int ctr;

	printf("\n\t\t\t\t\t[- - T I C K E T    P R I C E S - - ]\n\n\t\t\t\t\t______________________________________");
	printf("\n\n\t\t\t\t\tLEVEL\t\t\t\tAMOUNT\n\t\t\t\t\t______________________________________");
	printf("\n\n\t\t\t\t\tPRICE LEVEL 1\t\t       Php 635");
	printf("\n\t\t\t\t\tPRICE LEVEL 2\t\t       Php 535");
	printf("\n\t\t\t\t\tPRICE LEVEL 3\t\t       Php 485");
	printf("\n\t\t\t\t\tPRICE LEVEL 4\t\t       Php 385");
	printf("\n\t\t\t\t\tPRICE LEVEL 5\t\t       Php 275");
	printf("\n\t\t\t\t\tPRICE LEVEL 6\t\t       Php 225");
	printf("\n\t\t\t\t\tPRICE LEVEL 7\t\t       Php  90");
	printf("\n\t\t\t\t\tPRICE LEVEL 8\t\t       Php  40");
}


// function for generating a unique random number within a range. Called inside the buyReserve function.
int randomNum(int lower, int upper)
{
	int number;

	// makes use of the computer's internal clock to control the choice of the seed.
	// Since time is continually changing, the seed is forever changing.
	srand(time(NULL));

	number = (rand() % (upper - lower + 1)) + lower;

	return number;
}


// function for insertion of ticketCodes in the array
void insert(int level, int pos, int n, int number, char name[50])
{
	int ctr;

	if(pos==1){
		for (ctr = n; ctr >= 0; ctr--)
		{
			array[level - 1][ctr] = array[level - 1][ctr - 1];
			strcpy(allNames[level - 1][ctr], allNames[level - 1][ctr - 1]);
		}
		array[level - 1][pos - 1] = number;
		strcpy(allNames[level - 1][pos - 1], name);
	}
	else if (pos > 1 && pos <= n)
	{
		for (ctr = n; ctr >= pos - 1; ctr--)
		{
			array[level - 1][ctr] = array[level - 1][ctr - 1];
			strcpy(allNames[level - 1][ctr], allNames[level - 1][ctr - 1]);
		}
		array[level - 1][pos - 1] = number;
		strcpy(allNames[level - 1][pos - 1], name);
	}
}


// This function will return an integer value which is the chosen price level from the user.
// This function will let the user buy a ticket or reserve a seat inside the arena.
// The validation of user’s info will happen inside this function.
int buyReserve()
{

	int age, level, lower, upper, number, b, pos;
	char name[50], ansVacc, a, ans;
	float price, addFee = 30;

	system("CLS");
	printf("\n\t\t\t\t\t~ G O O D   D A Y   M A ' A M   o r  S I R ~");
	lineLoop();

	// validation of data according to the venue guidelines of the pba game inside the arena
	printf("\n\tPlease input your following details first.");

	printf("\n\n\t\tEnter your name [Firstname_Lastname]: ");
	scanf("%s", name);
	fflush(stdin);

	printf("\n\t\tAGE: ");
	scanf("%d", &age);
	fflush(stdin);

	// if the age is less than 5, then the user cannot buy/ reserve a seat inside the arena
	if (age < 5)
	{
		printf("\n\t\t** You're not allowed to go inside the coliseum, only 5 yrs old and above are allowed. **");
		lineLoop();
		getch();

		// allowed for the next validation
	}
	else
	{

		do
		{
			system("CLS");
			printf("\n\tNOTE: Must Present vaccination card together with any valid id w/ picture or government issued id w/ picture");
			lineLoop();
			printf("\n\t\t\tAre you fully vaccinated? [Y/N] : ");
			scanf("%c", &ansVacc);
			fflush(stdin);

			// if the user is not fully vaccinated then he/she cannot enter also since it is required that they are fully vaccinated
			if (toupper(ansVacc) != 'Y' && toupper(ansVacc) != 'N')
			{
				lineLoop();
				printf("\n\t\t\t** ERROR! INVALID DATA! Please enter Y or N only.Press any key to enter again...**");
				getch();
			}

		} while (toupper(ansVacc) != 'Y' && toupper(ansVacc) != 'N');

		// if a user can successfully enter, this part or condition will run.
		if (toupper(ansVacc) == 'Y')
		{

			// a do while loop that let the user choose another price level if they want to incase the previous price level they entered is already full.
			do
			{

				// a do while loop that let the users enter again if they inputted an invalid data
				do
				{
					system("CLS");

					priceLevels();
					lineLoop();
					printf("\t\t\t\t\tChoose Price level [1 - 8] : ");
					scanf("%d", &level);
					fflush(stdin);

					// if condition to let the users know that they inputted an invalid data
					if (level < 1 || level > rSize)
					{

						printf("\n\t\t\t** INVALID DATA! INPUT 1 TO 8 ONLY.PLEASE REFER TO THE TICKET PRICE ABOVE **\n");
						lineLoop();
						printf("\n\tPress any key to enter again...");
						getch();
					}

				} while (level < 1 || level > rSize);

				// b is used for tracking if the seats of the particular row or section is already full or not
				switch (level)
				{
				case 1:
					b = n[0];
					break;
				case 2:
					b = n[1];
					break;
				case 3:
					b = n[2];
					break;
				case 4:
					b = n[3];
					break;
				case 5:
					b = n[4];
					break;
				case 6:
					b = n[5];
					break;
				case 7:
					b = n[6];
					break;
				case 8:
					b = n[7];
					break;
				}

				// if the particular row is already full then the user can't avail this price level anymore
				if (b >= cSize)
				{
					printf("\n\t- Price level %d is no longer available since all the seats in this level are all occupied", level);
					lineLoop();
					getch();

					// do while loop that lets the user input again if they inputted invalid data.
					do
					{

						// if the price level inputted by the user was full then they'll be questioned if they want to buy another price level or cancel buying
						system("CLS");
						printf("\n\n\n\t\t\t\tDo you wish to buy another price level or cancel buying?\n\n\t\t\t\t\t[Y - buy another]\t[N - cancel] \n\n\t\t\t\t- [Y/N] : ");
						scanf("%c", &a);
						fflush(stdin);

						// an if else statement again for letting the user know that they have inputted an invalid data
						if (toupper(a) != 'Y' && toupper(a) != 'N')
						{
							lineLoop();
							printf("\n\t\t\t** ERROR! INVALID DATA! Please enter Y or N only.Press any key to enter again...**");
							getch();
						}

					} while (toupper(a) != 'Y' && toupper(a) != 'N');

					// else if the price level inputted by the user was not full then they can successfully buy
				}
				else
				{

					// a part where a user will be ask if he/she wants to choose a position or not
					// a do while loop to let the user enter again their answer if they inputted an invalid value
					do
					{
						system("CLS");

						printf("\tNOTE: Additional fee if you don't wan't to seat after the last person who reserved a seat in %s", section[level - 1]);
						lineLoop();

						printf("\n\n\t\t\t\t[a] - choose a seat before the last person (seat #1 - #%d) \n\t\t\t\t[b] - seat after the last person (seat #%d)\n\t\t\t\t__________________________________________________________\n\n\t\t\t\t[A/B]: ", n[level - 1], n[level - 1] + 1);
						scanf("%c", &ans);
						fflush(stdin);

						// an if else statement again for letting the user know that they have inputted an invalid data
						if (toupper(ans) != 'A' && toupper(ans) != 'B')
						{
							lineLoop();
							printf("\n\t\t\t** ERROR! INVALID DATA! Please enter A or B only.Press any key to enter again...**");
							getch();
						}

					} while (toupper(ans) != 'A' && toupper(ans) != 'B');

					if (toupper(ans) == 'A')
					{
						// a do while loop
						do
						{
							system("CLS");

							printf("\t\t\tNOTE: You will pay additional fee P %.2f since you want to choose a seat #.", addFee);
							lineLoop();

							printf("\n\t\tChoose seat# [1 to %d only]: ", n[level - 1]);
							scanf("%d", &pos);
							fflush(stdin);

							if (pos < 1 || pos > n[level - 1])
							{
								lineLoop();
								printf("\n\t\t\t** ERROR! INVALID DATA! Please enter 1 to %d only.Press any key to enter again...**", n[level - 1]);
								getch();
							}

						} while (pos < 1 || pos > n[level - 1]);
					}

					// a switch statement for assigning a unique ticketCode (with ranges depending by the price levels)  for the user/buyer
					switch (level)
					{

					// if price level is 1 then the ticket code generated ranges a value betweeen 10010 to 20000
					case 1:

						price = 635;
						lower = 110;
						upper = 200;
						number = randomNum(lower, upper);
						//if the user choose a seat then this part will call the insert function for the moving of values
						//and assigning it to the choosen position, then an additional fee for choosing a seat
						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[0], number, name);
							price += addFee;
						}
						//else there will be no additional fee and the values will be inserted after the last person in a specific section
						else
						{
							strcpy(allNames[level - 1][n[0]], name);
							array[level - 1][n[0]] = number;
							pos = n[0] + 1;
						}

						break;

					// if price level is 2 then the ticket code generated ranges a value betweeen 20010 to 30000
					case 2:
						price = 535;
						lower = 210;
						upper = 300;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[1], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[1]], name);
							array[level - 1][n[1]] = number;
							pos = n[1] + 1;
						}

						break;

					// if price level is 3 then the ticket code generated ranges a value betweeen 30010 to 40000
					case 3:
						price = 485;
						lower = 310;
						upper = 400;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[2], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[2]], name);
							array[level - 1][n[2]] = number;
							pos = n[2] + 1;
						}

						break;

					// if price level is 4 then the ticket code generated ranges a value betweeen 40010 to 50000
					case 4:
						price = 385;
						lower = 410;
						upper = 500;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[3], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[3]], name);
							array[level - 1][n[3]] = number;
							pos = n[3] + 1;
						}

						break;

					// if price level is 5 then the ticket code generated ranges a value betweeen 50010 to 60000
					case 5:
						price = 275;
						lower = 510;
						upper = 600;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[4], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[4]], name);
							array[level - 1][n[4]] = number;
							pos = n[4] + 1;
						}

						break;

					// if price level is 6 then the ticket code generated ranges a value betweeen 60010 to 70000
					case 6:
						price = 225;
						lower = 610;
						upper = 700;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[5], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[5]], name);
							array[level - 1][n[5]] = number;
							pos = n[5] + 1;
						}

						break;

					// if price level is 7 then the ticket code generated ranges a value betweeen 70010 to 80000
					case 7:
						price = 90;
						lower = 710;
						upper = 800;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[6], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[6]], name);
							array[level - 1][n[6]] = number;
							pos = n[6] + 1;
						}

						break;

					// if price level is 8 then the ticket code generated ranges a value betweeen 80010 to 90000
					case 8:
						price = 40;
						lower = 810;
						upper = 900;
						number = randomNum(lower, upper);

						if (toupper(ans) == 'A')
						{

							insert(level, pos, n[7], number, name);
							price += addFee;
						}
						else
						{
							strcpy(allNames[level - 1][n[7]], name);
							array[level - 1][n[7]] = number;

							// initialized pos variable if the user don't want to inserted after the last person on that section
							pos = n[7] + 1;
						}

						break;
					}
					//adding the price to the income
					income+=price;
					
					// displaying a note of some of the venue guidelines to let the user be reminded before entering the arena
					system("CLS");

					printf("\n\tNOTE: Use of facemask inside the arena is required. Strictly NO TICKET, NO ENTRY and NO RE-ENTRY policy.");

					lineLoop();
					
					printf("\n\n\t\t\t\t\t\t[ - - R E C E I P T - - ]\n\t\t\t\t\t_________________________________________\n\n\t\t\t\t\tName:\t\t-\t%s\n\t\t\t\t\tTicket Code\t-\t%d\n\t\t\t\t\tSection %d\t-\t%s\n\t\t\t\t\tSeat\t\t-\t#%d\t\n\t\t\t\t\t_________________________________________\n\n\t\t\t\t\tAmount\t\t=\tP %.2f", name, number, level, section[level - 1], pos, price);
					
					//if the user choose a seat, they will be reminded why their price were added up by the additional fee
					if (toupper(ans) == 'A')
					{
						printf("\n\n\n\n   Original price of your ticket was P %.2f but it was added by P%.2f for the additional fee for choosing a seat.", price - addFee, addFee);
					}

					getch();

					return level;
				}

			} while (toupper(a) == 'Y');

			// not allowed for the 2nd validation about vaccinated
		}
		else
		{
			lineLoop();
			printf("\n\t** You're not allowed to go inside the coliseum, only fully vaccinated individuals are allowed. **");
			getch();
		}
	}
}


// displays the 2d array of all the ticket codes with the name of each row which is the section. this is the main arrays of the program
void display2dArray()
{
	int row, col;

	printf("\n\t\t\t\t[ - - D I S P L A Y   O C C U P I E D    S E A T S  - - ]");
	lineLoop();
	for (row = 0; row < rSize; row++)
	{
		printf("\n\t\t\t%d) %s", row + 1, section[row]);

		printf("\n\t\t\t-");

		// displaying of all ticketCodes per row/section
		for (col = 0; col < cSize; col++)
		{

			printf(" %d\t", array[row][col]);
		}
		printf("\n");
	}
}


//displaying the names, sections, and ticket code for the additional infos
void displayNames(int row)
{
	int col;

	printf("\n\tSection %d: %s\n\t", row + 1, section[row]);
	for (col = 0; col < cSize; col++)
	{
		printf("\n\t\tSeat #%d: %s\n\t\t- Code: %d\n", col + 1, allNames[row][col], array[row][col]);
	}
}


// function for inputting ticket codes and store it into an integer variable
int inputCode()
{
	int value;

	printf("\n\t\t\t\t\t\tEnter Ticket Code: ");
	scanf("%d", &value);
	fflush(stdin);

	return value;
}


// function for searching a ticket code
int search(int value, int row)
{
	int ctr;

	for (ctr = 0; ctr < cSize; ctr++)
	{
		if (value == array[row][ctr])
		{
			ctr++;
			return ctr;
		}
	}

	return 0;
}


// function for deleting a value (ticket code) for canceling the reserved ticket
int cancel(int val, int n, int row)
{
	int ctr, pos;

	// used or called the serach() function for searching the ticketCode inputted by the user if it exist in the array or not
	pos = search(val, row);

	// it it is not found then
	if (pos == 0)
	{
		lineLoop();
		printf("\n\t\t\t\t\t\t- Ticket %d not found.", val);
		getch();

		// if it is found
	}
	else
	{
		if (pos == 1)
		{
			for (ctr = 0; ctr < n; ctr++)
			{
				array[row][ctr] = array[row][ctr + 1];
				strcpy(allNames[row][ctr], allNames[row][ctr + 1]);
			}
		}
		else if (pos > 1 && pos < n)
		{
			for (ctr = pos - 1; ctr < n - 1; ctr++)
			{
				array[row][ctr] = array[row][ctr + 1];
				strcpy(allNames[row][ctr], allNames[row][ctr + 1]);
			}
		}
		// assigning the value of last element of the particular row to 0 since it is not a real element anymore
		array[row][n - 1] = 0;
		strcpy(allNames[row][n - 1], "");

		// n is for tracking the real elements of thee program this could be the n1 or n2 or etc depending on the row
		// since 1 value is deleted in the array then it will be minus by 1
		n--;

		lineLoop();
		printf("\n\t\t\t\t\t- Ticket %d successfully canceled or deleted.", val);
		getch();
	}
	return n;
}


//a function that records the final informations into a .txt file before the program finally exits
void fileHandling(){
	FILE *fp;
	fp = fopen("PBA Records.txt", "a+");
	
	int row, col;
	
	//for the displaying of the current time and date
	time_t t;   // not a primitive datatype
    time(&t);
	
	fprintf(fp,"PBA GAME TICKETING RECORDS\t\t%sTotal Income: %.2f\n",ctime(&t),income);
	for(row=0;row<rSize;row++){
		fprintf(fp,"-----------------------------------------------------------------\n\tSection %d: %s\n\t", row + 1, section[row]);
		for (col = 0; col < cSize; col++)
		{
			fprintf(fp, "\n\t\tSeat #%d: %s\n\t\t- Code: %d\n", col + 1, allNames[row][col], array[row][col]);
		}
	}
	
	if (fp != NULL)
	{
		printf("\n\nInformations recorded successfully");
	}
	else
	{
		printf("\n\t\t\t- Error! Can\'t record the info, can\'t access the file");
	}
	
	fclose(fp);
}


//********main function**********
int main()
{

	int c, totalSeats, ticketCode, row, searchResult, s, result, ctr, r;
	char opt, ans;

	introDesign();
	lineLoop();

	printf("\t\t\t\t\tPress any key to open the app....");
	getch();

	// a do while loop that enable the program to only exit or end if the user chooses the exit option.
	do
	{
		// a do while loop that let the user to input again if they inputted an invalid data
		do
		{

			system("CLS");

			menuOptions();

			printf("\n\t\t\t\t\tChoose option [a,b,c,d,e]: ");
			scanf("%c", &opt);
			fflush(stdin);

			// if the user inputted an invalid data, this condition will let the user that the data is invalid
			if (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E')
			{

				printf("\n\t\t\t\t\t- Invalid Data! A,B,C,D,E only.");
				lineLoop();
				printf("\t\tPress any key to input again...");
				getch();
			}

		} while (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E');

		switch (toupper(opt))
		{

		case 'A':
			if (totalSeats < 80)
			{
				// c is used also for tracking the real elements of the 2d array for validation also of the price levels/rows if it is full or not yet
				c = buyReserve(section, array, n);

				// tracking of no. of occupied elements
				switch (c)
				{
				case 1:
					n[0]++;
					break;
				case 2:
					n[1]++;
					break;
				case 3:
					n[2]++;
					break;
				case 4:
					n[3]++;
					break;
				case 5:
					n[4]++;
					break;
				case 6:
					n[5]++;
					break;
				case 7:
					n[6]++;
					break;
				case 8:
					n[7]++;
					break;
				}
			}
			else
			{
				lineLoop();
				printf("\n\t\t\t\t- Not available since seats are now all occupied");
				getch();
			}

			break;

		case 'B':
			system("CLS");
			printf("\n\t\t\t\t[ - - S E A R C H   A   R E S E R V E D    S E A T - - ]");
			lineLoop();
			ticketCode = inputCode();

			// the user can't input ticketCode that is more than or equal to 90000 or less than or equal to 10000 since all codes were all between 10000 to 90000 only
			if (ticketCode <= 100 || ticketCode >= 900)
			{
				lineLoop();
				printf("\n\t\t\t\t- Invalid. Ticket Codes ranges between 100 to 900.");
				getch();

				// else if it is valid, then the rows are initialized for variable called inside the search function
			}
			
			else
			{

				if (ticketCode > 100 && ticketCode < 200)
				{
					row = 0;
				}
				else if (ticketCode >= 200 && ticketCode < 300)
				{
					row = 1;
				}
				else if (ticketCode >= 300 && ticketCode < 400)
				{
					row = 2;
				}
				else if (ticketCode >= 400 && ticketCode < 500)
				{
					row = 3;
				}
				else if (ticketCode >= 500 && ticketCode < 600)
				{
					row = 4;
				}
				else if (ticketCode >= 600 && ticketCode < 700)
				{
					row = 5;
				}
				else if (ticketCode >= 700 && ticketCode < 800)
				{
					row = 6;
				}
				else
				{
					row = 7;
				}

				searchResult = search(ticketCode, row);

				lineLoop();
				if (searchResult > 0)
				{
					printf("\n\t\t\t\t\t\t- Ticket Code %d is found.\n\n\n\t\t\t\t\t\tDETAILS\n\t\t\t\t\t\t____________________________\n\n\t\t\t\t\t\tName: %s\n\t\t\t\t\t\tSeat: %d\n\t\t\t\t\t\tSection: %s\n\t\t\t\t\t\t____________________________", ticketCode, allNames[row][searchResult - 1], searchResult, section[row]);
				}
				else
				{
					printf("\n\t\t\t\t\t- Ticket Code %d is not found in the array.", ticketCode);
				}

				getch();
			}
			break;

		case 'C':

			// the user can't input ticketCode that is more than or equal to 90000 or less than or equal to 10000 since all codes were all between 10000 to 90000 only
			system("CLS");
			printf("\n\t\t\t\t\t[ - - C A N C E L   A    T I C K E T  - - ]");
			lineLoop();
			ticketCode = inputCode();

			if (ticketCode <= 100 || ticketCode >= 900)
			{
				lineLoop();
				printf("\n\t\t\t\t-Invalid. Ticket Codes ranges between 100 to 900.");
				getch();

				// statement for deleting a value in a particular row depending on the ticketCode .. the row depends on which range the ticketCode inputted by the user belongs
			}
			else
			{
				//assigning rows every conditions since the row depends on the ranges of the codes
				if (ticketCode > 100 && ticketCode < 200)
				{
					row = 0;
					n[0] = cancel(ticketCode, n[0], row);
				}
				else if (ticketCode >= 200 && ticketCode < 300)
				{
					row = 1;
					n[1] = cancel(ticketCode, n[1], row);
				}
				else if (ticketCode >= 300 && ticketCode < 400)
				{
					row = 2;
					n[2] = cancel(ticketCode, n[2], row);
				}
				else if (ticketCode >= 400 && ticketCode < 500)
				{
					row = 3;
					n[3] = cancel(ticketCode, n[3], row);
				}
				else if (ticketCode >= 500 && ticketCode < 600)
				{
					row = 4;
					n[4] = cancel(ticketCode, n[4], row);
				}
				else if (ticketCode >= 600 && ticketCode < 700)
				{
					row = 5;
					n[5] = cancel(ticketCode, n[5], row);
				}
				else if (ticketCode >= 700 && ticketCode < 800)
				{
					row = 6;
					n[6] = cancel(ticketCode, n[6], row);
				}
				else
				{
					row = 7;
					n[7] = cancel(ticketCode, n[7], row);
				}
			}
			break;

		// displaying the 2d array which are all seats of the arena. A seat is occupied if its value is not 0 else if it is 0 then it means it is not yet occupied
		case 'D':
			do
			{
				system("CLS");
				display2dArray(array, section);

				totalSeats = 0;

				for (ctr = 0; ctr < rSize; ctr++)
				{
					totalSeats += n[ctr];
				}

				printf("\n\t\t\t\t\tTotal no. of seats occupied: %d out of 80 seats\n", totalSeats);
				lineLoop();

				printf("\n\tDo you want to view more informations?\n\n\t\t[Y/N]: ");
				scanf("%c", &ans);
				fflush(stdin);

				if (toupper(ans) != 'Y' && toupper(ans) != 'N')
				{

					printf("\n\t\t\t\t\t- Invalid Data! Y and N only.");
					lineLoop();
					printf("\t\tPress any key to input again...");
					getch();
				}

			} while (toupper(ans) != 'Y' && toupper(ans) != 'N');
			
			//if the user choose yes or 'y' then the program will display more informations
			if (toupper(ans) == 'Y')
			{
				//A LOOP THAT WILL LET THE USER VIEW INFORMATIONS AGAIN OF OTHER SECTION OR SAME SECTION
				do{
					//A LOOP FOR VALIDATION OF DATA R VARIABLE, LETTING THE INPUT AGAIN IF THEY INPUTTED WRONG DATA
					do
					{
						system("CLS");
						printf("\n\t\t\t\t\t[ - -  M O R E   I N F O R M A T I O N S - - ]");
						
						//the program will first ask the user what section or level they want to display
						printf("\n\n\tEnter the section # you want to view [1-8]: ");
						scanf("%d", &r);
						fflush(stdin);
						
						//letting the user know that they inputted an invalid data
						if (r < 1 || r > rSize)
						{
							printf("\n\t\t- Invalid Data! 1-%d only.Press any key to input again...", rSize);
							getch();
						}
	
					}while(r < 1 || r > rSize);
					
					lineLoop();
					
					//DO WHILE LOOP FOR VALIDATION OF DATA, LETTING THE USER INPUT AGAIN IF THEY INPUTTED WRONG DATA
					do
					{
						system("CLS");
						
						displayNames(r - 1);
						lineLoop();
						printf("\n\tDo you want to view informations again? [Y/N]: ");
						scanf("%c", &ans);
						fflush(stdin);
							
						
						if (toupper(ans) != 'Y' && toupper(ans) != 'N')
						{
							printf("\n\t\t\t\t\t- Invalid Data! Y and N only.Press any key to input again...");
							getch();
						}

					} while (toupper(ans) != 'Y' && toupper(ans) != 'N');
					
			 }while(toupper(ans)=='Y');
			}
			break;

		// displaying an outro before successfully exiting the program
		default:
			
			system("CLS");
			printf("\t\t\tTHIS PROGRAM WILL NOW EXIT...");
			introDesign();
			lineLoop();
			printf("\t\t\tDEVELOPED BY: BUGGY TEAM\n\n\t\t\t\tRezelle June G. Udtohan\t\tJonavia J. Mahumas");
			
			//RECORDING THE FINAL INFORMATIONS TO A TEXT FILE BEFORE SUCCESSFULLY EXITING
			fileHandling();
			getch();
			break;
		}

	}while(toupper(opt) != 'E');

	return 0;

	// The end :>
}