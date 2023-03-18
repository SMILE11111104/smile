#include "benh_nhan.cpp"

int main(){
    BN d;
    ifstream file("in.txt");
    file >> d;
    file.close();
    
    ofstream file2("out.txt");
    file2 << d;
    file2.close();
    return 0;
}