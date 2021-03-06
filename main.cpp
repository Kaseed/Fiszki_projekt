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
//string write_polish_words(string file , int nr_line);		//Program zwraca wszystkie slowa w jezyku polskim z pobranego pliku
string write_polish_word(string file, int nr_line);			//Program zwraca pierwsze slowo w jezyku polskim z pobranego pliku
string show_one_word(string word);							//Program rozdziela zbitke wyrazow rozdzielonych przecinkiem i pokazuje pierwszy wyraz
void write_files();											//Program wypisuje dostepne pliki
void show_score(int all,int good,int wrong);				//Program wypisuje tablice wynikow

int random_flashcard(string file);							//Wybiera randomowa liczbe z przedzialu pliku
string to_lower(string text);								//Zmniejsza wszystkie litery slowa
void game_flashcard(string file);							//Modul do gry w fiszki z angielskiego na polski
void game_flashcard2(string file);							//Modul do gry w fiszki z polskiego na angielski
bool is_mistake(string good, string wrong);					//Funkcja sprawdza czy blad moze byc zaliczony jako literowka
bool mistake_char(char good, char wrong);					//Funkcja sprawdza czy dwie litery sa bledem powaznym

void flashcard_quiz(string file);							//Quiz do gry z polskiego na angielski
void flashcard_quiz2(string file);							//Quiz do gry z angielskiego na polski
void remember_game(string file);							//Gra w pamiec
void random_queue(int* queue, int size);					//Losowa kolejnosc

void options();												//Otwiera opcje edycji fiszek
void new_file();											//Dodanie nowego pliku z fiszkami
string txtfile(string file_name);							//Sprawdzenie czy w nazwie pliku istnieje koncowka .txt
bool is_exist(string file);									//Sprawdzenie czy wybrany plik istnieje
void create_new_flashcard(string file);						//Tworzenie nowego pliku z fiszkami
void add_file();											//Dodanie istniejacego pliku do pliku files.txt
bool is_exist_inside_files(string file);					//Sprawdzenie czy podany plik istnieje juz wewnatrz pliku files.txt
int add_flashcards();										//Dodanie dodatkowych fiszek do istniejacych plikow
int delete_file();											//Usuwanie plikow z pliku files.txt



int color_menu();
//void game_flashcard_color(string file);						//Modu� do gry w fiszki z angielskiego na polski w kolorze


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
		
		//nice	
		
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

		case 7:
		{
			options();
			break;
		}


		case 8:				//Wyjscie z programu
		{

			system("cls");
			break;
			


		}
		}
	} while (menu != 8);

	
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

void show_score(int all, int good, int wrong)
{
	HANDLE hOut;									//Uchwyt koloru
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	unsigned char call = 219;

	cout << "\t";

	for (int i = 0; i < good; i++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);		//Zmiana koloru na zielony

		cout <<call<< " ";
	}

	for (int i = 0; i < wrong; i++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);		//Zmiana koloru na czerwony

		cout <<call<< " ";
	}

	for (int i = 0; i < (all-good-wrong); i++)
	{
		SetConsoleTextAttribute(hOut, 15);					//Zmiana koloru na bialy

		cout <<call<< " ";
	}

	cout << "\n\n";
	SetConsoleTextAttribute(hOut, 15);					//Powrot do bialego koloru

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

		plik.close();
		return nr_files;
	}
	else
		plik.close();
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
		cout << "\nblad pliku\n";
		return "000";
		
	}
}


