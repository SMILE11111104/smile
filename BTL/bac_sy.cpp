#include "danh_sach.cpp"

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
    a -> setCmt("SB" + a -> getCmt());
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
    os << '|' << setfill('=') << setw(152) << '|' << setfill(' ') << endl;
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

void ds_bs(Ds* &ds_bs){
    int x, i = 0;
    BS *bs;
    ifstream filein;
    lay_du_lieu();
    cin >> x;
    cin.ignore();
    if (x == 1) {
        filein.open("bac_sy.txt");
        filein >> x;
        filein.ignore();
        for (int i = 0; i < x; i++){
            bs = new BS;
            filein >> (BS*&) bs;
            last_list(ds_bs, bs);
        }  
    }
    else if (x == 2){
        do{
            bs = new BS;
            cout << "\n\tBac sy thu " << i + 1 << endl;
            cin >> (BS*&) bs;
            last_list(ds_bs, bs);
            i++;
            hoi_nhap();
            cin >> x;
            cin.ignore();
        }while(x == 1);
    }
    else return;
}