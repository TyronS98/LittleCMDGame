#include <iostream>
#include <windows.h>
#include <string>


class cMaterial {
public:
	int iWoodIncreaser(int iTimes, int iWoodIncreaser, int iWoodCurrent) {
		for (int i = 0; i < iTimes; i++) {
			iWoodCurrent = iWoodCurrent + iWoodIncreaser;
			std::cout << "Holz: " << iWoodCurrent << "\n";
			Sleep(250);
		};
		return iWoodCurrent;
	};
	int iMetallIncreaser(int iTimes, int iMetallIncreaser, int iMetallCurrent) {
		for (int i = 0; i < iTimes; i++) {
			iMetallCurrent = iMetallCurrent + iMetallIncreaser;
			std::cout << "Metall: " << iMetallCurrent << "\n";
			Sleep(500);
		};
		return iMetallCurrent;
	};
	
};

class cUpgrade {
public:
	std::string sAsk() {
		std::string sAnswer;
		std::cout << "Moechten Sie Holz oder Metall upgraden? (bitte *holz* oder *metall* eingeben)\n\n";
		std::cout << "Holz upgrade kostet   = 100 Holz\n" << 
					 "Metall upgrade kostet = 250 Metall\n";
		std::cin >> sAnswer;
		return sAnswer;
	};
};

class cActions {
public:
	std::string sText() {
		std::string sInput;
		std::cout << "Holz oder Metall abbauen? (bitte *holz* oder *metall* eingeben)\n";
		std::cin >> sInput;
		return sInput;
	}
};
void vText() {
	std::cout << "Hallo und wilkommen im Spiel!\n\n";
	Sleep(1500);
	std::cout << "Made by TyronS\n\n";
	Sleep(1500);
	std::cout << "Bitte beachten Sie, dass alle ANTWORTEN kleingeschrieben werden muessen!!!!\n";
	Sleep(2500);
};

int main()
{
	cMaterial material;
	cUpgrade upgrade;
	cActions ressource;
	std::string sAnswer;
	int iWoodValue = 0;
	int iMetallValue = 0;
	int iTimes;
	int iWoodIncreaser = 10;
	int iMetallIncreaser = 5;
	std::string sRessource;
	/*int *pWood,*pMetall,*pTimes;
	pMetall = &iMetallValue;
	pWood = &iWoodValue;
	pTimes = &iTimes;
	std::cout <<"Metall Adresse: "<<pMetall << "\nHolz Adresse: " << pWood << "\nRepeat Time Adress: "<< pTimes << "\n";*/
	vText();
	for (;;) {
		sRessource = ressource.sText();
		std::cout << "\nWie viele Stunden sollen ihre Arbeiter arbeiten? (Bitte als Zahl angeben) : \n";
		std::cin >> iTimes;
		if (iTimes > 0) {
			std::cout << "Sie werden nun " << iTimes << " Stunden arbeiten!\n";
		}
		Sleep(250);
		if (sRessource == "holz") {
			iWoodValue = material.iWoodIncreaser(iTimes, iWoodIncreaser, iWoodValue);
		}
		else if (sRessource == "metall") {
			iMetallValue = material.iMetallIncreaser(iTimes, iMetallIncreaser, iMetallValue);
		}
		std::cout << "\nHolz: " << iWoodValue << "	Metall: " << iMetallValue << "\nHolz Upgrade: +" << iWoodIncreaser <<"	Metall Upgrade: +" << iMetallIncreaser << "\n\n";
		sAnswer = upgrade.sAsk();
		if (sAnswer == "holz" && iWoodValue >= 100) {
			iWoodIncreaser += 10;
			iWoodValue -= 100;
		}
		else if (sAnswer == "metall" && iMetallValue >= 250) {
			iMetallIncreaser += 5;
			iMetallValue -= 250;
		}
		else
			std::cout << "Du hast nicht genuegend Ressourcen!\n";
	};
	
	std::cin.get();
	return 0;
};