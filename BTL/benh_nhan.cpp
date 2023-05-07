#pragma once
#include "don_thuoc.cpp"

class BN : public PS{
    private:
        string mbn, mhs, tsb, cdb;
        NS nc;
        long int vp;
        Ds *ds_dt;
        Ds *ds_dv;
    public:
        BN(){}
        BN(string mbn, string mhs, string tsb, string cdb, NS nc, long int vp, Ds *ds_dt, Ds *ds_dv);
        ~BN(){}
        
        friend istream& operator>>(istream &is, BN* a);

        friend ostream& operator<<(ostream &os, BN* a);

        void setMbn(string mbn);
        string getMbn();

        void setMhs(string mhs);
        string getMhs();

        void setTsb(string tsb);
        string getTsb();

        void setCdb(string cdb);
        string getCdb();

        void setNc(NS nc);
        NS getNc();

        void setVp(long int vp);
        long int getVp();

        void setDs_dt(Ds *ds_dt);
        Ds* getDs_dt();

        void setDs_dv(Ds *ds_dv);
        Ds* getDs_dv();

        long int thanh_tien();
};


BN :: BN(string mbn, string mhs, string tsb, string cdb, NS nc, long int vp, Ds *ds_dt, Ds *ds_dv){
    this -> mbn = mbn;
    this -> mhs = mhs;
    this -> tsb = tsb;
    this -> cdb = cdb;
    this -> nc = nc;
    this -> vp = vp;
    this -> ds_dt = ds_dt;
    this -> ds_dv = ds_dv;
}
 
istream& operator>>(istream &is, BN* a){
    is >> (PS*&) a;
    a -> setCmt("NB" + a -> getCmt());
    cout << "Ma benh nhan: "; getline(is, a -> mbn);
    cout << "Ma ho so: "; getline(is, a -> mhs);
    cout << "Tien su benh: "; getline(is, a -> tsb);
    cout << "Chan doan benh: "; getline(is, a -> cdb);
    cout << "\n\tNgay chuyen" << endl;
    is >> a -> nc;
    cout << "Vien phi: "; is >> a -> vp;
    return is;

}   

ostream& operator<<(ostream &os, BN* a){
    os << (PS*) a;
    os << '|' << setw(15) << a -> mbn;
    os << '|' << setw(15) << a -> mhs;
    os << '|' << setw(25) << a -> tsb;
    os << '|' << setw(25) << a -> cdb;
    os << a -> nc;
    os << '|' << setw(10) << a -> vp;
    os << '|' << setw(10) << a -> thanh_tien() << '|' << endl;
    cout << '|' << setfill('=') << setw(203) << '|' << setfill(' ') << endl;
    return os;
} 

long int BN :: thanh_tien(){
    Ds* tg = ds_dt;
    long int t1 = 0, t2 = 0;
    DV *dv;
    DT *dt;
    if (tg == NULL) t1 = 0;
    else {
        while(tg != NULL){
            dt = (DT*) tg -> getData();
            t1 += dt -> tong_tien();
            tg = tg -> getNext();
        }
    }

    tg = ds_dv;
    if (tg == NULL) t2 = 0;
    else {
        while(tg != NULL){
            dv = (DV*) tg -> getData();
            t2 += dv -> getDg();
            tg = tg -> getNext();
        }
    }

    return 0.2 * (t1 + vp) + t2;
}

void BN :: setMbn(string mbn){
    this -> mbn = mbn;
}
string BN :: getMbn(){
    return mbn;
}

void BN :: setMhs(string mhs){
    this -> mhs = mhs;
}
string BN :: getMhs(){
    return mhs;
}

void BN :: setTsb(string tsb){
    this -> tsb = tsb;
}
string BN :: getTsb(){
    return tsb;
}

void BN :: setCdb(string cdb){
    this -> cdb = cdb;
}
string BN :: getCdb(){
    return cdb;
}

void BN :: setNc(NS nc){
    this -> nc = nc;
}
NS BN :: getNc(){
    return nc;
}

void BN :: setVp(long int vp){
    this -> vp = vp;
}
long int BN :: getVp(){
    return vp;
}

void BN :: setDs_dt(Ds *ds_dt){
    this -> ds_dt = ds_dt;
}
Ds* BN :: getDs_dt(){
    return ds_dt;
}

void BN :: setDs_dv(Ds *ds_dv){
    this -> ds_dv = ds_dv;
}
Ds* BN :: getDs_dv(){
    return ds_dv;
}

bool tach_mahs(string a){
    string b = "";
    b = b + a[0] + a[1];
    if (b == "NT") return true;
    return false;
}

void ds_dt_file(Ds *&ds_dt, BN *bn){
    int x, y;
    string mbn;
    DT *dt1;
    ifstream filein2;

    filein2.open("don_thuoc.txt");
    filein2 >> x;
    filein2.ignore();
    for(int i = 0; i < x; i++){
        getline(filein2, mbn);
        if(mbn == bn -> getMbn()){
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++){
                dt1 = new DT;
                filein2 >> (DT*&) dt1;
                last_list(ds_dt, dt1);
            }
        }
        else {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++){
                dt1 = new DT;
                filein2 >> (DT*&) dt1;
                delete dt1;
            }
        }
    }
}

void ds_dv_file(Ds *&ds_dv, BN *bn){
    int x, y;
    string mbn;
    DV *dv1;
    ifstream filein2;

    filein2.open("dich_vu.txt");
    filein2 >> x;
    filein2.ignore();
    for(int i = 0; i < x; i++){
        getline(filein2, mbn);
        if(mbn == bn -> getMbn()){
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++){
                dv1 = new DV;
                filein2 >> (DV*&) dv1;
                last_list(ds_dv, dv1);
            }
        }
        else {
            filein2 >> y;
            filein2.ignore();
            for (int j = 0; j < y; j++){
                dv1 = new DV;
                filein2 >> (DV*&) dv1;
                delete dv1;
            }
        }
    }
}