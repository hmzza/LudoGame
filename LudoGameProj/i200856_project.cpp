//============================================================================
// Name        : .cpp
// NAME    : HAMZA  IQBAL 
//ROLL NUMBER : 20I-0856 
//Version 
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

bool mainmenu=1, ludo=0, instructions=0,quit=0,newgame=0;	//bool variables for different screen output
string p, name1=" ", name2=" ", name3=" ", name4=" ";		//declaration of variables for name input
bool flagname1=0, flagname2=0, flagname3=0, flagname4=0;	//flags for name of players
int players=0;	//variable for players counting
int dice;		//declaring variable for Random NUMBER
//DELARATION AND INITIALIZATION OF ARRAYS
int arr_b[58][2]={ 	 {350,77 },{350,126},{350,175},{350,224},{350,273},{273,350},{224,350}
					,{175,350},{126,350},{77,350 },{28,350 },{28,399 },{28,448 },{77,448 }
					,{126,448},{175,448},{224,448},{273,448},{350,526},{350,575},{350,624},{350,673},{350,722},{350,771}
					,{399,771},{448,771},{448,722},{448,673},{448,624},{448,575},{448,526},{526,448},{575,448},{624,448},{673,448}
					,{722,448},{771,448},{771,399},{771,350},{722,350},{673,350},{624,350},{575,350},{526,350},{448,273},{448,224},{448,175}
					,{448,126},{448,77 },{448,28 },{399,28 },{399,77 },{399,126},{399,175},{399,224},{399,273},{399,322}};

int arr_r[58][2]={ { 77,448},{126,448},{175,448},{224,448},{273,448},{350,526},{350,575},{350,624},{350,673},{350,722},{350,771}
					,{399,771},{448,771},{448,722},{448,673},{448,624},{448,575},{448,526},{526,448},{575,448},{624,448},{673,448}
					,{722,448},{771,448},{771,399},{771,350},{722,350},{673,350},{624,350},{575,350},{526,350},{448,273},{448,224},{448,175}
					,{448,126},{448,77 },{448,28 },{399,28 },{350,28 },{350,77 },{350,126},{350,175},{350,224},{350,273},{273,350},{224,350}
					,{175,350},{126,350},{77,350 },{28,350 },{28,399 },{77,399 },{126,399},{175,399},{224,399},{273,399},{322,399}};

int arr_g[58][2]={ {448,722},{448,673},{448,624},{448,575},{448,526},{526,448},{575,448},{624,448},{673,448}
					,{722,448},{771,448},{771,399},{771,350},{722,350},{673,350},{624,350},{575,350},{526,350},{448,273},{448,224},{448,175}
					,{448,126},{448,77 },{448,28 },{399,28 },{350,28 },{350,77 },{350,126},{350,175},{350,224},{350,273},{273,350},{224,350}
					,{175,350},{126,350},{77,350 },{28,350 },{28,399 },{28,448 },{77,448 },{126,448},{175,448},{224,448},{273,448},{350,526}
					,{350,575},{350,624},{350,673},{350,722},{350,771},{399,771},{399,722},{399,673},{399,624},{399,575},{399,526},{399,477}};

int arr_y[58][2]={   {722,350},{673,350},{624,350},{575,350},{526,350},{448,273},{448,224},{448,175}
					,{448,126},{448,77 },{448,28 },{399,28 },{350,28 },{350,77}, {350,126},{350,175},{350,224},{350,273},{273,350},{224,350}
					,{175,350},{126,350},{77,350 },{28,350 },{28,399 },{28,448}, {77,448 },{126,448},{175,448},{224,448},{273,448},{350,526}
					,{350,575},{350,624},{350,673},{350,722},{350,771}
					,{399,771},{448,771},{448,722},{448,673},{448,624},{448,575},{448,526},{526,448},{575,448},{624,448},{673,448}
					,{722,448},{771,448},{771,399},{722,399},{673,399},{624,399},{575,399},{526,399},{477,399}};