/*
string write_polish_word(string file, int nr_line)
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
			getline(plik, line);
			if (i == nr_line)
			{
				stringstream load(line);
				load >> polish_word;
				load >> polish_word;
				
				//Zamiana zbitki wyrazow na jeden wyraz
				polish_word = show_one_word(polish_word);

				return polish_word;
			}
		}
		return "000";
	}
	else
	{
		cout << "\nblad pliku\n";
		return "000";
		
	}
}

*/
string show_one_word(string word)
{
	string line;
	int length = word.length();

	for (int i = 0; i < length; i++)
	{
		if (word[i] == ',')
			return line;
		else
		{
			line[i] = word[i];
		}
	}


	return word;
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

	int amount_of_games;
	cout << "Podaj ile slow chcesz powtorzyc: ";
	cin >> amount_of_games;

	for (int i = 0; i < amount_of_games; i++)
	{
		show_score(amount_of_games, good_answer, wrong_answer);

		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		cout << "Podaj slowo po angielsku\n"<<english_word<<endl;
		cin >> answer;
		answer = to_lower(answer);					//Zamiana wszystkich liter odpowiedz na male
		if (answer != polish_word)
		{
			if (is_mistake(polish_word, answer))
			{
				good_answer++;
				cout << "Gratulacje poprawna odpowiedz\n" << endl;
				system("PAUSE");
				system("cls");
			}
			else
			{
				wrong_answer++;
				cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << polish_word << endl;
				system("PAUSE");
				system("cls");
			}
		}
		else
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
	}
	show_score(amount_of_games, good_answer, wrong_answer);

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer<<endl;




}

	//Funkcja jest modulem do gry w fiszki z polskiego na angielski


void game_flashcard2(string file)
{
	int good_answer = 0, wrong_answer = 0;	//Liczenie dobrych i zlych odpowiedzi
	int nr_flashcard;						//numer wylosowanej fiszki
	string english_word, polish_word, answer;

	int amount_of_games;
	cout << "Podaj ile slow chcesz powtorzyc: ";
	cin >> amount_of_games;

	for (int i = 0; i < amount_of_games; i++)
	{
		show_score(amount_of_games, good_answer, wrong_answer);

		nr_flashcard = random_flashcard(file);		//Losowanie numeru fiszki

		english_word = write_english_word(file, nr_flashcard);
		polish_word = write_polish_word(file, nr_flashcard);
		cout << "Podaj slowo po polsku\n" << polish_word << endl;
		cin >> answer;
		answer = to_lower(answer);					//Zamiana wszystkich liter odpowiedz na male
		if (answer != english_word)
		{
			if (is_mistake(english_word, answer))
			{
				good_answer++;
				cout << "Gratulacje poprawna odpowiedz\n" << endl;
				system("PAUSE");
				system("cls");
			}
			else
			{
				wrong_answer++;
				cout << "Zla odpowiedz\nPoprawna odpowiedz to:\n" << english_word << endl;
				system("PAUSE");
				system("cls");
			}
		}
		else
		{
			good_answer++;
			cout << "Gratulacje poprawna odpowiedz\n" << endl;
			system("PAUSE");
			system("cls");
		}
	}
	show_score(amount_of_games, good_answer, wrong_answer);

	cout << "Koniec gry liczba poprawnych odpowiedzi wynosi: " << good_answer << " a niepoprawnych: " << wrong_answer << endl;

}

bool is_mistake(string good, string wrong)
{
	int answer = -1;

	if (good.length() != wrong.length())
	{
		return false;
	}

	int amount_mistake = -1;

	for (int i = 0; i < good.length(); i++)
	{
		if (good[i] != wrong[i])
		{
			if (amount_mistake == -1)
			{
				amount_mistake = i;
			}
			else
				return false;
		}
	}

	if (mistake_char(good[amount_mistake], wrong[amount_mistake]))
	{
		cout << "W podanym przez ciebie wyrazie jest literowka zakwalifikowana do bledu niekardynalnego czy chcesz zaakceptorac odpoweidz?\n" <<
			"tak --- 1\nnie ---0\n";
			while (answer != 0 && answer != 1)
			{
				cin >> answer;
			}

			if (answer)
				return true;
			else
				return false;
	}
	else
		return false;

	return false;
}

