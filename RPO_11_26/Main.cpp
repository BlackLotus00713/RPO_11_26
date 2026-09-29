#include <iostream>
#include <Windows.h>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8); //  1251
	srand(time(NULL));

	// тип_данных имя_массива [кол_ячеек];

	// rand() % 10 + 1;

	const int row = 3, col = 4;

	int arr[row][col];  // заполнить этот массив рандомными числами через циклы

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10 + 1;
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}

	

	return 0;
}
 

/*
	Типы данных
	
	bool					true/false  0 - false
	char					'+'		43

	short					123		-32768 - 32767 
	unsigned short			123		0 - 65535
	
	int						123456		-2147483648 - 2147483647
	unsigned int			123456		0 - 4294967295
	long long int			123456789	a lot

	float					123.456		    +-(3.4E-38 ... 3.4E+38)
	double					123456.4567		+-(1.7E-308 ... 1.7E+308)
	long double				no comment		+-(3.4E-4932 ... 1.1E+4932)

	Операторы:

	математические: + - * / = ++ -- += -= *= /= % 
	сравнительные: > < >= <= == !=		<=>
	логические:		&& (и)		|| (или)	! (не)

	ТАБУ:	goto		and or not			int имяПеременной


	randomNumber = rand() % 10 + 1;

	std::cout << randomNumber << "\n";


	int choose = 0, hp = 0, number = 0, randomNumber = 0;
	int maxHp = 25, maxHpHard = 25, chance = 30;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\n\t\tИгра \"Угадай число\"\n\n\n";
		std::cout << "1 - Начать игру\n";
		std::cout << "2 - Настройки\n";
		std::cout << "0 - Выход\n\n";
		std::cout << "Ввод: ";
		std::cin >> choose;

		if (choose == 1)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\n\t\tВыберите уровень сложности\n\n\n";
				std::cout << "1 - Лёгкий (1 - 500)\n";
				std::cout << "2 - Сложный (1 - 5000)\n";
				std::cout << "0 - Выход в меню\n\n";
				std::cout << "Ввод: ";
				std::cin >> choose;

				if (choose == 1)
				{
					randomNumber = rand() % 500 + 1;
					hp = maxHp;
					while (true)
					{
						system("cls");
						std::cout << "Кол-во жизней: " << hp << "\n";
						std::cout << "Введите число от 1 до 500: ";
						std::cin >> number;
						if (number == randomNumber)
						{
							std::cout << "Поздравляем! Вы выиграли!\n";
							std::cout << "Осталось жизней: " << hp << "\n";
							system("pause");
							break;
						}
						else if (number < 1 || number > 500)
						{
							std::cout << "\nВы вышли за лимиты!\n";
							Sleep(1500);
						}
						else
						{
							hp--;
							if (hp <= 0)
							{
								std::cout << "Вы проиграли!\nЧисло компьютера было: " << randomNumber << "\n";
								system("pause");
								break;
							}
							std::cout << "\nНе угадали\n";
							std::cout << "Кол-во жизней: " << hp << "\n";
							std::cout << "Взять подсказку за 1 жизнь?\n";
							std::cout << "1 - Да\nЛюбое число - Нет\n\n";
							std::cout << "Ввод: ";
							std::cin >> choose;
							if (choose == 1)
							{
								hp--;
								if (hp <= 0)
								{
									std::cout << "Вы проиграли!\nЧисло компьютера было: " << randomNumber << "\n";
									system("pause");
									break;
								}

								if (number < randomNumber)
								{
									std::cout << "Ваше число меньше числа компьютера\n";
								}
								else
								{
									std::cout << "Ваше число больше числа компьютера\n";
								}
								Sleep(1500);
							}
							else
							{
								std::cout << "Отказ от подсказки\n";
								Sleep(500);
							}
						}
					}
				}
				else if (choose == 2)
				{
					randomNumber = rand() % 5000 + 1;
					hp = maxHpHard;
					while (true)
					{
						system("cls");
						std::cout << "Кол-во жизней: " << hp << "\n";
						std::cout << "Введите число от 1 до 5000: ";
						std::cin >> number;
						if (number == randomNumber)
						{
							std::cout << "Поздравляем! Вы выиграли!\n";
							std::cout << "Осталось жизней: " << hp << "\n";
							system("pause");
							break;
						}
						else if (number < 1 || number > 5000)
						{
							std::cout << "\nВы вышли за лимиты!\n";
							Sleep(1500);
						}
						else
						{
							hp--;
							if (hp <= 0)
							{
								std::cout << "Вы проиграли!\nЧисло компьютера было: " << randomNumber << "\n";
								system("pause");
								break;
							}
							std::cout << "\nНе угадали\n";
							std::cout << "Кол-во жизней: " << hp << "\n";
							std::cout << "Взять подсказку за 1 жизнь?\n";
							std::cout << "1 - Да\nЛюбое число - Нет\n\n";
							std::cout << "Ввод: ";
							std::cin >> choose;
							if (choose == 1)
							{
								if (rand() % 100 + 1 <= chance)
								{
									std::cout << "Бесплатная подсказка\n";
									Sleep(1000);
								}
								else
								{
									hp--;
									if (hp <= 0)
									{
										std::cout << "Вы проиграли!\nЧисло компьютера было: " << randomNumber << "\n";
										system("pause");
										break;
									}
								}


								if (number < randomNumber)
								{
									std::cout << "Ваше число меньше числа компьютера\n";
								}
								else
								{
									std::cout << "Ваше число больше числа компьютера\n";
								}
								Sleep(1500);
							}
							else
							{
								std::cout << "Отказ от подсказки\n";
								Sleep(500);
							}
						}
					}
				}
				else if (choose == 0)
				{
					break;
				}
				else
				{
					std::cout << "\nНекорректный ввод\n\n";
					Sleep(1500);
				}
			}
		}
		else if (choose == 2)
		{
			while (true)
			{
				system("cls");
				std::cout << "\n\n\n\t\tНастройки игры\n\n\n";
				std::cout << "1 - Изменить кол-во жизней для лёгкой игры\n";
				std::cout << "2 - Изменить кол-во жизней для сложной игры\n";
				std::cout << "3 - Изменить вероятность бесплатной подсказки для сложной игры\n";
				std::cout << "0 - Выход в меню\n\n";
				std::cout << "Ввод: ";
				std::cin >> choose;

				if (choose == 1)
				{
					while (true)
					{
						system("cls");
						std::cout << "Введите кол-во жизней для лёгкой игры: ";
						std::cin >> choose;
						if (choose < 1 || choose > 100)
						{
							std::cout << "Доспустимые значения от 1 до 100\n";
							Sleep(2000);
						}
						else
						{
							maxHp = choose;
							std::cout << "Успешно\n";
							Sleep(1000);
							break;
						}
					}
				}
				else if (choose == 2)
				{
					while (true)
					{
						system("cls");
						std::cout << "Введите кол-во жизней для сложной игры: ";
						std::cin >> choose;
						if (choose < 1 || choose > 100)
						{
							std::cout << "Доспустимые значения от 1 до 100\n";
							Sleep(2000);
						}
						else
						{
							maxHpHard = choose;
							std::cout << "Успешно\n";
							Sleep(1000);
							break;
						}
					}
				}
				else if (choose == 3)
				{
					while (true)
					{
						system("cls");
						std::cout << "Введите шанс подсказки для сложной игры: ";
						std::cin >> choose;
						if (choose < 0 || choose > 100)
						{
							std::cout << "Доспустимые значения от 0 до 100\n";
							Sleep(2000);
						}
						else
						{
							chance = choose;
							std::cout << "Успешно\n";
							Sleep(1000);
							break;
						}
					}
				}
				else if (choose == 0)
				{
					break;
				}
				else
				{
					std::cout << "\nНекорректный ввод\n";
					Sleep(1500);
				}
			}
		}
		else if (choose == 0)
		{
			system("cls");
			std::cout << "\n\n\n\t\tСпасибо за игру\n\n\n";
			break;
		}
		else
		{
			std::cout << "\nНекорректный ввод\n\n";
			Sleep(1500);
		}
	}


*/

/*

const int size = 15;

	int arr[size];
	int plus = 0, minus = 0, sum = 0;

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 21 - 10;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			plus += arr[i];
		}
		else
		{
			minus += arr[i];
		}
	}

	std::cout << "\n\n" << plus << "\n" << minus << "\n";

	std::cout << "\n\n";

*/

