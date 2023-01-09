#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// declaration of global variables
int i, a = 0;

// this function displays a series of underscore symbol using a for loop statement that will create a line for design purposes
void lineLoop()
{
	printf("\n");
	for (i = 1; i < 120; i++)
	{
		printf("_");
	}
	printf("\n");
}

// this function displays a welcome messsage to the user
void welcomeDisplay()
{

	printf("\n\n\n\n\n\n\t\t\t\t ");

	for (i = 1; i < 60; i++)
	{
		printf("-");
	}

	for (i = 1; i < 3; i++)
	{
		printf("\n\t\t\t\t!\t\t\t\t\t\t\t    !");
	}

	printf("\n\t\t\t\t!\t\t  W   E   L   C   O   M   E\t\t    !");

	for (i = 1; i < 3; i++)
	{
		printf("\n\t\t\t\t!\t\t\t\t\t\t\t    !");
	}

	printf("\n\t\t\t\t!\t\t\tU   S   E   R\t\t\t    !");

	for (i = 1; i < 4; i++)
	{
		printf("\n\t\t\t\t!\t\t\t\t\t\t\t    !");
	}

	printf("\n\t\t\t\t!\t\t[ press any key to continue ]\t\t    !");

	for (i = 1; i < 3; i++)
	{
		printf("\n\t\t\t\t!\t\t\t\t\t\t\t    !");
	}

	printf("\n\t\t\t\t ");

	for (i = 1; i < 60; i++)
	{
		printf("-");
	}

	printf("\n\n\n\n\n");
	getch();
}

// this function just displays the name of my program
void nameOfTheProgram()
{

	printf("\n\n\n\n\t\t\t\t\t#####  #   #  #  ####\t\t#  #### ");
	printf("\n\t\t\t\t\t  #    #   #  #  #   \t\t#  #\n");
	printf("\t\t\t\t\t  #    #####  #  ####\t\t#  ####");
	printf("\n\t\t\t\t\t  #    #   #  #     #\t\t#     #");
	printf("\n\t\t\t\t\t  #    #   #  #  ####\t\t#  ####\n\n\n\n");
	printf("\t\t\t\t\t   ########      #########      #######\n");
	printf("\t\t\t\t\t   ###          ##       ##    ### \n");
	printf("\t\t\t\t\t   ##           ##       ##     ###\n");
	printf("\t\t\t\t\t   ######       ## #######       #####\n");
	printf("\t\t\t\t\t   ##           ##   ####            ###\n");
	printf("\t\t\t\t\t   ###          ##      ##           ###\n");
	printf("\t\t\t\t\t   ########     ##       ##    ########\n\n\n");
	printf("\t\t\t\t\tE N T R Y     R E C O R D     S Y S T E M\n\n\n\n");
	printf("\t\t\t\t\t\t[ press any key to continue ]\n\n\n");
	getch();
}

// function for displaying menu options
void menuOptions()
{
	printf("\n\t\t\t\t\tMENU OPTIONS:\n\n\t\t\t\t\t[1] - New Entry\n\t\t\t\t\t[2] - List of all Entries\n\t\t\t\t\t[3] - Search an Entry\n\t\t\t\t\t[0] - Exit\n");
	printf("\t\t\t\t     ============================================\n\n");
}

// a user-defined data type

struct entry
{
	char name[40];
	char address[50];
	char mobileNo[15];
	char timeIn[6];
} n[1000];

