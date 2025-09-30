#include <iostream>
#include <vector>
using namespace std;

class Asigurare {
private:
	char* tipAsigurare;
	string numeAsigurat;
	float sumaAsigurata;
	int durata;
	static int nrAsigurari;

public:
	//const implicit
	Asigurare() {
		const char* tipImplicit = "Asigurare generala";
		this->tipAsigurare = new char[strlen(tipImplicit) + 1];
		strcpy_s(this->tipAsigurare, strlen(tipImplicit) + 1, tipImplicit);
		this->numeAsigurat = "Anonim";
		this->sumaAsigurata = 100.0;
		this->durata = 1;
		nrAsigurari++;
	}

	//const cu parametrii
	Asigurare(const char* tipAsigurare, string numeAsigurat, float sumaAsigurata, int durata) {
		this->tipAsigurare = new char[strlen(tipAsigurare) + 1];
		strcpy_s(this->tipAsigurare, strlen(tipAsigurare) + 1, tipAsigurare);
		this->numeAsigurat = numeAsigurat;
		this->sumaAsigurata = sumaAsigurata;
		this->durata = durata;
		nrAsigurari++;
	}

	//constructor de copiere
	Asigurare( const Asigurare& a) {
		this->tipAsigurare = new char[strlen(a.tipAsigurare) + 1];
		strcpy_s(this->tipAsigurare, strlen(a.tipAsigurare) + 1, a.tipAsigurare);
		this->numeAsigurat = a.numeAsigurat;
		this->sumaAsigurata = a.sumaAsigurata;
		this->durata = a.durata;
		nrAsigurari++;
	}

	//operator =
	Asigurare& operator=(const Asigurare& a) {
		if (this != &a) {
			delete[] this->tipAsigurare;
			this->tipAsigurare = new char[strlen(a.tipAsigurare) + 1];
			strcpy_s(this->tipAsigurare, strlen(a.tipAsigurare) + 1, a.tipAsigurare);
			this->numeAsigurat = a.numeAsigurat;
			this->sumaAsigurata = a.sumaAsigurata;
			this->durata = a.durata;
			
		}
		return *this;
	}
	//destructor
	~Asigurare() {
		delete[] this->tipAsigurare;
	}

	//getteri
	const char* getTipAsigurare() const {
		 char* copie = new char[strlen(this->tipAsigurare) + 1];
		strcpy_s(copie, strlen(this->tipAsigurare) + 1, this->tipAsigurare);
		return copie;
	}

	string getNumeAsigurat() const {
		return this->numeAsigurat;
	}

	float getSumaAsigurata() const {
		return this->sumaAsigurata;
	}

	int getDurata() const {
		return this->durata;
	}

	static int getNrAsigurari(){
		return nrAsigurari;
	}

	// setteri
	void setTipAsigurare(const char* tipAsig) {
		if (this->tipAsigurare != nullptr) {
			delete[] this->tipAsigurare;
			this->tipAsigurare = new char[strlen(tipAsig) + 1];
			strcpy_s(this->tipAsigurare, strlen(tipAsig) + 1, tipAsig);
		}
	}

	void setNumeAsigurat(string numeAs) {
		this->numeAsigurat = numeAs;
	}

	void setSumaAsigurata(float s) {
		this->sumaAsigurata = s;
	}

	void setDurata(int d) {
		this->durata = d;
	}

	//operator de afisare
	friend ostream& operator<<(ostream& out, const Asigurare& a) {
		out << "Tip Asigurare: " << a.tipAsigurare << endl <<
			"Nume Asigurat: " << a.numeAsigurat << endl <<
			"Suma asigurata: " << a.sumaAsigurata << endl <<
			"Durata asigurarii" << a.durata << " ani" << endl <<
			"Nr total asigurari" << a.nrAsigurari;
		return out;
	}

	//operator functie
	float operator()(double val) {
		sumaAsigurata *= val;
		return sumaAsigurata;
	}
	// operator double
	operator double() const {
		return sumaAsigurata;
	}

};

//clasa has-a
class ValoareAsigurare {
private:
	vector<pair< Asigurare, float >> asigurari;
public:
	float medieAsigurare(const Asigurare&a) {
		if (asigurari.empty()) {
			return 0;
		}

		float sumaTotala = 0;

		for (const auto& pereche : asigurari) {
			// pereche.first e Asigurare
			sumaTotala += pereche.first.getSumaAsigurata();
		}

		return sumaTotala / asigurari.size();
	}
	void adaugaAsigurare(const Asigurare& a, float valoareEvaluata = 0.0f) {
		asigurari.push_back(make_pair(a, valoareEvaluata));
	}
};

int Asigurare::nrAsigurari = 0;

int main() {
	Asigurare a1;
	Asigurare a2("DEZASTRU NATURAL", "Robert", 10000.0, 4);

	cout << "-------------TEST OPERATOR AFISARE-------------" << endl;
	cout << "Asigurarea a1 este:" << endl << a1 << endl;
	cout << "Asigurarea a2 este:" << endl << a2 << endl;

	a2.setDurata(5);

	cout << "-------------------------------------" << endl;
	cout << "Dupa modificari, a2 a devenit: " << endl << a2 << endl <<
		"deci durata sa s-a schimbat in: " << a2.getDurata() << endl;

	Asigurare a3("ACCIDENT RUTIER", "Raluca", 600, 3);
	
	cout << "--------TEST OPERATOR FUNCTIE------------" << endl;
	cout << "Valoarea asigurarii a3 in euro este: " << a3.getSumaAsigurata() << endl;
	cout << "Valoarea asigurarii a3 in lei este: " << a3(4.65) << endl;


	cout << "-------------TEST DOUBLE-----------" << endl;
	double val = a1;
	cout << val;

}