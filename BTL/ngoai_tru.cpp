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

void ds_not(Ds* &ds_not){
    int x, i = 0;
    BN *nt;
    Ds *dt = NULL, *dv = NULL;
    ifstream filein;
    lay_du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1){

        filein.open("benh_nhan_not.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++){
            nt = new NOT;
            filein >> (NOT*&) nt;
            last_list(ds_not, nt);
        } 
        filein.close(); 
    }
    else if (x == 2){
        do{
            nt = new NOT;
            cout << "\n\tBenh nhan ngoai tru thu " << i + 1 << endl;
            cin >> (NOT*&) nt;
            ds_dthuoc(dt);
            ds_dvu(dv);
            nt -> setDs_dt(dt);
            nt -> setDs_dv(dv);
            last_list(ds_not, nt);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
    }
    else return;
    
}