//DECLARATION AND INITIALIZATION OF x & y COORDINATES OF EVERY GOT
int b1x=125,b1y=175,b2x=175,b2y=175,b3x=125,b3y=125,b4x=175,b4y=125,r1x=125,r1y=675,r2x=125,r2y=625,r3x=175,r3y=675,r4x=175,r4y=625;
int g1x=625,g1y=675,g2x=675,g2y=675,g3x=625,g3y=625,g4x=675,g4y=625,y1x=625,y1y=175,y2x=675,y2y=175,y3x=625,y3y=125,y4x=675,y4y=125;

//flags for different players(colors boxes)
bool flag_blue=0,flag_red=0,flag_green=0,flag_yellow=0;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void dicefunc()	//FUNCTION FOR SHOWING DICE
{
	//heading for dice
	DrawString( 825, 575, "DICE:", colors[WHITE]);			
	//BORDERS FOR DICE 
	DrawLine( 825 , 565 ,  825 ,485 , 2 , colors[WHITE] );
	DrawLine( 825 , 485 ,  900 ,485 , 2 , colors[WHITE] );
	DrawLine( 900 , 485 ,  900 ,565 , 2 , colors[WHITE] );
	DrawLine( 900 , 565 ,  825 ,565 , 2 , colors[WHITE] );
	
	if(dice==1)			//if number on dice is 1, one dot will be displayed
	{
	DrawCircle(850,550,10,colors[WHITE]);
	}
	else if(dice==2)	//if number on dice is 2, two dots will be displayed
	{
		DrawCircle(850,550,10,colors[WHITE]);
		DrawCircle(875,550,10,colors[WHITE]);
	}
	else if(dice==3)	//if number on dice is 3, three dots will be displayed
	{
		DrawCircle(850,550,10,colors[WHITE]);
		DrawCircle(875,550,10,colors[WHITE]);
		DrawCircle(850,525,10,colors[WHITE]);		
	}
	else if(dice==4)	//if number on dice is 4,four dots will be displayed
	{
		DrawCircle(850,550,10,colors[WHITE]);
		DrawCircle(875,550,10,colors[WHITE]);
		DrawCircle(850,525,10,colors[WHITE]);
		DrawCircle(875,525,10,colors[WHITE]);
	}
	else if(dice==5)	//if number on dice is 5, five dots will be displayed
	{
		DrawCircle(850,550,10,colors[WHITE]);
		DrawCircle(875,550,10,colors[WHITE]);
		DrawCircle(850,525,10,colors[WHITE]);
		DrawCircle(875,525,10,colors[WHITE]);
		DrawCircle(850,500,10,colors[WHITE]);
	}
	else if(dice==6)	//if number on dice is 6, six dots will be displayed
	{
		DrawCircle(850,550,10,colors[WHITE]);
		DrawCircle(875,550,10,colors[WHITE]);
		DrawCircle(850,525,10,colors[WHITE]);
		DrawCircle(875,525,10,colors[WHITE]);
		DrawCircle(850,500,10,colors[WHITE]);
		DrawCircle(875,500,10,colors[WHITE]);
	}
}
int var1=0,var2=0,var3=0,var4=0;		//delaring variables for setting index of array and storing values in it

void blue()
{
	for(;dice>0;dice--)
	{
		var1++;							//increament in variable for next index
		b1x=arr_b[var1][0];				//storing values of arrays index in x coordinate	
		b1y=arr_b[var1][1];				//storing values of arrays index in y coordinate
	}
}

void red()
{
	for(;dice>0;dice--)
	{
		var2++;							//increament in variable for next index
		r1x=arr_r[var2][0];				//storing values of arrays index in x coordinate
		r1y=arr_r[var2][1];				//storing values of arrays index in y coordinate
	}
}
void green()
{
	for(;dice>0;dice--)
	{
		var3++;							//increament in variable for next index
		g1x=arr_g[var3][0];				//storing values of arrays index in x coordinate
		g1y=arr_g[var3][1];				//storing values of arrays index in y coordinate
	}
}
void yellow()
{
	for(;dice>0;dice--)
	{
		var4++;							//increament in variable for next index
		y1x=arr_y[var4][0];				//storing values of arrays index in x coordinate
		y1y=arr_y[var4][1];				//storing values of arrays index in y coordinate
	}
}

