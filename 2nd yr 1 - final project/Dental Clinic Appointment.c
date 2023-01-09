#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define cSize 5
#define rSize 5
#define size 100

// lengths of the struct array that has real values
int waitingLen[rSize] = {0}, existingLen = 10, totalLen = 0; // totalLen is the length of all real values in struct waitinglist array

// struct name is a template of first name, middle Initial and  last name
typedef struct
{
	char fname[30], mI, lname[30];
} name;

// struct record is a template of the patient's  record of the service, date and price
// gilahi nako ni since there can be a multiple record sa usa ka patient sa service and its price, and date na nidung ang patient sa clinic
typedef struct
{
	char service[3];
	int date[3]; // 3 array for month, day and year, gibuwag nako para dali ra isort
	float price;

} record;

// the main struct where record and name substruct is use.
// this is a template of a patient's record in the dental clinic
typedef struct
{
	name fullname;
	char patientID[4], contact[12];
	int age, countRecord; // countRecord just records kung kapila siya nagbalik balik sa clinic.
	record fullRecord[size];
} patient;

// function for the logo for intro and outro of our program
void logoDesign()
{

	printf("\n\t\t\t\t\t\t  ####   #########   ###\n\t\t\t\t\t       ######## ########### #######\n\t\t\t\t\t      ###############################\n\t\t\t\t\t     #################################\n\t\t\t\t\t     #################################\n\t\t\t\t\t     #################################\n\t\t\t\t\t      ###############################\n\t\t\t\t\t       #############################\n\t\t\t\t\t        ###########################\n\t\t\t\t\t         #########################\n\t\t\t\t\t         #########################\n\t\t\t\t\t         ###########   ###########\n\t\t\t\t\t         ##########     ##########\n\t\t\t\t\t        ##########       ##########\n\t\t\t\t\t        #########         #########\n\t\t\t\t\t        ########           ########\n\t\t\t\t\t         ######             ######\n\t\t\t\t\t          #####              ####\n\t\t\t\t\t           ####              ###\n\t\t\t\t\t             ###            ###\n\t\t\t\t\t               ##          ##");
	printf("\n\n\t\t\t\t\t         D E N T A L    C L I N I C\n\n\t\t\t\t\t\t    A P P O I N T M E N T\n");
}

// function that displays a line in the console using a for loop
void lineLoop()
{
	int ctr;

	printf("\n");
	for (ctr = 0; ctr < 120; ctr++)
	{
		printf("=");
	}
	printf("\n");
}

// function that displays the menu options
void menuOptions()
{
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);

	printf("\n\n\t\t\t\t\t< - - H O M E   P A G E - - >\t\t\t\t%s", ctime(&t));
	lineLoop();

	printf("\t\t\t\t\t   A - Schedule an appointment\n\t\t\t\t\t   B - Search a patient's record\n\t\t\t\t\t   C - Reschedule an appointment\n\t\t\t\t\t   D - Cancel appointment\n\t\t\t\t\t   E - Pending Appointments\n\t\t\t\t\t   F - Past records\n\t\t\t\t\t   G - Exit");
	lineLoop();
}

// function that displays the dental services offered and returns the value of what the user will choose
int services()
{
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	int option;
	do
	{
		system("CLS");
		printf("\n\n\t\t\t\t< - - D E N T A L   S E R V I C E S   O F F E R E D  - - >\t%s", ctime(&t));
		lineLoop();
		printf("\n\t\t\t\t\t  1 - Tooth Extraction\tTE | P 1200\n\t\t\t\t\t  2 - Teeth Whitening\tTW | P 9000\n\t\t\t\t\t  3 - Dental Fillings\tDF | P 1000\n\t\t\t\t\t  4 - Root Canal\tRC | P 6000\n\t\t\t\t\t  5 - Check Up\t\tCU | P 800\n\t\t\t\t\t  6 - Dental Cleaning\tDC | P 1000");
		lineLoop();
		printf("\n\t\t\t\t\tPatient's Choice: ");
		scanf("%d", &option);
		fflush(stdin);
		if (option < 1 || option > 6)
		{
			lineLoop();
			printf("\t\t\t\t- Wrong option. 1 - 6 only. Press any key to enter again...");
			getch();
		}
	} while (option < 1 || option > 6);
	return option;
}

// search an ID inputted by the user if it exist in the past records
int searchExist(patient array[100], char searchV[4])
{
	int ctr;
	for (ctr = 0; ctr < existingLen; ctr++)
	{
		// if found siya sa past record, i return ang position
		if (strcmpi(searchV, array[ctr].patientID) == 0)
		{
			ctr++;
			return ctr;
		}
	}
	return 0;
}

// search an ID inputted by the user if it is in the pending appointment record
int searchWait(patient waitingList[rSize][cSize + 1], char searchV[4], int *row)
{

	int ctr, ctr2;
	// used 2 for loops since 2d array ning gi searchan
	for (ctr = 0; ctr < rSize; ctr++)
	{
		for (ctr2 = 0; ctr2 < cSize; ctr2++)
		{
			// if found i return ang column positiion
			if (strcmpi(searchV, waitingList[ctr][ctr2].patientID) == 0)
			{
				*row = ctr; // since usa ra man ka value pwede i return, mao nagamit ko ani para ma store sad if asa nga index no. sa row nakit an
				return ctr2 + 1;
			}
		}
	}
	return 0;
}