bool mistake_char(char good, char wrong)
{
	switch (good)
	{
	case 'q':
	{
		if (wrong == 'w' || wrong == 'a')
			return true;
		else
			return false;
		break;
	}

	case 'w':
	{
		if (wrong == 'q' || wrong == 'e' ||wrong == 's')
			return true;
		else
			return false;
		break;
	}

	case 'e':
	{
		if (wrong == 'w' || wrong == 'r' || wrong == 'd')
			return true;
		else
			return false;
		break;
	}

	case 'r':
	{
		if (wrong == 'e' || wrong == 'f' || wrong == 't')
			return true;
		else
			return false;
		break;
	}

	case 't':
	{
		if (wrong == 'r' || wrong == 'g' || wrong == 'y')
			return true;
		else
			return false;
		break;
	}

	case 'y':
	{
		if (wrong == 't' || wrong == 'h' || wrong == 'u')
			return true;
		else
			return false;
		break;
	}

	case 'u':
	{
		if (wrong == 'y' || wrong == 'j' || wrong == 'i')
			return true;
		else
			return false;
		break;
	}

	case 'i':
	{
		if (wrong == 'u' || wrong == 'k' || wrong == 'o')
			return true;
		else
			return false;
		break;
	}

	case 'o':
	{
		if (wrong == 'i' || wrong == 'l' || wrong == 'p')
			return true;
		else
			return false;
		break;
	}

	case 'p':
	{
		if (wrong == 'o' || wrong == 'l')
			return true;
		else
			return false;
		break;
	}

	case 'a':
	{
		if (wrong == 'q' || wrong == 's' || wrong == 'z')
			return true;
		else
			return false;
		break;
	}

	case 's':
	{
		if (wrong == 'a' || wrong == 'w' || wrong == 'd' || wrong == 'x')
			return true;
		else
			return false;
		break;
	}

	case 'd':
	{
		if (wrong == 's' || wrong == 'e' || wrong == 'f' || wrong == 'c')
			return true;
		else
			return false;
		break;
	}

	case 'f':
	{
		if (wrong == 'd' || wrong == 'r' || wrong == 'g' || wrong == 'v')
			return true;
		else
			return false;
		break;
	}

	case 'g':
	{
		if (wrong == 'f' || wrong == 't' || wrong == 'h' || wrong == 'b')
			return true;
		else
			return false;
		break;
	}

	case 'h':
	{
		if (wrong == 'g' || wrong == 'y' || wrong == 'j' || wrong == 'n')
			return true;
		else
			return false;
		break;
	}

	case 'j':
	{
		if (wrong == 'h' || wrong == 'u' || wrong == 'k' || wrong == 'm')
			return true;
		else
			return false;
		break;
	}

	case 'k':
	{
		if (wrong == 'j' || wrong == 'i' || wrong == 'l' || wrong == 'm')
			return true;
		else
			return false;
		break;
	}

	case 'l':
	{
		if (wrong == 'k' || wrong == 'o')
			return true;
		else
			return false;
		break;
	}
	
	case 'z':
	{
		if (wrong == 'a' || wrong == 's' || wrong == 'x')
			return true;
		else
			return false;
		break;
	}

	case 'x':
	{
		if (wrong == 'z' || wrong == 's' || wrong == 'd' || wrong == 'c')
			return true;
		else
			return false;
		break;
	}

	case 'c':
	{
		if (wrong == 'x' || wrong == 'd' || wrong == 'f' || wrong == 'v')
			return true;
		else
			return false;
		break;
	}

	case 'v':
	{
		if (wrong == 'c' || wrong == 'f' || wrong == 'g' || wrong == 'b')
			return true;
		else
			return false;
		break;
	}

	case 'b':
	{
		if (wrong == 'v' || wrong == 'g' || wrong == 'h' || wrong == 'n')
			return true;
		else
			return false;
		break;
	}

	case 'n':
	{
		if (wrong == 'b' || wrong == 'h' || wrong == 'j' || wrong == 'm')
			return true;
		else
			return false;
		break;
	}

	case 'm':
	{
		if (wrong == 'n' || wrong == 'j' || wrong == 'k')
			return true;
		else
			return false;
		break;
	}

	}

	return false;
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
		cout << "\tKreator fiszek" << endl;
		if (position == 7)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 8)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tWyjscie z programu" << endl;
		if (position == 8)
		{
			SetConsoleTextAttribute(hOut, 15);
		}


		znak = _getch();

		if (znak == 80 && position < 8)
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

	int amount_of_games;
	cout << "Podaj ile slow chcesz powtorzyc: ";
	cin >> amount_of_games;

	for (int i = 0; i < amount_of_games; i++)
	{
		show_score(amount_of_games, good_answer, wrong_answer);

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
	show_score(amount_of_games, good_answer, wrong_answer);

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

	int amount_of_games;
	cout << "Podaj ile slow chcesz powtorzyc: ";
	cin >> amount_of_games;

	for (int i = 0; i < amount_of_games; i++)
	{
		show_score(amount_of_games, good_answer, wrong_answer);

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
	show_score(amount_of_games, good_answer, wrong_answer);

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
	/*
	for (int i = 0; i < size_of_board * 2; i++)
	{
		cout << array_queue[i] << endl;
	}
	*/

	//system("pause");

	/*for (int i = 0; i < size_of_board * 2; i ++)
	{
		cout << array[i] << endl;
	}
	*/

	for (int j = 0; j < size_of_board; j++)					
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
			j--;
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

void options()
{
	//int menu_option;

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
		cout << "\tStworz nowa fiszke" << endl;
		if (position == 1)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 2)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tPodepnij gotowy folder" << endl;
		if (position == 2)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 3)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tDodaj fiszki" << endl;
		if (position == 3)
		{
			SetConsoleTextAttribute(hOut, 15);
		}

		if (position == 4)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout << "\tUsun fiszki" << endl;
		if (position == 4)
		{
			SetConsoleTextAttribute(hOut, 15);
		}


		znak = _getch();

		if (znak == 80 && position < 4)
			position++;
		else if (znak == 72 && position > 1)
			position--;

		system("cls");
	}

	switch (position)
	{
	case 1:
	{
		//Tworzenie nowych plikow z fiszkami
		new_file();
		break;
	}

	case 2:
	{
		//Podpinanie gotowych plikow z fiszkami
		add_file();

		break;
	}

	case 3:
	{
		//Dodawanie nowych fiszek do gotowych plikow
		add_flashcards();

		break;
	}

	case 4:
	{
		//Usuwanie nazw plikow z pliku files.txt
		delete_file();

		break;
	}

	}


	system("cls");

}

