#include "don_thuoc.cpp"
#include "dich_vu.cpp"
#include "MENU.cpp"

class BN : protected PS{
    private:
        string mbn, mhs, tsb, cdb;
        long int vp;
        int n, m;
        DT *dt;
        DV *dv;
    public:
        BN(){}
        BN(string ht, string cmt, string gt, string dc, NS ns, string mbn, string mhs, string tsb, string cdb, long int vp, DT *dt, DV *dv);
        ~BN(){}
        
        friend istream& operator>>(istream &is, BN &a);

        friend ostream& operator<<(ostream &os, BN a);

        void ds_thuoc(istream &is);
        void ds_dvu(istream &is);

        void setN(int n);
        int getN();

        void setM(int m);
        int getM();

        long int thanh_tien();
};


BN :: BN(string ht, string cmt, string gt, string dc, NS ns, string mbn, string mhs, string tsb, string cdb, long int vp,  DT *dt, DV *dv) : PS(ht, cmt, gt, dc, ns){
    this -> mbn = mbn;
    this -> mhs = mhs;
    this -> tsb = tsb;
    this -> cdb = cdb;
    this -> vp = vp;
    this -> dt = dt;
    this -> dv = dv;
}
 
istream& operator>>(istream &is, BN &a){
    is >> (PS&) a;
    cout << "Ma benh nhan: "; getline(is, a.mbn);
    cout << "Ma ho so: "; getline(is, a.mhs);
    cout << "Tien su benh: "; getline(is, a.tsb);
    cout << "Chan doan benh: "; getline(is, a.cdb);
    cout << "Vien phi: "; is >> a.vp;
    a.ds_thuoc(is);
    a.ds_dvu(is);
    cout << endl;
    is.ignore();
    return is;
}   

void BN :: setN(int n){
    this -> n = n;
}
int BN :: getN(){
    return n;
}

void BN :: setM(int m){
    this -> m = m;
}
int BN :: getM(){
    return m;
}

void BN :: ds_thuoc(istream &is){
    int x;
    hoi_don_thuoc();
    cout << "\n\tLua chon: "; is >> x;
    

    if (x == 0) setN(0);
    else{
        int i = 0;
        do{
            is.ignore();
            cout << "\n\tThuoc thu " << i + 1 << endl;
            is >> dt[i];
            i++;
            setN(i);

            hoi_nhap();
            cout << "\n\tLua chon: "; is >> x;
        }while(x == 1);
    }
}

void BN :: ds_dvu(istream &is){
    int x;
    hoi_dvu();
    cout << "\n\tLua chon: "; is >> x;

    if (x == 0) setM(0);
    else{
        int i = 0;
        do{
            is.ignore();
            cout << "\n\tThuoc thu " << i + 1 << endl;
            is >> dv[i];
            i++;
            setM(i);

            hoi_nhap();
            cout << "\n\tLua chon: "; is >> x;
        }while(x == 1);
    }
}

long int BN :: thanh_tien(){
    long int t1 = 0, t2 = 0;
    for(int i = 0; i < getN(); i++){
        t1 += dt[i].tong_tien();
    } 
    for(int i = 0; i < getM(); i++){
        t2 += dv[i].getDg();
    } 

    return (t1 + vp) * 0.8 + t2;
}

ostream& operator<<(ostream &os, BN a){
    os << (PS) a;
    os << '|' << setw(25) << a.mbn;
    os << '|' << setw(15) << a.mhs;
    os << '|' << setw(25) << a.tsb;
    os << '|' << setw(25) << a.cdb;
    os << '|' << setw(15) << a.vp;
    os << '|' << setw(15) << a.thanh_tien() << '|' << endl;
    os << '|' << setfill('=') << setw(229) << '|' << setfill(' ') << endl;
    return os;
} 
