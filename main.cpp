#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
#include <conio.h>

using namespace std;

int amount_of_words(string file);							//Program liczy wyrazy w pliku
int amount_of_files();										//Program liczy dostepne pliki
int write_words(string file);								//Program wypisuje wszystkie wyrazy 
string choose_file(void);									//Program podaje nazwe pliku z ktorym uzytkownik chce pracowac
string write_english_word(string file , int nr_line);		//Program zwraca slowo w jezyku angielskim z pobranego pliku
string write_polish_word(string file , int nr_line);		//Program zwraca slowo w jezyku polskim z pobranego pliku
void write_files();											//Program wypisuje dostepne pliki

int random_flashcard(string file);							//Wybiera randomowa liczbe z przedzialu pliku
string to_lower(string text);								//Zmniejsza wszystkie litery slowa
void game_flashcard(string file);							//Modul do gry w fiszki z angielskiego na polski
void game_flashcard2(string file);							//Modul do gry w fiszki z polskiego na angielski

void flashcard_quiz(string file);							//Quiz do gry z polskiego na angielski
void flashcard_quiz2(string file);							//Quiz do gry z angielskiego na polski
void remember_game(string file);							//Gra w pamiec
void random_queue(int* queue, int size);					//Losowa kolejnosc



int color_menu();
//void game_flashcard_color(string file);						//Modu³ do gry w fiszki z angielskiego na polski w kolorze


int main()
{
	int nr_line;									//Numer linii z pliku
	string english_word, polish_word;				//Polskie i angielskie slowa
	string file;									//Wybrany plik do pracy

	int menu = 1;									//Numer wybranej opcji

	srand(time(NULL));								//Zerowanie liczb pseudolosowych
	HANDLE hOut;									//Uchwyt koloru
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		
		
		
		
		//cout << "Wybierz opcje\n1---Ucz sie fiszek\n2---Gra w fiszki z angielskiego na polski\n3---Gra w fiszki z polskiego na angielski\n4---Wyjscie z programu\n";
		//cin >> menu;

		menu = color_menu();


		switch (menu)
		{
		case 1: //Nauka fiszek
		{
			system("cls");

			//write_files();		//Wypisanie wszystkich plikow

			//cout << "\nPodaj numer pliku do pracy\n";

			//cin >> void;		//Wczytanie numeru pliku do pracy

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}

			write_words(file);	//Wypisanie wszystkich slow
			
			cout << "\nPodaj numer linii\n";

			cin >> nr_line;		//Pobranie lini do zapisania

			english_word = write_english_word(file,nr_line);
			cout << english_word << endl;

			if (english_word == "000")	//Obsluga bledu wczytania angielskiego slowa
			{
				cout << "\nblad wczytanego slowa w jezyku angielskim z pliku "<< file<<endl;
				break;
			}
			polish_word = write_polish_word(file,nr_line);
			cout << polish_word << endl;

			if (polish_word == "000")	//Obsluga bledu wczytania polskiego slowa
			{
				cout << "\nblad wczytanego slowa w jezyku polskim z pliku " << file << endl;
				break;
			}

		





			system("PAUSE");
			system("cls");
			break;
		}
		case 2:	//Nauka losowych fiszek
		{
			system("cls");

			//write_files();		//Wypisanie wszystkich plikow

			//cout << "\nPodaj numer pliku do pracy\n";

			//cin >> nr_file;		//Wczytanie numeru pliku do pracy

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}



			game_flashcard(file);












			system("PAUSE");
			system("cls");
			break;
		}
		case 3:	//Nauka losowych fiszek
		{
			system("cls");

			//write_files();		//Wypisanie wszystkich plikow

			//cout << "\nPodaj numer pliku do pracy\n";

			//cin >> nr_file;		//Wczytanie numeru pliku do pracy

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}



			game_flashcard(file);












			system("PAUSE");
			break;
		}

		case 4:				//Quiz z polskiego na angielski
		{
			system("cls");

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}

			flashcard_quiz(file);

			system("PAUSE");
			system("cls");
			break;
		}

		case 5:				//Quiz z angielskiego na polski
		{
			system("cls");

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}

			flashcard_quiz2(file);

			system("PAUSE");
			system("cls");

			break;
		}

		case 6:				//Wyjscie z programu
		{
			
			system("cls");

			file = choose_file();

			system("cls");

			if (file == "000")	//Sprawdzenie kodu bledu
			{
				cout << "\nblad wczytanego pliku\n";
				break;
			}

			remember_game(file);
			
			//system("pause");
			//system("cls");
			break;
			

			
		}

		case 7:				//Wyjscie z programu
		{

			system("cls");
			break;
			


		}
		}
	} while (menu != 7);

	
	return 0;
}

	//Wypisanie wszystkich wczytanych plikow

