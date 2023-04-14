#include "benh_nhan.cpp"

class NOT : public BN{
    private:
        string noc;
    public:
        NOT(){}
        NOT(string noc);
        ~NOT(){}

        friend istream& operator>>(istream &is, NOT* a);
        friend ostream& operator<<(ostream &os, NOT* a);

        void setNoc(string noc);
        string getNoc();
};

NOT :: NOT(string noc){
    this -> noc = noc;
}

istream& operator>>(istream &is, NOT* a){
    is >> (BN*&) a;
    is.ignore();
    a -> setMhs("NOT" + a -> getMhs());
    cout << "Noi chuyen: ";
    getline(is, a -> noc);
    return is;
}

ostream& operator<<(ostream &os, NOT* a){
    os << (BN*) a;
    os << '|' << setw(20) << a -> noc << '|' << endl;
    os << '|' << setfill('=') << setw(264) << '|' << setfill(' ') << endl;
    return os;
}

void NOT ::setNoc(string noc){
    this -> noc = noc;
}
string NOT ::getNoc(){
    return noc;
}