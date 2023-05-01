#include <iostream>
#include <string>
#include "Header.h"
#include <Windows.h>
#include <fstream>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));
    setlocale(0, "");
    int n;
    std::cout << "Введите количество покемонов: ";
    std::cin >> n;
    Pokemon* pokemons = new Pokemon[n];
    filling(pokemons, n);
    give_anti_type(pokemons, n);
    attacker_filling(pokemons, n);
    print(pokemons, n);
    fight(pokemons, n);
}
