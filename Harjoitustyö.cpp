#include <iostream>   // Lis�t��n, jotta voi k�ytt�� esimerkiksi cin, cout, endl
#include <cstdlib>    // Lis�t��n, jotta voi k�ytt�� random funktioita
#include <ctime>      // Lis�t��n, jotta voidaan generoida random-lukuja


using namespace std;










bool onkohuonevapaa(int huonenumero, bool huoneet[]) {     // Ensimm�inen aliohjelma. K�ytet��n, kun halutaan tiet�� onko joku huone vapaana
	return !huoneet[huonenumero];
}








void tarkistvarausnumerolla(int varausnumero) {    // Toinen aliohjelma. K�ytet��n, kun halutaan tarkistaa varausnumerolla onko joku huone vapaa tai varattu
	
	if (varausnumero == 10001) {
		cout << "Pekka Haavisto on varannut huoneen 1";  // Jos kytyt��n onko joku varannut varausnumerolla 10001, tulostaa ohjelam t�m�n tekstin 
	}
	else if (varausnumero == 10002) {
		cout << "Alex Stubb on varannut huoneen 2"; // Jos kytyt��n onko joku varannut varausnumerolla 10002, tulostaa ohjelam t�m�n tekstin 

	}
	else if (varausnumero == 10003) {
		cout << "Sanna Marin on varannut huoneen 3"; // Jos kytyt��n onko joku varannut varausnumerolla 10003, tulostaa ohjelam t�m�n tekstin 
	}

	else {
		cout << "Ei l�ydy tollaisella varausnumerolla mit��n";   // jos sy�tet��n mit� vaan muuta, tulee t�m� teksti n�yt�lle
	}
	
}












