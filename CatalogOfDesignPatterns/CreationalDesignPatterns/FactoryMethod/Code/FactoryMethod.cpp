#include <iostream>

// BaseClass
// Factory
class Kahve {
public:
    int sure;
    double cekirdekKalinlik;
    virtual void hazirla() = 0;
    void servisEt() {
        this->hazirla();
        std::cout << "Kahve servis ediliyor..." << std::endl;
    }
};

// Products

class TurkKahvesi : public Kahve {
private:
    void Init() {
        this->sure = 5;
        this->cekirdekKalinlik = 0.5;
    }
public:
    void hazirla() override {
        this->Init();
        std::cout << "Türk kahvesi hazırlanıyor..." << std::endl;
        std::cout << sure << " dakika demleniyor." << std::endl;
        std::cout << "Çekirdek kalınlığı: " << cekirdekKalinlik << std::endl;
    }
};

class Espresso : public Kahve {
private:
    void Init() {
        this->sure = 2;
        this->cekirdekKalinlik = 0.6;
    }
public:
    void hazirla() override {
        std::cout << "Espresso hazırlanıyor..." << std::endl;
        std::cout << sure << " dakika demleniyor." << std::endl;
        std::cout << "Çekirdek kalınlığı: " << cekirdekKalinlik << std::endl;
    }
};

class FiltreKahve : public Kahve {
private:
    void Init() {
        this->sure = 5;
        this->cekirdekKalinlik = 1;
    }
public:
    void hazirla() override {
        std::cout << "Filtre kahvesi hazırlanıyor..." << std::endl;
        std::cout << sure << " dakika demleniyor." << std::endl;
        std::cout << "Çekirdek kalınlığı: " << cekirdekKalinlik << std::endl;
    }
};

// Interface
class KahveMakinesi {
public:
    virtual Kahve* kahveUret() = 0;
};

// Creators

class TurkKahvesiMakinesi : public KahveMakinesi {
public:
    Kahve* kahveUret() override {
        return new TurkKahvesi();
    }
};

class EspressoMakinesi : public KahveMakinesi {
public:
    Kahve* kahveUret() override {
        return new Espresso();
    }
};

class FiltreKahveMakinesi : public KahveMakinesi {
public:
    Kahve* kahveUret() override {
        return new FiltreKahve();
    }
};

int main() {
    KahveMakinesi* kahveMakinesi = new TurkKahvesiMakinesi();
    Kahve* kahve = kahveMakinesi->kahveUret();
    kahve->servisEt();

    return 0;
}