// function that inputs details of the patient to fill up
void inputDetails(patient waitingList[rSize][cSize + 1], patient existing[100], int day)
{
	int result, count, searchResult = 0, searchResult2 = 0, row = 0;
	char tempID[4] = {""};
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	do
	{
		do
		{
			system("CLS");
			printf("\n\n\t\t\t\t\t< - - P A T I E N T   I N F O R M A T I O N - - >\t%s", ctime(&t));
			lineLoop();
			printf("\n\t\t\t\t\tNew Patient's ID [3 digits]: ");
			gets(tempID);
			// lets the user know na mali iya na type or invalid
			if (strlen(tempID) != 3)
			{
				lineLoop();
				printf("\t\t\t\t- Wrong typed. a patient's ID consist 3 digits. Press any key to type again...");
				getch();
			}
		} while (strlen(tempID) != 3); // validation since naplanohan namo nga 3 digits lang ang ID tanan

		// searching if nag exist ba ang ID sa past records
		searchResult = searchExist(existing, tempID);
		// searching if nag exist sad ba ang ID sa upcoming appointments or pending
		searchResult2 = searchWait(waitingList, tempID, &row);
		// if found siya either one of the records, then dili siya pwede kay nag exist naman ang ID, dapat unique ang ID every patient
		if (searchResult != 0 || searchResult2 != 0)
		{
			printf("\n\t\t\t\t- This ID already exist. Press any key to enter again...");
			getch();
		}

	} while (searchResult != 0 || searchResult2 != 0); // validating para makatype ang user balik ug unique nga ID no
	// makagawas siya sa loop if valid na ang ID nga gi input sa user
	// mag add nag record sa pending appointment or waitingList nga struct array

	// copying the valid ID sa waitingList nga array, ang day is row siya since 2d ang waitingList  nga array
	// waitingLen which is the length of array nga naay value or index [column] nga naay real elements or sulod
	strcpy(waitingList[day - 1][waitingLen[day - 1]].patientID, tempID);
	// ngayog input sa user ug i copy siya sa waitingList nga struct array
	printf("\n\t\t\t\t\tFirst Name: ");
	gets(waitingList[day - 1][waitingLen[day - 1]].fullname.fname);
	fflush(stdin);
	printf("\n\t\t\t\t\tMiddle Initial: ");
	scanf("%c", &waitingList[day - 1][waitingLen[day - 1]].fullname.mI);
	fflush(stdin);
	printf("\n\t\t\t\t\tLast Name: ");
	gets(waitingList[day - 1][waitingLen[day - 1]].fullname.lname);
	fflush(stdin);
	printf("\n\t\t\t\t\tAge: ");
	scanf("%d", &waitingList[day - 1][waitingLen[day - 1]].age);
	fflush(stdin);
	do
	{
		printf("\n\t\t\t\t\tContact #: ");
		gets(waitingList[day - 1][waitingLen[day - 1]].contact);
		fflush(stdin);
		if (strlen(waitingList[day - 1][waitingLen[day - 1]].contact) != 11)
		{
			lineLoop();
			printf("\t\t\t\t- Wrong typed. Contact # consist 11 digits. Press any key to type again...");
			getch();
			system("CLS");
			printf("\n\n\t\t\t\t\t< - - P A T I E N T   I N F O R M A T I O N - - >\t%s", ctime(&t));
			lineLoop();
			printf("\n\t\t\t\t\tNew Patient's ID: %s\n\n\t\t\t\t\tFirst Name: %s\n\n\t\t\t\t\tMiddle Initial: %c\n\n\t\t\t\t\tLast Name: %s\n\n\t\t\t\t\tAge: %d\n", waitingList[day - 1][waitingLen[day - 1]].patientID, waitingList[day - 1][waitingLen[day - 1]].fullname.fname, waitingList[day - 1][waitingLen[day - 1]].fullname.mI, waitingList[day - 1][waitingLen[day - 1]].fullname.lname, waitingList[day - 1][waitingLen[day - 1]].age);
		}
		// validation para dapat 11 digits ang contact no.
	} while (strlen(waitingList[day - 1][waitingLen[day - 1]].contact) != 11);
	// displayign the services offered, makapili ang user ug unsa nga service ag gipili sa patient then return the no. nga gipili sa user ug gi store siya sa result nga variable
	result = services();
	// gistore lang nakog laing variable kay murag taas ra if waitingList...countRecord ang ibutang as index number
	count = waitingList[day - 1][waitingLen[day - 1]].countRecord;
	// switch condition depende ug unsa nga service ang gipili sa pasyente
	// i copy lang ani ag service nga abbreviation adto sa record sa pending appointment sa pasyente
	switch (result)
	{
	case 1:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "TE");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1200;
		break;
	case 2:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "TW");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 9000;
		break;
	case 3:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "DF");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1000;
		break;
	case 4:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "RC");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 6000;
		break;
	case 5:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "CU");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 800;
		break;
	default:
		strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "DC");
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1000;
		break;
	}
	// kini i record ug unsa nga date ag appointment sa pasyente dpende sa iyang gipili nga adlaw
	// Jan 2 to 6 lnag ni nga week amoa , bali 1 week lang siya
	switch (day)
	{
	case 1:
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;  // month
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 2;  // day
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23; // year  23 = 2023
		break;
	case 2:
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 3;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
		break;
	case 3:
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 4;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
		break;
	case 4:
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 5;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
		break;
	default:
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 6;
		waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
		break;
	}
	waitingList[day - 1][waitingLen[day - 1]].countRecord++;
}
// function that displays option of weekdays
void weekDays()
{
	printf("\n\t\t\t\t\t\t1 - Monday\n\t\t\t\t\t\t2 - Tuesday\n\t\t\t\t\t\t3 - Wednesday\n\t\t\t\t\t\t4 - Thursday\n\t\t\t\t\t\t5 - Friday");
}