int turn=0;
bool flag_b=1,flag_r=1,flag_g=1,flag_y=1;
void assign()	//FUNCTION FOR ASSIGNING TURNS 
{
	DrawString( 800, 750, "press spacebar to start game", colors[WHITE]);
	if(turn==0 && flag_b==1)
	{
		blue();		//blue function will be called and turn will be of BLUE if turn is equal to 0 and flag of blue is 1
	}

	if(turn==1 && flag_r==1)
	{
		red();		//red function will be called and turn will be of RED if turn is equal to 0 and flag of red is 1
	}
	if(turn==2 && flag_g==1)
	{
		green();		//green function will be called and turn will be of GREEN if turn is equal to 0 and flag of green is 1
	}
	if(turn==3 && flag_y==1)
	{
		yellow();		//yellow function will be called and turn will be of YELLOW if turn is equal to 0 and flag of yellow is 1
	}

	//WIN MENU WILL BE DISPLAYED IF FIRST GOT ENTER IN HOME
	if(b1x==0 && b1y==0)
	{
		flag_b=0;
		flag_blue=1;//BLUE FLAG WILL SET TO TRUE IF CONFITION IS TRUE
		flag_red=0;
		flag_green=0;
		flag_yellow=0;
	}
	
	if(r1y==0 && r1x==0)
	{
		flag_r=0;
		flag_blue=0;
		flag_red=1;	//RED FLAG WILL SET TO TRUE IF CONFITION IS TRUE
		flag_green=0;
		flag_yellow=0;
	}
	if(g1x==0 && g1y==0)
	{
		flag_g=0;
		flag_blue=0;
		flag_red=0;
		flag_green=1;//GREEN FLAG WILL SET TO TRUE IF CONFITION IS TRUE
		flag_yellow=0;
	}
	if(y1x==0 && y1y==0) 
	{
		flag_y=0;
		flag_blue=0;
		flag_red=0;
		flag_green=0;
		flag_yellow=1;//YELLOW FLAG WILL SET TO TRUE IF CONFITION IS TRUE
	}
	//WIN MENU WILL BE DISPLAYED IF FIRST GOT ENTER IN HOME
	if(flag_blue==1)
	{
		DrawSquare( 0 , 0 ,1000,colors[BLACK]); 
		DrawString( 300, 400, "WINNER: BLUE", colors[BLUE]);
	}	
	if(flag_red==1)
	{
		DrawSquare( 0 , 0 ,1000,colors[BLACK]); 
		DrawString( 300, 400, "WINNER: RED", colors[RED]);
	}
	if(flag_green==1)
	{
		DrawSquare( 0 , 0 ,1000,colors[BLACK]);
		DrawString( 300, 400, "WINNER: GREEN", colors[GREEN]);
	}
	if(flag_yellow==1)
	{
		DrawSquare( 0 , 0 ,1000,colors[BLACK]); 
		DrawString( 300, 400, "WINNER: YELLOW", colors[YELLOW]);
	}
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	if(mainmenu==1)	//IF 6 IS PRESSED MAIN MENU WILL BE DISPLAYED
	{
	//glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glClear (GL_COLOR_BUFFER_BIT); //Update the colors	


	//MAIN MENU
	DrawSquare( 0 , 0 ,800,colors[RED]); 
	DrawRoundRect( 50 , 50 ,700,700,colors[GRAY]); 
	DrawString( 250, 700, "(WELCOME - TO - LUDO)", colors[BLACK]);
	DrawString( 200, 500, "New Game--------(press 9): ", colors[BLUE]);
	DrawString( 200, 450, "Instructions----(press 8): ", colors[GREEN]);
	DrawString( 200, 400, "QUIT------------(press ESC): ", colors[GOLD]);
	glutSwapBuffers(); // do not modify this line..
	}

	else if(newgame==1)		//IF 9 IS PRESSED NEWGAME MENU WILL BE DISPLAYED
	{
	DrawSquare( 0 , 0 ,800,colors[BLUE]); 
	DrawRoundRect( 50 , 50 ,700,700,colors[GRAY]); 
	DrawString( 200, 600, "Enter number of players: ", colors[BLACK]);

		if(players==2)//if players are 2 it will ask for 2 inputs 
		{
		DrawString( 550, 600, "2", colors[BLACK]);
		DrawString( 200, 500, "Enter name of player#1: ", colors[RED]);
		DrawString( 200, 450, "Enter name of player#2: ", colors[RED]);
		DrawString( 460, 500, name1, colors[BLACK]);
		DrawString( 460, 450, name2, colors[BLACK]);	
		}
		if(players==3)//if players are 3 it will ask for 3 inputs 
		{
		DrawString( 550, 600, "3", colors[BLACK]);
		DrawString( 200, 500, "Enter name of player#1: ", colors[RED]);
		DrawString( 200, 450, "Enter name of player#2: ", colors[RED]);
		DrawString( 200, 400, "Enter name of player#3: ", colors[RED]);
		DrawString( 460, 500, name1, colors[BLACK]);
		DrawString( 460, 450, name2, colors[BLACK]);
		DrawString( 460, 400, name3, colors[BLACK]);	
		}
		if(players==4)//if players are 4 it will ask for four inputs
		{
		DrawString( 550, 600, "4", colors[BLACK]);
		DrawString( 200, 500, "Enter name of player#1: ", colors[RED]);
		DrawString( 200, 450, "Enter name of player#2: ", colors[RED]);
		DrawString( 200, 400, "Enter name of player#3: ", colors[RED]);
		DrawString( 200, 350, "Enter name of player#4: ", colors[RED]);
		DrawString( 460, 500, name1, colors[BLACK]);
		DrawString( 460, 450, name2, colors[BLACK]);
		DrawString( 460, 400, name3, colors[BLACK]);
		DrawString( 460, 350, name4, colors[BLACK]);				
		}
	DrawString( 300, 100, "PRESS 0-to enter in game", colors[BLACK]);
	glutSwapBuffers(); // do not modify this line..
	}


	else if(instructions==1)	//IF 8 IS PRRSSED INSTRUCTION MENU WILLL BE DISPLAYED
	{
	DrawSquare( 0 , 0 ,800,colors[GREEN]); 
	DrawRoundRect( 50 , 50 ,700,700,colors[GRAY]); 
	DrawString( 300, 700, "INSTRUCTIONS", colors[BLACK]);
	DrawString( 200, 650, "> press spacebar to roll dice", colors[BLACK]);
	DrawString( 200, 600, "> this is four player game ", colors[BLACK]);
	DrawString( 200, 550, "> press 6 for mainmenu", colors[BLACK]);
	DrawString( 200, 500, "> press 7 to exit", colors[BLACK]);
	DrawString( 200, 450, "> press 9 for players input", colors[BLACK]);

	glutSwapBuffers(); // do not modify this line..
	}


	else if(ludo==1)	//IF 0 IS PRESSED GAME WILL BE STARTED
	{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	
	DrawSquare( 0 , 0 ,800,colors[BLACK]); 
	//Mushroom
	DrawSquare( 0 , 0 ,300,colors[BLUE]); 
	DrawSquare( 500 , 0 ,300,colors[YELLOW]);
	DrawSquare( 0 , 500 ,300,colors[RED]); 
	DrawSquare( 500 , 500 ,300,colors[GREEN]);  
	DrawSquare( 300 , 300 ,200,colors[GRAY]);  
	//Display Score
		//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	
	DrawTriangle( 400, 400 , 300, 300 , 300 , 500, colors[RED] );
	DrawTriangle( 400, 400 , 300, 300 , 500 , 300, colors[BLUE] );
	DrawTriangle( 400, 400 , 500, 300 , 500 , 500, colors[YELLOW] );
	DrawTriangle( 400, 400 , 500, 500 , 300 , 500, colors[GREEN] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	
	
	//FOR RED BLOCK MINI BOXES
	for(int i=4; i<=250; i=i+49)	//bottom row
	{
	DrawSquare( i , 326 , 48,colors[WHITE]);	
	}
	DrawSquare( 102 , 326 , 48,colors[GRAY]);	//third box: red color	

	for(int i=4; i<=250; i=i+49)	//middle row
	{
	DrawSquare( i , 375 , 48,colors[RED]);	
	}
	DrawSquare( 4 , 375 , 48,colors[WHITE]);	//first box: white color	


	for(int i=4; i<=250; i=i+49)	//top row
	{
	DrawSquare( i , 424 , 48,colors[WHITE]);	
	}
	DrawSquare( 53 , 424 , 48,colors[RED]);	//seconf box: red color	


	//FOR YELLOW BLOCK MINI BOXES
	for(int i=502; i<=750; i=i+49)	//bottom row
	{
	DrawSquare( i , 326 , 48,colors[WHITE]);	
	}
	DrawSquare( 698 , 326 , 48,colors[YELLOW]);	//fourth box: yellow color	

	for(int i=502; i<=750; i=i+49)	//middle row
	{
	DrawSquare( i , 375 , 48,colors[YELLOW]);	
	}
	DrawSquare( 747 , 375 , 48,colors[WHITE]);	//sixth box: white color	


	for(int i=502; i<=750; i=i+49)	//top row
	{
	DrawSquare( i , 424 , 48,colors[WHITE]);	
	}
	DrawSquare( 649 , 424 , 48,colors[GRAY]);	//fifth box: yellow color	



	//FOR BLUE BLOCK MINI BOXES
	for(int i=4; i<=250; i=i+49)	//left column
	{
	DrawSquare( 326 , i , 48,colors[WHITE]);	
	}
	DrawSquare( 326 , 53, 48,colors[BLUE]);	//seccond box: blue color	

	for(int i=4; i<=250; i=i+49)	//middle column
	{
	DrawSquare( 375 , i , 48,colors[BLUE]);	
	}
	DrawSquare( 375 , 4 , 48,colors[WHITE]);	//first box: white color	


	for(int i=4; i<=250; i=i+49)	//right most column
	{
	DrawSquare( 424 , i , 48,colors[WHITE]);	
	}
	DrawSquare( 424 , 102 , 48,colors[GRAY]);	//third box: blue color	
	
	
	//FOR GREEN BLOCK MINI BOXES
	for(int i=502; i<=750; i=i+49)	//left column
	{
	DrawSquare( 326 , i , 48,colors[WHITE]);	
	}
	DrawSquare( 326 , 649 , 48,colors[GRAY]);	//fourth box: green color	

	for(int i=502; i<=750; i=i+49)	//middle column
	{
	DrawSquare( 375 , i , 48,colors[GREEN]);	
	}
	DrawSquare( 375 , 747 , 48,colors[WHITE]);	//sixth box: white color	


	for(int i=502; i<=750; i=i+49)	//right column
	{
	DrawSquare( 424 , i , 48,colors[WHITE]);	
	}
	DrawSquare( 424 , 698 , 48,colors[GREEN]);	//fifth box: green color	

	//INNER BOXES FOR EACH GOT
	//BLUE 
	DrawSquare( 80 , 80 , 140,colors[BLACK]);	
	DrawSquare( 90 , 90 , 120,colors[BLUE]);	
	DrawSquare( 100 , 100 , 100,colors[BLACK]);	
	//YELLOW 
	DrawSquare( 580 , 80 , 140,colors[BLACK]);	
	DrawSquare( 590 , 90 , 120,colors[YELLOW]);	
	DrawSquare( 600 , 100 , 100,colors[BLACK]);	
	//RED
	DrawSquare( 80 , 580 , 140,colors[BLACK]);	
	DrawSquare( 90 , 590 , 120,colors[RED]);	
	DrawSquare( 100 , 600 , 100,colors[BLACK]);
	//GREEN
	DrawSquare( 580 , 580 , 140,colors[BLACK]);	
	DrawSquare( 590 , 590 , 120,colors[GREEN]);	
	DrawSquare( 600 , 600 , 100,colors[BLACK]);

	//GOTSS
	//Blue
	DrawCircle(b1x,b1y,20,colors[INDIGO]);
	DrawCircle(b2x,b2y,20,colors[INDIGO]);
	DrawCircle(b3x,b3y,20,colors[INDIGO]);
	DrawCircle(b4x,b4y,20,colors[INDIGO]);
	
	//red
	DrawCircle(r1x,r1y,20,colors[MAROON]);
	DrawCircle(r2x,r2y,20,colors[MAROON]);
	DrawCircle(r3x,r3y,20,colors[MAROON]);
	DrawCircle(r4x,r4y,20,colors[MAROON]);

	//green
	DrawCircle(g1x,g1y,20,colors[LIGHT_GREEN]);
	DrawCircle(g2x,g2y,20,colors[LIGHT_GREEN]);
	DrawCircle(g3x,g3y,20,colors[LIGHT_GREEN]);
	DrawCircle(g4x,g4y,20,colors[LIGHT_GREEN]);

	//yellow
	DrawCircle(y1x,y1y,20,colors[ORANGE]);
	DrawCircle(y2x,y2y,20,colors[ORANGE]);
	DrawCircle(y3x,y3y,20,colors[ORANGE]);
	DrawCircle(y4x,y4y,20,colors[ORANGE]);	

	
	dicefunc();	//function for DICE
	assign();	//FUNCTION FOR TURN
	glutSwapBuffers(); // do not modify this line..
	}
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	unsigned char key2;

	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}

	if (key=='2')
	{
		players=2;
		p=="2";	
	}

	if(key>='a' && key<='z')//if these keys are pressed
	{
		if(flagname1==0)
		{name1+=key;}//store values for first input
		else if(flagname2==0)
		{name2+=key;}//store values for second input
		else if(flagname3==0)
		{name3+=key;}//store values for third input	
		else if(flagname4==0)
		{name4+=key;}//store values for four input
	}


	if (key=='3')//if 3 is pressed it will take three players only
	{players=3;
		p=="3";}

	if (key=='4')//if 4 is pressed it will take four players only
	{players=4;
		p=="4";}

	if (key==' ')
	{
		srand(time(NULL));
		dice=rand()%6 +1;//RANDOM NUMBER GENERATOR
		turn++;//every time when space bar is pressed it will generate a number and increament in turn variables
		if(turn==4)
		{
			turn=0;
		}
	}
	if (key == '6')//if 6 is pressed flag for main menu will set to true rest will set to false
	{
		mainmenu=1;
		ludo=0;
		instructions=0;
		newgame=0;
		quit=0;

	}	
	if (key=='0')//if 0 is pressed flag for ludo will set to true rest will set to false
	{
		mainmenu=0;
		ludo=1;
		instructions=0;
		newgame=0;
		quit=0;
	}
	if (key=='9')//if 9 is pressed flag for newgame will set to true rest will set to false
	{
		mainmenu=0;
		ludo=0;
		instructions=0;
		newgame=1;
		quit=0;
	}
	if (key=='8')//if 8 is pressed flag for instruction will set to true rest will set to false
	{
		mainmenu=0;
		ludo=0;
		instructions=1;
		newgame=0;
		quit=0;
	}
	if (key=='7')//if 7 is pressed flag for quit will set to true rest will set to false
	{
		mainmenu=0;
		ludo=0;
		instructions=0;
		newgame=0;
		quit=1;
	}
	if(key== 13)
	{
		//when enter key is pressed, you will enter for next player
		if(flagname1==0)//
		{flagname1=1;}	
		else if(flagname2==0)
		{flagname2=1;}
		else if(flagname3==0)
		{flagname3=1;}
		else if(flagname4==0)
		{flagname4=1;}	
	}	


	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
