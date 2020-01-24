#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

int amount_of_words(string file);							//Program liczy wyrazy w pliku
int amount_of_files();										//Program liczy dostepne pliki
int write_words(string file);								//Program wypisuje wszystkie wyrazy 
string choose_file(int nr_file);							//Program podaje nazwe pliku z ktorym uzytkownik chce pracowac
string write_english_word(string file , int nr_line);		//Program zwraca slowo w jezyku angielskim z pobranego pliku
string write_polish_word(string file , int nr_line);		//Program zwraca slowo w jezyku polskim z pobranego pliku
void write_files();											//Program wypisuje dostepne pliki

int random_flashcard(string file);							//Wybiera randomowa liczbe z przedzialu pliku
string to_lower(string text);								//Zmniejsza wszystkie litery slowa
void game_flashcard(string file);							//Modul do gry w fiszki z angielskiego na polski
void game_flashcard2(string file);							//Modul do gry w fiszki z polskiego na angielski


int main()
{
	int menu,nr_line,nr_file;						//Numer wybranej opcji, Numer linii z pliku, Numer pliku do pracy
	string english_word, polish_word;				//Polskie i angielskie slowa
	string file;									//Wybrany plik do pracy
	srand(time(NULL));

	do
	{
		cout << "Wybierz opcje\n1---Ucz sie fiszek\n2---Gra w fiszki z angielskiego na polski\n3---Gra w fiszki z polskiego na angielski\n4---Wyjscie z programu\n";
		cin >> menu;


		switch (menu)
		{
		case 1: //Nauka fiszek
		{
			system("cls");

			write_files();		//Wypisanie wszystkich plikow

			cout << "\nPodaj numer pliku do pracy\n";

			cin >> nr_file;		//Wczytanie numeru pliku do pracy

			file = choose_file(nr_file);

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

			write_files();		//Wypisanie wszystkich plikow

			cout << "\nPodaj numer pliku do pracy\n";

			cin >> nr_file;		//Wczytanie numeru pliku do pracy

			file = choose_file(nr_file);

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
		case 3:	//Nauka losowych fiszek
		{
			system("cls");

			write_files();		//Wypisanie wszystkich plikow

			cout << "\nPodaj numer pliku do pracy\n";

			cin >> nr_file;		//Wczytanie numeru pliku do pracy

			file = choose_file(nr_file);

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
		case 4:	//Wyjscie z programu
		{
			cout << "b";
			break;
			system("cls");
		}
		}
	} while (menu != 2);

	
	system("PAUSE");
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

string choose_file(int nr_file)
{
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
					cout <<endl<< english_word<< " - ";
					cout << polish_word;
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
