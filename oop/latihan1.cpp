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
};
    
int main(){
    MyClass Ahnaf;
    Ahnaf.MHSname = "Ahnaf";
    Ahnaf.printname();
}

