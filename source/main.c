#include <3ds.h>
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char **argv) {
    gfxInitDefault();
	
	PrintConsole topScreen, bottomScreen;
	int choice = 1;
	FILE *file;
	
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	
	consoleSelect(&topScreen);
	printf(ANSI_COLOR_YELLOW "\x1b[13;14HTHE LEGEND OF TOADSTOOL\n" ANSI_COLOR_RESET);
	printf("\x1b[15;6HYou can quit anytime by pressing \x1b[36mSTART\x1b[0m.\n");
	printf("\x1b[17;10HThe game is saved when quitting.\n");
	
	consoleSelect(&bottomScreen);
	printf("\x1b[15;12HPress \x1b[36mA\x1b[0m to continue.\n");

    while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	gfxExit();
    		return 0;
		}
		
		else if(hidKeysDown() & KEY_A) {
        	break;
		}
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
	
	int savefile = 0;
	file = fopen("save.txt", "r");
	if(file == NULL) {
		FILE* file = fopen("save.txt", "w");
		fprintf(file, "0");
		fclose(file);
	}
	file = fopen("save.txt", "r");	
	fscanf(file,"%d", &savefile);
	
	// edit this whenever there is a new saveskip
	if(savefile != 0) { 
		consoleInit(GFX_TOP, &topScreen);
		consoleInit(GFX_BOTTOM, &bottomScreen);
		
		consoleSelect(&topScreen);
		printf("\x1b[14;12HA save file has been found.");
		printf("\x1b[16;14HDo you wish to continue?");
		
		consoleSelect(&bottomScreen);
		printf("\x1b[14;12HPress \x1b[36mA\x1b[0m to continue.\n");
		printf("\x1b[16;10HPress \x1b[36mB\x1b[0m to delete file.\n");
		
		while(aptMainLoop()) {
        	gspWaitForVBlank();
        	hidScanInput();
        	
        	if(hidKeysDown() & KEY_START) {
        		FILE* file = fopen("save.txt", "w");
        		fprintf(file, "%d", savefile);
        		fclose(file);
        		gfxExit();
    			return 0;
			}
			
        	else if(hidKeysDown() & KEY_A) {
        		consoleInit(GFX_TOP, &topScreen);
				consoleInit(GFX_BOTTOM, &bottomScreen);
        		if(savefile == 1) goto saveskip1;
        		if(savefile == 2) goto saveskip2;
        		if(savefile == 3) goto saveskip3;
        		if(savefile == 4) goto saveskip4;
        		if(savefile == 5) goto saveskip5;
			}
			
			else if(hidKeysDown() & KEY_B) {
				consoleInit(GFX_TOP, &topScreen);
				consoleInit(GFX_BOTTOM, &bottomScreen);
				
				FILE* file = fopen("save.txt", "w");
				fprintf(file, "0");
				fclose(file);
				
				consoleSelect(&topScreen);
				printf("\x1b[14;17HSave file deleted.");
				printf("\x1b[16;16HContinuing the game.");
				
				consoleSelect(&bottomScreen);
				printf("\x1b[15;12HPress \x1b[36mA\x1b[0m to continue.\n");
				
				while(aptMainLoop()) {
        			gspWaitForVBlank();
        			hidScanInput();
			
        			if(hidKeysDown() & KEY_START) {
        				gfxExit();
    					return 0;
					}
					
					else if(hidKeysDown() & KEY_A) {
        				break;
					}
		 
       			 	gfxFlushBuffers();
        			gfxSwapBuffers();
    			}
    			break;
			}
			
        	gfxFlushBuffers();
        	gfxSwapBuffers();
    	}
	}
	
	saveskip1:
		
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	
    consoleSelect(&topScreen);
    printf("\x1b[2;2HIt is a peaceful, \x1b[33msunny\x1b[0m day.");
    printf("\x1b[6;2H\x1b[35mPrincess Toadstool\x1b[0m decides to throw a \x1b[32mparty\x1b[0m.");
    printf("\x1b[8;2HAs a plumber of the \x1b[35mMushroom Kingdom\x1b[0m, you are");
    printf("\x1b[10;2Hextremely honoured to be invited to the massive");
    printf("\x1b[12;2Hevent. Moreover, the princess is going to bake a");
    printf("\x1b[14;2H\x1b[32mcake\x1b[0m and cook \x1b[32mspaghetti\x1b[0m for everyone who attends");
    printf("\x1b[16;2Hthe grand feast.");
    
    printf("\x1b[20;2HHowever, the princess is always looking for");
    printf("\x1b[22;2H\x1b[36msomething in return\x1b[0m.");
    
    consoleSelect(&bottomScreen);
    printf("\x1b[2;2HYour first decision would be choosing");
    printf("\x1b[4;2Hhow to \x1b[36mthank\x1b[0m her royal highness. You");
    printf("\x1b[6;2Hhave proposed the following methods:");
    
    printf("\x1b[10;2H> Use your coins to buy a \x1b[33mpresent\x1b[0m");
    printf("\x1b[12;2H  from Toad Shop for the princess.");
    printf("\x1b[15;2H  Pick \x1b[35mflowers\x1b[0m from your own garden");
    printf("\x1b[17;2H  and give them to the princess.");
    printf("\x1b[20;2H  \x1b[32mPlumb\x1b[0m the princess' toilet for free");
    printf("\x1b[22;2H  and offer a discount next time.");
    printf("\x1b[25;2H  Bring nothing and do nothing, pray");
    printf("\x1b[27;2H  so that you don't get caught.");
    
    savefile = 1;
    
    consoleSelect(&bottomScreen);
	while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	file = fopen("save.txt", "w");
        	fprintf(file, "%d", savefile);
        	fclose(file);
        	gfxExit();
    		return 0;
		}
		
        else if(hidKeysDown() & KEY_DOWN) {
			if (choice < 4) 
				++choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
		
		else if(hidKeysDown() & KEY_UP) {
			if (choice > 1) 
				--choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
        
        else if(hidKeysDown() & KEY_A) {
			break;
		}
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
	
    if(choice == 1) goto saveskip2;
    if(choice == 2) goto saveskip3;
    if(choice == 3) goto saveskip4;
    if(choice == 4) goto saveskip5;
    
    saveskip2:
    	
	choice = 1;
	
	consoleSelect(&topScreen);
    printf("test2");
    
    savefile = 2;
    
    consoleSelect(&bottomScreen);
	while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	file = fopen("save.txt", "w");
        	fprintf(file, "%d", savefile);
        	fclose(file);
        	gfxExit();
    		return 0;
		}
		
        else if(hidKeysDown() & KEY_DOWN) {
			if (choice < 4) 
				++choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
		
		else if(hidKeysDown() & KEY_UP) {
			if (choice > 1) 
				--choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
        
        else if(hidKeysDown() & KEY_A) {
			break;
		}
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
    
    saveskip3:
	
	choice = 1;
	
	consoleSelect(&topScreen);
    printf("test3");
    
    savefile = 3;
    
    consoleSelect(&bottomScreen);
	while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	file = fopen("save.txt", "w");
        	fprintf(file, "%d", savefile);
        	fclose(file);
        	gfxExit();
    		return 0;
		}
		
        else if(hidKeysDown() & KEY_DOWN) {
			if (choice < 4) 
				++choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
		
		else if(hidKeysDown() & KEY_UP) {
			if (choice > 1) 
				--choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
        
        else if(hidKeysDown() & KEY_A) {
			break;
		}
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
    
    saveskip4:
	
	choice = 1;
	
	consoleSelect(&topScreen);
    printf("test4");
    
    savefile = 4;
    
    consoleSelect(&bottomScreen);
	while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	file = fopen("save.txt", "w");
        	fprintf(file, "%d", savefile);
        	fclose(file);
        	gfxExit();
    		return 0;
		}
		
        else if(hidKeysDown() & KEY_DOWN) {
			if (choice < 4) 
				++choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
		
		else if(hidKeysDown() & KEY_UP) {
			if (choice > 1) 
				--choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
        
        else if(hidKeysDown() & KEY_A) {
			break;
		}
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	saveskip5:
	
	choice = 1;
	
	consoleSelect(&topScreen);
    printf("test5");
    
    savefile = 5;
    
	consoleSelect(&bottomScreen);
	while(aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        
        if(hidKeysDown() & KEY_START) {
        	file = fopen("save.txt", "w");
        	fprintf(file, "%d", savefile);
        	fclose(file);
        	gfxExit();
    		return 0;
		}
		
        else if(hidKeysDown() & KEY_DOWN) {
			if (choice < 4) 
				++choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
		
		else if(hidKeysDown() & KEY_UP) {
			if (choice > 1) 
				--choice;
			printf("\x1b[10;2H ");
			printf("\x1b[15;2H ");
			printf("\x1b[20;2H ");
			printf("\x1b[25;2H ");
			printf("\x1b[%d;2H>", 5*choice+5);
		}
        
        else if(hidKeysDown() & KEY_A) {
			break;
		}
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);
}