int main() {     // Aloittaa p��ohjelman

	setlocale(LC_ALL, "FI_fi");  // Sallii ��kk�set

	

	cout << "Hotellin Varausohjelma" << endl;  // Printaa tekstin n�yt�lle
	cout << "Mit� seuraavista asioista haluat tehd�? " << endl << endl; 
	cout << "1. Varaa huone " << endl << endl << "2. Sammuta ohjelma " << endl << endl <<"3. Tarkistetaan huoneen vapautta " << endl << endl << "4. Tarkistetaan varausnumerolla " << endl << endl; // Printaa tekstin n�yt�lle, jokaisen vaihtoehdon v�iss� yksi tyhj�  rivi



	int valinta= 0; // Nollaa ensin valinnan

	
	
	while (valinta != 1 && valinta != 2 && valinta !=3 && valinta !=4) { // While- luuppi. Tarkoitus ova jatkaa kysymist� kunnes sy�te on oikea
		
		cout << "Valitse numero 1, 2, 3 tai 4 " << endl;
		cin >> valinta; // K�ytt�j� tekee valinnan


		if (cin.fail()) {  // Jos k�ytt�j� ei sy�t� numeroa, niin ohjelma hylk�� ja kysyys uudestaan
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Virheellinen sy�te, kokeile uudestaan." << endl;
			valinta = 0; // Valinta nollataan j�lleen kerran
			continue;
		}

		if (valinta == 1) {
			cout << "Jatketaan varaamiseen " << endl << endl;  // Jos k�ytt�j� valitsee 1, niin tulee t�m� teksti ja ohjelma jatkuu alempana
		}
		
		else if (valinta == 2) {
			cout << "Poistutaan ohjelmasta " << endl; // Jos k�ytt�j� valitsee 2, niin tulee t�m� teksti
			return 0; // T�m� kertoo ett� ohjelma valmis/ ei jatketa koodia
		}

		else if (valinta == 3) {
			cout << "Tarkistetaan onko huone vapaa " << endl; // jos k�ytt�j� valitsee 3, niin tulee t�m� teksti, joka jatkaa huoneen tarkistukseen
			
			int huonenumero; // huonenumero komento lis�t��n koodiin
			
			cout << "Anna huoneen numero niin voin takistaa onko vapaa (huonenumerot 1-70)" << endl;
			cin >> huonenumero;  // K�ytt�j� sy�tt�� huonenumeron
			
			if (huonenumero < 1 || huonenumero > 70) {  
				cout << "Ei ole t�ll�ist� huonetta"; // Jos k�ytt�j�n sy�tt�m� huone ei ole 1-70 tulee t�m� teksti. Eli jos laittaa vaikka kirjaimia tai negatiivisia lukuja
				
				return 0;   // T�m� kertoo ett� ohjelma valmis/ ei jatketa koodia

			}



			bool huoneet[71] = { false }; // Alustetaan taulukko ja viitataan aliohjelmaan. Kaikki 70 huonetta on t�ss� kohtaa vapaita
			huoneet[1] = true; // huone 1 on varataan t�ll� koodilla
			huoneet[2] = true; // huone 2 on varataan t�ll� koodilla
			huoneet[3] = true; // huone 3 on varataan t�ll� koodilla
				
			if (onkohuonevapaa(huonenumero, huoneet)) {    // Viitataan aliohjelmaan
				cout << "Huone " << huonenumero << " on vapaa " << endl; // Jos k�ytt�j�n sy�tt�m� huonenumeo on vapaa tulee t�m� teksi
			}
			else {
				cout << "Huone " << huonenumero << " on varattu " << endl; // Jos k�ytt�j�n sy�tt�m� huonenumeo on varattu tulee t�m� teksi
			}
			
			return 0; // T�m� kertoo ett� ohjelma valmis/ ei jatketa koodia
		}

		else if (valinta == 4) {
			cout << "Haetaan varausnumerolla ja katsotaan kuka on varaillut " << endl; // Jos K�ytt�j� valitsee 4. alkuvalikosta tulee t�m�
			
			int varausnumero; // lis�t��n "varausnumero" komento
			
			cout << "Varausnumero kiitos " << endl;
			cin >> varausnumero;  // K�ytt�j� sy�tt�� varausnumeron
			 

			tarkistvarausnumerolla(varausnumero);  // Viitataan aliohjelmaan, jossa tarkistetaan varausnumerolla
		
			return 0; // T�m� kertoo ett� ohjelma valmis/ ei jatketa koodia
		
		}

		else {
			cout << "Paina joko 1, 2, 3 tai 4 kiitos! " << endl << endl;  // Jos K�ytt�j� ei paina alkuvalikossa 1,2,3 tai 4 kysyy ohjelma sen k�ytt�j�lt� uudestaan, koska se on while-luupissa
		}

	}  // Alkuvalikko osio valmis. Seuraavaksi jatkuu uuden asiakkaan tietojen kirjaaminen

	





	cout << "ASIAKKAAN TIEDOT: " << endl << endl; // Otsikko uudelle osiolle

	string Nimi; // Asiakkaan nimi string-muodossa teht�v�nannon mukaan
	int varausnumero, huonenumero1,huonenumero2, yon_hinta, yomaara, huonemaara;  // Lis�t��n n�m� kaikki komennot


	srand(time(0)); // Lis�t��n random funktio


	yon_hinta = 80 + rand() % 21;  // M��ritell��n y�n hinnaksi satunnaisluku v�lilt� 80-100
	varausnumero = 10004 + rand() % 89996; // m��riteell��n varausnumeroksi satunnaisluku 10004-99999 teht�v�nannon mukaan. Varausnumero 10001,10002 ja 10003 ovat jo k�yt�ss�
	huonenumero1 = 4 + rand() % 67; // M��ritell��n huoneen satunnaisluvat 4-70 v�lill�, koska 1,2,3 ovat jo k�yt�ss�
	
	do {
		huonenumero2 = 4 + rand() % 67; // M��ritell��n huoneen satunnaisluku 4-70 v�lill�, koska 1,2,3 ovat jo k�yt�ss�
	} while (huonenumero2 == huonenumero1);        // Varmisteaan while-luupilla, ett� huonenumero 1 ja 2 eiv�t generoidu samoina



	cout << "Asiakkaan nimi? " << endl; // Kysyt��n asiakkaan nimi
	cin >> Nimi;  // K�ytt�j� sy�tt�� asiakkaan nimen


	do {
	    cout << "Kuinka monta huonetta haaluat varata (Max 2) " << endl; // Kysyt��n kuinka monta huonetta halutaan varata
		cin >> huonemaara; //K�ytt�j� sy�tt�� m��r�n

			if (huonemaara < 1 || huonemaara > 2) {
				cout << "2 huonetta on maksimi kokeile uudestaan " << endl; // Jos sy�te ei ole 1 tai 2 tulee t�m� n�yt�lle
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Sallitaan vaan numerot
			}
		

	} while (huonemaara < 1 || huonemaara > 2);  //While-luuppi

	do {
		cout << "Kunka monta y�t� ? Y�n hinta vaihtelee 80-100� " << endl << endl;  // Kun k�ytt�j� on sy�tt�ny oikeat arvot ilmestyy t�m� teksti
			cin >> yomaara; // K�ytt�j� sy�tt�� y�m��r�n
		

		if (yomaara < 1) {
			cout << "kokeile uusiksi " << endl;  // Jos y�m��r� on alle 1, tulee t�m� teksti
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Sallitaan vaan numerot

		}

	} while (yomaara < 1); // while- luuppi jos sy�te on oikea. K�ynnist�� loppusosan ohjelmasta







	cout << "Loppusummasi on " << huonemaara * yomaara * yon_hinta << "e Kiitos " << endl << endl;  // Loppusumma m��ritell��n

	if (huonemaara == 2) {
		cout << "Huoneen numerot ovat " << huonenumero1 << ", " << huonenumero2 << endl << endl; // Jos huonem��r� on 2 niin ohjelma ilmoittaa 2 huonenumeroa
	}

	else{
		cout << "Huoneen numero on " << huonenumero1 << endl << endl;  // Jos huonem��r� on 1, niin ohjelma ilmoittaa yhden huonenumeron
	}

	cout << "Varausnumero on " << varausnumero << endl << endl;  // Ohjelma ilmoittaa varausnumeron
	cout << "Kiitos " << Nimi << endl;   // Ohjelma kiittaa asiakasta



	

	return 0; // T�m� kertoo ett� ohjelma valmis/ ei jatketa koodia
}  //Ohjelma valmis