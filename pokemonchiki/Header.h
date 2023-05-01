#include <string>
#include <iostream>

enum element_type{Normal, Insects, Poisonous, Herbal, Water, Fiery, Earthy, Combat, Stone, Magic, Electric, Mental, Ghostly,
Draconic, Ice, Flying, Steel, Dark};
struct attack_ch
{
	char attack_name;
	int attack_damage;
};
struct Pokemon
{
	int id, hp, def, buff_counter, anti_counter, attack_main;
	std::string name;
	element_type type, *buff_type, *anti_type;
	attack_ch attack[3];
};

void filling(struct Pokemon* poki, int count);
void print(struct Pokemon* poki, int count);
void print_1(Pokemon poki);
void correct_cin(int& a, int n);
void give_anti_type(struct Pokemon* poki, int count);
void elem_filling(int n1, int n2, element_type*& m1, element_type*& m2, element_type a[], element_type b[], Pokemon& pok);
void attacker_filling(struct Pokemon* poki, int count);
void fight(struct Pokemon* poki, int n);
void pokemonki_vs(Pokemon poki1, Pokemon poki2, int flag);
element_type str_to_type(std::string s);
std::string type_to_str(element_type t);