#include "Menu.cpp"

class Ds{
    private:
        void* data;
        Ds *next;
    public:
        Ds(){};
        ~Ds(){
            delete next;
        }

        void setData(void *data);
        void* getData();

        void setNext(Ds* next);
        Ds* getNext();
};
 
void Ds :: setData(void* data){
    this -> data = data;
}

void* Ds :: getData(){
    return data;
}

void Ds :: setNext(Ds* next){
    this -> next = next; 
}

Ds* Ds :: getNext(){
    return next;
}

void init(Ds* &ds){
    ds = new Ds;
    ds = NULL;
}

Ds* create(void* data){
    Ds *tg = new Ds;
    tg -> setData(data);
    tg ->setNext(NULL);
    return tg;
}

void first_list(Ds* &ds, void* data){
    Ds *tg = create(data);
    ds = tg;
}

void last_list(Ds* &ds, void* data){
    Ds *tg = create(data);
    
    if (ds == NULL) first_list(ds, data); 
    else{
        Ds *ds1 = ds;
        while(ds1 -> getNext() != NULL){
            ds1 = ds1 -> getNext();
        }
        ds1 ->setNext(tg);
    }
}

void xuat_dt(Ds* &ds){
    if (ds == NULL) return;
    Ds *tg = ds;
    do{
        cout << (DT*) tg ->getData();
        tg = tg -> getNext();
    }while(tg != NULL);
}

void ds_dthuoc(istream &is, Ds* &ds_dt){
    int x, i = 0;
    hoi_don_thuoc();
    cout << "\n\tLua chon: "; is >> x;
    
    init(ds_dt);
    if (x == 0) ds_dt = NULL;
    else{
        DT *dt;
        do{
            dt = new DT; 
            is.ignore();
            cout << "\n\tThuoc thu " << i + 1 << endl;
            is >> dt;
            last_list(ds_dt, dt);
            i++;
            hoi_nhap();
            cout << "\n\tLua chon: "; is >> x;
        }while(x == 1);
    }
}

void ds_dvu(istream &is, Ds* &ds_dv){
    int x, i = 0;
    hoi_dvu();
    cout << "\n\tLua chon: "; is >> x;
    
    init(ds_dv);
    if (x == 0) ds_dv = NULL;
    else{
        DV *dv;
        do{
            dv = new DV;
            is.ignore();
            cout << "\n\tDich vu thu " << i + 1 << endl;
            is >> dv;
            last_list(ds_dv, dv);
            i++;
            hoi_nhap();
            cout << "\n\tLua chon: "; is >> x;
        }while(x == 1);
    }
}