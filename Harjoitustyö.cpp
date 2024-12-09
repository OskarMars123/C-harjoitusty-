#include <iostream>   // Lisätään, jotta voi käyttää esimerkiksi cin, cout, endl
#include <cstdlib>    // Lisätään, jotta voi käyttää random funktioita
#include <ctime>      // Lisätään, jotta voidaan generoida random-lukuja


using namespace std;










bool onkohuonevapaa(int huonenumero, bool huoneet[]) {     // Ensimmäinen aliohjelma. Käytetään, kun halutaan tietää onko joku huone vapaana
	return !huoneet[huonenumero];
}








void tarkistvarausnumerolla(int varausnumero) {    // Toinen aliohjelma. Käytetään, kun halutaan tarkistaa varausnumerolla onko joku huone vapaa tai varattu
	
	if (varausnumero == 10001) {
		cout << "Pekka Haavisto on varannut huoneen 1";  // Jos kytytään onko joku varannut varausnumerolla 10001, tulostaa ohjelam tämän tekstin 
	}
	else if (varausnumero == 10002) {
		cout << "Alex Stubb on varannut huoneen 2"; // Jos kytytään onko joku varannut varausnumerolla 10002, tulostaa ohjelam tämän tekstin 

	}
	else if (varausnumero == 10003) {
		cout << "Sanna Marin on varannut huoneen 3"; // Jos kytytään onko joku varannut varausnumerolla 10003, tulostaa ohjelam tämän tekstin 
	}

	else {
		cout << "Ei löydy tollaisella varausnumerolla mitään";   // jos syötetään mitä vaan muuta, tulee tämä teksti näytölle
	}
	
}