// function that will schedule an appointment
void scheduleAppointment(patient existingList[100], patient waitingList[rSize][cSize + 1])
{
	char option, tempID[4], ans, ans2;
	int day, result, searchResult, searchResult2, row = 0, count, count2, ctr;
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	// validating if puno na gali ang limit tanan nga adlaw, then ingun dayun nga kini nga week kay full na
	if (totalLen >= 25)
	{
		system("CLS");
		printf("\n\n\t\t\t\t   < - - S C H E D U L E    A P P O I N T M E N T - - >\t\t%s", ctime(&t));
		lineLoop();
		printf("\n\t\t\t\t- Appointment for the first week of January is already full");
	}
	else
	{ // else if dili pa puno tanang days then i marun ni

		do
		{
			system("CLS");
			printf("\n\n\t\t\t\t   < - - S C H E D U L E    A P P O I N T M E N T - - >\t\t%s", ctime(&t));
			lineLoop();
			printf("\n\t\t\t\t\t\tIs the patient...\n\n\t\t\t\t\t\tA - New\n\t\t\t\t\t\tB - Regular\n");
			lineLoop();
			printf("\n\t\t\t\t\t\tEnter: ");
			scanf("%c", &option);
			fflush(stdin);
			// letting the user know nga invalid iya gi input
			if (toupper(option) != 'A' && toupper(option) != 'B')
			{
				printf("\n\t\t\t\t\t- Wrong option. Letter A or B only");
				lineLoop();
				printf("\t\tPress any key to enter again...");
				getch();
			}
			// validationn para A ug B ra ma input sa user
		} while (toupper(option) != 'A' && toupper(option) != 'B');
		do
		{

			do
			{
				system("CLS");
				printf("\n\t\t\t\t\tWhich day the patient wants an appointment?");
				lineLoop();
				weekDays();
				lineLoop();
				// kini nga if condition is para dili madisplay sa output  ug "days nga full" if wala pay nafull
				if (waitingLen[0] >= 5 || waitingLen[1] >= 5 || waitingLen[2] >= 5 || waitingLen[3] >= 5 || waitingLen[4] >= 5)
				{
					// if naa nay nafull nga day ( 5 person per day)  then i display ang days nga full na para makahibaw agad ang user
					printf("Days that are already full: ");
					if (waitingLen[0] >= 5)
					{
						printf("MONDAY ");
					}
					if (waitingLen[1] >= 5)
					{
						printf("TUESDAY ");
					}
					if (waitingLen[2] >= 5)
					{
						printf("WEDNESDAY ");
					}
					if (waitingLen[3] >= 5)
					{
						printf("THURDAY ");
					}
					if (waitingLen[4] >= 5)
					{
						printf("FRIDAY ");
					}
				}
				// nangayog input sa user unsang adlawa
				printf("\n\t\t\t\t\t\tEnter: ");
				scanf("%d", &day);
				fflush(stdin);
				// letting the user know nga mali ag iya gi input
				if (day < 1 || day > cSize)
				{
					printf("\n\t\t\t\t\t- Wrong number entered. 1 to %d only", cSize);
					lineLoop();
					printf("\t\tPress any key to enter again...");
					getch();
				}
				// validation again sa input sa user, dapat 1 to 5 lang since from monday to friday lang open ang clinic, 5 days lang siya
				// this do while loop is allowing the user to input again a correct value
			} while (day < 1 || day > cSize);

			// if ang day nga gi input sa user is again full na ug appointments , then mu display siyag this day is already full
			if (waitingLen[day - 1] >= 5)
			{
				printf("\n\t\t\t\t\t- This day is already full.");
				lineLoop();
				printf("\n\t\t\tEnter Y to choose other day:  ");
				scanf("%c", &ans2);
			}
		} while (toupper(ans2) == 'Y' && waitingLen[day - 1] >= 5);
		if (waitingLen[day - 1] >= 5)
		{
			printf("\n\t\t\t\t\t- Appointment canceled");
		}
		else
		{ // else if dili pa gani puno then i run ni

			// if condition para sa new ug old patient since naay kalahian ang pag schedule ug appointment
			// if 'A' meaning new patient then mangayog ang user sa basic information sa patient like name, age, contact number and i add to sa pending appointment nga struct array
			// i copy na sad ani ag mga ID, service nga gipili sa patient, date of the appointment ug cost sa service
			if (toupper(option) == 'A')
			{
				// function nga maag add ug record sa new patient
				inputDetails(waitingList, existingList, day);
				waitingLen[day - 1]++; // adding 1 sa length depnde unsa nga row/day since nag add ta ug record sa pending appointment
				printf("\n\t\t\t\t\tSuccessfully added an appointment.");
				getch();
			}
			else // if old patient or existing patient na, then no need to input again basic informations
			{
				do
				{
					do
					{
						system("CLS");
						printf("\n\n\t\t\t\t\t< - - P A T I E N T   I N F O R M A T I O N - - >\t%s", ctime(&t));
						lineLoop();
						// need input sa id sa exisiting patient para isearch lang ang iya information
						printf("\n\t\t\t\t\tPatient's ID[3 digits]: ");
						gets(tempID);
						fflush(stdin);
						if (strlen(tempID) != 3)
						{
							lineLoop();
							printf("\t\t\t\t- Wrong typed. a patient's ID consist 3 digits. Press any key to type again...");
							getch();
						}
						// validation gihapon para 3 digits ang ma input sa user
					} while (strlen(tempID) != 3);
					// searching if nag exist ang ID sa past records
					searchResult = searchExist(existingList, tempID);
					// searching if nag exist na ba pud ang id sa pending nga appointment records
					searchResult2 = searchWait(waitingList, tempID, &row);

					// if wala siya mag exist both then i display nga ID dont exist or walay sa records tong ID ha
					if (searchResult == 0 && searchResult2 == 0)
					{
						lineLoop();
						// the user will be given a chance to enter again if ganahan siya
						printf("\t\t\t\t\t- %s ID don't exist. \n\n\t\t\t\tDo you want to enter again? [Type Y if Yes]: ", tempID);
						scanf("%c", &ans);
						fflush(stdin);
					}
					// validating if wala sa mga records ang ID ug gusto mo enter ang user again.
				} while (searchResult == 0 && searchResult2 == 0 && toupper(ans) == 'Y');
				lineLoop();

				// else if wala sa records ang ID unya dili na mudayon ang user ug enter again then mu display ug no appoinment added ug mu go back na to home page
				if (searchResult == 0 && searchResult2 == 0 && toupper(ans) != 'Y')
				{
					printf("\n\t\t\t\t\tHaven't added an appointment");
				}
				else
				{ // else if found ang ID sa records then ma run ni

					// validation if nag exist na ang id sa pending appointments
					// it will display nga naka book na siya ug appointment ana nga week, para  d na siya magbook  balik2
					if (searchResult2 != 0)
					{
						printf("\n\t\t\tPatient %s: %s %c. %s has already booked an appointment this week", tempID, waitingList[row][searchResult2 - 1].fullname.fname, waitingList[row][searchResult2 - 1].fullname.mI, waitingList[row][searchResult2 - 1].fullname.lname);
					}
					else
					{
						// else if wala siya sa pending appointments pa then successfully maka appoinmetn siya
						// display nga nag exist ang ID sa past records
						printf("\n\t\t\t\tPatient %s - %s %c. %s has an existing record of this clinic.", existingList[searchResult - 1].patientID, existingList[searchResult - 1].fullname.fname, existingList[searchResult - 1].fullname.mI, existingList[searchResult - 1].fullname.lname);
						getch();
						// copying the basic infos sa old patient to the pending appointment since ganahan siya magpa appointment balik
						count = waitingList[day - 1][waitingLen[day - 1]].countRecord;
						count2 = existingList[searchResult - 1].countRecord;
						strcpy(waitingList[day - 1][waitingLen[day - 1]].patientID, existingList[searchResult - 1].patientID);
						strcpy(waitingList[day - 1][waitingLen[day - 1]].contact, existingList[searchResult - 1].contact);
						strcpy(waitingList[day - 1][waitingLen[day - 1]].fullname.fname, existingList[searchResult - 1].fullname.fname);
						waitingList[day - 1][waitingLen[day - 1]].fullname.mI = existingList[searchResult - 1].fullname.mI;
						strcpy(waitingList[day - 1][waitingLen[day - 1]].fullname.lname, existingList[searchResult - 1].fullname.lname);
						waitingList[day - 1][waitingLen[day - 1]].age = existingList[searchResult - 1].age;

						// displaying the services ug mangayo input sa user ug unsa gipili sa services
						result = services();

						// copying the abbreviation of services dpende ug unsa gipili sa patient
						switch (result)
						{
						case 1:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "TE");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1200;
							break;
						case 2:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "TW");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 9000;
							break;
						case 3:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "DF");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1000;
							break;
						case 4:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "RC");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 6000;
							break;
						case 5:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "DCU");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 800;
							break;
						default:
							strcpy(waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].service, "DC");
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].price = 1000;
							break;
						}

						// nagbutang sad ug unsa gna date ang appointment sa patient dpende sa unsa nga day iya gipili
						switch (day)
						{
						case 1:
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;  // month
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 2;  // day
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23; // year  23 = 2023
							break;
						case 2:
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 3;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
							break;
						case 3:
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 4;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
							break;
						case 4:
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 5;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
							break;
						default:
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[0] = 1;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[1] = 6;
							waitingList[day - 1][waitingLen[day - 1]].fullRecord[count].date[2] = 23;
							break;
						}

						waitingList[day - 1][waitingLen[day - 1]].countRecord++;
						waitingLen[day - 1]++;
						printf("\n\t\t\t\t\tSuccessfully added an appointment.");
					}
				}
			}
		}
	}
	getch();
}

