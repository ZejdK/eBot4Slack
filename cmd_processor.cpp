#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>

inline bool Slovo(char s) { return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')                          ; }
inline bool Broj (char s) { return                                                     (s >= '0' && s <= '9'); }
inline bool Arg  (char s) { return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9'); }

template <typename Tip>
std::list<Tip> Indeksiraj(Tip s, Tip k) // s - start; k - kraj; p - pocetak
{
	std::list<Tip> indeksi;
	for(Tip p = s; s != k; s++)
		if((  Slovo(*s) && (s == p || !Arg(*(s - 1))) ))
			indeksi.push_back(s);
	return indeksi;
}

template <typename Tip, typename Kontejner>
bool Ima(Tip sta, Kontejner gdjestart, Kontejner gdjekraj)
{
	while(gdjestart != gdjekraj) if(sta == *gdjestart++) return true;
	return false;
}

bool Poredi(std::string::iterator p, std::string::iterator k, const std::string &cmd)
{
	auto cmdp = cmd.begin();
	while(cmdp != cmd.end() && (p != k && *p != ' ')) // cmdp = cmd pocetak
		if(*p++ != *cmdp++)
			return false;
	return cmdp == cmd.end() && (p == k || *p == ' ');
}

namespace Komanda
{
	int Saberi(int a, int b) { std::cout << " : ID = <" << a + b << ">\n"; return a + b; }
	const char *nazivi[10] =  { "pisi", "citaj", "testiraj", "nogiraj", "povecaj", "saberi", "ocisti", "banuj", "sutni", "oklagija" };
	int (*funkcije[10])(int, int) = { Saberi, Saberi, Saberi, Saberi, Saberi, Saberi, Saberi, Saberi, Saberi, Saberi };
}

int main()
{
	std::list<std::string> stringovi; // liste jer zelim garanciju da tip nece biti re-alociran pri promjeni velicine

	for(int i = 0; i < 10; ++i) stringovi.push_back(Komanda::nazivi[i]);

	for(std::string str; std::cout << "$>", std::getline(std::cin, str), str != "q"; std::cout << "\n\n")
	{
		std::cout << "   Uneseno: \"" << str << "\"\n";
		if(!str.size()) continue;

		for(auto a = stringovi.begin(); a != stringovi.end(); a++)
		{
			std::list<std::string::iterator> indeksi = Indeksiraj(str.begin(), str.end()); // Cuvaju se iteratori koji pokazuju na prve znakove 'parametara'/'argumenata'
																						   // Prvi parametar se smatra komandom, parametri koji imaju prvi znak '-' trebaju se smatrati kao opcije
			if(indeksi.size() == 0 && (std::cout << "   Prazno\n", 1))
				break;
			if(Poredi(*(indeksi.begin()), str.end(), *a))
			{
				int udaljenost = std::distance(stringovi.begin(), a);
				Komanda::funkcije[udaljenost](udaljenost, 0);
				std::cout << " : Unos = '" << str << "'\n : Komanda = '" << *a << "'\n";
				std::cout << " : Broj parametara = " << int(indeksi.size()) - 1 << '\n';
				break;
			}
		}
	}
	// void Test1(); Test1(); std::cin.get();
	return 0;
}

/*
template <typename Tip>
struct Komanda
{
	std::string naziv;
	int broj_param;
	Tipovi tipovi_parametara; // ???
	std::function<Tip> funkcija;
public:
	Komanda(const std::string &naziv, const std::function<Tip> &Tip)
		: naziv(naziv), funkcija(funkcija) {}

	Komanda(const Komanda &  ) = delete;

	Komanda(	  Komanda &&k)
		: naziv(std::move(k.naziv)), funkcija(std::move(k.funkcija)) {}

	std::string        DajNaziv() const { return naziv;    }
	std::function<Tip> DajFunkc() const { return funkcija; }

	// void PromjeniFunkciju() // mora biti istog tipa?

	void Pozovi() { funkcija(???); } // sta ako funkcija baci izuzetak, ili ako vraca nesto sto alocira memoriju?

	??? operator() (Tip parametri???) { return funkcija(parametri???) } // ovo treba da pozove funkciju
};*/

void Test1()
{
	const char *str = "mv this dir"; int str_len = std::strlen(str);

	std::vector<std::string> stringovi;
	stringovi.push_back("ovaj");
	stringovi.push_back("");
	stringovi.push_back("   ");
	stringovi.push_back("  string stringova stringova");
	stringovi.push_back("ljepotan   st ring   ");
	stringovi.push_back("tehnicki svrab");
	stringovi.push_back("poluprecnik    ");
	stringovi.push_back("  polovica");
	stringovi.push_back(" Ovaj string je namjenjen testiranju funkcije koju sam napisao. Trebao bi da");
	stringovi.push_back("bude poprilicno dug, ali nemam ideje sta da pisem, kao i uvijek. Valjda mi moze ");
	stringovi.push_back("posluziti i ovo sto sam do sada napisao.  ");
	stringovi.push_back("^%$&*%&#@!(Samo(*)#&@ovo ..',240972342@#&*( treba da $$%! ..,bude   argument");
	stringovi.push_back("Sem23482Trr Tr3424 333TTuAU d");
	
	std::list<const char *> argumenti = Indeksiraj(str, str + str_len);
	for(const char *p = str; *p; p++) std::cout << (Ima(p, argumenti.begin(), argumenti.end()) ? '|' : ' ');
	std::cout << '\n' << str << "\n------------------------\n";
	
	for(std::string &s : stringovi)
	{
		std::list<std::string::iterator> tmp = Indeksiraj(s.begin(), s.end());
		for(auto p = s.begin(); p != s.end(); p++)
			if(Ima(p, tmp.begin(), tmp.end()))
				std::cout << '|'; else std::cout << ' ';
		std::cout << "\n" << s << ">\n------------------------\n";
	}
}