void new_file()
{
	string file;
	cout << "Podaj nazwe pliku :";
	cin >> file;

	file = txtfile(file);			//Poprawa nazwy pliku poprzez dodanie .txt

	//cout << file;

	is_exist(file);

	if (!is_exist(file))
	{
		create_new_flashcard(file);
	}
	else
	{
		cout << "Podany plik juz istnieje nie mozna utworzyc nowego\n";
	}


	system("PAUSE");
}

	//Sprawdzenie czy w nazwie pliku istnieje koncowka .txt

string txtfile(string file_name)
{
	string nazwa = file_name;
	int length = nazwa.length();
	if (length <= 4)
	{
		file_name += ".txt";
		return file_name;
	}

	if (file_name[length - 4] != '.' || file_name[length - 3] != 't' || file_name[length - 2] != 'x' || file_name[length - 1] != 't')
	{
		file_name += ".txt";
	}

	system("cls");
	return file_name;
}

	//Sprawdzenie czy wybrany plik istnieje

bool is_exist(string file)
{
	fstream plik;
	plik.open(file, ios::in | ios::_Nocreate);  // wa�ne, by nie tworzy� pliku, je�li nie istnieje
	if (plik.is_open())
	{
		plik.close();
		return true;
	}
	plik.close();
	return false;
}

	//Tworzenie nowego pliku z fiszkami

void create_new_flashcard(string file)
{
	int amount_of_flashcards;

	cout << "Podaj liczbe slow";
	cin >> amount_of_flashcards;

	string* flash_p = new string[amount_of_flashcards*2];

	for (int i = 0; i < amount_of_flashcards*2; i += 2)
	{
		cout << "Podaj angielske slowo\n";
		cin >> flash_p[i];
		cout << "Podaj polskie slowo\n";
		cin >> flash_p[i+1];
	}

	fstream new_file;

	new_file.open(file, ios::out);
	if (new_file.good() == true)
	{
		new_file << amount_of_flashcards << endl;
		for (int i = 0; i < amount_of_flashcards*2; i+=2)
		{
			new_file << flash_p[i] << " " << flash_p[i + 1] << endl;
		}
		new_file.close();

		fstream add_file;
		add_file.open("files.txt", ios::out | ios::app);
		if (add_file.good())
		{
			add_file <<endl<< file;
		}
		else
		{
			cout << "Blad przy dopisie do bazy plikow";
		}
		add_file.close();

	}
	else
	{
		cout << "Blad przy tworzeniu pliku";
	}
}