int main() {     // Aloittaa pääohjelman

	setlocale(LC_ALL, "FI_fi");  // Sallii ääkköset

	

	cout << "Hotellin Varausohjelma" << endl;  // Printaa tekstin näytölle
	cout << "Mitä seuraavista asioista haluat tehdä? " << endl << endl; 
	cout << "1. Varaa huone " << endl << endl << "2. Sammuta ohjelma " << endl << endl <<"3. Tarkistetaan huoneen vapautta " << endl << endl << "4. Tarkistetaan varausnumerolla " << endl << endl; // Printaa tekstin näytölle, jokaisen vaihtoehdon väissä yksi tyhjä  rivi



	int valinta= 0; // Nollaa ensin valinnan

	
	
	while (valinta != 1 && valinta != 2 && valinta !=3 && valinta !=4) { // While- luuppi. Tarkoitus ova jatkaa kysymistä kunnes syöte on oikea
		
		cout << "Valitse numero 1, 2, 3 tai 4 " << endl;
		cin >> valinta; // Käyttäjä tekee valinnan


		if (cin.fail()) {  // Jos käyttäjä ei syötä numeroa, niin ohjelma hylkää ja kysyys uudestaan
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virheellinen syöte, kokeile uudestaan." << endl;
			valinta = 0; // Valinta nollataan jälleen kerran
			continue;
		}

		if (valinta == 1) {
			cout << "Jatketaan varaamiseen " << endl << endl;  // Jos käyttäjä valitsee 1, niin tulee tämä teksti ja ohjelma jatkuu alempana
		}
		
		else if (valinta == 2) {
			cout << "Poistutaan ohjelmasta " << endl; // Jos käyttäjä valitsee 2, niin tulee tämä teksti
			return 0; // Tämä kertoo että ohjelma valmis/ ei jatketa koodia
		}

		else if (valinta == 3) {
			cout << "Tarkistetaan onko huone vapaa " << endl; // jos käyttäjä valitsee 3, niin tulee tämä teksti, joka jatkaa huoneen tarkistukseen
			
			int huonenumero; // huonenumero komento lisätään koodiin
			
			cout << "Anna huoneen numero niin voin takistaa onko vapaa (huonenumerot 1-70)" << endl;
			cin >> huonenumero;  // Käyttäjä syöttää huonenumeron
			
			if (huonenumero < 1 || huonenumero > 70) {  
				cout << "Ei ole tälläistä huonetta"; // Jos käyttäjän syöttämä huone ei ole 1-70 tulee tämä teksti. Eli jos laittaa vaikka kirjaimia tai negatiivisia lukuja
				
				return 0;   // Tämä kertoo että ohjelma valmis/ ei jatketa koodia

			}



			bool huoneet[71] = { false }; // Alustetaan taulukko ja viitataan aliohjelmaan. Kaikki 70 huonetta on tässä kohtaa vapaita
			huoneet[1] = true; // huone 1 on varataan tällä koodilla
			huoneet[2] = true; // huone 2 on varataan tällä koodilla
			huoneet[3] = true; // huone 3 on varataan tällä koodilla
				
			if (onkohuonevapaa(huonenumero, huoneet)) {    // Viitataan aliohjelmaan
				cout << "Huone " << huonenumero << " on vapaa " << endl; // Jos käyttäjän syöttämä huonenumeo on vapaa tulee tämä teksi
			}
			else {
				cout << "Huone " << huonenumero << " on varattu " << endl; // Jos käyttäjän syöttämä huonenumeo on varattu tulee tämä teksi
			}
			
			return 0; // Tämä kertoo että ohjelma valmis/ ei jatketa koodia
		}

		else if (valinta == 4) {
			cout << "Haetaan varausnumerolla ja katsotaan kuka on varaillut " << endl; // Jos Käyttäjä valitsee 4. alkuvalikosta tulee tämä
			
			int varausnumero; // lisätään "varausnumero" komento
			
			cout << "Varausnumero kiitos " << endl;
			cin >> varausnumero;  // Käyttäjä syöttää varausnumeron
			 

			tarkistvarausnumerolla(varausnumero);  // Viitataan aliohjelmaan, jossa tarkistetaan varausnumerolla
		
			return 0; // Tämä kertoo että ohjelma valmis/ ei jatketa koodia
		
		}

		else {
			cout << "Paina joko 1, 2, 3 tai 4 kiitos! " << endl << endl;  // Jos Käyttäjä ei paina alkuvalikossa 1,2,3 tai 4 kysyy ohjelma sen käyttäjältä uudestaan, koska se on while-luupissa
		}

	}  // Alkuvalikko osio valmis. Seuraavaksi jatkuu uuden asiakkaan tietojen kirjaaminen

	





	cout << "ASIAKKAAN TIEDOT: " << endl << endl; // Otsikko uudelle osiolle

	string Nimi; // Asiakkaan nimi string-muodossa tehtävänannon mukaan
	int varausnumero, huonenumero1,huonenumero2, yon_hinta, yomaara, huonemaara;  // Lisätään nämä kaikki komennot


	srand(time(0)); // Lisätään random funktio


	yon_hinta = 80 + rand() % 21;  // Määritellään yön hinnaksi satunnaisluku väliltä 80-100
	varausnumero = 10004 + rand() % 89996; // määriteellään varausnumeroksi satunnaisluku 10004-99999 tehtävänannon mukaan. Varausnumero 10001,10002 ja 10003 ovat jo käytössä
	huonenumero1 = 4 + rand() % 67; // Määritellään huoneen satunnaisluvat 4-70 välillä, koska 1,2,3 ovat jo käytössä
	
	do {
		huonenumero2 = 4 + rand() % 67; // Määritellään huoneen satunnaisluku 4-70 välillä, koska 1,2,3 ovat jo käytössä
	} while (huonenumero2 == huonenumero1);        // Varmisteaan while-luupilla, että huonenumero 1 ja 2 eivät generoidu samoina



	cout << "Asiakkaan nimi? " << endl; // Kysytään asiakkaan nimi
	cin >> Nimi;  // Käyttäjä syöttää asiakkaan nimen


	do {
	    cout << "Kuinka monta huonetta haaluat varata (Max 2) " << endl; // Kysytään kuinka monta huonetta halutaan varata
		cin >> huonemaara; //Käyttäjä syöttää määrän

			if (huonemaara < 1 || huonemaara > 2) {
				cout << "2 huonetta on maksimi kokeile uudestaan " << endl; // Jos syöte ei ole 1 tai 2 tulee tämä näytölle
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Sallitaan vaan numerot
			}
		

	} while (huonemaara < 1 || huonemaara > 2);  //While-luuppi

	do {
		cout << "Kunka monta yötä ? Yön hinta vaihtelee 80-100€ " << endl << endl;  // Kun käyttäjä on syöttäny oikeat arvot ilmestyy tämä teksti
			cin >> yomaara; // Käyttäjä syöttää yömäärän
		

		if (yomaara < 1) {
			cout << "kokeile uusiksi " << endl;  // Jos yömäärä on alle 1, tulee tämä teksti
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Sallitaan vaan numerot

		}

	} while (yomaara < 1); // while- luuppi jos syöte on oikea. Käynnistää loppusosan ohjelmasta







	cout << "Loppusummasi on " << huonemaara * yomaara * yon_hinta << "e Kiitos " << endl << endl;  // Loppusumma määritellään

	if (huonemaara == 2) {
		cout << "Huoneen numerot ovat " << huonenumero1 << ", " << huonenumero2 << endl << endl; // Jos huonemäärä on 2 niin ohjelma ilmoittaa 2 huonenumeroa
	}

	else{
		cout << "Huoneen numero on " << huonenumero1 << endl << endl;  // Jos huonemäärä on 1, niin ohjelma ilmoittaa yhden huonenumeron
	}

	cout << "Varausnumero on " << varausnumero << endl << endl;  // Ohjelma ilmoittaa varausnumeron
	cout << "Kiitos " << Nimi << endl;   // Ohjelma kiittaa asiakasta



	

	return 0; // Tämä kertoo että ohjelma valmis/ ei jatketa koodia
}  //Ohjelma valmis