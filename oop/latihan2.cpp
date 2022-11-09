#include <iostream>
#include <string>
using namespace std;

class MyClass{        
        public:
        string MHSname;
		
		public:
        void printname(){
            cout <<  MHSname;
        }
        MyClass(string nama){
            MHSname = nama;
        }
};
    
int main(){
    MyClass Mhs("Ahnaf");
    Mhs.printname();
}


