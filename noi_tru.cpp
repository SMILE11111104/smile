#include "benh_nhan.cpp"

class NT : public BN{
    private:
        NS nx;
        string tk;
        int sp, sg;
    public:
        NT(){}
        NT(NS nx, string tk, int sp, int sg);
        ~NT(){}

        friend istream& operator>>(istream &is, NT* a);
        friend ostream& operator<<(ostream &os, NT* a);

        void setNx(NS nx);
        NS getNx();

        void setTk(string tk);
        string getTk();

        void setSp(int sp);
        int getSp();

        void setSg(int sg);
        int getSg();
};

NT :: NT(NS nx, string tk, int sp, int sg){
    this -> nx = nx;
    this -> tk = tk;
    this -> sp = sp;
    this -> sg = sg;
}

istream& operator>>(istream &is, NT* a){
    is >> (BN*) a;
    cout << "\n\tNgay xuat vien" << endl;
    is >> a -> nx;
    is.ignore();
    cout << "Ten khoa: ";
    getline(is, a -> tk);
    cout << "So phong: ";
    is >> a -> sp;
    cout << "So giuong: ";
    is >> a -> sg;
    return is;
}

ostream& operator<<(ostream &os, NT* a){
    os << (BN*) a;
    os << a -> nx;
    os << '|' << setw(20) << a -> tk;
    os << '|' << setw(10) << a -> sp;
    os << '|' << setw(10) << a -> sg << '|' << endl;
    os << '|' << setfill('=') << setw(300) << '|' << setfill(' ') << endl;
    return os;
}

void NT ::setNx(NS nx){
    this -> nx = nx;
}
NS NT ::getNx(){
    return nx;
}

void NT ::setTk(string tk){
    this -> tk = tk;
}
string NT ::getTk(){
    return tk;
}

void NT ::setSp(int sp){
    this -> sp = sp;
}
int NT ::getSp(){
    return sp;
}

void NT ::setSg(int sg){
    this -> sg = sg;
}
int NT ::getSg(){
    return sg;
}