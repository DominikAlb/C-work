//Dominik Albiniak
//2017-02-04
#if __cplusplus > 201103L
#else
#define override
#endif
#include <iostream>
#include <typeinfo>
enum Estanowisko { GornikPrzodowy, Sztygar, Strzalowy, Kierownik};

class Iitem {

public:
	virtual bool CzyMaZezwolenie(Estanowisko prac) = 0;
	/**
	* Metoda oblicza koszt pracy
	* @param Estanowisko  Enum typu stanowiska
	* @return zwraca koszt.
	*/
	virtual int PoliczKoszt(Estanowisko Gornik, int koszt) = 0;
	/**
	* Zwraca nazwe przyrzadu górniczego jako nazwe klasy np: klasa M³ot zwroci napis  "Mlot"
	*/
	virtual std::string pobierzNazwe() = 0;
};

class Stanowisko {
public:
	Stanowisko(Estanowisko typ) {
        if (typ == GornikPrzodowy) {
            SetKoszt(1);
            stanowisko = typ;
        } else if (typ == Sztygar) {
            SetKoszt(3);
            stanowisko = typ;
        } else if (typ == Strzalowy) {
            SetKoszt(5);
            stanowisko = typ;
        } else if (typ == Kierownik) {
            SetKoszt(11);
            stanowisko = typ;
        }
        stanowisko = typ;
	}
	int pobierzkoszt() {
        return _koszt;
	}
	Estanowisko GetStanowisko() {
        return stanowisko;
	}


private:
	int _koszt;
	Estanowisko stanowisko;
	void SetKoszt(int koszt) {
        _koszt = koszt;
	}
};

class Icharacter {

public:

	virtual void UstawStanowisko(Stanowisko stanowisko) = 0;

	virtual void Wyposaz(Iitem *iitem) = 0;

	virtual int policzCalkowityKoszt() = 0;

	virtual Stanowisko pobierzStanowisko() = 0;

	virtual Iitem* pobierzItem() = 0;

protected:
	int  CalkowityKoszt;
	int  BazowyKOszt;
	Icharacter() {BazowyKOszt = 1;};
};
class Mlot : public Iitem {

public:
	/**
	* Dla wsztkich typów Estanowisko zwraca true
	*/
	bool CzyMaZezwolenie(Estanowisko prac) override {
        return true;
	}
	/**
	* Zwraca 1
	*/
	int PoliczKoszt(Estanowisko Gornik, int koszt) override {
        return 1;
	}
	/**
	 * Zwraca napis "Mlot"
	 */
	std::string pobierzNazwe() override {
        return "Mlot";
	}

};

/**
* Kilof dziedziczy po m³otku wiêc te¿ ka¿dy mo¿e go u¿ywaæ
* Koszt = Koszt z parametru + Koszt klasy bazowej (czyli m³otka).
* KIlofa mog¹ u¿ywaæ te same osoby co m³otka
*/
class Kilof : public Mlot {

public:
	int PoliczKoszt(Estanowisko Gornik, int koszt) override {
        return koszt + 1;
	}
	std::string pobierzNazwe() override {
        return "Kilof";
	}
};

class Notes : public Iitem {
	bool CzyMaZezwolenie(Estanowisko prac) override {
        if (prac == Kierownik || prac == Sztygar) {
            return true;
        } else return false;
	}
	int PoliczKoszt(Estanowisko Gornik, int koszt) override {
        return 1;
	}
	std::string pobierzNazwe() override {
        return "Notes";
	}
};
class MaterialWybuchowy {
protected:
	std::string WypiszPodTyp() {
        return "MaterialWybuchowy";
    }
};


/**
* Dynamit implementuje Iitem oraz MaterialWybuchowy
* Koszt =10 mo¿e u¿ywaæ tylko Strza³owy
*/
class Dynamit : public Iitem, MaterialWybuchowy {
	bool CzyMaZezwolenie(Estanowisko prac) override {
        if (prac == Strzalowy) {
            return true;
        } else return false;
	}
	int PoliczKoszt(Estanowisko Gornik, int koszt) override {
        return 10;
	}
	std::string pobierzNazwe() override {
        return WypiszPodTyp() + "-Dynamit";
	}
};
class Pracownik :public  Icharacter {

public:
	/**
	* Kosntruktor ustawia CalkowityKoszt = 0; oraz _item na M³ot
	*/
	Pracownik() : _stanowisko(GornikPrzodowy) {
        CalkowityKoszt = 0;
        _item = new Mlot();
	}
	/**
	* Ustawia stanowisko na to z parametru
	* @param Stanowisko  Przekazywany obiekt stanowiska do ustawienia
	*/
	void UstawStanowisko(Stanowisko stanowisko) override {
        _stanowisko = stanowisko;
	}

	/**
	* za pomoc¹ metody z klasy Iitem o nazwie CzyMaZezwolenie sprawdza czy pracownik mo¿e posiadaæ dany przedmiot
	* ze wzglêdu na stanowisko.
	* Jak nie mo¿e ma wypisaæ std::cout << "BRAK-ZEZWOLENIA" << endl;
	* @param Iitem * WskaŸnik do narzedzia
	*/
	void Wyposaz(Iitem *iitem) override {
        if (!(iitem->CzyMaZezwolenie(_stanowisko.GetStanowisko()))) {
            std::cout << "BRAK-ZEZWOLENIA\n";
        } else  _item = iitem;
	}


	/**
	* Liczy koszt ca³kowity wedle wzoru _stanowisko.pobierzkoszt +  item.PoliczKosz i go zwraca
	*/
	int policzCalkowityKoszt() override {
        return _stanowisko.pobierzkoszt() + _item->PoliczKoszt(_stanowisko.GetStanowisko(), CalkowityKoszt);
	}
	/**
	* Zwraca stanowisko
	* @return stanowisko
	*/
	Stanowisko pobierzStanowisko() override {
        return _stanowisko;
	}
	/**
	* Zwraca wskaŸnik do itemu
	* @return Iitem*
	*/
	Iitem* pobierzItem() override {
        return _item;
	}

private:
	Iitem *_item;
	Stanowisko _stanowisko;

};