void add_file()
{
	string file;
	cout << "Podaj nazwe pliku :";
	cin >> file;

	file = txtfile(file);

	//cout << file;
	//system("pause");

	if(is_exist(file))
	{
		if (!is_exist_inside_files(file))
		{
			fstream add_file;
			add_file.open("files.txt", ios::out | ios::app);
			if (add_file.good())
			{
				add_file << endl << file;
				cout << "Plik podpiety prawidlowo\n";
				system("pause");
			}
			else
			{
				cout << "Blad przy dopisie do bazy plikow";
			}
			add_file.close();
		}
		else
		{
			cout << "Ten plik jest juz podpiety\nNie mozna ponownie zaladowac pliku\n";
		}
	}
	else
	{
		cout << "Podany plik nie istnieje\nNie mozna podpiac fiszek\n";
	}



	system("pause");
}

bool is_exist_inside_files(string file)
{
	fstream plik;
	string line;

	plik.open("files.txt");

	if (plik.good())
	{
		while (getline(plik, line))
		{
			if (line == file)
			{
				plik.close();
				return true;
			}
		}
	}
	else
	{
		cout << "Blad pliku";
		plik.close();
		return false;
	}
	plik.close();

	return false;
}

int add_flashcards()
{
	string polish_word, english_word;

	string file;
	cout << "Podaj nazwe pliku :";
	cin >> file;

	file = txtfile(file);

	if (!is_exist(file))
	{
		cout << "Podany plik nie istnieje\n";
		return -1;
	}

	int amount_of_new_flashcards;			//Liczba nowych slow

	cout << "Podaj liczbe slow";
	cin >> amount_of_new_flashcards;

	int amount_of_old_flashcards = amount_of_words(file);		//Liczba starych slow

	string* array_words = new string[amount_of_old_flashcards*2];

	fstream plik;
	plik.open(file);
	if (plik.good())
	{
		string line;
		string polish_word;

		getline(plik, line);
		for (int i = 0; i < amount_of_old_flashcards*2; i+=2)
		{
			getline(plik, line);
			stringstream load(line);
			load >> polish_word;
			array_words[i] = polish_word;
			load >> polish_word;
			array_words[i+1] = polish_word;
			
		}
	}
	plik.close();

	fstream new_file;

	new_file.open(file, ios::out);
	if (new_file.good() == true)
	{
		new_file << amount_of_old_flashcards + amount_of_new_flashcards << endl;
		for (int i = 0; i < amount_of_old_flashcards * 2; i += 2)
		{
			new_file << array_words[i] << " " << array_words[i + 1] << endl;
		}

		delete[] array_words;								//Usuniecie z pamieci tablicy
		//array_words = "NULL";

		for (int i = 0; i < amount_of_new_flashcards; i++)
		{
			cout << "Podaj slowo po angielsku";
			cin >> english_word;
			english_word = to_lower(english_word);
			cout << "Podaj slowo po polsku";
			cin >> polish_word;
			polish_word = to_lower(polish_word);
			new_file << english_word << " " << polish_word << endl;
		}

		new_file.close();

	

	}
	else
	{
		cout << "Blad przy otworzeniu pliku";
		return -1;
	}

	return 1;
}

int delete_file()
{
	string file;
	cout << "Podaj nazwe pliku :";
	cin >> file;

	file = txtfile(file);

	if (!is_exist_inside_files(file))
	{
		cout << "Podany plik nie zostal podpiety\n";
		return -1;
	}

	int amount_files = amount_of_files();			//Zmienna do przechowywania liczby plikow wewnatrz funkcji

	string* array_files = new string[amount_files];

	fstream plik;
	string line;

		//Wczytanie wyrazow z pliku

	plik.open("files.txt");
	if (plik.good())
	{
		for (int i = 0;i<amount_files;i++)
		{
			getline(plik, line);
			array_files[i] = line;
		}
	}
	else
		return -1;

	plik.close();

		//Zapis wyrazow do pliku bez pliku usunietego

	fstream plik2;

	plik2.open("files.txt",ios::out);
	if (plik2.good())
	{
		for (int i = 0; i < amount_files; i++)
		{
			if (i != 0 && file != array_files[i])
				plik2 << endl;


			if (file != array_files[i])
				plik2 << array_files[i];
		}
	}
	else
		return -1;

	plik2.close();

	delete[] array_files;

	cout << "\nPomyslnie usunieto plik " << file << endl;

	system("pause");

	return 1;

}

