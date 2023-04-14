#include "person.cpp"

class BS : public PS{
    private:
        string ck;
        int sp;
        float bl;
    public:
        BS(){}
        BS(string ck, int sp, float bl);
        ~BS(){}
        
        friend istream& operator>>(istream &is, BS* a);

        friend ostream& operator<<(ostream &os, BS* a);

        void setCk(string ck);
        string getCk();

        void setSp(int sp);
        int getSp();

        void setBl(float bl);
        float getBl();

        float tl();
};


BS :: BS(string ck, int sp, float bl){
    this -> ck = ck;
    this -> sp = sp;
    this -> bl = bl;
}

istream& operator>>(istream &is, BS* a){
    is >> (PS*&) a;
    cout << "Chuyen khoa: "; getline(is, a -> ck);
    cout << "Ten phong quan ly: "; is >> a -> sp;
    cout << "Bac luong: "; is >> a -> bl;
    is.ignore();
    return is;
}   

ostream& operator<<(ostream &os, BS* a){
    os << (PS*) a;
    os << '|' << setw(25) << a -> ck;
    os << '|' << setw(15) << a -> sp;
    os << '|' << setw(10) << a -> bl;
    os << '|' << setw(15) << a -> tl() << '|' << endl;
    os << '|' << setfill('=') << setw(172) << '|' << setfill(' ') << endl;
    return os;
} 

void BS :: setCk(string ck){
    this -> ck = ck;
}
string BS :: getCk(){
    return ck;
}

void BS :: setSp(int sp){
    this -> sp = sp;
}
int BS :: getSp(){
    return sp;
}

void BS :: setBl(float bl){
    this -> bl = bl;
}
float BS :: getBl(){
    return bl;
}

float BS :: tl(){
    return bl * 1940;
}