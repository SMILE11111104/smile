#include "dich_vu.cpp"

class DT{
    private:
        string tc, cd;
        int dg, sl;
    public:
        DT(){}
        DT(string tc, string cd, int sl, int dg);
        ~DT(){}
        
        friend istream& operator>>(istream &is, DT* &a);

        friend ostream& operator<<(ostream &os, DT* a);

        void setTc(string tc);
        string getTc();

        void setCd(string cd);
        string getCd();

        void setDg(int dg);
        int getDg();

        void setSl(int sl);
        int getSl();

        long int tong_tien();
};

DT :: DT(string tc, string cd, int sl, int dg){
    this -> tc = tc;
    this -> cd = cd;
    this -> sl = sl;
    this -> dg = dg;
}

istream& operator>>(istream &is, DT* &a){
    cout << "Ten thuoc: "; getline(is, a -> tc);
    cout << "Cach dung: "; getline(is, a -> cd);
    cout << "So luong: "; is >> a -> sl;
    cout << "Don gia: "; is >> a -> dg;
    return is;
}

ostream& operator<<(ostream &os, DT* a){
    os << '|' << setw(25) << a -> tc;
    os << '|' << setw(20) << a -> cd;
    os << '|' << setw(10) << a -> sl;
    os << '|' << setw(15) << a -> dg;
    os << '|' << setw(15) << a -> tong_tien() << '|' << endl;
    return os;
}

void DT :: setTc(string tc){
    this -> tc = tc;
}
string DT :: getTc(){
    return tc;
}

void DT :: setCd(string cd){
    this -> cd = cd;
}
string DT :: getCd(){
    return cd;
}

void DT :: setDg(int dg){
    this -> dg = dg;
}
int DT :: getDg(){
    return dg;
}

void DT :: setSl(int sl){
    this -> sl = sl;
}
int DT :: getSl(){
    return sl;
}

long int DT :: tong_tien(){
    return sl * dg;
}

void ds_dthuoc(Ds* &ds_dt){
    int x, i = 0;
    hoi_don_thuoc();
    cin >> x;
    
    init(ds_dt);
    if (x == 0) ds_dt = NULL;
    else{
        DT *dt;
        do{
            dt = new DT; 
            cin.ignore();
            cout << "\n\tThuoc thu " << i + 1 << endl;
            cin >> dt;
            last_list(ds_dt, dt);
            i++;
            hoi_nhap();
            cin >> x;
        }while(x == 1);
    }
}