void write_files()
{
	int i = 1;
	fstream plik;
	plik.open("files.txt");
	if (plik.good())
	{
		string line;
		while(getline(plik,line))
		{
			cout <<i <<" --- "<< line << endl;
			i++;
		}
	}
}

	//Wybor dostepnego pliku do pracy
	//Program jako kod bledu zwraca symbol bledu 000

string choose_file(void)
{
	/*
	fstream plik;
	plik.open("files.txt");
	if (plik.good())
	{
		string line;
		for (int i = 1; i <= amount_of_files(); i++)
		{
			getline(plik, line);
			if (i == nr_file)
				return line;
		}
		return "000";
	}
	else
		return "000";
		*/

	fstream plik;
	string linia;

	int amount_of_options = 0;
	int nr_opcji = 0;
	HANDLE hOut;								//Uchwyt na kolor
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char znak = 'a';					//Zmienna do przechodzenia po menu

	plik.open("files.txt");

	if (plik.good())
	{
		while (getline(plik, linia))
		{
			amount_of_options++;
		}
	}
	else
	{
		cout << "Blad pliku";
		return "000";
	}
	plik.close();

	while (znak != 13)
	{
		plik.open("files.txt");

		for (int i = 0; i < amount_of_options; i++)
		{
			getline(plik, linia);

			if (nr_opcji == i)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

				cout << linia << endl;

				SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru
			}
			else
				cout << linia << endl;
		}

		plik.close();

		znak = _getch();

		if (znak == 80 && nr_opcji < amount_of_options - 1)
			nr_opcji++;
		else if (znak == 72 && nr_opcji > 0)
			nr_opcji--;
		//cout << znak << endl;

		system("cls");
	}

	plik.open("files.txt");

	for (int i = 0; i <= amount_of_files(); i++)
	{
		getline(plik, linia);
		if (i == nr_opcji)
		{
			return linia;
			plik.close();
		}
	}

	return linia;
	//return nr_opcji;
}

	//Program liczy liczbe wszystkich dostepnych plikow do pracy

int amount_of_files()
{
	int nr_files = 0;
	fstream plik;
	string line;
	
	plik.open("files.txt");
	if (plik.good())
	{
		while (getline(plik, line))
		{
			nr_files++;
		}
		return nr_files;
	}
	else
		return -1;
}

	//Program pobiera liczbe slow z pliku

int amount_of_words(string file)
{
	fstream plik;
	plik.open(file);
	if (plik.good())
	{
		int amount_line;
		string line;
		getline(plik, line);
		amount_line = atoi(line.c_str());
		return amount_line;
	}
	else
	{
		return -1;
		cout << "\nNie otworzono pliku\n";
	}
	plik.close();
}

	//Program wypisuje wszystkie slowa z pliku
	//Jako kod bledu program zwraca -1

int write_words(string file)
{
	fstream plik;
	plik.open(file);
	if (plik.good())
	{
		string line;
		string polish_word, english_word;
		int n = amount_of_words(file);
		if (n != -1)	//Sprawdzenie kodu bledu
		{
			for (int i = 0; i <= n ; i++)
			{
				getline(plik, line);
				if (i != 0)		//Wczytanie tylko slow bez liczby poczatkowej
				{
					stringstream load(line);
					load >> english_word;
					load >> polish_word;
					cout <<i<<" "<< english_word<< " - ";
					cout << polish_word<<endl;
				}
			}
		return 0;
		}
		return -1;
		
	}
	else
	{
		return -1;	//Wypisanie kodu bledu przy zlym wczytaniu pliku
		cout << "\nNie otworzono pliku\n";
	}
	plik.close();
}

	//Program wypisuje wszystkie angielskie slowa z pliku
	//Jako kod bledu program zwraca symbol bledu 000