// a function that searches if a patient exist in past records or pending appointment records or both. It will then display its data if found
void searchPatient(patient existingList[100], patient waitingList[rSize][cSize + 1])
{
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	int search, search2, row = 0, ctr, count;
	char tempID[4];
	do
	{
		system("CLS");
		printf("\n\n\t\t\t\t   < - - S E A R C H   P A T I E N T  - - >\t\t%s", ctime(&t));
		lineLoop();
		// ngayog patient ID sa user para sa search
		printf("\n\t\t\t\t\tEnter Patient's ID: ");
		gets(tempID);
		fflush(stdin);
		if (strlen(tempID) != 3)
		{
			lineLoop();
			printf("\t\t\t\t- Wrong typed. a patient's ID consist 3 digits. Press any key to type again...");
			getch();
		}
	} while (strlen(tempID) != 3); // validation again para 3 digits ang id iinput sa user

	// searching again if nag exist ba siya sa past records or pending appointment  record
	search = searchExist(existingList, tempID);
	search2 = searchWait(waitingList, tempID, &row);

	// if wala mag exist then  ipahibaw sa user nga wala record nang id or wala siya ga exist
	if (search == 0 && search2 == 0)
	{
		printf("\n\t\t\t\tID - %s don't have any record or pending appointment", tempID);
	}
	else
	{ // else if nakit an , then ma run na nga code

		// if nakit an siya sa past record, then i ipahibaw sa user
		if (search != 0)
		{
			printf("\n\t\t\t\t\t- Patient %s has an existing record in this clinic", tempID);
		} // wala ko ga else if or else since it is possible that the ID will exist in both past records ug pending appointment records

		// if nakit an siya sa pending appointment,  then i ipahibaw sa user pud
		if (search2 != 0)
		{
			printf("\n\t\t\t\t\t- Patient %s has a pending appointment", tempID);
		}
		lineLoop();
		printf("\n\n\t\t\t\t\tPress any key to view his/her record...");
		getch();

		system("CLS");
		printf("\n\n\t\t\t\t   < - - P A T I E N T ' S    R E C O R D  - - >\t\t%s", ctime(&t)); // i display na ag record sa patient
		lineLoop();
		// if naay nag exist sa past records ra or both past record ug pending appoinment records then mao ni ang i display
		if (search != 0 || (search != 0 && search2 != 0))
		{
			printf("\n\t\t\t\t\tPatient ID: %s", existingList[search - 1].patientID);
			printf("\n\t\t\t\t\tName: %s %c. %s", existingList[search - 1].fullname.fname, existingList[search - 1].fullname.mI, existingList[search - 1].fullname.lname);
			printf("\n\t\t\t\t\tAge: %d", existingList[search - 1].age);
			printf("\n\t\t\t\t\tContact #: %s", existingList[search - 1].contact);
			lineLoop();
			printf("\n\t\t\t\t\t%d EXISTING RECORD", existingList[search - 1].countRecord);
			count = existingList[search - 1].countRecord;
			for (ctr = 0; ctr < count; ctr++)
			{
				printf("\n\t\t\t\t\t%d) DATE: %02d/%02d/%02d - SERVICE: %s | PAID: %.2f", ctr + 1, existingList[search - 1].fullRecord[ctr].date[0], existingList[search - 1].fullRecord[ctr].date[1], existingList[search - 1].fullRecord[ctr].date[2], existingList[search - 1].fullRecord[ctr].service, existingList[search - 1].fullRecord[ctr].price);
			}
			if (search2 != 0)
			{
				lineLoop();
				printf("\n\t\t\t\t\t%d PENDING APPOINTMENT", waitingList[row][search2 - 1].countRecord);
				count = waitingList[row][search2 - 1].countRecord;
				for (ctr = 0; ctr < count; ctr++)
				{
					printf("\n\t\t\t\t\t%d) DATE: %02d/%02d/%02d - SERVICE: %s | COST: %.2f", ctr + 1, waitingList[row][search2 - 1].fullRecord[ctr].date[0], waitingList[row][search2 - 1].fullRecord[ctr].date[1], waitingList[row][search2 - 1].fullRecord[ctr].date[2], waitingList[row][search2 - 1].fullRecord[ctr].service, waitingList[row][search2 - 1].fullRecord[ctr].price);
				}
			}
		}
		else // if sa pending records ra siya nag exist then kini nga code ma run, pareha pareha lang silas babaw naa lang kalahian gamay
		{	 // i think pwede pa ni ma minimize na code bali i usa lnag sa ibabaw nga if pero kapoy na hehe pareha ra bitaw
			printf("\n\t\t\t\t\tPatient ID: %s", waitingList[row][search2 - 1].patientID);
			printf("\n\t\t\t\t\tName: %s %c. %s", waitingList[row][search2 - 1].fullname.fname, waitingList[row][search2 - 1].fullname.mI, waitingList[row][search2 - 1].fullname.lname);
			printf("\n\t\t\t\t\tAge: %d", waitingList[row][search2 - 1].age);
			printf("\n\t\t\t\t\tContact #: %s", waitingList[row][search2 - 1].contact);
			lineLoop();
			printf("\n\t\t\t\t\t%d PENDING APPOINTMENT", waitingList[row][search2 - 1].countRecord);
			count = waitingList[row][search2 - 1].countRecord;
			for (ctr = 0; ctr < count; ctr++)
			{
				printf("\n\t\t\t\t\t%d) DATE: %02d/%02d/%02d - SERVICE: %s | COST: %.2f", ctr + 1, waitingList[row][search2 - 1].fullRecord[ctr].date[0], waitingList[row][search2 - 1].fullRecord[ctr].date[1], waitingList[row][search2 - 1].fullRecord[ctr].date[2], waitingList[row][search2 - 1].fullRecord[ctr].service, waitingList[row][search2 - 1].fullRecord[ctr].price);
			}
		}
	}
	getch();
}

// function to delete a data or info sa usa ka patient if mucancel  siya or mu reschedule ba
// bali i move lang siya padung sa kinaunhan since slot2 ning appointment , if naay madelete or mawala then ma isbog tung ga sunod niya pa una depende ug unsa nga position tung mawala
void deleteData(patient waitingList[rSize][cSize + 1], int row, int search)
{
	int ctr;

	if (search == 1)
	{
		for (ctr = 0; ctr < waitingLen[row]; ctr++)
		{
			waitingList[row][ctr] = waitingList[row][ctr + 1];
		}
	}
	else if (search == cSize)
	{
		waitingList[row][cSize - 1] = waitingList[row][cSize]; // the real size of our cSize is 5 pero nag add kog usa para if madelete tung last element, makacopy ug value nga xxxx ug 0 from index 5 since i display nako tanang row ug column whether naay sulod or wala
	}
	else if (search > 1 && search <= waitingLen[row])
	{
		for (ctr = search - 1; ctr < waitingLen[row]; ctr++)
		{
			waitingList[row][ctr] = waitingList[row][ctr + 1];
		}
	}
}

// function to enable the user na makaresched if ganahan magreschedule ang usa ka patient
void reschedule(patient waitingList[rSize][cSize + 1])
{
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	int day, search, row = 0, ctr;
	char tempID[4], ans;
	// if wala pa gali appointment sa tanang days, then dili pa makareschedule since wala pa may record nga naay naka schedule
	// ipahibaw dayun sa user nga wala pay list of pending appoinment
	if (totalLen == 0)
	{
		lineLoop();
		printf("\n\t\t\t\t\tThere is still no pending appointment");
	}
	// if wala nay slot tanang days then dili sad makaresched since puno na
	else if (totalLen == 25)
	{
		lineLoop();
		printf("\n\t\t\tCannot reschedule since all the days is already full of appointments");
	}
	else
	{ // else if naa na then kini nga code mu run

		do
		{
			system("CLS");
			printf("\n\n\t\t\t   < - - R E S C H E D U L E    A P P O I N T M E N T - - >\t\t%s", ctime(&t));
			lineLoop();
			// mangayo lang sa ID sa patient para ma search iya information
			printf("\n\t\t\t\tEnter Patient's ID[3 digits]: ");
			gets(tempID);
			fflush(stdin);
			if (strlen(tempID) != 3)
			{
				lineLoop();
				printf("\t\t\t\t- Wrong typed. a patient's ID consist 3 digits. Press any key to type again...");
				getch();
			}
			// validation again para 3 digits lang ma input
		} while (strlen(tempID) != 3);
		// searching if naa ba siya sa pending appointment nga records
		search = searchWait(waitingList, tempID, &row);

		if (search == 0) // wala ma found then display nga wala siyay pending appoinment unya mu go back na to home page after
		{
			printf("\n\t\t\t\t-ID %s doesn't have a record of any pending appointment", tempID);
		}
		else
		{ // else if found then ma run ni
			do
			{ // display ug what date ang user nakapa appoinment na
				printf("\n\t\t\t\t- Patient %s have a pending appointment on %02d/%02d/%02d.", waitingList[row][search - 1].patientID, waitingList[row][search - 1].fullRecord[0].date[0], waitingList[row][search - 1].fullRecord[0].date[1], waitingList[row][search - 1].fullRecord[0].date[2]);
				lineLoop();
				// asking the user if i dayun ba gyud pag reschedule sa appointment
				printf("\n\t\t\t\tContinue to reschedule Patient %s's appointment or not? [Y/N]: ", waitingList[row][search - 1].patientID);
				scanf("%c", &ans);
				fflush(stdin);
				if (toupper(ans) != 'Y' && toupper(ans) != 'N')
				{
					printf("\n\t\t\t\t- Please enter only Y or N.Press any key to enter again...");
					getch();
					system("CLS");
				}
				// validation para Y ug N lang ma input sa user
			} while (toupper(ans) != 'Y' && toupper(ans) != 'N');

			// if yes then makareschedule na
			if (toupper(ans) == 'Y')
			{
				do
				{ // validation if ang date/day nga napili sa pasyente kay same day/date sa iyang pending appointment, if mag resched so dapat laing adlaw, dili same day

					do // validation para 1 to 5 lang ma input sa user which is the day options
					{
						system("CLS");
						printf("\n\t\t\t\tWhich day the patient wants to reschedule the appointment?");
						lineLoop();
						weekDays();
						lineLoop();
						// displaying again sa user if naay day nga na full na
						if (waitingLen[0] >= 5 || waitingLen[1] >= 5 || waitingLen[2] >= 5 || waitingLen[3] >= 5 || waitingLen[4] >= 5)
						{
							printf("Days that are already full: ");
							if (waitingLen[0] >= 5)
							{
								printf("MONDAY ");
							}
							if (waitingLen[1] >= 5)
							{
								printf("TUESDAY ");
							}
							if (waitingLen[2] >= 5)
							{
								printf("WEDNESDAY ");
							}
							if (waitingLen[3] >= 5)
							{
								printf("THURDAY ");
							}
							if (waitingLen[4] >= 5)
							{
								printf("FRIDAY ");
							}
						}

						printf("\n\t\t\t\t\t\tEnter: ");
						scanf("%d", &day);
						fflush(stdin);
						if (day < 1 || day > cSize)
						{
							printf("\n\t\t\t\t\t- Wrong number entered. 1 to %d only", cSize);
							lineLoop();
							printf("\t\tPress any key to enter again...");
							getch();
						}
						// validation para 1 to 5 lang ma input sa user which is the day options
					} while (day < 1 || day > cSize);
					if ((day - 1) == row)
					{
						printf("\n\t- Can't reschedule in this day since it is the same date %02d/%02d/%02d to the pending schedule of the patient", waitingList[row][search - 1].fullRecord[0].date[0], waitingList[row][search - 1].fullRecord[0].date[1], waitingList[row][search - 1].fullRecord[0].date[2]);
						lineLoop();
						printf("\t\tPress any key to enter again...");
						getch();
					}
					// validation if ang date/day nga napili sa pasyente kay same day/date sa iyang pending appointment, if mag resched so dapat laing adlaw, dili same day
				} while ((day - 1) == row);

				// validation again if ag napili sa user nga adlaw kay puno na
				if (waitingLen[day - 1] >= 5)
				{
					printf("\n\t\t\t\t\t- This day is already full.");
				}
				else // if dili puno then maka resched na gyud siya successfully
				{
					// moving its data dpende ug unsa nga day siya magparesched
					waitingList[day - 1][waitingLen[day - 1]] = waitingList[row][search - 1];

					// changing its date since the patient reschedule so dili na same date sa iya old pending appoinment
					switch (day)
					{
					case 1:
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0] = 1;	// month
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1] = 2;	// day
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2] = 23; // year  23 = 2023
						break;
					case 2:
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0] = 1;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1] = 3;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2] = 23;
						break;
					case 3:
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0] = 1;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1] = 4;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2] = 23;
						break;
					case 4:
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0] = 1;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1] = 5;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2] = 23;
						break;
					default:
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0] = 1;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1] = 6;
						waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2] = 23;
						break;
					}
					printf("\n\t\t\t\t- Successfully reschedule Patient %s's appointment on %02d/%02d/%02d", waitingList[day - 1][waitingLen[day - 1]].patientID, waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[0], waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[1], waitingList[day - 1][waitingLen[day - 1]].fullRecord->date[2]);
					waitingLen[day - 1]++;

					// calling the function that can delete the data of the patient's old  pending appointment record
					deleteData(waitingList, row, search);
					waitingLen[row]--;
				}
			}
		}
	}
	getch();
}

