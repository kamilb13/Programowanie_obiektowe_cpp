class kalkulator{
private:
    float x, y;
public:
    kalkulator(float x=0, float y=0): x(x), y(y){}
    float suma();
    float odejmowanie();
    float iloczyn();
    float iloraz();
    void zwrocxy(float x, float y){
        this->x=x;
        this->y=y;
    }
};