string write_english_word(string file, int nr_line)
{
	if (nr_line > amount_of_words(file))
		return "000";
	fstream plik;
	plik.open(file);
	if (plik.good())
	{
		string line;
		string english_word;
		for (int i = 0; i <= amount_of_words(file); i++)
		{	
			getline(plik,line);
			if (i == nr_line)
			{
				stringstream load(line);
				load >> english_word;
				
				return english_word;
			}
			
		}
		return "000";
	}
	else
	{
		return "000";
	}
	plik.close();
}

	//Program wypisuje wszystkie polskie slowa z pliku
	//Jako kod bledu program zwraca symbol bledu 000

string write_polish_word(string file , int nr_line)
{
	if (nr_line > amount_of_words(file))
		return "000";
	fstream plik;
	plik.open(file);
	if (plik.good())
	{
		string line;
		string polish_word;
		for (int i = 0; i <= amount_of_words(file); i++)
		{
			getline(plik,line);
			if (i == nr_line)
			{
				stringstream load(line);
				load >> polish_word;
				load >> polish_word;
				return polish_word;
			}
		}
		return "000";
	}
	else
	{
		return "000";
		cout << "\nblad pliku\n";
	}
}

	//Funkaja losuje randomowa liczbe z zakresu 

int random_flashcard(string file)
{
	return (1 + rand() % amount_of_words(file));
}

	//Funkcja zmniejsza wszystkie litery w slowie

string to_lower(string text)
{
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

	//Funkcja jest modulem do gry w fiszki z angielskiego na polski

void game_flashcard(string file)
{
	int good_answer = 0, wrong_answer = 0;	//Liczenie dobrych i zlych odpowiedzi
	int nr_flashcard;						//numer wylosowanej fiszki
	string english_word, polish_word,answer;



	for (int i = 0; i < 5; i++)
	{
		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		cout << "Podaj slowo po polsku\n"<<english_word<<endl;
		cin >> answer;
		answer = to_lower(answer);					//Zamiana wszystkich liter odpowiedz na male
		if (answer != polish_word)
		{
			wrong_answer++;
			cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n"<<polish_word << endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
	}

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer<<endl;




}

	//Funkcja jest modulem do gry w fiszki z polskiego na angielski


void game_flashcard2(string file)
{
	int good_answer = 0, wrong_answer = 0;	//Liczenie dobrych i zlych odpowiedzi
	int nr_flashcard;						//numer wylosowanej fiszki
	string english_word, polish_word, answer;



	for (int i = 0; i < 5; i++)
	{
		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		cout << "Podaj slowo po polsku\n" << polish_word << endl;
		cin >> answer;
		answer = to_lower(answer);					//Zamiana wszystkich liter odpowiedz na male
		if (answer != english_word)
		{
			wrong_answer++;
			cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << english_word << endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
	}

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer << endl;

}



void game_flashcard_color(string file)
{
	int good_answer = 0, wrong_answer = 0;		//Liczba dobrych i zlych odpoweidzi
	int nr_flashcard;							//Numer wylosowanej fiszki
	string english_word, polish_word, answer;	//zapisanie fiszki po polsku angielsku i odpoweidzi
	int amount_of_round = 0;					//Licba rund

	cout << "Liczba rund: ";
	cin >> amount_of_round;

	for (int i = 0; i < amount_of_round; i++)
	{
		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		cout << "Podaj slowo po polsku\n" << polish_word << endl;
		cin >> answer;
		answer = to_lower(answer);					//Zamiana wszystkich liter odpowiedz na male

		if (answer != english_word)
		{
			wrong_answer++;
			cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << english_word << endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			good_answer++;
			cout << "Podaj slowo po polsku\n" << polish_word << endl;

			system("PAUSE");
			system("cls");
		}
	}
}

int color_menu()
{
	char znak = 'a';
	int position = 1;

	HANDLE hOut;									//Uchwyt koloru
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (znak != 13)
	{
		if (position == 1)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tUcz sie fiszek" << endl;
		if (position == 1)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 2)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tGra w fiszki z angielskiego na polski" << endl;
		if (position == 2)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 3)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tGra w fiszki z polskiego na angielski" << endl;
		if (position == 3)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 4)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tQuiz z polskiego na angielski" << endl;
		if (position == 4)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 5)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tQuiz z angielskiego na polski" << endl;
		if (position == 5)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 6)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tGra w pamiec" << endl;
		if (position == 6)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 7)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tWyjscie z programu" << endl;
		if (position == 7)
		{
			SetConsoleTextAttribute(hOut, 15);
		}


		znak = _getch();

		if (znak == 80 && position < 7)
			position++;
		else if (znak == 72 && position > 1)
			position--;

		system("cls");
	}

