#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main(){
	float distance, distance1, payable, earnings = 0;
	int ctr, i = 0, g;
	char type, ans, ans2;
	
	do{
		do{		/*the do-while loop at this part will let the user to input again if the data inputted by the user is invalid [which is the distance]*/
			system("CLS");
			
			printf("\n\t\t\t\t ~ B U S	F A R E	    T O T A L I Z E R ~\n");
			
			for(ctr=1;ctr<=120;ctr++){	/* This is just a line for design on my application*/
				printf("_");
			}
			
			printf("\n\n\t\t\t\t\t\t** M E N U **\n\n\t[A] - Child\t\t[B] - Student\t\t[C] - Adult\t\t[D] - Senior Citizen\n");
			
			printf("\n\n\t\t***NOTE: you can\'t ride the bus if your distance is less than 10 km or more than 100 km.***\n");
			
			for(ctr=1;ctr<=120;ctr++){	/* This is just a line for design on my application*/
				printf("_");
			}
			
			g=i+1;
			printf("\n %d\n\n\n\t- Input the no. of distance in kilometer you\'d be riding in the bus: ", g);
			scanf("%f", &distance);
			
			if(distance<10 || distance >100){
				printf("\n\t\t\t\t\t***INVALID! PLEASE READ THE NOTE***\n\nPress any key to input distance again..."); 			/*In case the data input here by the user is invalid, this text will show up */
				getch();
			}
			fflush(stdin);
		}while(distance<10 || distance >100);
		
		distance1 = distance/10;		/* The distance inputted is divided by 10 since the fare is depends by per 10km*/
		
		printf("\n");
		for(ctr=1;ctr<=120;ctr++){	/* This loop again is just a line for design on my application*/
			printf("-");
		}
		
		do {	/*the do-while loop at this part will let the user to input again if the data inputted by the user is invalid [which is the MENU OPTIONS]*/
			
			printf("\n\n\n\t\t\t\t\tWHAT TYPE OF COMMUTER ARE YOU? \n\n\t- [A, B, C, D] refer to the MENU at the top: ");
			scanf("%c", &type);
			fflush(stdin);
			switch(toupper(type)){
				case 'A': payable = 15*distance1;
					printf("\n\t\t\t\t\t >> Your fare is P %.2f\n", payable); break;
				case 'B': payable = 20*distance1;
					printf("\n\t\t\t\t\t >> Your fare is P %.2f\n", payable); break;
				case 'C': payable = 30*distance1;
					printf("\n\t\t\t\t\t >> Your fare is P %.2f\n", payable); break;
				case 'D': payable = 10*distance1;
					printf("\n\t\t\t\t\t >> Your fare is P %.2f\n", payable); break;
				default: printf("\n\t\t\t***INVALID!! Wrong typed, Please refer to the MENU [A, B, C , D only]***\n\nPress any key to enter what type of commuter are you again..."); 
					getch();		/*the purpose of the default is incase the user inputted invalid data, the text above will show up if it is invalid*/
				}
				
		}while(toupper(type)!='A'&&toupper(type)!='B'&&toupper(type)!='C'&&toupper(type)!='D');
		
		earnings+=payable;
		i++;
		
		for(ctr=1;ctr<=120;ctr++){	/* This loop again is just a line for design on my application*/
			printf("-");
		}
		
		do{		/*the do-while loop at this part will let the user to input again if the data inputted by the user is invalid [which is the YES OR NO]*/
			printf("\n\t\t\t\t\tARE THERE STILL COMMUTERS? \n\n\t- [Type Y for a yes and N for a no] : ");
			scanf("%c", &ans);
			fflush(stdin);
			if(toupper(ans)!='Y'&&toupper(ans)!='N'){/*the purpose of this if else statement is incase the user inputted invalid data, a text will show up to let the user know that they inputted an invalied data*/
				printf("\n\t\t\t\t  *** INVALID!! Type only \"Y\" or \"N\" ***\n\nPress any key to type again...");
				getch();
			}
		}while(toupper(ans)!='Y'&&toupper(ans)!='N');
		
		if(toupper(ans)=='Y'){
			printf("\n\nPress any key to input again details of the other commuter....");
			getch();
		}
		
	}while(toupper(ans)=='Y');	/* This is the main loop where it depends if there area still commuters or none*/
	
	/* This part is where it already exits the main loop of the program*/
	printf("\n\nPress any key to see the total no. of commuters that rode the bus and to see the total income of the bus....");
	getch();
	
	system("CLS");
	printf("\n\n\n\t\t\t\t\t *** R E S U L T ***\n\n\t\t- There are %d commuters that rode the bus in this route.\n\n\t\t- The total income earned by the bus is %.2f", i, earnings);
	if(earnings<1000){		/* This multiple selection structure part is where it determines the status of income*/
		printf("\n\n\t\t\t\t\t >> Very Low Income");
	}else if(earnings >= 1000 && earnings<= 3000){
		printf("\n\n\t\t\t\t\t >> Low Income");
	}else if(earnings >3000 && earnings <= 5000){
		printf("\n\n\t\t\t\t\t >> Average Income");
	}else{
		printf("\n\n\t\t\t\t\t\t >> High Income");
	}
	/* This part of code is just for displaying my name, section and course*/
	printf("\n\n\n\n\n\nPress any key to see who made this application....");
	getch();
	system("CLS");
	printf("\n\nThis application is made by:\n\n\n\t\t\tR E Z E L L E\t\tJ U N E\t\tU D T O H A N\n\n\t\t\t\t\t      B S I T - 1\n\t\t\t\t\t    C C S  1 0 2 - A\n\n\n\n");
	return 0;
}