void fillUp()
{

	FILE *fp;

	system("CLS");

	fp = fopen("Records.txt", "a+");

	printf("\n\n\t\t\t\t\t\t<-- New Entry Form -->");
	lineLoop();

	printf("\n\t\t\tEnter your name: ");
	gets(n[a].name);
	fflush(stdin);

	printf("\n\t\t\tEnter your address: ");
	gets(n[a].address);
	fflush(stdin);

	printf("\n\t\t\tEnter your mobile #: ");
	gets(n[a].mobileNo);
	fflush(stdin);

	printf("\n\t\t\tEnter the current time [24 HRS FORMAT ex. 16:00 ]: ");
	gets(n[a].timeIn);
	fflush(stdin);

	lineLoop();

	if (fp != NULL)
	{
		printf("\n\t\t\t- New Entry recorded successfully");
	}
	else
	{
		printf("\n\t\t\t- Error! Can\'t record the info because I can\'t access the file");
	}

	fprintf(fp, "\n\n-----------------------------------------------------------------------------\n\tName: %s\n\tAddress: %s\n\tMobile #: %s\n\tTime In: %s", n[a].name, n[a].address, n[a].mobileNo, n[a].timeIn);

	fclose(fp);
}

void addNewEntry()
{

	char ans1, ans2;
	float temp;

	system("CLS");

	printf("\n\n\n\n\n\n\t\t\t      Before you can enter inside, answer some questions first\n\t\t\t\t----------------------------------------------------\n\t\t\t\t       *for COVID-19 control and prevention*\n\n\n\n\n\n\n\t\t\t\t\t[press any key to start answering]\n\n\n\n\n\n\n");
	getch();

	do
	{
		system("CLS");

		printf("\n\n\n\n\n\t\t\t\t\t - Are you currently wearing a mask ?\n\n\t\t\t\t\t[Y/N] : ");
		scanf("%c", &ans1);
		fflush(stdin);

		if (toupper(ans1) != 'Y' && toupper(ans1) != 'N')
		{
			lineLoop();
			printf("\n\n\t\t\t\t\t\t- Error! Y and N only\n\n\tPress any key to answer again....");
			getch();
		}

	} while (toupper(ans1) != 'Y' && toupper(ans1) != 'N');

	if (toupper(ans1) == 'Y')
	{

		lineLoop();
		printf("\n\t\tPress any key to proceed to another question...");
		getch();

		do
		{
			system("CLS");
			printf("\n\n\n\n\n\t\t\t\t- Are you experiencing the symptoms below these past few days?\n\t\t\t\t\t   ( fever, cough, shortness of breath )\n\n\t\t\t\t\t[Y/N] : ");
			scanf("%c", &ans2);
			fflush(stdin);

			if (toupper(ans2) != 'Y' && toupper(ans2) != 'N')
			{
				lineLoop();
				printf("\n\n\t\t\t\t\t\t- Error! Y and N only\n\n\tPress any key to answer again....");
				getch();
			}

		} while (toupper(ans2) != 'Y' && toupper(ans2) != 'N');

		if (toupper(ans2) == 'N')
		{

			lineLoop();
			printf("\n\t\tPress any key to proceed to another question...");
			getch();

			system("CLS");
			printf("\n\n\n\n\n\t\t\t\t- NOTE: SCAN YOURSELF ON THE THERMAL SCANNER\n\n\t\t\t\tEnter your temperature [CELSIUS] : ");
			scanf("%f", &temp);
			fflush(stdin);

			if (temp <= 37.5)
			{

				printf("\n\n\n\n\t\tPress any key to continue...");
				getch();

				system("CLS");
				printf("\n\n\n\n\n\n\t\t\t<-- You can enter inside since you have no sign of COVID-19 -->\n\n");
				lineLoop();
				printf("\n\n\n\t\t\t**You have something to fill up first before entering successfully**\n\t\t\t--------------------------------------------------------------------\n\n");
				printf("\n\n\n\n\t\tPress any key to proceed...");
				getch();

				system("CLS");
				fillUp();

				a++;
			}
			else
			{
				printf("\n\n\t* You cannot enter because you\'re temperature is above normal, it could possibly be a sign of COVID-19*");
			}
		}
		else
		{
			printf("\n\n\t\t\t* You cannot enter because you\'re experiencing some signs and symptoms of COVID-19 *");
		}
	}
	else
	{
		printf("\n\n\t\t\t\t- You cannot enter because you\'re not wearing a mask");
	}
}