// function that is capable to cancel a pending appointment of a user of they wish to cancel it
void cancelAppointment(patient waitingList[rSize][cSize + 1])
{
	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);
	int day, search, row = 0, ctr, count;
	char tempID[4], ans;
	// checking again if wala pa bay nagpa appointment
	if (totalLen == 0)
	{
		lineLoop();
		printf("\n\t\t\t\t\tThere is still no pending appointment");
	}
	else
	{ // else if naa nay pending appointment na then ma run ni nga code

		do
		{
			system("CLS");
			printf("\n\n\t\t\t   < - - D E L E T E    A P P O I N T M E N T - - >\t\t%s", ctime(&t));
			lineLoop();

			printf("\n\t\t\t\tEnter Patient's ID: ");
			gets(tempID);
			fflush(stdin);
			if (strlen(tempID) != 3)
			{
				lineLoop();
				printf("\t\t\t\t- Wrong typed. a patient's ID consist 3 digits. Press any key to type again...");
				getch();
			}
		} while (strlen(tempID) != 3); // validation again
		// searching if makita ba siya sa pending appoinment nga List or record
		search = searchWait(waitingList, tempID, &row);

		if (search == 0) // if ID is not found sa pending appoinment nga List
		{
			printf("\n\t\t\t\t-ID %s doesn't have a record of any pending appointment", tempID);
		}
		else // if found
		{
			do
			{
				printf("\n\t\t\t\t- Patient %s have a pending appointment on %02d/%02d/%02d.", waitingList[row][search - 1].patientID, waitingList[row][search - 1].fullRecord[0].date[0], waitingList[row][search - 1].fullRecord[0].date[1], waitingList[row][search - 1].fullRecord[0].date[2]);
				lineLoop();
				// asking the user if idayun ba jud ug cancel
				printf("\n\t\t\t\tContinue to cancel Patient %s's appointment or not? [Y/N]: ", waitingList[row][search - 1].patientID);
				scanf("%c", &ans);
				fflush(stdin);
				if (toupper(ans) != 'Y' && toupper(ans) != 'N')
				{
					printf("\n\t\t\t\t- Please enter only Y or N.Press any key to enter again...");
					getch();
					system("CLS");
				}

			} while (toupper(ans) != 'Y' && toupper(ans) != 'N'); // validatation Y or N only
		}
		if (toupper(ans) == 'Y')
		{
			// calling the function that can delete the data in the pending appointment list
			deleteData(waitingList, row, search);
			printf("\n\t\t\t\t\t- Successfully canceled Patient %s's appointment.", tempID);
			waitingLen[row]--;
		}
	}
	getch();
}

// function that displays the list of pending appointment from monday to friday
void pendingAppointment(patient waitingList[rSize][cSize + 1])
{
	int i;

	system("CLS");
	printf("\n\n\t\t\t\t\t   < - - P E N D I N G    A P P O I N T M E N T S - - >\t\t");
	printf("\n=====================================================================================================================================================\n");

	printf("MONDAY\t\t\t\tTUESDAY\t\t\t\tWEDNESDAY\t\t\tTHURSDAY\t\t\tFRIDAY");
	printf("\n=====================================================================================================================================================\n");

	for (i = 0; i < 5; i++)
	{
		printf("\n%d) Patient ID: %s\t\t%d) Patient ID: %s\t\t%d)Patient ID: %s\t\t%d) Patient ID: %s\t\t%d) Patient ID: %s", i + 1, waitingList[0][i].patientID, i + 1, waitingList[1][i].patientID, i + 1, waitingList[2][i].patientID, i + 1, waitingList[3][i].patientID, i + 1, waitingList[4][i].patientID);
		fflush(stdout);
		printf("\nFirst name: %s\t\tFirst name: %s\t\tFirst name: %s\t\tFirst name: %s\t\tFirst name: %s", waitingList[0][i].fullname.fname, waitingList[1][i].fullname.fname, waitingList[2][i].fullname.fname, waitingList[3][i].fullname.fname, waitingList[4][i].fullname.fname);
		fflush(stdout);
		printf("\nMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.", waitingList[0][i].fullname.mI, waitingList[1][i].fullname.mI, waitingList[2][i].fullname.mI, waitingList[3][i].fullname.mI, waitingList[4][i].fullname.mI);
		fflush(stdout);
		printf("\nLast name: %s\t\tLast name: %s\t\tLast name: %s\t\tLast name: %s\t\tLast name: %s", waitingList[0][i].fullname.lname, waitingList[1][i].fullname.lname, waitingList[2][i].fullname.lname, waitingList[3][i].fullname.lname, waitingList[4][i].fullname.lname);
		fflush(stdout);
		printf("\n%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old", waitingList[0][i].age, waitingList[1][i].age, waitingList[2][i].age, waitingList[3][i].age, waitingList[4][i].age);
		fflush(stdout);
		printf("\n%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s", waitingList[0][i].contact, waitingList[1][i].contact, waitingList[2][i].contact, waitingList[3][i].contact, waitingList[4][i].contact);
		fflush(stdout);
		printf("\nService: %s\t\t\tService: %s\t\t\tService: %s\t\t\tService: %s\t\t\tService: %s", waitingList[0][i].fullRecord->service, waitingList[1][i].fullRecord->service, waitingList[2][i].fullRecord->service, waitingList[3][i].fullRecord->service, waitingList[4][i].fullRecord->service);
		fflush(stdout);
		printf("\nCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f", waitingList[0][i].fullRecord->price, waitingList[1][i].fullRecord->price, waitingList[2][i].fullRecord->price, waitingList[3][i].fullRecord->price, waitingList[4][i].fullRecord->price);
		fflush(stdout);
		printf("\n%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d", waitingList[0][i].fullRecord->date[0], waitingList[0][i].fullRecord->date[1], waitingList[0][i].fullRecord->date[2], waitingList[1][i].fullRecord->date[0], waitingList[1][i].fullRecord->date[1], waitingList[1][i].fullRecord->date[2], waitingList[2][i].fullRecord->date[0], waitingList[2][i].fullRecord->date[1], waitingList[2][i].fullRecord->date[2], waitingList[3][i].fullRecord->date[0], waitingList[3][i].fullRecord->date[1], waitingList[3][i].fullRecord->date[2], waitingList[4][i].fullRecord->date[0], waitingList[4][i].fullRecord->date[1], waitingList[4][i].fullRecord->date[2]);
		fflush(stdout);
		printf("\n=====================================================================================================================================================\n");
	}
	getch();
}

