#include <iostream>
#include <string>
#include "Header.h"
#include <iomanip>
#include <ctime>
#include <fstream>
//Normal, Insects, Poisonous, Herbal, Water, Fiery, Earthy, Combat, Stone, Magic, Electric, Mental, Ghostly,
//Draconic, Ice, Flying, Steel, Dark
//Bob1 Water 20 5 5

void filling(struct Pokemon* poki, int count)
{//Name Type HP DEF ATT
	std::ifstream in("date.txt");
	std::string s;
	for (int i = 0; i < count; i++)
	{
		if (in.is_open())
		{
			in >> poki[i].name >> s >> poki[i].hp >> poki[i].def >> poki[i].attack_main;
		}
		poki[i].id = i + 1;
		poki[i].type = str_to_type(s);
	}
}


void print(struct Pokemon* poki, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << poki[i].id << ')' << poki[i].name << "\nТип: " << type_to_str(poki[i].type) <<'\n'
			<< "HP: " << std::setw(2) << poki[i].def << '\n'
			<< "DEF: " << std::setw(2) << poki[i].hp << '\n';
	}
}

void give_anti_type(struct Pokemon* poki, int count)
{
	//n1 - buff n2 - anti
	for (int i = 0; i < count; i++)
	{
		if (poki[i].type == Normal)
		{
			element_type a[] = { Normal};
			element_type b[] = { Combat };
			elem_filling(1, 1, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Insects)
		{
			element_type a[] = { Herbal, Mental, Dark};
			element_type b[] = { Flying, Fiery, Stone };
			elem_filling(3, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Poisonous)
		{
			element_type a[] = { Herbal, Magic};
			element_type b[] = { Earthy, Mental};
			elem_filling(2, 2, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Herbal)
		{
			element_type a[] = { Water, Earthy, Stone};
			element_type b[] = { Flying, Poisonous, Insects, Fiery, Ice};
			elem_filling(3, 5, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Water)
		{
			element_type a[] = { Fiery, Earthy, Stone};
			element_type b[] = { Electric, Herbal };
			elem_filling(3, 2, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Fiery)
		{
			element_type a[] = { Steel, Insects, Ice, Herbal };
			element_type b[] = {Earthy, Stone, Water };
			elem_filling(4, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Earthy)
		{
			element_type a[] = { Fiery, Electric, Poisonous, Stone, Steel};
			element_type b[] = { Water, Herbal, Ice};
			elem_filling(5, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Combat)
		{
			element_type a[] = { Normal};
			element_type b[] = { Flying, Mental, Magic};
			elem_filling(1, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Stone)
		{
			element_type a[] = { Fiery, Ice, Flying, Insects};
			element_type b[] = { Water, Herbal, Combat, Earthy, Steel };
			elem_filling(4, 5, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Magic)
		{
			element_type a[] = { Combat, Draconic, Dark};
			element_type b[] = { Poisonous, Steel };
			elem_filling(3, 2, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Electric)
		{
			element_type a[] = { Water, Flying};
			element_type b[] = { Earthy, Herbal, Steel, Draconic };
			elem_filling(2, 4, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Mental)
		{
			element_type a[] = { Combat, Poisonous};
			element_type b[] = { Insects, Ghostly, Dark};
			elem_filling(2, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Ghostly)
		{
			element_type a[] = { Mental, Ghostly};
			element_type b[] = { Ghostly, Dark};
			elem_filling(2, 2, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Draconic)
		{
			element_type a[] = { Draconic};
			element_type b[] = { Ice, Draconic, Magic};
			elem_filling(1, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Ice)
		{
			element_type a[] = { Herbal, Earthy, Flying, Draconic };
			element_type b[] = { Fiery, Combat, Stone, Steel };
			elem_filling(4, 4, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Flying)
		{
			element_type a[] = { Herbal, Combat, Insects };
			element_type b[] = { Electric, Ice, Stone };
			elem_filling(3, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Steel)
		{
			element_type a[] = { Magic, Ice, Stone };
			element_type b[] = { Combat, Fiery, Earthy};
			elem_filling(3, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
		if (poki[i].type == Dark)
		{
			element_type a[] = { Mental, Ghostly};
			element_type b[] = { Combat, Magic, Insects};
			elem_filling(2, 3, poki[i].buff_type, poki[i].anti_type, a, b, poki[i]);
		}
	}
}
void attacker_filling(struct Pokemon* poki, int count)
{
	for (int i = 0; i < count; i++)
	{
		poki[i].attack[0].attack_name = 'K';
		poki[i].attack[1].attack_name = 'H';
		poki[i].attack[2].attack_name = 'S';
		poki[i].attack[0].attack_damage = poki[i].attack_main + 2;
		poki[i].attack[1].attack_damage = poki[i].attack_main;
		poki[i].attack[2].attack_damage = poki[i].attack_main + 5;
	}
}
void elem_filling(int n1, int n2, element_type*& m1, element_type*& m2, element_type a[], element_type b[], Pokemon& pok)
{
	pok.buff_counter = n1;
	pok.anti_counter = n2;
	element_type* mm1 = new element_type[n1];
	element_type* mm2 = new element_type[n2];
	for (int i = 0; i < n1; i++)
		mm1[i] = a[i];
	for (int i = 0; i < n2; i++)
		mm2[i] = b[i];
	m1 = mm1;
	m2 = mm2;
}
element_type str_to_type(std::string s)
{
	element_type a[18] = { Normal, Insects, Poisonous, Herbal, Water, Fiery, Earthy, Combat, Stone, Magic, Electric, Mental, Ghostly,
		Draconic, Ice, Flying, Steel, Dark };
	std::string str[18] = { "Normal", "Insects", "Poisonous", "Herbal", "Water", "Fiery", "Earthy", "Combat", "Stone",
		"Magic", "Electric", "Mental", "Ghostly", "Draconic", "Ice", "Flying", "Steel", "Dark" };
	for (int i = 0; i < 18; i++)
	{
		if (str[i] == s) return a[i];
	}
}
std::string type_to_str(element_type s)
{
	element_type a[18] = { Normal, Insects, Poisonous, Herbal, Water, Fiery, Earthy, Combat, Stone, Magic, Electric, Mental, Ghostly,
		Draconic, Ice, Flying, Steel, Dark };
	std::string str[18] = { "Normal", "Insects", "Poisonous", "Herbal", "Water", "Fiery", "Earthy", "Combat", "Stone",
		"Magic", "Electric", "Mental", "Ghostly", "Draconic", "Ice", "Flying", "Steel", "Dark" };
	for (int i = 0; i < 18; i++)
	{
		if (a[i] == s) return str[i];
	}
}
void fight(struct Pokemon* poki, int n)
{
	int id1, id2, random;
	int flag1 = 0, flag2 = 0, flag = 0;
	float damage_multi_buff = 1.2, damage_multi_debuff = 0.8;
	char move;
	Pokemon player1, player2;
	std::cout << "\nВыберите ID 2-ух покемонов для боя\n";
	std::cout << "\n===Первый покемон===\n";
	correct_cin(id1, n);
	std::cout << "\n===Вторый покемон===\n";
	correct_cin(id2, n);
	player1 = poki[id1 - 1];
	player2 = poki[id2 - 1];
	for (int i = 0; i < player2.buff_counter; i++)
	{
		if (player1.type == player2.buff_type[i])
		{
			flag2 = 1;
			break;
		}
	}
	for (int i = 0; i < player2.anti_counter; i++)
	{
		if (player1.type == player2.anti_type[i])
		{
			flag2 = 2;
			break;
		}
	}
	for (int i = 0; i < player1.buff_counter; i++)
	{
		if (player2.type == player1.buff_type[i])
		{
			flag1 = 1;
			break;
		}
	}
	for (int i = 0; i < player1.anti_counter; i++)
	{
		if (player2.type == player1.anti_type[i])
		{
			flag1 = 2;
			break;
		}
	}
	if (flag2 == 1) player2.attack[2].attack_damage *= damage_multi_buff;
	else if (flag2 == 2) player2.attack[2].attack_damage *= damage_multi_debuff;
	if (flag1 == 1) player1.attack[2].attack_damage *= damage_multi_buff;
	else if (flag1 == 2) player1.attack[2].attack_damage *= damage_multi_debuff;

	if (flag1 < flag2) flag = 1;
	else if (flag2 < flag1) flag = 2;
	random = rand() % 2;// кто ходит первый
	std::cout << "\n====================================";
	std::cout << "\nХарактеристики покемонов на этот бой\n";
	std::cout << "====================================\n";
	pokemonki_vs(player1, player2, flag);
	std::cout << "Первый покемон\n";
	print_1(player1);
	std::cout << "\nВторый покемон\n";
	print_1(player2);
	std::cout << "\nДа начнётся бой!\n";
	while (player2.hp * player1.hp > 0)
	{
		std::cout << "\nХодит " << random + 1 << " игрок: \n";
		std::cout << "Выберите действие: \n";
		if (random == 0)
		{
			std::cout << "-Атака ногой: " << player1.attack[0].attack_name
				<< "\n-Атака рукой : " << player1.attack[1].attack_name << "\n-Атака способностью : " << player1.attack[2].attack_name << "\n";
			std::cin >> move;
			switch (move)
			{
			case 'K':
			{
				player2.hp -= player1.attack[0].attack_damage;
				std::cout << "1-ый игрок бьет ногой!\n";
				break;
			}
			case 'H':
			{
				player2.hp -= player1.attack[1].attack_damage;
				std::cout << "1-ый игрок бьет рукой!\n";
				break;
			}
			case 'S':
			{
				player2.hp -= player1.attack[2].attack_damage;
				std::cout << "1-ый игрок использует способность!\n";
				break;
			}
			default: continue;
			}
			std::cout << "\nЗдоровье " << 1 << "-ого игрока: " << player1.hp << '\n';
			std::cout << "Здоровье " << 2 << "-ого игрока: " << player2.hp << '\n';
			random = (random + 1) % 2;
		}
		else if (random == 1)
		{
			std::cout << "-Атака ногой: " << player2.attack[0].attack_name
				<< "\n-Атака рукой: " << player2.attack[1].attack_name << "\n-Атака способностью: " << player2.attack[2].attack_name << "\n";
			std::cin >> move;
			switch (move)
			{
			case 'K':
			{
				player1.hp -= player2.attack[0].attack_damage;
				std::cout << "2-ой игрок бьет ногой!\n";
				break;
			}
			case 'H':
			{
				player1.hp -= player2.attack[1].attack_damage;
				std::cout << "2-ой игрок бьет рукой!\n";
				break;
			}
			case 'S':
			{
				player1.hp -= player2.attack[2].attack_damage;
				std::cout << "2-ой игрок использует способность!\n";
				break;
			}
			default: continue;
			}
			std::cout << "\nЗдоровье " << 1 << "-ого игрока: " << player1.hp << '\n';
			std::cout << "Здоровье " << 2 << "-ого игрока: " << player2.hp << '\n';
			random = (random + 1) % 2;
		}
	}
	if (player2.hp < 0) std::cout << "\nПобедил 1-ый игрок!\n";
	else std::cout << "\nПобедил 2-ой игрок!\n";
}
void print_1(Pokemon pokis)
{
	std::cout << "ID: " << pokis.id << "\nИмя: " << pokis.name << "\nТип: " << type_to_str(pokis.type)
		<< "\nHP: " << pokis.hp << "\nDef: " << pokis.def << '\n' << "Атака ногой: " << pokis.attack[0].attack_damage
		<< " || Атака рукой: " << pokis.attack[1].attack_damage << " || Атака способностью: " << pokis.attack[2].attack_damage << '\n';
}
void pokemonki_vs(Pokemon poki1, Pokemon poki2, int flag)
{
	if (flag == 2)
	{
		std::cout << '\n' << type_to_str(poki2.type) << " сильнее против " << type_to_str(poki1.type)
			<< "\nУрон 2-ого покемона повышен на x1.2\nУрон 1-ого покемона понижен на x0.8\n";
	}
	else if (flag == 1)
	{
		std::cout << '\n' << type_to_str(poki1.type) << " сильнее против " << type_to_str(poki2.type)
			<< "\nУрон 1-ого покемона повышен на x1.2\nУрон 2-ого покемона понижен на x0.8\n";
	}
}
void correct_cin(int& a, int n)
{
	while (a < 1 || a > n)
	{
		std::cout << "Введите id покемона от " << 1 << " до " << n << ':';
		std::cin >> a;
	}
}