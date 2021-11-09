class compte
{
private:
    double solde;
    int numerodecompte;
public:
    compte(double=0.0);
    bool retraitArgent(double);
    void depotArgent(double);
    double getSolde();
    bool transfertArgent(double,compte&);
    void depotArgent2emeCompte(double);

};


