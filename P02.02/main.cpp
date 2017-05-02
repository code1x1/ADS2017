
#include<iostream>
#include<string>
using namespace std;

void print_menu() {
	cout << "\n=====================================\n";
	cout << "Person Analyzer v19.84, by George Orwell\n";
	cout << "=====================================\n";
	cout << "1) Datensatz einfuegen, manuell\n";
	cout << "2) Datensatz einfuegen, CSV Datei\n";
	cout << "3) Datensatz loeschen\n";
	cout << "4) Suchen\n";
	cout << "5) Datenstruktur anzeigen\n";
}

int main()
{

	int eingabe = 0;
	while (true)
	{
		print_menu();
		// Nutzereingabe
		cout << "?> ";
		cin >> eingabe;
		cin.ignore();


		if (eingabe == 1) {
			std::string name;
			int alter, plz;
			double einkommen;
			cout << "+ Bitte geben Sie die den Datensatz ein\n";
			cout << "Name ?> ";
			getline(cin, name);
			cout << "Alter ?> ";
			cin >> alter;
			cout << "Einkommen ?> ";
			cin >> einkommen;
			cout << "PLZ ?> ";
			cin >> plz;

			// TODO: TreeNode in Tree einfügen

			cout << "+ Ihr Datensatz wurde eingefuegt.\n";

		}
		else if (eingabe == 2) {
			
			// TODO: TreeNodes ueber CSV import erstellen und in Tree einfuegen
			
			cout << "+ CSV Datensaetze wurde eingefuegt.\n";

		}
		else if (eingabe == 3) {

			cout << "+ Bitte geben Sie den zu loeschenden Datensatz an.\n";

			// TODO: Datensatz loeschen

			cout << "+ Datensatz wurde geloescht.\n";

		}
		else if (eingabe == 4) {
			std::string name;
			cout << "+ Bitte geben Sie den zu suchenden Datensatz an.\n";
			cout << "Name ?>";
			getline(cin, name);
			// TODO: Suchen

			cout << "+ Fundstellen:\n";

		}
		else if (eingabe == 5) {

			cout << "ID | Name \t| Alter | Einkommen | PLZ | Pos\n" 
				 << "---+------------+-------+-----------+-------+-------\n";
			// TODO: Tree in Preorder ausgeben
			// Tree.preorder();

		}
	}


	return 0;
}