void listEntries()
{

	int b;

	system("CLS");

	printf("\n\n\t\t\t\t\t\t<-- List of All Entries -->");
	lineLoop();

	if (a == 0)
	{
		printf("\n\n\t\t\t\t\t\t   No entry/entries yet\n\n\n\n");
	}
	else
	{
		for (i = 0; i < a; i++)
		{

			b = i + 1;

			printf("\n\t\t\t\t\t%d) Name: %s", b, n[i].name);
			printf("\n\t\t\t\t\t   Address: %s", n[i].address);
			printf("\n\t\t\t\t\t   Mobile #: %s", n[i].mobileNo);
			printf("\n\t\t\t\t\t   Time In: %s", n[i].timeIn);
			printf("\n\t\t\t\t\t-------------------------------------\n");
		}
	}
}

void searchEntry()
{

	int result = 1, d = 0;
	char search[40];

	system("CLS");

	printf("\n\n\t\t\t\t\t\t<-- Search a recorded entry -->");
	lineLoop();

	if (a == 0)
	{
		printf("\n\n\t\t\t\t- You can\'t search yet because there are no entry/entries yet\n\n\n\n");
	}

	else
	{
		printf("\n\n\t\t\t\t\tEnter the name you want to search: ");
		gets(search);
		fflush(stdin);

		while (result != 0 && d < a)
		{
			result = strcmpi(search, n[d].name);

			d++;
		}

		lineLoop();

		if (result == 0)
		{
			d--;
			printf("\n\t\t\t\t\t\t** I N F O R M A T I O N **");
			printf("\n\t\t\t\t\t\t------------------------------");
			printf("\n\t\t\t\t\t- Name: %s", n[d].name);
			printf("\n\t\t\t\t\t- Address: %s", n[d].address);
			printf("\n\t\t\t\t\t- Mobile #: %s", n[d].mobileNo);
			printf("\n\t\t\t\t\t- Time In: %s", n[d].timeIn);
		}
		else
		{

			printf("\n\n\t\t\t\t\t\t[ N O    R E S U L T ]\n\n\n\t\t - It could be because the person you searched has not yet entered successfully\n\t\t - or maybe the name is mispelled\n\n\n");
		}
	}
}

// main function
int main()
{

	int options;

	welcomeDisplay();

	system("CLS");

	nameOfTheProgram();

	do
	{

		do
		{
			system("CLS");

			printf("\n\n\t\t\t\t< - - E N T R Y     R E C O R D    S Y S T E M - - >");

			lineLoop();

			menuOptions();

			printf("\t\t\t\t\tNOTE: REFER FROM THE MENU OPTIONS ABOVE\n\n\n\t\t\t\t\t- Enter option [0,1,2,3]: ");
			scanf("%d", &options);
			fflush(stdin);
			lineLoop();

			if (options < 0 || options > 3)
			{
				printf("\n\t\t\t\t- Error! Please refer from the menu options above [0,1,2,3] only\n\n\n\tPress any key to input again...");
				getch();
			}

		} while (options < 0 || options > 3);

		printf("\n\n\t\t- Press any key to proceed...");
		getch();

		switch (options)
		{

		case 1:
			addNewEntry();

			lineLoop();

			printf("\n\n\n\tPress any key to go back to MENU OPTIONS...");
			getch();

			break;

		case 2:
			listEntries();

			lineLoop();

			printf("\n\n\n\n\tPress any key to go back to MENU OPTIONS...");
			getch();

			break;

		case 3:
			searchEntry();

			lineLoop();

			printf("\n\n\n\n\tPress any key to go back to MENU OPTIONS...");
			getch();

			break;

		default:
			system("CLS");

			printf("\n\n\n\n\t\t\t\t\t\t- The program will now exit\n\n\n\n\tPress any key to exit...\n\n\n\n");
			getch();
		}

	} while (options != 0);

	return 0;
}
