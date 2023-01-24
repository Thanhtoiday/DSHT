#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int xyz(){
    return 2;
}
//them chuc nang 1

//them chuc nang 2

class BN{
    string ten;
    int ma;
    string benh;
    string Khoa;
    public:
        BN(){
            ten = "";
            ma =0;
            benh ="";
            Khoa = "";
        }

        virtual void nhap();
        virtual void xuat();
        virtual int GetMa(){
            return ma;
        }
};

void BN::nhap(){
    cin>>ten;
    cin>>ma;
    cin>>benh;
    cin>>Khoa;
}

void BN::xuat(){
    cout<<this->ten<<this->ma<<this->benh<<this->Khoa<<endl;
}

class NoiTru: public BN{
    int maphong;
    public:
        NoiTru(){
            maphong = 0;
        }
        void nhap(){
            BN::nhap();
            cin>>maphong;
        }

        void xuat(){
            BN::xuat();
            cout<<" "<<maphong;
        }
};

class NgoaiTru: public BN{
    string donthuoc;
    public:
        NgoaiTru(){
            donthuoc = "";
        }
        void nhap(){
            BN::nhap();
            cin>>donthuoc;
        }
        void xuat(){
            BN::xuat();
            cout<<" "<<donthuoc;
        }
};



int main(){
    BN **ds;
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    ds = new BN*[n];
    int i;
    for(i = 0; i<n ; i++){
        cout<<"1-Noi"<<endl;
        cout<<"2-Ngoai"<<endl;
        int op;
        cin>>op;
        if(op == 1){
            ds[i] = new NoiTru();
        }
        else if(op ==2){
            ds[i] = new NgoaiTru();
        }
        ds[i]->nhap();
    }

    

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ds[i]->GetMa() > ds[j]->GetMa()){
                BN *tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
        }
    }

    for(int i=0; i<n; i++){
        ds[i]->xuat();
    }
}