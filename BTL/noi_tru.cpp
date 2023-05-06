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
    is >> (BN*&) a;
    a -> setMhs("NT" + a -> getMhs());
    cout << "\n\tNgay xuat vien" << endl;
    is >> a -> nx;
    is.ignore();
    cout << "Ten khoa: ";
    getline(is, a -> tk);
    cout << "So phong: ";
    is >> a -> sp;
    cout << "So giuong: ";
    is >> a -> sg;
    is.ignore();
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

void ds_nt(Ds* &ds_nt){
    int x, y, i = 0;
    BN *nt;
    Ds *dt, *dv;
    ifstream filein;
    lay_du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1){
        filein.open("benh_nhan_nt.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++){
            nt = new NT;
            init(dt);
            init(dv);
            filein >> (NT*&) nt; 
            ds_dt_file(dt, nt);
            nt -> setDs_dt(dt);
            ds_dv_file(dv, nt);
            nt -> setDs_dv(dv);
            last_list(ds_nt, nt);
        }
        
    }
    else if (x == 2){
        do{
            nt = new NT;
            dt = new Ds;
            dv = new Ds;
            cout << "\n\tBenh nhan noi tru thu " << i + 1 << endl;
            cin >> (NT*&) nt;
            ds_dthuoc(dt);
            ds_dvu(dv);
            nt -> setDs_dt(dt);
            nt -> setDs_dv(dv);
            last_list(ds_nt, nt);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
    }
    else return;
}

