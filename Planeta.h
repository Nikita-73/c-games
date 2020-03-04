class Planeta
{
    char* name; // Название
    double radnum; // Расположение
    double sredred; // Средний радиус орбиты
    double gravite; // Сила притяжения
public:
    Planeta();
    Planeta( char* name1, double rudnum1, double sredred1, double gravite1);
    ~Planeta();
    void setName(char* name1);
    void setRadnum(double rudnum1);
    void setSredred(double sredred1);
    void setGravite(double gravite1);
    char* getName();
    double getRadnum();
    double getSredred();
    double getGravite();  
};