return position;
}

	//Funckcja jest quizem do gry w fiszki gdzie uzytkownik wybiera odpowiedz sposrod 4 wariantow
	//Z polskiego na angielski

void flashcard_quiz(string file)
{
	int good_answer = 0, wrong_answer = 0;	//Liczenie dobrych i zlych odpowiedzi
	int nr_flashcard;						//numer wylosowanej fiszki
	int answer, user_answer;				//Odpowiedz, opdowiedz uzytkownika
	string english_word, polish_word;

	for (int i = 0; i < 5; i++)
	{
		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		answer = rand() % 4;						//Losowanie miejsca odpowiedzi

		string answers[4];							//Tablica z odpowiedziami
		answers[answer] = english_word;

		cout << polish_word << "\n\n";

		for (int i = 0; i < 4; i++)					//Uzupelnienie pustych odpowiedzi
		{
			if(answers[i] != english_word)
			{
				bool ok_answer = true;
				do
				{
					nr_flashcard = random_flashcard(file);
					answers[i] = write_english_word(file, nr_flashcard);

					
					if (answers[i] == english_word)
						ok_answer = false;
					else if (i - 1 > -1 && answers[i] == answers[i - 1])
						ok_answer = false;
					else if (i - 2 > -1 && answers[i] == answers[i - 2])
						ok_answer = false;
					else if (i - 3 > -1 && answers[i] == answers[i - 3])
						ok_answer = false;
					else 
						ok_answer = true;
				} while (!ok_answer);// || answers[i] == answers[i - 1] || answers[i] == answers[i - 2] || answers[i] == answers[i - 3]);
			}

			cout << answers[i] << endl;
		}

		cin >> user_answer;							//Podanie odpowiedzi przez uzytkownika
		user_answer--;

		if (answer == user_answer)
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			wrong_answer++;
			cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << answer + 1<<"  "<<answers[answer] << endl;
			system("PAUSE");
			system("cls");
		}


	}

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer << endl;

}

		//Funckcja jest quizem do gry w fiszki gdzie uzytkownik wybiera odpowiedz sposrod 4 wariantow
		//Z angielskiego na polski


void flashcard_quiz2(string file)
{
	int good_answer = 0, wrong_answer = 0;	//Liczenie dobrych i zlych odpowiedzi
	int nr_flashcard;						//numer wylosowanej fiszki
	int answer, user_answer;				//Odpowiedz, opdowiedz uzytkownika
	string english_word, polish_word;

	for (int i = 0; i < 5; i++)
	{
		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		answer = rand() % 4;						//Losowanie miejsca odpowiedzi

		string answers[4];							//Tablica z odpowiedziami
		answers[answer] = polish_word;

		cout << english_word << "\n\n";

		for (int i = 0; i < 4; i++)					//Uzupelnienie pustych odpowiedzi
		{
			if (answers[i] != polish_word)
			{
				bool ok_answer = true;
				do
				{
					nr_flashcard = random_flashcard(file);
					answers[i] = write_polish_word(file, nr_flashcard);


					if (answers[i] == polish_word)
						ok_answer = false;
					else if (i - 1 > -1 && answers[i] == answers[i - 1])
						ok_answer = false;
					else if (i - 2 > -1 && answers[i] == answers[i - 2])
						ok_answer = false;
					else if (i - 3 > -1 && answers[i] == answers[i - 3])
						ok_answer = false;
					else
						ok_answer = true;
				} while (!ok_answer);// || answers[i] == answers[i - 1] || answers[i] == answers[i - 2] || answers[i] == answers[i - 3]);
			}

			cout << answers[i] << endl;
		}

		cin >> user_answer;							//Podanie odpowiedzi przez uzytkownika
		user_answer--;

		if (answer == user_answer)
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
		else
		{
			wrong_answer++;
			cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << answer + 1 << "  " << answers[answer] << endl;
			system("PAUSE");
			system("cls");
		}


	}

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer << endl;

}

