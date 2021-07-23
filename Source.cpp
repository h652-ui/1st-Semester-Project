#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<MMSystem.h>
#include "mygraphics.h"
#include "myconsole.h"
//--Color initialization--
COLORREF purple = RGB(128, 0, 128);
COLORREF black = RGB(0, 0, 0);
COLORREF white = RGB(255, 255, 255);
COLORREF turquoise = RGB(64, 224, 208);
COLORREF red = RGB(255, 0, 0);
COLORREF green = RGB(0, 255, 0);
COLORREF blue = RGB(0, 0, 255);
COLORREF light = RGB(255, 204, 153);
COLORREF yellow = RGB(255, 255, 0);
COLORREF skyblue = RGB(51, 51, 255);
//--Fuctions Declaration--
void border(void);//Border lines
void score_board(int);//Scoreboard graphics
int options(int& option,int& tos);//Option selection 
void r_options(int& option, int& o_option, int& wicket, int& score,int& tos);//Random option selection
int innings_1(int& overss,int& tos,int& innings);//First innings
int innings_2(int& overss, int& tos, int& innings,int);//2nd innings
int overs(void);//Overs selection
int toss(void);//Toss
int main_menu(int& m_option);//main menu
int exit_1(int);//Exit option
int main()
{
	int m_option = 0;//Menu option
	int e_option = 1;//Exit option
	m_option = main_menu(m_option);//Determine whether main menu option(Line 188)
	if (m_option == 1)//If new game is selected 
	{
		while (e_option != 2)//If exit option is "No" then it runs infinitely
		{
			Sleep(300);//Pause the program
			system("cls");//Clear screen
			Sleep(300);
			//Local variables
			//tos contains option that is bat or bowl
			//score_1 stores score of first innings while score_2 of second innings
			//Inning in still equal 1 at the start
			//Overss store over's option
			int overss, score_1 = 0, tos, score_2, inning = 1;
			//Toss funstion call
			tos = toss();
			Sleep(1000);
			system("cls");
			Sleep(300);
			//Over selection
			overss = overs();
			Sleep(1000);
			system("cls");
			Sleep(300);
			//innings_1 option is called 
			score_1 = innings_1(overss, tos, inning);//line 290
			inning++;//innings become 2
			system("cls");
			Sleep(300);
			border();
			//sound generation
			PlaySound(TEXT("Gets ready.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//message dislpay
			myDrawTextWithFont(10, 20, 50, "Innings Ends...", white, black);
			myDrawTextWithFont(340, 300, 50, "---Get's Ready---", turquoise, black);
			myDrawTextWithFont(720, 600, 50, "Next Innings", white, black);
			Sleep(4000);
			system("cls");
			Sleep(300);
			if (tos == 1)//tos == 1 contains batting option
				tos++;//As tos contains bat or bowl option so if first bat is done then bowl will be
			else
				tos--;//First bowl then batting
			score_2 = innings_2(overss, tos, inning, score_1+1);//Second innings score,in this function target is also given. Line 310
			//----Match results----
			if (tos == 2)//if user batting first
			{
				if (score_1<score_2)//score 2 is greater then user lose 
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();
					PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);//disapponitment sound generates
					//message display inside border 
					myDrawTextWithFont(400, 210, 60, "Ooops!", red, black);
					myDrawTextWithFont(350, 300, 50, "----You Lose----", red, black);
					myLine(340, 190, 600, 190, light);
					myLine(340, 190, 340, 370, light);
					myLine(600, 190, 600, 370, light);
					myLine(340, 370, 600, 370, light);
				}
				else if (score_1>score_2)//If score 2 is small
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();//line 
					PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
					myDrawTextWithFont(300, 210, 60, "Congragulation", green, black);
					myDrawTextWithFont(340, 300, 50, "----You Win----", green, black);
					myLine(290, 190, 620, 190, light);
					myLine(290, 190, 290, 370, light);
					myLine(620, 190, 620, 370, light);
					myLine(290, 370, 620, 370, light);
				}
				else if (score_1==score_2)//If equal
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();
					PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
					myDrawTextWithFont(400, 210, 60, "Ooo Nooo!", red, black);
					myDrawTextWithFont(350, 300, 50, "----Draw----", blue, black);
					myLine(340, 190, 600, 190, light);
					myLine(340, 190, 340, 370, light);
					myLine(600, 190, 600, 370, light);
					myLine(340, 370, 600, 370, light);
				}
			}
			else//if first bowling
			{
				if (score_1<score_2)//If score_1 is smaller then user wins  
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();
					PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
					myDrawTextWithFont(300, 210, 60, "Congragulation", green, black);
					myDrawTextWithFont(340, 300, 50, "----You Win----", green, black);
					myLine(290, 190, 620, 190, light);
					myLine(290, 190, 290, 370, light);
					myLine(620, 190, 620, 370, light);
					myLine(290, 370, 620, 370, light);

				}
				else if (score_1>score_2)
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();
					PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
					myDrawTextWithFont(400, 210, 60, "Ooops!", red, black);
					myDrawTextWithFont(350, 300, 50, "----You Lose----", red, black);
					myLine(340, 190, 600, 190, light);
					myLine(340, 190, 340, 370, light);
					myLine(600, 190, 600, 370, light);
					myLine(340, 370, 600, 370, light);
				}
				else
				{
					Sleep(300);
					system("cls");
					Sleep(300);
					border();
					PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
					myDrawTextWithFont(400, 210, 60, "Ooo Nooo!", red, black);
					myDrawTextWithFont(350, 300, 50, "----Draw----", blue, black);
					myLine(340, 190, 600, 190, light);
					myLine(340, 190, 340, 370, light);
					myLine(600, 190, 600, 370, light);
					myLine(340, 370, 600, 370, light);
				}
			}
			Sleep(2000);
			system("cls");
			Sleep(300);
			e_option = exit_1(e_option);//Line(238)
			system("cls");
			Sleep(300);
		}
	}
	system("cls");
	Sleep(300);
	border();
	//Message for thanking
	myDrawTextWithFont(340, 300, 50, "Thanks For Playing", turquoise, black);
	return 0;
}
int main_menu(int& m_option)
{
	border();
	myDrawTextWithFont(290, 50, 80, "---Heads Tail---", skyblue, black);
	myDrawTextWithFont(390, 200, 60, "New Game", white, black);
	myDrawTextWithFont(460, 300, 60, "Exit", white, black);
	myDrawTextWithFont(365, 400, 60, "------------------", red, black);
	PlaySound(TEXT("Hamid.wav"), NULL, SND_FILENAME | SND_ASYNC);//starting sound
	myDrawTextWithFont(820, 600, 30, "BY", red, black);
	myDrawTextWithFont(730, 640, 40, "HAMID MUZAFFAR", red, black);
	char chh;//initialization of a character
	myLine(380, 190, 600, 190, red);
	myLine(380, 190, 380, 270, red);
	myLine(380, 270, 600, 270, red);
	myLine(600, 190, 600, 270, red);
	m_option++;//menu option becomes 1 that is "New game"
	chh = _getch();//Character input
	while (chh != 13)
	{
		if (m_option == 1 && chh == 80)//If down key is pressed
		{
			myLine(380, 190, 600, 190, black);
			myLine(380, 190, 380, 270, black);
			myLine(380, 270, 600, 270, black);
			myLine(600, 190, 600, 270, black);
			myLine(450, 290, 540, 290, red);
			myLine(450, 290, 450, 370, red);
			myLine(450, 370, 540, 370, red);
			myLine(540, 290, 540, 370, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			m_option++;
		}
		if (m_option == 2 && chh == 72)//If up key is pressed
		{
			myLine(380, 190, 600, 190, red);
			myLine(380, 190, 380, 270, red);
			myLine(380, 270, 600, 270, red);
			myLine(600, 190, 600, 270, red);
			myLine(450, 290, 540, 290, black);
			myLine(450, 290, 450, 370, black);
			myLine(450, 370, 540, 370, black);
			myLine(540, 290, 540, 370, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			m_option--;
		}
		chh = _getch();
	}
	PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	return m_option;
}
int exit_1(int e_option)
{
	char chh;
	border();
	myLine(270, 190, 770, 190, light);
	myLine(270, 190, 270, 370, light);
	myLine(770, 190, 770, 370, light);
	myLine(270, 370, 770, 370, light);
	myDrawTextWithFont(280, 210, 50, "Would You like to play again?", skyblue, black);
	myDrawTextWithFont(420, 300, 50, "Yes", green, black);
	myDrawTextWithFont(580, 300, 50, "No", red, black);
	myLine(410, 290, 490, 290, green);
	myLine(410, 290, 410, 360, green);
	myLine(490, 290, 490, 360, green);
	myLine(410, 360, 490, 360, green);
	chh = _getch();
	while (chh != 13)//Until carriage return is pressed
	{
		if (chh == 77 && e_option == 1)//If right key is pressed
		{
			myLine(410, 290, 490, 290, black);
			myLine(410, 290, 410, 360, black);
			myLine(490, 290, 490, 360, black);
			myLine(410, 360, 490, 360, black);
			myLine(570, 290, 630, 290, red);
			myLine(570, 290, 570, 360, red);
			myLine(630, 290, 630, 360, red);
			myLine(570, 360, 630, 360, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			++e_option;
		}
		else if (chh == 75 && e_option == 2)//If left key is pressed
		{
			myLine(570, 290, 630, 290, black);
			myLine(570, 290, 570, 360, black);
			myLine(630, 290, 630, 360, black);
			myLine(570, 360, 630, 360, black);
			myLine(410, 290, 490, 290, green);
			myLine(410, 290, 410, 360, green);
			myLine(490, 290, 490, 360, green);
			myLine(410, 360, 490, 360, green);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			--e_option;
		}
		chh = _getch();
		PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	return e_option;
}
int innings_1(int& overss,int& tos,int& inning)
{
	//Locla variables that is wicket ,over,score and balls 
	int wicket = 0, over = 0, score = 0, balls = 0;
	for (size_t i = 1; i <= overss * 6 && wicket != 10; i++)//until balls finishes or wicket is smaller than 10
	{
		int option = -1;
		//Printing scoreboard
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t%d\t\t\t\t\t\t\t\t\t\t\t%d\n\n\t\t%d\t\t\t\t\t\t\t\t\t\t\t%d\n\n\t\t", score, over, wicket, balls);
		border();
		score_board(inning);//Call score board
		option = options(option,tos);//Call option functon 
		int o_option;//random option
		srand(time(0));
		o_option = rand() % 7;
		r_options(option, o_option, wicket, score,tos);//random option function which displays option and random option simultaneously
		balls++;
		if (balls % 6 == 0)
		{
			over++;
		}
		Sleep(4000);
		system("cls");
		Sleep(50);
	}
	return score;
}
int innings_2(int& overss, int& tos, int& inning,int score_1)//Similar to innings 1 However in this target is compared with score
{
	int wicket = 0, over = 0, score = 0, balls = 0; 
	for (size_t i = 1; i <= overss * 6 && wicket != 10 && score_1>score; i++)//continue unless target, overs or wicket is comlpeted
	{
		int option = -1;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t%d\t\t\t\t\t\t\t\t\t\t\t%d\n\n\t\t%d\t\t\t\t\tTarget is %d\t\t\t\t\t%d\n\n\t\t\t", score, over, wicket, score_1, balls);
		border();
		score_board(inning);
		option = options(option, tos);
		int o_option;
		srand(time(0));
		o_option = rand() % 7;
		r_options(option, o_option, wicket, score, tos);
		balls++;
		if (balls % 6 == 0)
		{
			over++;
		}
		Sleep(4000);
		system("cls");
		Sleep(50);
	}
	return score;
}
int toss(void)//toss selection
{
	int t_option = 0, rt_option, s_option = 0;//t_option is your selection
	srand(time(0));
	rt_option = 1 + rand() % 2;//rt_option is computer's selection
	border();
	myDrawTextWithFont(390, 20, 60, "---Toss---", red, black);
	myDrawTextWithFont(20, 100, 50, "Choose:", white, black);
	myDrawTextWithFont(290, 150, 50, "Heads", white, black);
	myDrawTextWithFont(570, 150, 50, "Tails", white, black);
	char chh;
	myLine(280, 145, 400, 145, blue);
	myLine(280, 145, 280, 205, blue);
	myLine(280, 205, 400, 205, blue);
	myLine(400, 145, 400, 205, blue);
	t_option++;
	chh = _getch();
	while (chh != 13)
	{
		if (t_option == 1 && chh == 77)//if right key is pressed
		{
			myLine(280, 145, 400, 145, black);
			myLine(280, 145, 280, 205, black);
			myLine(280, 205, 400, 205, black);
			myLine(400, 145, 400, 205, black);
			myLine(560, 145, 655, 145, yellow);
			myLine(560, 145, 560, 205, yellow);
			myLine(560, 205, 655, 205, yellow);
			myLine(655, 145, 655, 205, yellow);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			t_option++;
		}
		if (t_option == 2 && chh == 75)//if left key is pressed
		{
			myLine(280, 145, 400, 145, blue);
			myLine(280, 145, 280, 205, blue);
			myLine(280, 205, 400, 205, blue);
			myLine(400, 145, 400, 205, blue);
			myLine(560, 145, 655, 145, black);
			myLine(560, 145, 560, 205, black);
			myLine(560, 205, 655, 205, black);
			myLine(655, 145, 655, 205, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			t_option--;
		}
		chh = _getch();
		PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	PlaySound(TEXT("coindrop.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (size_t i = 0; i <= rt_option + 16; i++)//This loop is ony for styling
	{
		//rt_option+16 actually the loops will run by 17 or 18 times 
		if (i % 2 == 0)//if 18 then 
		{
			myLine(280, 145, 400, 145, black);
			myLine(280, 145, 280, 205, black);
			myLine(280, 205, 400, 205, black);
			myLine(400, 145, 400, 205, black);
			myLine(560, 145, 655, 145, yellow);
			myLine(560, 145, 560, 205, yellow);
			myLine(560, 205, 655, 205, yellow);
			myLine(655, 145, 655, 205, yellow);
			Sleep(100);
		}
		else//if 17 then 
		{
			myLine(280, 145, 400, 145, blue);
			myLine(280, 145, 280, 205, blue);
			myLine(280, 205, 400, 205, blue);
			myLine(400, 145, 400, 205, blue);
			myLine(560, 145, 655, 145, black);
			myLine(560, 145, 560, 205, black);
			myLine(560, 205, 655, 205, black);
			myLine(655, 145, 655, 205, black);
			Sleep(100);
		}
	}
	if (rt_option == t_option)//if your and opponent option matches
	{
		switch (rt_option)//display heads or tails 
		{
		case 1:myDrawTextWithFont(430, 220, 50, "Heads", white, black);
			myLine(420, 210, 540, 210, blue);
			myLine(420, 210, 420, 270, blue);
			myLine(420, 270, 540, 270, blue);
			myLine(540, 210, 540, 270, blue);
			break;
		case 2:myDrawTextWithFont(440, 220, 50, "Tails", white, black);
			myLine(430, 210, 525, 210, yellow);
			myLine(430, 210, 430, 270, yellow);
			myLine(430, 270, 525, 270, yellow);
			myLine(525, 210, 525, 270, yellow);
			break;
		}
		PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
		myDrawTextWithFont(380, 300, 50, "Won the toss", light, black);
		myDrawTextWithFont(20, 330, 50, "Choose:", light, black);
		myDrawTextWithFont(290, 380, 40, "Bat", light, black);
		myDrawTextWithFont(600, 380, 40, "Bowl", light, black);
		char chh;
		myLine(280, 370, 360, 370, red);
		myLine(280, 370, 280, 430, red);
		myLine(280, 430, 360, 430, red);
		myLine(360, 370, 360, 430, red);
		s_option++;
		chh = _getch();
		while (chh != 13)//choose bat or bowl logic is same
		{
			if (s_option == 1 && chh == 77)
			{
				myLine(280, 370, 360, 370, black);
				myLine(280, 370, 280, 430, black);
				myLine(280, 430, 360, 430, black);
				myLine(360, 370, 360, 430, black);
				myLine(590, 370, 680, 370, red);
				myLine(590, 370, 590, 430, red);
				myLine(590, 430, 680, 430, red);
				myLine(680, 370, 680, 430, red);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				s_option++;
			}
			if (s_option == 2 && chh == 75)
			{
				myLine(280, 370, 360, 370, red);
				myLine(280, 370, 280, 430, red);
				myLine(280, 430, 360, 430, red);
				myLine(360, 370, 360, 430, red);
				myLine(590, 370, 680, 370, black);
				myLine(590, 370, 590, 430, black);
				myLine(590, 430, 680, 430, black);
				myLine(680, 370, 680, 430, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				s_option--;
			}
			chh = _getch();
		}
		PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
		switch (s_option)
		{
		case 1:myDrawTextWithFont(320, 440, 40, "You has decided to bat", light, black);
			break;
		case 2:myDrawTextWithFont(320, 440, 40, "You has decided to bowl", light, black);
			break;
		}
	}
	else if (t_option != rt_option)//if both option does not match
	{
		switch (rt_option)
		{
		case 1:myDrawTextWithFont(430, 220, 50, "Heads", white, black);
			myLine(420, 210, 540, 210, blue);
			myLine(420, 210, 420, 270, blue);
			myLine(420, 270, 540, 270, blue);
			myLine(540, 210, 540, 270, blue);
			break;
		case 2:myDrawTextWithFont(440, 220, 50, "Tails", white, black);
			myLine(430, 210, 525, 210, yellow);
			myLine(430, 210, 430, 270, yellow);
			myLine(430, 270, 525, 270, yellow);
			myLine(525, 210, 525, 270, yellow);
			break;
		}
		PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
		myDrawTextWithFont(380, 300, 50, "Lost the toss", red, black);
		switch ( 1 + rand() % 2)//This will give the computer's option of batting or bowling
		{
		case 1:myDrawTextWithFont(290, 380, 40, "Opponent has decided to bat", light, black);
			s_option = 2;
			break;
		case 2:myDrawTextWithFont(290, 380, 40, "Opponent has decided to Bowl", light, black);
			s_option = 1;
			break;
		}
	}
	myDrawTextWithFont(385, 540, 40, "Get's started", turquoise, black);
	Sleep(700);
	return s_option;
}
void border(void)//border lines
{
	myLine(5, 5, 5, 680, white);
	myLine(5, 5, 965, 5, white);
	myLine(5, 680, 965, 680, white);
	myLine(965, 5, 965, 680, white);
}
void score_board(int innings)//display the scoreboard
{
	if (innings==1)
		myDrawTextWithFont(330, 20, 60, "1st innings", red, black);
	else
		myDrawTextWithFont(330, 20, 60, "2nd innings", red, black);
	myLine(5, 500, 965, 500, white);
	myDrawTextWithFont(410, 515, 40, "Scoreboard", light, black);
	myDrawTextWithFont(100, 530, 30, "Batting", light, black);
	myDrawTextWithFont(50, 575, 20, "Score :", light, black);
	myDrawTextWithFont(50, 605, 20, "Wickets : ", light, black);
	myDrawTextWithFont(800, 530, 30, "Bowling", light, black);
	myDrawTextWithFont(750, 575, 20, "Overs :", light, black);
	myDrawTextWithFont(750, 605, 20, "Balls :", light, black);
}
int options(int &option,int& tos)//your option selector
{
	char chh;
	if (tos == 1)//If you are batting
	{
		//-----You-----
		myDrawTextWithFont(40, 80, 60, "You", red, black);
		myDrawTextWithFont(70, 150, 40, "0", turquoise, black);
		myDrawTextWithFont(70, 200, 40, "1", turquoise, black);
		myDrawTextWithFont(70, 250, 40, "2", turquoise, black);
		myDrawTextWithFont(70, 300, 40, "3", turquoise, black);
		myDrawTextWithFont(70, 350, 40, "4", turquoise, black);
		myDrawTextWithFont(70, 400, 40, "5", turquoise, black);
		myDrawTextWithFont(70, 450, 40, "6", turquoise, black);
		//----opponent------
		myDrawTextWithFont(730, 80, 60, "Opponent", red, black);
		myDrawTextWithFont(820, 150, 40, "0", turquoise, black);
		myDrawTextWithFont(820, 200, 40, "1", turquoise, black);
		myDrawTextWithFont(820, 250, 40, "2", turquoise, black);
		myDrawTextWithFont(820, 300, 40, "3", turquoise, black);
		myDrawTextWithFont(820, 350, 40, "4", turquoise, black);
		myDrawTextWithFont(820, 400, 40, "5", turquoise, black);
		myDrawTextWithFont(820, 450, 40, "6", turquoise, black);
		//---moves-----
		myLine(60, 147, 95, 147, white);
		myLine(60, 147, 60, 190, white);
		myLine(60, 190, 95, 190, white);
		myLine(95, 147, 95, 190, white);
		chh = _getch();
		option++;
		while (chh != 13)//Untill you choose an option
		{
			if (chh == 80 && option == 0)
			{
				myLine(60, 147, 95, 147, black);
				myLine(60, 147, 60, 190, black);
				myLine(60, 190, 95, 190, black);
				myLine(95, 147, 95, 190, black);
				myLine(60, 197, 95, 197, white);
				myLine(60, 197, 60, 240, white);
				myLine(60, 240, 95, 240, white);
				myLine(95, 197, 95, 240, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 1)
			{
				myLine(60, 147, 95, 147, white);
				myLine(60, 147, 60, 190, white);
				myLine(60, 190, 95, 190, white);
				myLine(95, 147, 95, 190, white);
				myLine(60, 197, 95, 197, black);
				myLine(60, 197, 60, 240, black);
				myLine(60, 240, 95, 240, black);
				myLine(95, 197, 95, 240, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 1)
			{
				myLine(60, 247, 95, 247, white);
				myLine(60, 247, 60, 290, white);
				myLine(60, 290, 95, 290, white);
				myLine(95, 247, 95, 290, white);
				myLine(60, 197, 95, 197, black);
				myLine(60, 197, 60, 240, black);
				myLine(60, 240, 95, 240, black);
				myLine(95, 197, 95, 240, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 2)
			{
				myLine(60, 247, 95, 247, black);
				myLine(60, 247, 60, 290, black);
				myLine(60, 290, 95, 290, black);
				myLine(95, 247, 95, 290, black);
				myLine(60, 197, 95, 197, white);
				myLine(60, 197, 60, 240, white);
				myLine(60, 240, 95, 240, white);
				myLine(95, 197, 95, 240, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 2)
			{
				myLine(60, 247, 95, 247, black);
				myLine(60, 247, 60, 290, black);
				myLine(60, 290, 95, 290, black);
				myLine(95, 247, 95, 290, black);
				myLine(60, 297, 95, 297, white);
				myLine(60, 297, 60, 340, white);
				myLine(60, 340, 95, 340, white);
				myLine(95, 297, 95, 340, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 3)
			{
				myLine(60, 247, 95, 247, white);
				myLine(60, 247, 60, 290, white);
				myLine(60, 290, 95, 290, white);
				myLine(95, 247, 95, 290, white);
				myLine(60, 297, 95, 297, black);
				myLine(60, 297, 60, 340, black);
				myLine(60, 340, 95, 340, black);
				myLine(95, 297, 95, 340, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 3)
			{
				myLine(60, 297, 95, 297, black);
				myLine(60, 297, 60, 340, black);
				myLine(60, 340, 95, 340, black);
				myLine(95, 297, 95, 340, black);
				myLine(60, 347, 95, 347, white);
				myLine(60, 347, 60, 390, white);
				myLine(60, 390, 95, 390, white);
				myLine(95, 347, 95, 390, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 4)
			{
				myLine(60, 297, 95, 297, white);
				myLine(60, 297, 60, 340, white);
				myLine(60, 340, 95, 340, white);
				myLine(95, 297, 95, 340, white);
				myLine(60, 347, 95, 347, black);
				myLine(60, 347, 60, 390, black);
				myLine(60, 390, 95, 390, black);
				myLine(95, 347, 95, 390, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 4)
			{
				myLine(60, 347, 95, 347, black);
				myLine(60, 347, 60, 390, black);
				myLine(60, 390, 95, 390, black);
				myLine(95, 347, 95, 390, black);
				myLine(60, 397, 95, 397, white);
				myLine(60, 397, 60, 440, white);
				myLine(60, 440, 95, 440, white);
				myLine(95, 397, 95, 440, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 5)
			{
				myLine(60, 347, 95, 347, white);
				myLine(60, 347, 60, 390, white);
				myLine(60, 390, 95, 390, white);
				myLine(95, 347, 95, 390, white);
				myLine(60, 397, 95, 397, black);
				myLine(60, 397, 60, 440, black);
				myLine(60, 440, 95, 440, black);
				myLine(95, 397, 95, 440, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 5)
			{
				myLine(60, 447, 95, 447, white);
				myLine(60, 447, 60, 490, white);
				myLine(60, 490, 95, 490, white);
				myLine(95, 447, 95, 490, white);
				myLine(60, 397, 95, 397, black);
				myLine(60, 397, 60, 440, black);
				myLine(60, 440, 95, 440, black);
				myLine(95, 397, 95, 440, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 6)
			{
				myLine(60, 447, 95, 447, black);
				myLine(60, 447, 60, 490, black);
				myLine(60, 490, 95, 490, black);
				myLine(95, 447, 95, 490, black);
				myLine(60, 397, 95, 397, white);
				myLine(60, 397, 60, 440, white);
				myLine(60, 440, 95, 440, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				myLine(95, 397, 95, 440, white);
				option--;
			}
			chh = _getch();
		}
		PlaySound(TEXT("Hamid3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (tos==2)//If you are bowling
	{
		//-----Opponent-----
		myDrawTextWithFont(40, 80, 60, "Opponent", red, black);
		myDrawTextWithFont(120, 150, 40, "0", turquoise, black);
		myDrawTextWithFont(120, 200, 40, "1", turquoise, black);
		myDrawTextWithFont(120, 250, 40, "2", turquoise, black);
		myDrawTextWithFont(120, 300, 40, "3", turquoise, black);
		myDrawTextWithFont(120, 350, 40, "4", turquoise, black);
		myDrawTextWithFont(120, 400, 40, "5", turquoise, black);
		myDrawTextWithFont(120, 450, 40, "6", turquoise, black);
		//----You------
		myDrawTextWithFont(790, 80, 60, "You", red, black);
		myDrawTextWithFont(820, 150, 40, "0", turquoise, black);
		myDrawTextWithFont(820, 200, 40, "1", turquoise, black);
		myDrawTextWithFont(820, 250, 40, "2", turquoise, black);
		myDrawTextWithFont(820, 300, 40, "3", turquoise, black);
		myDrawTextWithFont(820, 350, 40, "4", turquoise, black);
		myDrawTextWithFont(820, 400, 40, "5", turquoise, black);
		myDrawTextWithFont(820, 450, 40, "6", turquoise, black);
		//---moves-----
		myLine(810, 147, 845, 147, white);
		myLine(810, 147, 810, 190, white);
		myLine(810, 190, 845, 190, white);
		myLine(845, 147, 845, 190, white);
		chh = _getch();
		option++;
		while (chh != 13)
		{
			if (chh == 80 && option == 0)
			{
				myLine(810, 147, 845, 147, black);
				myLine(810, 147, 810, 190, black);
				myLine(810, 190, 845, 190, black);
				myLine(845, 147, 845, 190, black);
				myLine(810, 197, 845, 197, white);
				myLine(810, 197, 810, 240, white);
				myLine(810, 240, 845, 240, white);
				myLine(845, 197, 845, 240, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 1)
			{
				myLine(810, 147, 845, 147, white);
				myLine(810, 147, 810, 190, white);
				myLine(810, 190, 845, 190, white);
				myLine(845, 147, 845, 190, white);
				myLine(810, 197, 845, 197, black);
				myLine(810, 197, 810, 240, black);
				myLine(810, 240, 845, 240, black);
				myLine(845, 197, 845, 240, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 1)
			{
				myLine(810, 247, 845, 247, white);
				myLine(810, 247, 810, 290, white);
				myLine(810, 290, 845, 290, white);
				myLine(845, 247, 845, 290, white);
				myLine(810, 197, 845, 197, black);
				myLine(810, 197, 810, 240, black);
				myLine(810, 240, 845, 240, black);
				myLine(845, 197, 845, 240, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;				
			}
			else if (chh == 72 && option == 2)
			{
				myLine(810, 247, 845, 247, black);
				myLine(810, 247, 810, 290, black);
				myLine(810, 290, 845, 290, black);
				myLine(845, 247, 845, 290, black);
				myLine(810, 197, 845, 197, white);
				myLine(810, 197, 810, 240, white);
				myLine(810, 240, 845, 240, white);
				myLine(845, 197, 845, 240, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 2)
			{
				myLine(810, 247, 845, 247, black);
				myLine(810, 247, 810, 290, black);
				myLine(810, 290, 845, 290, black);
				myLine(845, 247, 845, 290, black);
				myLine(810, 297, 845, 297, white);
				myLine(810, 297, 810, 340, white);
				myLine(810, 340, 845, 340, white);
				myLine(845, 297, 845, 340, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 3)
			{
				myLine(810, 247, 845, 247, white);
				myLine(810, 247, 810, 290, white);
				myLine(810, 290, 845, 290, white);
				myLine(845, 247, 845, 290, white);
				myLine(810, 297, 845, 297, black);
				myLine(810, 297, 810, 340, black);
				myLine(810, 340, 845, 340, black);
				myLine(845, 297, 845, 340, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 3)
			{
				myLine(810, 297, 845, 297, black);
				myLine(810, 297, 810, 340, black);
				myLine(810, 340, 845, 340, black);
				myLine(845, 297, 845, 340, black);
				myLine(810, 347, 845, 347, white);
				myLine(810, 347, 810, 390, white);
				myLine(810, 390, 845, 390, white);
				myLine(845, 347, 845, 390, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 4)
			{
				myLine(810, 297, 845, 297, white);
				myLine(810, 297, 810, 340, white);
				myLine(810, 340, 845, 340, white);
				myLine(845, 297, 845, 340, white);
				myLine(810, 347, 845, 347, black);
				myLine(810, 347, 810, 390, black);
				myLine(810, 390, 845, 390, black);
				myLine(845, 347, 845, 390, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 4)
			{
				myLine(810, 347, 845, 347, black);
				myLine(810, 347, 810, 390, black);
				myLine(810, 390, 845, 390, black);
				myLine(845, 347, 845, 390, black);
				myLine(810, 397, 845, 397, white);
				myLine(810, 397, 810, 440, white);
				myLine(810, 440, 845, 440, white);
				myLine(845, 397, 845, 440, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 5)
			{
				myLine(810, 347, 845, 347, white);
				myLine(810, 347, 810, 390, white);
				myLine(810, 390, 845, 390, white);
				myLine(845, 347, 845, 390, white);
				myLine(810, 397, 845, 397, black);
				myLine(810, 397, 810, 440, black);
				myLine(810, 440, 845, 440, black);
				myLine(845, 397, 845, 440, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			else if (chh == 80 && option == 5)
			{
				myLine(810, 447, 845, 447, white);
				myLine(810, 447, 810, 490, white);
				myLine(810, 490, 845, 490, white);
				myLine(845, 447, 845, 490, white);
				myLine(810, 397, 845, 397, black);
				myLine(810, 397, 810, 440, black);
				myLine(810, 440, 845, 440, black);
				myLine(845, 397, 845, 440, black);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option++;
			}
			else if (chh == 72 && option == 6)
			{
				myLine(810, 447, 845, 447, black);
				myLine(810, 447, 810, 490, black);
				myLine(810, 490, 845, 490, black);
				myLine(845, 447, 845, 490, black);
				myLine(810, 397, 845, 397, white);
				myLine(810, 397, 810, 440, white);
				myLine(810, 440, 845, 440, white);
				myLine(845, 397, 845, 440, white);
				PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				option--;
			}
			chh = _getch();
		}
		PlaySound(TEXT("Hamid4.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	return option;
}
void r_options(int& option, int& o_option, int& wicket, int& score,int& tos)//Selects computer's option
{
	if (tos == 1)
	{
		int wick = option;//if you are batting then your runs and wickets is calculated by your options
		int runs = option;
		switch (option)
		{
		case 0: myDrawTextWithFont(400, 250, 40, "0", turquoise, black);
			break;
		case 1: myDrawTextWithFont(400, 250, 40, "1", turquoise, black);
			break;
		case 2: myDrawTextWithFont(400, 250, 40, "2", turquoise, black);
			break;
		case 3: myDrawTextWithFont(400, 250, 40, "3", turquoise, black);
			break;
		case 4: myDrawTextWithFont(400, 250, 40, "4", turquoise, black);
			break;
		case 5: myDrawTextWithFont(400, 250, 40, "5", turquoise, black);
			break;
		case 6: myDrawTextWithFont(400, 250, 40, "6", turquoise, black);
			break;
		}
		switch (option == o_option)//o_option is computer turn
		{
		case 1:myDrawTextWithFont(430, 250, 40, "=", turquoise, black);
			wicket += 1;
			switch (wick)
			{
			case 1: myDrawTextWithFont(360, 350, 40, "->>Run out<<-", red, black);
				PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 4: myDrawTextWithFont(320, 350, 40, "---Caught behind---", red, black);
				PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 6:myDrawTextWithFont(330, 350, 40, "Caught at straight", red, black);
				PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			default:myDrawTextWithFont(330, 350, 40, "->Clean Bowled<-", red, black);
				PlaySound(TEXT("Disappointment.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			}
			break;
		case 0:myDrawTextWithFont(430, 250, 40, "!=", turquoise, black);
			score += option;
			switch (runs)
			{
			case 0:myDrawTextWithFont(390, 350, 40, "--Duck--", white, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 1:myDrawTextWithFont(385, 350, 40, "--Single--", white, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 2:myDrawTextWithFont(385, 350, 40, "--Double--", blue, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 3:myDrawTextWithFont(385, 350, 40, "--Triple--", blue, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 4:myDrawTextWithFont(390, 350, 40, "->Four<-", blue, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 5:myDrawTextWithFont(385, 350, 40, "-->Five<--", green, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 6:myDrawTextWithFont(380, 350, 40, ">>Sixer<<", green, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			}
			break;
		}
		switch (o_option)
		{
		case 0: myDrawTextWithFont(470, 250, 40, "0", turquoise, black);
			break;
		case 1: myDrawTextWithFont(470, 250, 40, "1", turquoise, black);
			break;
		case 2: myDrawTextWithFont(470, 250, 40, "2", turquoise, black);
			break;
		case 3: myDrawTextWithFont(470, 250, 40, "3", turquoise, black);
			break;
		case 4: myDrawTextWithFont(470, 250, 40, "4", turquoise, black);
			break;
		case 5: myDrawTextWithFont(470, 250, 40, "5", turquoise, black);
			break;
		case 6: myDrawTextWithFont(470, 250, 40, "6", turquoise, black);
			break;
		}
	}
	else if (tos==2)
	{
		int wick = o_option;//If you are bowling then runs and wickets are calculated by computer's turn 
		int runs = o_option;
		switch (o_option)
		{
		case 0: myDrawTextWithFont(400, 250, 40, "0", turquoise, black);
			break;
		case 1: myDrawTextWithFont(400, 250, 40, "1", turquoise, black);
			break;
		case 2: myDrawTextWithFont(400, 250, 40, "2", turquoise, black);
			break;
		case 3: myDrawTextWithFont(400, 250, 40, "3", turquoise, black);
			break;
		case 4: myDrawTextWithFont(400, 250, 40, "4", turquoise, black);
			break;
		case 5: myDrawTextWithFont(400, 250, 40, "5", turquoise, black);
			break;
		case 6: myDrawTextWithFont(400, 250, 40, "6", turquoise, black);
			break;
		}
		switch (option == o_option)
		{
		case 1:myDrawTextWithFont(430, 250, 40, "=", turquoise, black);
			wicket += 1;
			switch (wick)
			{
			case 1: myDrawTextWithFont(360, 350, 40, "->>Run out<<-", red, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 4: myDrawTextWithFont(320, 350, 40, "---Caught behind---", red, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 6:myDrawTextWithFont(330, 350, 40, "Caught at straight", red, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			default:myDrawTextWithFont(330, 350, 40, "->Clean Bowled<-", red, black);
				PlaySound(TEXT("cheers.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			}
			break;
		case 0:myDrawTextWithFont(430, 250, 40, "!=", turquoise, black);
			score += o_option;
			switch (runs)
			{
			case 0:myDrawTextWithFont(390, 350, 40, "--Duck--", white, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 1:myDrawTextWithFont(385, 350, 40, "--Single--", white, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 2:myDrawTextWithFont(385, 350, 40, "--Double--", blue, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 3:myDrawTextWithFont(385, 350, 40, "--Triple--", blue, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 4:myDrawTextWithFont(390, 350, 40, "->Four<-", blue, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 5:myDrawTextWithFont(385, 350, 40, "-->Five<--", green, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			case 6:myDrawTextWithFont(380, 350, 40, ">>Sixer<<", green, black);
				PlaySound(TEXT("claps.wav"), NULL, SND_FILENAME | SND_ASYNC);
				break;
			}
			break;
		}
		switch (option)
		{
		case 0: myDrawTextWithFont(470, 250, 40, "0", turquoise, black);
			break;
		case 1: myDrawTextWithFont(470, 250, 40, "1", turquoise, black);
			break;
		case 2: myDrawTextWithFont(470, 250, 40, "2", turquoise, black);
			break;
		case 3: myDrawTextWithFont(470, 250, 40, "3", turquoise, black);
			break;
		case 4: myDrawTextWithFont(470, 250, 40, "4", turquoise, black);
			break;
		case 5: myDrawTextWithFont(470, 250, 40, "5", turquoise, black);
			break;
		case 6: myDrawTextWithFont(470, 250, 40, "6", turquoise, black);
			break;
		}
	}
}
int overs(void)//Overs selection
{
	char chh;
	int ov_option = 0, tm_option = 0, rtm_option;
	srand(time(0));
	rtm_option = 1 + rand() % 4;
	border();
	myDrawTextWithFont(390, 20, 60, "---Overs---", red, black);
	myDrawTextWithFont(20, 100, 50, "Choose:", white, black);
	myDrawTextWithFont(150, 180, 50, "1", white, black);
	myDrawTextWithFont(350, 180, 50, "2", white, black);
	myDrawTextWithFont(550, 180, 50, "5", white, black);
	myDrawTextWithFont(750, 180, 50, "10", white, black);
	myLine(140, 177, 175, 177, red);
	myLine(140, 177, 140, 230, red);
	myLine(140, 230, 175, 230, red);
	myLine(175, 177, 175, 230, red);
	ov_option++;
	chh = _getch();
	while (chh != 13)
	{
		if (chh == 77 && ov_option == 1)
		{
			myLine(140, 177, 175, 177, black);
			myLine(140, 177, 140, 230, black);
			myLine(140, 230, 175, 230, black);
			myLine(175, 177, 175, 230, black);
			myLine(340, 177, 375, 177, red);
			myLine(340, 177, 340, 230, red);
			myLine(340, 230, 375, 230, red);
			myLine(375, 177, 375, 230, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option++;
		}
		else if (chh == 75 && ov_option == 2)
		{
			myLine(140, 177, 175, 177, red);
			myLine(140, 177, 140, 230, red);
			myLine(140, 230, 175, 230, red);
			myLine(175, 177, 175, 230, red);
			myLine(340, 177, 375, 177, black);
			myLine(340, 177, 340, 230, black);
			myLine(340, 230, 375, 230, black);
			myLine(375, 177, 375, 230, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option--;
		}
		else if (chh == 77 && ov_option == 2)
		{
			myLine(540, 177, 575, 177, red);
			myLine(540, 177, 540, 230, red);
			myLine(540, 230, 575, 230, red);
			myLine(575, 177, 575, 230, red);
			myLine(340, 177, 375, 177, black);
			myLine(340, 177, 340, 230, black);
			myLine(340, 230, 375, 230, black);
			myLine(375, 177, 375, 230, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option++;
		}
		else if (chh == 75 && ov_option == 3)
		{
			myLine(540, 177, 575, 177, black);
			myLine(540, 177, 540, 230, black);
			myLine(540, 230, 575, 230, black);
			myLine(575, 177, 575, 230, black);
			myLine(340, 177, 375, 177, red);
			myLine(340, 177, 340, 230, red);
			myLine(340, 230, 375, 230, red);
			myLine(375, 177, 375, 230, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option--;
		}
		else if (chh == 77 && ov_option == 3)
		{
			myLine(540, 177, 575, 177, black);
			myLine(540, 177, 540, 230, black);
			myLine(540, 230, 575, 230, black);
			myLine(575, 177, 575, 230, black);
			myLine(740, 177, 790, 177, red);
			myLine(740, 177, 740, 230, red);
			myLine(740, 230, 790, 230, red);
			myLine(790, 177, 790, 230, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option++;
		}
		else if (chh == 75 && ov_option == 4)
		{
			myLine(540, 177, 575, 177, red);
			myLine(540, 177, 540, 230, red);
			myLine(540, 230, 575, 230, red);
			myLine(575, 177, 575, 230, red);
			myLine(740, 177, 790, 177, black);
			myLine(740, 177, 740, 230, black);
			myLine(740, 230, 790, 230, black);
			myLine(790, 177, 790, 230, black); 
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			ov_option--;
		}
		chh = _getch();
	}
	PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	myDrawTextWithFont(390, 300, 60, "---Team---", red, black);
	myDrawTextWithFont(20, 350, 50, "Choose:", white, black);
	myDrawTextWithFont(150, 420, 50, "I.U", red, black);
	myDrawTextWithFont(350, 420, 50, "Q.G", purple, black);
	myDrawTextWithFont(550, 420, 50, "L.Q", green, black);
	myDrawTextWithFont(750, 420, 50, "K.K", blue, black);
	myLine(140, 417, 200, 417, red);
	myLine(140, 417, 140, 470, red);
	myLine(140, 470, 200, 470, red);
	myLine(200, 417, 200, 470, red);
	tm_option++;
	chh = _getch();
	while (chh != 13)
	{
		if (chh == 77 && tm_option == 1)
		{
			myLine(140, 417, 200, 417, black);
			myLine(140, 417, 140, 470, black);
			myLine(140, 470, 200, 470, black);
			myLine(200, 417, 200, 470, black);
			myLine(340, 417, 410, 417, red);
			myLine(340, 417, 340, 470, red);
			myLine(340, 470, 410, 470, red);
			myLine(410, 417, 410, 470, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option++;
		}
		else if (chh == 75 && tm_option == 2)
		{
			myLine(140, 417, 200, 417, red);
			myLine(140, 417, 140, 470, red);
			myLine(140, 470, 200, 470, red);
			myLine(200, 417, 200, 470, red);
			myLine(340, 417, 410, 417, black);
			myLine(340, 417, 340, 470, black);
			myLine(340, 470, 410, 470, black);
			myLine(410, 417, 410, 470, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option--;
		}
		else if (chh == 77 && tm_option == 2)
		{
			myLine(540, 417, 600, 417, red);
			myLine(540, 417, 540, 470, red);
			myLine(540, 470, 600, 470, red);
			myLine(600, 417, 600, 470, red);
			myLine(340, 417, 410, 417, black);
			myLine(340, 417, 340, 470, black);
			myLine(340, 470, 410, 470, black);
			myLine(410, 417, 410, 470, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option++;
		}
		else if (chh == 75 && tm_option == 3)
		{
			myLine(540, 417, 600, 417, black);
			myLine(540, 417, 540, 470, black);
			myLine(540, 470, 600, 470, black);
			myLine(600, 417, 600, 470, black);
			myLine(340, 417, 410, 417, red);
			myLine(340, 417, 340, 470, red);
			myLine(340, 470, 410, 470, red);
			myLine(410, 417, 410, 470, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option--;
		}
		else if (chh == 77 && tm_option == 3)
		{
			myLine(540, 417, 600, 417, black);
			myLine(540, 417, 540, 470, black);
			myLine(540, 470, 600, 470, black);
			myLine(600, 417, 600, 470, black);
			myLine(740, 417, 810, 417, red);
			myLine(740, 417, 740, 470, red);
			myLine(740, 470, 810, 470, red);
			myLine(810, 417, 810, 470, red);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option++;
		}
		else if (chh == 75 && tm_option == 4)
		{
			myLine(540, 417, 600, 417, red);
			myLine(540, 417, 540, 470, red);
			myLine(540, 470, 600, 470, red);
			myLine(600, 417, 600, 470, red);
			myLine(740, 417, 810, 417, black);
			myLine(740, 417, 740, 470, black);
			myLine(740, 470, 810, 470, black);
			myLine(810, 417, 810, 470, black);
			PlaySound(TEXT("Hamid1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tm_option--;
		}
		chh = _getch();
	}
	PlaySound(TEXT("Hamid2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	switch (tm_option)//team selection
	{
	case 1: myDrawTextWithFont(400, 500, 50, "I.U", red, black);
		break;
	case 2:	myDrawTextWithFont(400, 500, 50, "Q.G", purple, black);
		break;
	case 3:	myDrawTextWithFont(400, 500, 50, "L.Q", green, black);
		break;
	case 4:	myDrawTextWithFont(400, 500, 50, "K.K", blue, black);
		break;
	}
	myDrawTextWithFont(470, 500, 50, (char*)"VS", white, black);
	switch (rtm_option)
	{
	case 1: myDrawTextWithFont(530, 500, 50, "I.U", red, black);
		break;
	case 2:	myDrawTextWithFont(530, 500, 50, "Q.G", purple, black);
		break;
	case 3:	myDrawTextWithFont(530, 500, 50, "L.Q", green, black);
		break;
	case 4:	myDrawTextWithFont(530, 500, 50, "K.K", blue, black);
		break;
	}
	return ov_option;
}