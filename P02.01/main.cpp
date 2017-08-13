#include"Ringpuffer.h"
#include"RingNode.h"
#include<iostream>

using namespace std;

void print_menu() {
	cout << "=====================================\n";
	cout << "OneRingToRuleThemAll v0.1, by Sauron Schmidt\n";
	cout << "=====================================\n";
	cout << "1) Backup einfuegen\n";
	cout << "2) Backup suchen\n";
	cout << "3) Alle Backups ausgeben\n";
}

int main() 
{
	Ringpuffer rp;
	print_menu();
	int eingabe = 0;
	rp.addNode("erstes Backup", "echtWichtig1");
	rp.addNode("zweites Backup", "456");
	rp.addNode("drittes Backup", "789");
	rp.addNode("viertes Backup", "007");
	rp.addNode("fuenftes Backup", "1337");
	rp.addNode("sechstes Backup", "0118999");
	rp.addNode("siebtes Backup", "7");
	while (true)
	{
		cout << "?>";
		cin >> eingabe;
		cin.ignore();
		if (eingabe == 1) {
			std::string beschreibung;
			std::string daten;
			cout << "+Neuen Datensatz einfuegen\n";
			cout << "Beschreibung ?> ";
			getline(cin, beschreibung);
			cout << "Daten ?> ";
			getline(cin, daten);
			if(rp.addNode(beschreibung,daten))
				cout << "+Ihr Datensatz wurde hinzugefuegt.\n";
			else
				cout << "+Datensatz wurde ueberschrieben.\n";
		}
		else if (eingabe == 2) {
			std::string suchen;
			cout << "+Nach welchen Daten soll gesucht werden?\n";
			cout << "?> ";
			getline(cin, suchen);
			cin.ignore();
			rp.search(suchen);
		}
		else if (eingabe == 3) {
			rp.print();
		}
	}


	return 0;
}