// function to bubble sort the past records in alphabetical order
void alphabeticalSort(patient sorted[100])
{
	int c, ctr, i;
	patient temp;

	// sorting first by last name
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if (strcmp(sorted[ctr].fullname.lname, sorted[ctr + 1].fullname.lname) > 0)
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
	// sorting by first name if the same last name
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if ((strcmp(sorted[ctr].fullname.lname, sorted[ctr + 1].fullname.lname) == 0) && (strcmp(sorted[ctr].fullname.fname, sorted[ctr + 1].fullname.fname) > 0))
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
	// sorting by middle initial if the same last name and first name
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if ((strcmp(sorted[ctr].fullname.lname, sorted[ctr + 1].fullname.lname) == 0) && (strcmp(sorted[ctr].fullname.fname, sorted[ctr + 1].fullname.fname) == 0) && (sorted[ctr].fullname.mI > sorted[ctr + 1].fullname.mI > 0))
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
}

// function to bubble sort the past records by ID in ascending order
void idSort(patient sorted[100])
{
	int c, ctr, i;
	patient temp;

	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if (strcmp(sorted[ctr].patientID, sorted[ctr + 1].patientID) > 0)
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
}

// function to bubble sort the past records by date in ascending order
void dateSort(patient sorted[100])
{
	int c, ctr, i;
	patient temp;

	// sorting first by year
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if (sorted[ctr].fullRecord->date[2] > sorted[ctr + 1].fullRecord->date[2])
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
	// sorting  by month if same year
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if ((sorted[ctr].fullRecord->date[2] == sorted[ctr + 1].fullRecord->date[2]) && (sorted[ctr].fullRecord->date[0] > sorted[ctr + 1].fullRecord->date[0]))
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
	// sorting  by day if same month and year
	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if ((sorted[ctr].fullRecord->date[2] == sorted[ctr + 1].fullRecord->date[2]) && (sorted[ctr].fullRecord->date[0] == sorted[ctr + 1].fullRecord->date[0]) && (sorted[ctr].fullRecord->date[1] > sorted[ctr + 1].fullRecord->date[1]))
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
}

// function that sort by service
void serviceSort(patient sorted[100])
{
	int c, ctr, i;
	patient temp;

	for (c = 1; c < existingLen - 1; c++)
	{
		for (ctr = 0; ctr < existingLen - 1; ctr++)
		{
			if (strcmp(sorted[ctr].fullRecord->service, sorted[ctr + 1].fullRecord->service) > 0)
			{
				temp = sorted[ctr + 1];
				sorted[ctr + 1] = sorted[ctr];
				sorted[ctr] = temp;
			}
		}
	}
}

