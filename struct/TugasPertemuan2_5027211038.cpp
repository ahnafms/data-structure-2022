#include <iostream>
#include <Array>
using namespace std;

struct Mobil{
	string nama;
	int jumlah;
	float harga;
	bool ready;
	string color[4];
};

int main(){
	Mobil daftar[20];
	
	for(int i = 0; i<20; i++){
		cout << "Mobil ke - " << i+1 << endl;
		cin >> daftar[i].nama;
		cin >> daftar[i].jumlah;
		cin >> daftar[i].harga;
		cin >> daftar[i].ready;
		for(int j = 0; j<4; j++){
			cin >> daftar[i].color[j];
		}
		cout << endl;
	}
	
	for(int i = 0; i<20; i++){
		cout << "Mobil ke - " << i+1 << endl;
		cout << daftar[i].nama << endl;
		cout << daftar[i].jumlah << endl;
		cout << daftar[i].harga << endl;
		cout << daftar[i].ready << endl;
		for(int j=0; j<4; j++){
			cout << daftar[i].color[j] << endl;
		}
		cout << endl;
	}
}