void remember_game(string file)
{
	int size_of_board;				//Wielkosc tablicy do gry
	int nr_line;					//Numer wylosowanej linii

	unsigned char znak = 'a';				//Znak do poruszania sie po planszy
	int position = 1;				//Poczatkowa pozycja na planszy
	int choose[2] = {-1};			//Dwa wybrane kolejne slowa

	HANDLE hOut;									//Uchwyt koloru
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	cout << "Ile fiszek chesz uzyc do gry?";
	cin >> size_of_board;

	string* const array_words = new string[size_of_board*2];		//Tablica do przechowywania wyrazow
	int* array_numbers = new int[size_of_board*2];					//Tablica zapasowa do sprawdzania czy wyraz jest odkryty
	int* array_queue = new int[size_of_board * 2];					//Tablica do zmienionej kolejnosci slow

	for (int i = 0; i < size_of_board * 2; i++)						//Ustawienie wszystkich komorek na nieodkryte
	{
		array_numbers[i] = 0;
		array_queue[i] = i + 1;
	}

	for (int i = 0; i < size_of_board*2; i+=2)						//Wylosowanie slowek
	{
		nr_line = random_flashcard(file);
		array_words[i] = write_polish_word(file, nr_line);
		array_words[i+1] = write_english_word(file, nr_line);
		
	}

	random_queue(array_queue, size_of_board * 2);

	for (int i = 0; i < size_of_board * 2; i++)
	{
		cout << array_queue[i] << endl;
	}
	//system("pause");

	/*for (int i = 0; i < size_of_board * 2; i ++)
	{
		cout << array[i] << endl;
	}
	*/

	for (int j = 0; j < size_of_board * 2; j++)					
	{
		//znak = 'a';

		for (int k = 0; k < 2; k++)										//Petla przechodzaca dwa razy po planszy i porownujaca slowa
		{
			znak = 'a';

			while (znak != 13) //&& array_numbers[position - 1] != 1)	//Petla streujaca menu
			{
				for (int i = 1; i <= size_of_board * 2; i++)			//Petla wypisujaca slowa
				{
				
					if (array_numbers[i - 1] == 1)
					{
						if (position == i)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

							cout << array_words[i - 1] << "\t";

							SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru
						}
						else
							cout << array_words[i - 1] << "\t";
					}
					else
					{
						if (position == i)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

							cout << " -------- \t";

							SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru
						}
						else
							cout << " -------- \t";
					}



					if (i != 0 && i % 4 == 0)
						cout << endl;
				}

				znak = _getch();

				if (znak == 80 && position < (size_of_board * 2) - 3)		//strzalka w dol
					position += 4;
				else if (znak == 72 && position > 4)						//strzalka w gore
					position -= 4;
				else if (znak == 75 && position > 1)						//strzalka w lewo
					position--;
				else if (znak == 77 && position < (size_of_board * 2))		//strzalka w prawo
					position++;
				//cout << znak << endl;



				system("cls");


			}

			choose[k] = position;

			array_numbers[position - 1] = 1;
			position = 1;

			
			
			
		}

		for (int i = 1; i <= size_of_board * 2; i++)
		{
			
			if (array_numbers[i - 1] == 1)
			{
				if (position == i)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

					cout << array_words[i - 1] << "\t";

					SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru
				}
				else
					cout << array_words[i - 1] << "\t";
			}
			else
			{
				if (position == i)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

					cout << " -------- \t";

					SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru
				}
				else
					cout << " -------- \t";
			}



			if (i != 0 && i % 4 == 0)
				cout << endl;
		}






		if((choose[0]%2==0 && choose[0]==choose[1]+1) || (choose[1] % 2 == 0 && choose[1] == choose[0] + 1))
		{
			cout << endl << "Poprawna odpowiedz\n";
			system("pause");
			system("cls");
		}
		else
		{	
			cout << endl << "Nie poprawna odpowiedz\n";
			array_numbers[choose[0]-1] = 0;
			array_numbers[choose[1]-1] = 0;
			system("pause");
			system("cls");
		}

	}


	//Usuwanie tablic
	delete[] array_words;
	delete[] array_numbers;
	delete[] array_queue;
}

	//Funckja ktora losowo miesza elementy tablicy

void random_queue(int* queue, int size)
{
	queue[size];
	int random_call;		//Zmienna do losowania 

	for (int i = 0; i < size; i++)
	{
		random_call = rand() % size;
		int x = queue[i];
		queue[i] = queue[random_call];
		queue[random_call] = x;
	}
}