// funciton that displays the past records, the type of listings will be done here
void pastRecords(patient existingList[100])
{
	patient sorted[100];
	int i, ctr;
	char opt;
	do
	{
		do
		{
			system("CLS");
			printf("\n\t\t\t\t\t   < - - P A S T    R E C O R D S   P A G E - - >\t\t");
			/* this is just a code snippet of displaying the original contents of the array

			lineLoop();
			printf("\tID\tNAME\t\t\tAGE\tCONTACT#\t\tDATE\t\tSERVICE\t\tPAID");
			lineLoop();
			for (i = 0; i < existingLen; i++)
			{
				printf("\n\t%s\t%s,%s %c.\t%d\t%s\t\t%02d/%02d/%02d\t%s\t\tP %.2f\n", existingList[i].patientID, existingList[i].fullname.lname, existingList[i].fullname.fname, existingList[i].fullname.mI, existingList[i].age, existingList[i].contact, existingList[i].fullRecord->date[0], existingList[i].fullRecord->date[1], existingList[i].fullRecord->date[2], existingList[i].fullRecord->service, existingList[i].fullRecord->price);
			}
			*/
			lineLoop();
			printf("\n\t\t\t\t\t\tDISPLAY RECORDS BY:\n\n\t\t\t\t\t\tA - Alphabetical order\n\t\t\t\t\t\tB - ID in ascending order\n\t\t\t\t\t\tC - Date from oldest to most recent\n\t\t\t\t\t\tD - Service Category\n\t\t\t\t\t\tE - Go back to HOME PAGE\n");
			lineLoop();
			printf("\n\t\t\t\t\tEnter: ");
			scanf("%c", &opt);
			fflush(stdin);

			// if the user inputted an invalid data, this condition will let the user that the data is invalid
			if (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E')
			{

				printf("\n\t\t\t\t\t- Wrong option. Letter A to E only");
				lineLoop();
				printf("\t\tPress any key to enter again...");
				getch();
			}
		} while (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E');

		// copying the values of past records to another struct array so that the original array will not be change
		for (ctr = 0; ctr < existingLen; ctr++)
		{
			sorted[ctr] = existingList[ctr];
		}
		// switch condition depdning on what type of list the user want to be displayed on the console
		switch (toupper(opt))
		{
		// sorting in alphabetical order and display it
		case 'A':
			alphabeticalSort(sorted);
			system("CLS");
			printf("\n\t\t\t\t   < - - A L P H A B E T I C A L    O R D E R - - >\t\t");
			lineLoop();
			printf("\t\tNAME\t\tID\tAGE\tCONTACT#\t\tDATE\t\tSERVICE\t\tPAID");
			lineLoop();
			for (i = 0; i < existingLen; i++)
			{
				printf("\n\t%s, %s %c.\t%s\t%d\t%s\t\t%02d/%02d/%02d\t%s\t\tP %.2f\n", sorted[i].fullname.lname, sorted[i].fullname.fname, sorted[i].fullname.mI, sorted[i].patientID, sorted[i].age, sorted[i].contact, sorted[i].fullRecord->date[0], sorted[i].fullRecord->date[1], sorted[i].fullRecord->date[2], sorted[i].fullRecord->service, sorted[i].fullRecord->price);
			}
			lineLoop();
			printf("\n\t\t\t\t\tPress any key to go back to past records page...");
			getch();
			break;
		// sorting in ascending order of ID and display it
		case 'B':
			idSort(sorted);
			system("CLS");
			printf("\n\t\t\t\t   < - - I D   A S C E N D I N G   O R D E R - - >\t\t");
			lineLoop();
			printf("\tID\tNAME\t\t\tAGE\tCONTACT#\t\tDATE\t\tSERVICE\t\tPAID");
			lineLoop();
			for (i = 0; i < existingLen; i++)
			{
				printf("\n\t%s\t%s, %s %c.\t%d\t%s\t\t%02d/%02d/%02d\t%s\t\tP %.2f\n", sorted[i].patientID, sorted[i].fullname.lname, sorted[i].fullname.fname, sorted[i].fullname.mI, sorted[i].age, sorted[i].contact, sorted[i].fullRecord->date[0], sorted[i].fullRecord->date[1], sorted[i].fullRecord->date[2], sorted[i].fullRecord->service, sorted[i].fullRecord->price);
			}
			lineLoop();
			printf("\n\t\t\t\t\tPress any key to go back to past records page...");
			getch();
			break;
		// sorting by date from oldest to latest and display it
		case 'C':
			dateSort(sorted);
			system("CLS");
			printf("\n\t\t\t   < - - F R O M   O L D E S T   T O   L A T E S T   O R D E R- - >\t\t");
			lineLoop();
			printf("\tDATE\t\tID\tNAME\t\t\tAGE\tCONTACT#\tSERVICE\t\tPAID");
			lineLoop();
			for (i = 0; i < existingLen; i++)
			{
				printf("\n\t%02d/%02d/%02d\t%s\t%s, %s %c.\t%d\t%s\t%s\t\tP %.2f\n", sorted[i].fullRecord->date[0], sorted[i].fullRecord->date[1], sorted[i].fullRecord->date[2], sorted[i].patientID, sorted[i].fullname.lname, sorted[i].fullname.fname, sorted[i].fullname.mI, sorted[i].age, sorted[i].contact, sorted[i].fullRecord->service, sorted[i].fullRecord->price);
			}
			lineLoop();
			printf("\n\t\t\t\t\tPress any key to go back to past records page...");
			getch();
			break;
		// sorting in by service and display it
		case 'D':
			serviceSort(sorted);
			system("CLS");
			printf("\n\t\t\t\t   < - - S E R V I C E   C A T E G O R Y - - >\t\t");
			lineLoop();
			printf("\tSERVICE\t\tID\tNAME\t\t\tAGE\tCONTACT#\t\tDATE\t\tPAID");
			lineLoop();
			for (i = 0; i < existingLen; i++)
			{
				printf("\n\t%s\t\t%s\t%s, %s %c.\t%d\t%s\t\t%02d/%02d/%02d\tP %.2f\n", sorted[i].fullRecord->service, sorted[i].patientID, sorted[i].fullname.lname, sorted[i].fullname.fname, sorted[i].fullname.mI, sorted[i].age, sorted[i].contact, sorted[i].fullRecord->date[0], sorted[i].fullRecord->date[1], sorted[i].fullRecord->date[2], sorted[i].fullRecord->price);
			}
			lineLoop();
			printf("\n\t\t\t\t\tPress any key to go back to past records page...");
			getch();

			break;
		}

	} while (toupper(opt) != 'E');
}

// a function that records the final informations into a .txt file before the program finally exits
void fileHandling(patient existingList[100], patient waitingList[rSize][cSize + 1], float income)
{
	FILE *fp;
	fp = fopen("Records.txt", "w+");

	int i;

	// for the displaying of the current time and date
	time_t t; // not a primitive datatype
	time(&t);

	fprintf(fp, "Recorded: %s\n\t\t\t\t\tDENTAL CLINIC RECORDS\n\n\n\t\t\t\t\t    PAST RECORDS\n", ctime(&t));

	// alphabetical order
	alphabeticalSort(existingList);

	fprintf(fp, "\n1. Alphabetical Order\n=================================================================================================================\n");
	fprintf(fp, "\t\tNAME\t\tID\tAGE\tCONTACT#\t\tDATE\t\tSERVICE\t\tPAID\n=================================================================================================================\n");
	for (i = 0; i < existingLen; i++)
	{
		fprintf(fp, "\n\t%s, %s %c.\t%s\t%d\t%s\t\t%02d/%02d/%02d\t%s\t\tP %.2f\n", existingList[i].fullname.lname, existingList[i].fullname.fname, existingList[i].fullname.mI, existingList[i].patientID, existingList[i].age, existingList[i].contact, existingList[i].fullRecord->date[0], existingList[i].fullRecord->date[1], existingList[i].fullRecord->date[2], existingList[i].fullRecord->service, existingList[i].fullRecord->price);
	}

	// id ascendinig order
	idSort(existingList);
	fprintf(fp, "=================================================================================================================\n\n2. ID ASCENDING ORDER\n=================================================================================================================\n");
	fprintf(fp, "\tID\tNAME\t\t\tAGE\tCONTACT#\t\tDATE\t\tSERVICE\t\tPAID\n=================================================================================================================\n");
	for (i = 0; i < existingLen; i++)
	{
		fprintf(fp, "\n\t%s\t%s, %s %c.\t%d\t%s\t\t%02d/%02d/%02d\t%s\t\tP %.2f\n", existingList[i].patientID, existingList[i].fullname.lname, existingList[i].fullname.fname, existingList[i].fullname.mI, existingList[i].age, existingList[i].contact, existingList[i].fullRecord->date[0], existingList[i].fullRecord->date[1], existingList[i].fullRecord->date[2], existingList[i].fullRecord->service, existingList[i].fullRecord->price);
	}

	// by date
	dateSort(existingList);
	fprintf(fp, "=================================================================================================================\n\n3. Date from oldest to latest\n=================================================================================================================\n");
	fprintf(fp, "\tDATE\t\tID\tNAME\t\t\tAGE\tCONTACT#\tSERVICE\t\tPAID\n=================================================================================================================\n");
	for (i = 0; i < existingLen; i++)
	{
		fprintf(fp, "\n\t%02d/%02d/%02d\t%s\t%s, %s %c.\t%d\t%s\t%s\t\tP %.2f\n", existingList[i].fullRecord->date[0], existingList[i].fullRecord->date[1], existingList[i].fullRecord->date[2], existingList[i].patientID, existingList[i].fullname.lname, existingList[i].fullname.fname, existingList[i].fullname.mI, existingList[i].age, existingList[i].contact, existingList[i].fullRecord->service, existingList[i].fullRecord->price);
	}

	// by service
	serviceSort(existingList);
	fprintf(fp, "=================================================================================================================\n\n4. By Service\n=================================================================================================================\n");
	fprintf(fp, "\tSERVICE\t\tID\tNAME\t\t\tAGE\tCONTACT#\t\tDATE\t\tPAID\n=================================================================================================================\n");
	for (i = 0; i < existingLen; i++)
	{
		fprintf(fp, "\n\t%s\t\t%s\t%s, %s %c.\t%d\t%s\t\t%02d/%02d/%02d\tP %.2f\n", existingList[i].fullRecord->service, existingList[i].patientID, existingList[i].fullname.lname, existingList[i].fullname.fname, existingList[i].fullname.mI, existingList[i].age, existingList[i].contact, existingList[i].fullRecord->date[0], existingList[i].fullRecord->date[1], existingList[i].fullRecord->date[2], existingList[i].fullRecord->price);
	}

	// pending appointments
	fprintf(fp, "=================================================================================================================\n\n\n\n\n\n\n\t\t\t\t\t    PENDING APPOINTMENT RECORD\n");
	fprintf(fp, "=====================================================================================================================================================\n\nMONDAY\t\t\t\tTUESDAY\t\t\t\tWEDNESDAY\t\t\tTHURSDAY\t\t\tFRIDAY");
	fprintf(fp, "\n=====================================================================================================================================================\n");

	for (i = 0; i < 5; i++)
	{
		fprintf(fp, "\n%d) Patient ID: %s\t\t%d) Patient ID: %s\t\t%d)Patient ID: %s\t\t%d) Patient ID: %s\t\t%d) Patient ID: %s", i + 1, waitingList[0][i].patientID, i + 1, waitingList[1][i].patientID, i + 1, waitingList[2][i].patientID, i + 1, waitingList[3][i].patientID, i + 1, waitingList[4][i].patientID);
		fprintf(fp, "\nFirst name: %s\t\tFirst name: %s\t\tFirst name: %s\t\tFirst name: %s\t\tFirst name: %s", waitingList[0][i].fullname.fname, waitingList[1][i].fullname.fname, waitingList[2][i].fullname.fname, waitingList[3][i].fullname.fname, waitingList[4][i].fullname.fname);
		fprintf(fp, "\nMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.\t\tMiddle Initial: %c.", waitingList[0][i].fullname.mI, waitingList[1][i].fullname.mI, waitingList[2][i].fullname.mI, waitingList[3][i].fullname.mI, waitingList[4][i].fullname.mI);
		fprintf(fp, "\nLast name: %s\t\tLast name: %s\t\tLast name: %s\t\tLast name: %s\t\tLast name: %s", waitingList[0][i].fullname.lname, waitingList[1][i].fullname.lname, waitingList[2][i].fullname.lname, waitingList[3][i].fullname.lname, waitingList[4][i].fullname.lname);
		fprintf(fp, "\n%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old\t\t\t%d yrs old", waitingList[0][i].age, waitingList[1][i].age, waitingList[2][i].age, waitingList[3][i].age, waitingList[4][i].age);
		fprintf(fp, "\n%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s", waitingList[0][i].contact, waitingList[1][i].contact, waitingList[2][i].contact, waitingList[3][i].contact, waitingList[4][i].contact);
		fprintf(fp, "\nService: %s\t\t\tService: %s\t\t\tService: %s\t\t\tService: %s\t\t\tService: %s", waitingList[0][i].fullRecord->service, waitingList[1][i].fullRecord->service, waitingList[2][i].fullRecord->service, waitingList[3][i].fullRecord->service, waitingList[4][i].fullRecord->service);
		fprintf(fp, "\n%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d\t\t\t%02d/%02d/%02d", waitingList[0][i].fullRecord->date[0], waitingList[0][i].fullRecord->date[1], waitingList[0][i].fullRecord->date[2], waitingList[1][i].fullRecord->date[0], waitingList[1][i].fullRecord->date[1], waitingList[1][i].fullRecord->date[2], waitingList[2][i].fullRecord->date[0], waitingList[2][i].fullRecord->date[1], waitingList[2][i].fullRecord->date[2], waitingList[3][i].fullRecord->date[0], waitingList[3][i].fullRecord->date[1], waitingList[3][i].fullRecord->date[2], waitingList[4][i].fullRecord->date[0], waitingList[4][i].fullRecord->date[1], waitingList[4][i].fullRecord->date[2]);
		fprintf(fp, "\nCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f\t\t\tCost: P %.2f", waitingList[0][i].fullRecord->price, waitingList[1][i].fullRecord->price, waitingList[2][i].fullRecord->price, waitingList[3][i].fullRecord->price, waitingList[4][i].fullRecord->price);
		fprintf(fp, "\n=====================================================================================================================================================\n");
	}
	fprintf(fp, "\n\nWeekly Pofit[Jan 02 - 06 2023] = P %.2f\n\n", income);

	if (fp != NULL)
	{
		printf("\n\n\t\t\t\t\t- Informations recorded successfully -");
	}
	else
	{
		printf("\n\t\t\t\t- Error! Can\'t record the info, can\'t access the file");
	}

	fclose(fp);
}

int main()
{
	patient waitingList[rSize][cSize + 1], existingList[size] = {
											   {"Rosefin", 'B', "Galolo", "100", "09511532208", 60, 1, "TE", {07, 21, 21}, 1200},
											   {"Janna", 'F', "Mahumas", "001", "09356423542", 19, 1, "DC", {05, 19, 22}, 1000},
											   {"Fatima", 'E', "Udtohan", "200", "09356423272", 18, 1, "CU", {03, 03, 22}, 800},
											   {"Robin", 'T', "Rodrigez", "400", "09356638193", 28, 1, "DF", {9, 30, 21}, 1000},
											   {"Sanaki", 'M', "Aguilar", "300", "09195438282", 26, 1, "DC", {05, 19, 22}, 1000},
											   {"Lindsay", 'B', "Doblas", "005", "09511532208", 20, 1, "TW", {01, 04, 20}, 9000},
											   {"Cyril", 'F', "Mahumas", "500", "09356423542", 21, 1, "RC", {02, 25, 18}, 6000},
											   {"Zaydel", 'P', "Aguilar", "002", "09356423272", 22, 1, "CU", {06, 22, 22}, 800},
											   {"Christy", 'M', "Galolo", "003", "09356638193", 47, 1, "DF", {04, 11, 19}, 1000},
											   {"Fatima", 'O', "Udtohan", "004", "09195438282", 36, 1, "DC", {07, 26, 20}, 1000}

										   };

	char opt;
	int row, col, ctr;
	float income;

	// initializing  records of every pending appointments
	for (row = 0; row < rSize; row++)
	{
		for (col = 0; col < cSize + 1; col++)
		{
			strcpy(waitingList[row][col].patientID, "XXX");
			strcpy(waitingList[row][col].contact, "XXXXXXXXXXX");
			strcpy(waitingList[row][col].fullname.fname, "Xxxxxx");
			waitingList[row][col].fullname.mI = 'X';
			strcpy(waitingList[row][col].fullname.lname, "Xxxxxxxxx");
			strcpy(waitingList[row][col].fullRecord->service, "XX");
			waitingList[row][col].fullRecord->date[0] = 0;
			waitingList[row][col].fullRecord->date[1] = 0;
			waitingList[row][col].fullRecord->date[2] = 0;
			waitingList[row][col].fullRecord->price = 0;
			waitingList[row][col].countRecord = 0;
			waitingList[row][col].age = 0;
		}
	}

	logoDesign();
	lineLoop();
	printf("\t\t\t\t\tPress any key to open the app....");
	getch();

	// a do while loop that enable the program to only exit or end if the user chooses the exit option.
	do
	{
		// a do while loop that let the user to input again if they inputted an invalid data
		do
		{
			totalLen = 0;
			for (ctr = 0; ctr < cSize; ctr++)
			{
				totalLen += waitingLen[ctr];
			}

			system("CLS");

			menuOptions();

			printf("\n\t\t\t\t\tEnter: ");
			scanf("%c", &opt);
			fflush(stdin);

			// if the user inputted an invalid data, this condition will let the user that the data is invalid
			if (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E' && toupper(opt) != 'F' && toupper(opt) != 'G')
			{

				printf("\n\t\t\t\t\t- Wrong option. Letter A to G only");
				lineLoop();
				printf("\t\tPress any key to enter again...");
				getch();
			}

		} while (toupper(opt) != 'A' && toupper(opt) != 'B' && toupper(opt) != 'C' && toupper(opt) != 'D' && toupper(opt) != 'E' && toupper(opt) != 'F' && toupper(opt) != 'G');

		switch (toupper(opt))
		{

		case 'A':
			scheduleAppointment(existingList, waitingList);
			break;

		case 'B':
			searchPatient(existingList, waitingList);
			break;

		case 'C':
			reschedule(waitingList);
			break;

		case 'D':
			cancelAppointment(waitingList);
			break;
		case 'E':
			pendingAppointment(waitingList);
			break;
		case 'F':
			pastRecords(existingList);
			break;
		default:
			// computing the overall income /profit from the pending appointments jan 02 to 06
			income = 0;
			for (row = 0; row < rSize; row++)
			{
				for (col = 0; col < cSize; col++)
				{
					income += waitingList[row][col].fullRecord->price;
				}
			}
			system("CLS");
			logoDesign();
			lineLoop();
			printf("\t\t\t\t\t\tDEVELOPED BY: BUGGY TEAM\n\n\t\t\t\tRezelle June G. Udtohan\t\tJonavia J. Mahumas\n\n\t\t\t\t\t\tCCS 104 B BATCH 2\n\n\t\t\t\t\t[ - - F I N A L   P R O J E C T - - ]");

			// RECORDING THE FINAL INFORMATIONS TO A TEXT FILE BEFORE SUCCESSFULLY EXITING
			fileHandling(existingList, waitingList, income);
			printf("\n\n\t\t\t\t\t *** THIS PROGRAM WILL NOW EXIT ***");
			getch();
			break;
		}

	} while (toupper(opt) != 'G');
}

// end of the program :>